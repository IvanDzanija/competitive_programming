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
vector<ll> link, len;
int find(int x) {
  if (x == link[x]) return x;
  return link[x] = find(link[x]);
}
bool same(int a, int b) { return find(a) == find(b); }
void unite(int a, int b) {
  a = find(a);
  b = find(b);
  if (len[a] < len[b]) swap(a, b);
  len[a] += len[b];
  link[b] = a;
}

vector<vector<ll>> adj;
vector<bool> visited;
vector<vector<ll>> queries;
vector<ll> anc;
vector<ll> prefix;
vector<ll> cost;
map<pair<ll, ll>, ll> answers;

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
    if (visited[q]) {
      ll lca = anc[find(q)];
      ll ans = prefix[v] + prefix[q] - 2 * prefix[lca] + cost[lca];
      answers[{v, q}] = ans;
      answers[{q, v}] = ans;
    }
  }
}

void calc_prefix(ll v, ll p, ll curr) {
  curr += cost[v];
  prefix[v] = curr;
  for (ll u : adj[v]) {
    if (u != p) {
      calc_prefix(u, v, curr);
    }
  }
}

void solve(void) {
  ll n, m;
  cin >> n >> m;
  cost.resize(n);
  for (ll i = 0; i < n; i++) {
    cin >> cost[i];
  }

  adj.resize(n);
  visited.resize(n, false);
  anc.resize(n);
  for (ll i = 0; i < n - 1; ++i) {
    ll x, y;
    cin >> x >> y;
    --x, --y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  link.resize(n);
  len.resize(n, 1);
  for (ll i = 0; i < n; ++i) {
    link[i] = i;
  }

  prefix.resize(n, 0);
  calc_prefix(0, -1, 0);

  queries.resize(n);
  vector<pair<ll, ll>> qs;
  ll prev = 0;
  for (ll i = 0; i < m; ++i) {
    ll x;
    cin >> x;
    --x;
    qs.push_back({prev, x});
    queries[prev].push_back(x);
    queries[x].push_back(prev);
    prev = x;
  }
  dfs(0);
  for (auto q : qs) {
    if (q.first == q.second) {
      cout << 0 << ' ';
    } else {
      cout << answers[q] - cost[q.first] << ' ';
    }
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
