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
  ll n;
  cin >> n;
  string s;
  cin >> s;
  vector<pair<ll, char>> pref;
  char prev = s[0];
  ll curr = 0;
  for (auto x : s) {
    if (x != prev) {
      pref.push_back({curr, prev});
      curr = 1;
      prev = x;
    } else {
      ++curr;
    }
  }
  pref.push_back({curr, prev});
  ll tot = pref[0].first;
  ll mx = 0;
  ll pos = -1;
  for (ll i = 1; i < pref.size() - 1; ++i) {
    auto [pl, pc] = pref[i - 1];
    auto [cl, cc] = pref[i];
    auto [nl, nc] = pref[i + 1];
    tot += cl;
    if (cl != 1) {
      continue;
    }
    if (pc != nc) {
      if (1 > mx) {
        mx = 1;
        pos = tot - 1;
      }
    } else {
      ll r = pl + nl + 1;
      if (r > mx) {
        mx = r;
        pos = tot - 1;
      }
    }
  }
  if (pos == -1) {
    s.erase(1, 1);
  } else {
    s.erase(pos, 1);
  }
  // cout << s << endl;
  prev = s[0];
  curr = 0;
  pref.clear();
  for (auto x : s) {
    if (x != prev) {
      pref.push_back({curr, prev});
      curr = 1;
      prev = x;
    } else {
      ++curr;
    }
  }
  cout << pref.size() + 1 << endl;

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
