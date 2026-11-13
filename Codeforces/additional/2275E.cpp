// #pragma GCC target("avx2,bmi,bmi2,fmi,lzcnt,popcnt")
#include <bits/stdc++.h>

#include <climits>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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

ll n;
vector<ll> a;
vector<ll> b;
ll ans = LLONG_MIN;

vector<ll> prefix1;
vector<ll> prefix2;
vector<ll> suffix1;
vector<ll> suffix2;
void run(ll pos, bool skipped, ll curr) {
  ans = max(ans, curr);
  if (pos == n) {
    return;
  }
  if (skipped) {
    if (pos & 1) {
      curr += prefix1[n - 1] - prefix1[pos - 1];
      curr += a[n - 1] == b[n - 1] ? 2 : 1;

      if (n & 1) {
        curr += suffix2[pos - 1];
      } else {
        curr += suffix1[pos - 1];
      }
    } else {
      curr += prefix2[n - 1] - prefix2[pos - 1];
      curr += a[n - 1] == b[n - 1] ? 2 : 1;
      if (n & 1) {
        curr += suffix1[pos - 1];
      } else {
        curr += suffix2[pos - 1];
      }
    }
    ans = max(ans, curr);
    return;
  }
  run(pos + 1, true, curr);
  curr += a[pos] == b[pos] ? 2 : 1;
  ans = max(ans, curr);
  if (pos + 1 < n) {
    curr += a[pos + 1] == b[pos] ? 2 : 1;
    run(pos + 1, false, curr);
  }
}

void solve(void) {
  cin >> n;
  a.resize(n);
  b.resize(n);
  prefix1.resize(n, 0);
  prefix2.resize(n, 0);
  suffix1.resize(n, 0);
  suffix2.resize(n, 0);
  for (auto &x : a) {
    cin >> x;
  }
  for (auto &x : b) {
    cin >> x;
  }

  bool step = false;
  for (ll i = 1; i < n; ++i) {
    ll curr1 = (a[i - 1] == b[i]) ? 2 : 1;
    ll curr2 = (b[i - 1] == a[i]) ? 2 : 1;

    ll s = n - 1 - i;
    ll suff1 = (a[s + 1] == b[s]) ? 2 : 1;
    ll suff2 = (b[s + 1] == a[s]) ? 2 : 1;
    if (step) {
      swap(curr1, curr2);
      swap(suff1, suff2);
    }
    prefix1[i] = prefix1[i - 1] + curr1;
    prefix2[i] = prefix2[i - 1] + curr2;
    suffix1[s] = suffix1[s + 1] + suff1;
    suffix2[s] = suffix2[s + 1] + suff2;
    step = !step;
  }

  // for (auto x : prefix1) {
  //   cout << x << ' ';
  // }
  // cout << endl;
  // for (auto x : prefix2) {
  //   cout << x << ' ';
  // }
  // cout << endl;
  // for (auto x : suffix1) {
  //   cout << x << ' ';
  // }
  // cout << endl;
  // for (auto x : suffix2) {
  //   cout << x << ' ';
  // }
  // cout << endl;
  run(0, false, 0);
  cout << ans << endl;
  a.clear();
  b.clear();
  prefix1.clear();
  prefix2.clear();
  suffix1.clear();
  suffix2.clear();
  ans = 0;

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
