// #pragma GCC target("avx2,bmi,bmi2,fmi,lzcnt,popcnt")
#include <bits/stdc++.h>

#include <climits>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <numeric>
#include <queue>
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define INF (ll)1e9
#define all(x) (x).begin(), (x).end()
#define MOD (ll)(1e9 + 7)

using namespace __gnu_pbds;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
using indexed_set = tree<T, null_type, std::less<T>, rb_tree_tag,
                         tree_order_statistics_node_update>;
struct custom_hash {
  static ull splitmix64(ull x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(ull x) const {
    static const ull FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
void solve(void) {
  ll n, k;
  cin >> n >> k;
  vector<vector<ll>> vec(n, vector<ll>(3));
  priority_queue<pair<ll, ll>> pq;
  for (ll i = 0; i < n; ++i) {
    cin >> vec[i][0] >> vec[i][1] >> vec[i][2];
    pq.push(make_pair(-accumulate(vec[i].begin(), vec[i].end(), 0LL), i));
  }
  if (k == 0) {
    cout << -pq.top().first << endl;
    return;
  }
  ll steps = 0;
  ll cnt = 0;
  ll curr = LLONG_MAX;
  ll ans = LLONG_MIN;
  while (steps < k && !pq.empty()) {
    auto [val, it] = pq.top();
    val = -val;
    pq.pop();

    ll a = vec[it][0], b = vec[it][1], c = vec[it][2];

    if (curr < val) {
      ll tmp = curr;
      curr += min((k - steps) / cnt, val - tmp);
      steps += min(k - steps, (val - tmp) * cnt);
      ans = max(ans, curr);
    }
    if (steps >= k) {
      break;
    }

    // cout << val << ' ' << it << ' ' << curr << endl;
    // cout << steps << endl;
    if (a > b || a > c || b > c) {
      ++cnt;
      curr = val;
    } else {
      ans = max(ans, val);
      if (a == b && a == c) {
        cout << ans << endl;
        return;
      }

      ll diff = min(b - a, c - a);
      diff = min(diff, c - b);

      if (k - steps < diff) {
        ll poss = k - steps;
        ans = max(ans, min(curr, val - poss));
        steps = k;
        break;
      }

      ++diff;
      steps += diff;
      val -= diff;
      if (curr != LLONG_MAX) {
        if (k - steps >= curr - val) {
          steps += curr - val;
          ++cnt;
        } else {
          steps = k;
          break;
        }
      } else {
        ++cnt;
        curr = val;
      }
    }
    // cout << val << ' ' << it << ' ' << curr << endl;
  }
  // cout << steps << ' ' << k << ' ' << curr << endl;

  if (steps < k) {
    curr += (k - steps) / cnt;
    ans = max(ans, curr);
  }
  cout << ans << endl;

  return;
}

signed main(void) {
  std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
  ll tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
#ifdef LOCAL
    cout << "--------------------------------------------" << endl;
#endif
  }

#ifdef LOCAL
  cerr << "Finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
  return 0;
}
