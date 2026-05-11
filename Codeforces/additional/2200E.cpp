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

const ll MX = 1e6;
vector<set<ll>> sieve(MX + 1, set<ll>());
void precompute(void) {
  for (ll i = 2; i <= MX; ++i) {
    if (sieve[i].size() > 0) {
      continue;
    }
    for (ll j = i + i; j <= MX; j += i) {
      sieve[j].insert(i);
    }
  }
}

bool check_nd(vector<ll> &a) {
  for (ll i = 0; i < a.size() - 1; ++i) {
    if (a[i] > a[i + 1]) {
      return false;
    }
  }
  return true;
}

void solve(void) {
  ll n;
  cin >> n;
  vector<ll> a(n);
  ll mx = 0;
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }
  if (check_nd(a)) {
    cout << "Bob" << endl;
    return;
  }
  for (ll i = 0; i < n; ++i) {
    if (sieve[a[i]].size() > 1) {
      cout << "Alice" << endl;
      return;
    } else if (sieve[a[i]].size() == 1) {
      a[i] = *sieve[a[i]].begin();
    }
  }
  if (check_nd(a)) {
    cout << "Bob" << endl;
  } else {
    cout << "Alice" << endl;
  }

  return;
}

signed main(void) {
  std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
  ll tc = 1;
  cin >> tc;
  precompute();
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
