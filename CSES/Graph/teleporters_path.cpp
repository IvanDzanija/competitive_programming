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
  ll n, m;
  cin >> n >> m;
  vector<vector<pair<ll, ll>>> vec(n + 1);
  set<pair<ll, ll>> edges;
  for (ll i = 0; i < m; ++i) {
    ll u, v;
    cin >> u >> v;
    vec[u].push_back(make_pair(v, i));
    edges.insert({u, v});
  }

  stack<ll> st;
  vector<bool> seen(m, false);
  vector<ll> cyc;
  st.push(1);
  while (!st.empty()) {
    ll nd = st.top();
    if (!vec[nd].empty()) {
      auto [u, idx] = vec[nd].back();
      vec[nd].pop_back();
      if (seen[idx]) {
        continue;
      }
      seen[idx] = true;
      st.push(u);
    } else {
      st.pop();
      cyc.push_back(nd);
    }
  }

  reverse(all(cyc));
  if (cyc.size() != m + 1 || cyc[0] != 1 || cyc.back() != n) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }
  vector<bool> used_edge(m, false);
  for (ll i = 0; i < cyc.size() - 1; ++i) {
    auto r = make_pair(cyc[i], cyc[i + 1]);
    if (edges.count(r)) {
      used_edge[i] = true;
    }
  }
  for (ll i = 0; i < cyc.size() - 1; ++i) {
    if (!used_edge[i]) {
      cout << "IMPOSSIBLE" << endl;
      return;
    }
  }

  for (auto x : cyc) {
    cout << x << ' ';
  }
  cout << endl;
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
