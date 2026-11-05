// #pragma GCC target("avx2,bmi,bmi2,fmi,lzcnt,popcnt")
// #include <bits/stdc++.h>

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#include <chrono>
#include <iostream>
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
  vector<vector<ll>> vec(n);
  vector<ll> depth(n);
  vector<bool> isleaf(n, false);
  depth[0] = 1;

  for (ll i = 0; i < n - 1; ++i) {
    ll x, y;
    cin >> x >> y;
    --x, --y;
    vec[x].push_back(y);
    vec[y].push_back(x);
  }
  queue<pair<ll, ll>> q;

  q.push({0, 0});
  set<ll> seen;
  while (!q.empty()) {
    auto [u, d] = q.front();
    q.pop();
    if (seen.count(u)) {
      continue;
    }
    seen.insert(u);
    bool leaf = true;
    for (auto v : vec[u]) {
      if (seen.count(v)) {
        continue;
      }
      q.push({v, d + 1});
      leaf = false;
    }

    depth[u] = d;
    isleaf[u] = leaf;
  }
  // for (auto x : isleaf) {
  //   cout << x << endl;
  // }
  ll curr = n + 1;
  ll ans = 0;
  vector<pair<ll, ll>> res;
  for (ll i = 0; i < n; ++i) {
    if (isleaf[i] && (depth[i] & 1)) {
      ++ans;
      res.push_back({i + 1, curr++});
    }
  }
  cout << ans << endl;
  for (auto x : res) {
    cout << x.first << ' ' << x.second << endl;
  }

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
