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
vector<vector<ll>> adj;
vector<vector<ll>> capacity;
ll bfs(ll s, ll t, vector<ll> &parent) {
  fill(all(parent), -1);
  parent[s] = -2;
  queue<pair<ll, ll>> q;
  q.push({s, LLONG_MAX});
  while (!q.empty()) {
    auto [curr, flow] = q.front();
    q.pop();
    for (ll next : adj[curr]) {
      if (parent[next] == -1 && capacity[curr][next]) {
        parent[next] = curr;
        ll new_flow = min(flow, capacity[curr][next]);
        if (next == t) {
          return new_flow;
        }
        q.push({next, new_flow});
      }
    }
  }

  return 0;
}
void solve(void) {
  ll n, m;
  cin >> n >> m;
  adj.resize(n);
  capacity.resize(n);
  capacity.assign(n, vector<ll>(n, 0));
  for (ll i = 0; i < m; ++i) {
    ll x, y, w;
    cin >> x >> y >> w;
    --x, --y;
    adj[x].push_back(y);
    adj[y].push_back(x);
    capacity[x][y] += w;
  }
  ll ans = 0;
  vector<ll> vec(n);

  while (true) {
    ll flow = bfs(0, n - 1, vec);
    if (flow == 0) {
      break;
    }
    ans += flow;
    ll curr = n - 1;
    while (curr != 0) {
      ll prev = vec[curr];
      capacity[prev][curr] -= flow;
      capacity[curr][prev] += flow;
      curr = prev;
    }
  };
  cout << ans << endl;

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
