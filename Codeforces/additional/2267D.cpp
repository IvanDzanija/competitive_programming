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
  set<ll> f;
  set<ll> s;
  for (ll i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    if (i % 2 == 0) {
      f.insert(x);
    } else {
      s.insert(x);
    }
  }
  bool forw = true;
  ll p = 0;
  for (ll i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      if (forw) {
        auto it = f.upper_bound(p);
        if (it == f.end()) {
          forw = false;
        } else {
          p = *it;
          f.erase(it);
        }
      }
      if (!forw) {
        auto it = f.lower_bound(p);
        if (it == f.begin()) {
          cout << "NO" << endl;
          return;
        }
        it = prev(it);
        p = *it;
        f.erase(it);
      }
    } else {
      if (forw) {
        auto it = s.upper_bound(p);
        if (it == s.end()) {
          forw = false;
        } else {
          p = *it;
          s.erase(it);
        }
      }
      if (!forw) {
        auto it = s.lower_bound(p);
        if (it == s.begin()) {
          cout << "NO" << endl;
          return;
        }
        it = prev(it);
        p = *it;
        s.erase(it);
      }
    }
  }
  cout << "YES" << endl;

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
