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

vector<vector<vector<ll>>> preg(10, vector<vector<ll>>(10, vector<ll>()));
ll aa, bb;

void gen(ll x) {
  if (x < 0 || x > 1e18) {
    return;
  }

  preg[aa][bb].push_back(x);
  ll x1 = x * 10 + aa;
  ll x2 = x * 10 + bb;
  if (x1 != 0) {
    gen(x1);
  }
  if (x2 != 0) {
    gen(x2);
  }
};

void pregen(void) {
  for (ll i = 0; i < 10; ++i) {
    for (ll j = i + 1; j < 10; ++j) {
      aa = i;
      bb = j;
      gen(i);
      gen(j);
      sort(all(preg[i][j]));
    }
  }
}

void solve(void) {
  ll a, n;
  cin >> a >> n;
  ll d, e;
  cin >> d >> e;
  if (d > e) {
    swap(d, e);
  }

  ll ans = LLONG_MAX;
  auto it = lower_bound(all(preg[d][e]), a);
  if (it != preg[d][e].end()) {
    ans = min(ans, abs(*it - a));
    ans = min(ans, abs(*prev(it) - a));
  }
  cout << ans << endl;

  return;
}

signed main(void) {
  std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
  ll tc = 1;
  cin >> tc;
  pregen();
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
