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
  vector<ll> a(n), b(m);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (ll i = 0; i < m; i++) {
    cin >> b[i];
  }
  vector<vector<ll>> dp(n + 1, vector<ll>(m + 1));
  vector<vector<ll>> row(n + 1, vector<ll>(m + 1));
  vector<vector<ll>> col(n + 1, vector<ll>(m + 1));
  for (ll i = 0; i < n; ++i) {
    for (ll j = 0; j < m; ++j) {
      if (a[i] == b[j]) {
        if (row[i + 1][j] == 0 && dp[i + 1][j] + 1 > dp[i][j + 1]) {
          dp[i + 1][j + 1] = dp[i + 1][j] + 1;
          row[i + 1][j + 1] = 1;
          col[i + 1][j + 1] = 1;
          continue;
        } else if (col[i][j + 1] == 0 && dp[i][j + 1] + 1 > dp[i + 1][j]) {
          dp[i + 1][j + 1] = dp[i][j + 1] + 1;
          col[i + 1][j + 1] = 1;
          row[i + 1][j + 1] = 1;
          continue;
        }
      }
      if (dp[i + 1][j] > dp[i][j + 1]) {
        dp[i + 1][j + 1] = dp[i + 1][j];
        row[i + 1][j + 1] = row[i + 1][j];
        col[i + 1][j + 1] = 0;
      } else if (dp[i + 1][j] < dp[i][j + 1]) {
        dp[i + 1][j + 1] = dp[i][j + 1];
        col[i + 1][j + 1] = col[i][j + 1];
        row[i + 1][j + 1] = 0;
      } else {
        dp[i + 1][j + 1] = dp[i][j + 1];
        if (row[i + 1][j] == 0 || col[i][j + 1] == 0) {
          col[i + 1][j + 1] = 0;
          row[i + 1][j + 1] = 0;
        } else {
          col[i + 1][j + 1] = 1;
          row[i + 1][j + 1] = 1;
        }
      }
    }
  }
  ll res = dp[n][m];
  ll r = n, c = m;
  vector<ll> ans;
  while (ans.size() < res) {
    ll up = dp[r - 1][c];
    ll left = dp[r][c - 1];
    ll curr = dp[r][c];
    if (up == curr) {
      --r;
    } else if (left == curr) {
      --c;
    } else {
      ans.push_back(a[r - 1]);
      --r, --c;
    }
  }
  reverse(all(ans));
  cout << res << endl;
  for (auto x : ans) {
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
