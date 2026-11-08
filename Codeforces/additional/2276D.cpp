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
void solve(void) {
  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> g(n);
  for (ll i = 0; i < m; ++i) {
    ll x, y;
    cin >> x >> y;
    --x, --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (ll i = 0; i < n; ++i) {
    if (g[i].size() == 0) {
      cout << "Brain Melt" << endl;
      return;
    }
  }

  deque<ll> q;
  q.push_back(0);
  set<ll> seen;
  bool many = false;
  while (!q.empty()) {
    ll curr = q.front();
    q.pop_front();
    if (seen.count(curr)) {
      continue;
    }
    seen.insert(curr);
    for (ll v : g[curr]) {
      if (g[v].size() >= 2 && g[curr].size() >= 2) {
        many = true;
      }
      q.push_back(v);
    }
  }
  if (seen.size() != n) {
    cout << "Many" << endl;
    return;
  }
  if (many) {
    cout << "Many" << endl;
  } else {
    cout << 2 << endl;
  }

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
