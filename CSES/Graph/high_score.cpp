// #pragma GCC target("avx2,bmi,bmi2,fmi,lzcnt,popcnt")
#include <bits/stdc++.h>

#include <climits>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
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
struct edge {
  ll u, v, w;
};

void solve(void) {
  ll n, m;
  cin >> n >> m;
  vector<edge> es;
  vector<vector<ll>> adj(n + 1);
  vector<vector<ll>> rev(n + 1);
  for (ll i = 0; i < m; ++i) {
    ll u, v, w;
    cin >> u >> v >> w;
    w = -w;
    edge e = {u, v, w};
    es.push_back(e);
    adj[u].push_back(v);
    rev[v].push_back(u);
  }

  set<ll> seen;
  queue<ll> q;
  q.push(n);
  while (!q.empty()) {
    auto u = q.front();
    q.pop();
    if (seen.count(u)) {
      continue;
    }
    seen.insert(u);
    for (auto v : rev[u]) {
      q.push(v);
    }
  }

  vector<ll> dist(n + 1, LLONG_MAX);
  vector<ll> p(n + 1, -1);
  dist[1] = 0;
  bool any = false;
  vector<ll> rel;
  for (ll i = 0; i <= n; ++i) {
    any = false;
    for (auto e : es) {
      if (dist[e.u] < LLONG_MAX) {
        if (dist[e.v] > dist[e.u] + e.w) {
          dist[e.v] = max(LLONG_MIN, dist[e.u] + e.w);
          p[e.v] = e.u;
          any = true;
          if (i == n) {
            rel.push_back(e.v);
          }
        }
      }
    }
    if (!any) {
      break;
    }
  }
  if (!any) {
    cout << -dist[n] << endl;
  } else {
    for (auto y : rel) {
      for (ll i = 0; i < n; ++i) {
        y = p[y];
      }

      vector<int> path;
      for (int cur = y;; cur = p[cur]) {
        if (seen.count(cur)) {
          cout << -1 << endl;
          return;
        }
        path.push_back(cur);
        if (cur == y && path.size() > 1) {
          break;
        }
      }
    }
    cout << -dist[n] << endl;
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
