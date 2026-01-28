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
vector<ll> links, len;
int find(int x) {
  if (x == links[x]) return x;
  return links[x] = find(links[x]);
}
bool same(int a, int b) { return find(a) == find(b); }
void unite(int a, int b) {
  a = find(a);
  b = find(b);
  if (len[a] < len[b]) swap(a, b);
  len[a] += len[b];
  links[b] = a;
}

struct query {
  ll to, ind;
};
vector<vector<ll>> adj;
vector<bool> visited;
vector<vector<query>> queries;
vector<ll> anc;
vector<ll> depth;
vector<ll> answers;

void calc_depth(ll v, ll p, ll curr) {
  depth[v] = curr;
  for (ll u : adj[v]) {
    if (u != p) {
      calc_depth(u, v, curr + 1);
    }
  }
}

// https://cp-algorithms.com/graph/lca_tarjan.html
void dfs(ll v) {
  visited[v] = true;
  anc[v] = v;
  for (ll u : adj[v]) {
    if (!visited[u]) {
      dfs(u);
      unite(v, u);
      anc[find(v)] = v;
    }
  }
  for (auto q : queries[v]) {
    if (visited[q.to]) {
      ll lca = anc[find(q.to)];
      ll ans = depth[v] + depth[q.to] - 2 * depth[lca];
      answers[q.ind] = ans;
    }
  }
}

void solve(void) {
  ll n, m;
  ll x, y;
  cin >> n >> m;

  adj.resize(n);
  visited.resize(n, false);
  anc.resize(n);
  for (ll i = 0; i < n - 1; ++i) {
    cin >> x >> y;
    --x, --y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  links.reserve(n);
  len.resize(n, 1);
  for (ll i = 0; i < n; ++i) {
    links.emplace_back(i);
    links[i] = i;
  }
  depth.resize(n);
  calc_depth(0, -1, 0);

  queries.resize(n);
  answers.resize(m);
  for (ll i = 0; i < m; ++i) {
    cin >> x >> y;
    --x, --y;
    queries[x].push_back({y, i});
    queries[y].push_back({x, i});
  }
  dfs(0);
  for (ll i = 0; i < m; ++i) {
    cout << answers[i] << "\n";
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
