// #pragma GCC target("avx2,bmi,bmi2,fmi,lzcnt,popcnt")
#include <bits/stdc++.h>

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
using indexed_set =
    tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
  ll n, d;
  cin >> n >> d;
  vector<pair<ll, ll>> a(n);
  vector<ll> b(n);
  for (ll i = 0; i < n; ++i) {
    cin >> a[i].first;
    a[i].second = i;
    b[i] = a[i].first;
  }
  vector<bool> visited(n, false);
  sort(all(a), std::greater<pair<ll, ll>>());
  ll current = a[0].second;

  ll left_msum = 0, right_msum = 0;
  ll left_tsum = 0, right_tsum = 0;
  ll left_taken = 0, right_taken = 0;
  ll left_missing = d, right_missing = d;

  for (ll diff = 1; diff <= d; ++diff) {
    ll lx = (current - diff + n) % n;
    ll rx = (current + diff) % n;
    left_msum += b[lx];
    right_msum += b[rx];
  }
  ll ans = 0;

  for (ll i = 0; i < n; ++i) {
    ll cx = (current + i) % n;

    ll gain = b[cx] * (left_missing + right_missing) - left_msum - right_msum;
    ll loss = left_tsum + right_tsum - b[cx] * (left_taken + right_taken);
    ll total = gain - loss;
    if (total > 0) {
      visited[cx] = true;
      ans += total;
    }

    // Left left
    ll llx = (cx - d + n) % n;
    if (visited[llx]) {
      --left_taken;
      left_tsum -= b[llx];
    } else {
      --left_missing;
      left_msum -= b[llx];
    }
    // Left right
    if (visited[cx]) {
      ++left_taken;
      left_tsum += b[cx];
    } else {
      ++left_missing;
      left_msum += b[cx];
    }
    // Right left
    ll rlx = (cx + 1) % n;
    if (visited[rlx]) {
      --right_taken;
      right_tsum -= b[rlx];
    } else {
      --right_missing;
      right_msum -= b[rlx];
    }
    // Right right
    ll rrx = (cx + d + 1) % n;
    if (visited[rrx]) {
      ++right_taken;
      right_tsum += b[rrx];
    } else {
      ++right_missing;
      right_msum += b[rrx];
    }
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
