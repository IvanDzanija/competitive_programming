// #pragma GCC target("avx2,bmi,bmi2,fmi,lzcnt,popcnt")
// #include <bits/stdc++.h>

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define INF (ll)1e9
#define all(x) (x).begin(), (x).end()
#define MOD (ll)(1e9 + 7)

// using namespace __gnu_pbds;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
// using indexed_set = tree<T, null_type, std::less<T>, rb_tree_tag,
// tree_order_statistics_node_update>;
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
  ll n;
  cin >> n;
  vector<pair<ll, ll>> vec(n);
  for (ll i = 0; i < n; ++i) {
    ll x, y, z;
    cin >> x >> y >> z;
    ll g = gcd(abs(x), abs(y));
    x /= g;
    y /= g;
    if (x < 0) {
      x = -x;
      y = -y;
    }
    vec[i] = {x, y};
  }
  sort(all(vec));
  // for (auto [x, y] : vec) {
  //   cout << x << ' ' << y << endl;
  // }
  vector<ll> grs;
  ll cnt = 1;
  for (ll i = 1; i < vec.size(); ++i) {
    if (vec[i] == vec[i - 1]) {
      ++cnt;
    } else {
      grs.push_back(cnt);
      cnt = 1;
    }
  }
  grs.push_back(cnt);
  ll x = 0, y = 0, z = 0;
  for (auto w : grs) {
    z += (w * y % MOD);
    z %= MOD;
    y += (w * x % MOD);
    y %= MOD;
    x += (w % MOD);
    x %= MOD;
    // cout << x << ' ' << y << ' ' << z << endl;
  }
  cout << z << endl;

  return;
}

signed main(void) {
  std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
  ll tc = 1;
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
