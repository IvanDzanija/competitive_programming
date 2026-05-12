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

ll calc_edges(ll c, vector<pair<ll, ll>> &t, vector<ll> &edges) {
  if (t[c] == make_pair(0, 0)) {
    return 1;
  }
  ll tot = 0;
  auto [l, r] = t[c];
  if (l != 0) {
    tot += calc_edges(l, t, edges);
  }
  if (r != 0) {
    tot += calc_edges(r, t, edges);
  }
  edges[c] = tot;
  return tot + 1;
}
ll dfs(ll c, vector<pair<ll, ll>> &t) {
  if (t[c] == make_pair(0, 0)) {
    return 1;
  }
  ll tot = 0;
  auto [l, r] = t[c];
  if (l != 0) {
    ++tot;
    tot += dfs(l, t);
    tot %= MOD;
  }
  if (r != 0) {
    ++tot;
    tot += dfs(r, t);
    tot %= MOD;
  }
  return (tot + 1) % MOD;
}
void slv(ll c, ll par, vector<pair<ll, ll>> &t, vector<ll> &edges, vector<ll> &calc) {
  auto [l, r] = t[c];
  ll cp = calc[c];

  if (l != 0) {
    ll curr = edges[l];
    curr *= 2;
    curr %= MOD;
    ++curr;
    curr %= MOD;
    calc[l] = (cp + curr) % MOD;
    slv(l, c, t, edges, calc);
  }
  if (r != 0) {
    ll curr = edges[r];
    curr *= 2;
    curr %= MOD;
    ++curr;
    curr %= MOD;
    calc[r] = (cp + curr) % MOD;
    slv(r, c, t, edges, calc);
  }
}

void solve(void) {
  ll n;
  cin >> n;
  vector<pair<ll, ll>> t(n + 1, make_pair(0, 0));
  t[0] = make_pair(1, 0);
  vector<ll> edges(n + 1);
  for (ll i = 1; i <= n; ++i) {
    ll x, y;
    cin >> x >> y;
    t[i] = make_pair(x, y);
  }
  calc_edges(0, t, edges);
  ll one = dfs(1, t);
  vector<ll> calc(n + 1);
  calc[1] = one;
  slv(1, 0, t, edges, calc);
  for (ll i = 1; i <= n; ++i) {
    cout << calc[i] << ' ';
  }
  cout << endl;

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
