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
int R, C;
vector<string> grid;
map<pair<int, int>, ll> memo;
ll dfs(int r, int c) {
  auto key = make_pair(r, c);
  if (memo.count(key)) {
    return memo[key];
  }
  if (r == R) {
    return 1;
  }
  ll tot = 0;
  if (grid[r][c] == '^') {
    if (c + 1 < C) {
      tot += dfs(r + 1, c + 1);
    }
    if (c - 1 >= 0) {
      tot += dfs(r + 1, c - 1);
    }
  } else {
    tot += dfs(r + 1, c);
  }
  memo[key] = tot;
  return tot;
}
void solve(void) {
  string line;
  int r = 0;
  ll sr, sc;
  while (getline(cin, line)) {
    grid.push_back(line);
    for (int i = 0; i < line.size(); ++i) {
      if (line[i] == 'S') {
        sr = r, sc = i;
      }
    }

    ++r;
  }
  R = grid.size();
  C = grid[0].size();
  ll ans = dfs(sr, sc);
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
