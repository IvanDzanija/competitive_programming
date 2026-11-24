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
// https://www.geeksforgeeks.org/dsa/print-all-prime-factors-of-a-given-number/
vector<int> primes(ll n) {
  vector<int> factors;

  // Store the number of 2s that divide n
  while (n % 2 == 0) {
    factors.push_back(2);
    n = n / 2;
  }

  // n must be odd at this point. So we can
  // skip one element (i = i + 2)
  for (int i = 3; i * i <= n; i = i + 2) {
    while (n % i == 0) {
      factors.push_back(i);
      n = n / i;
    }
  }

  // If n is a prime number greater than 2
  if (n > 2)
    factors.push_back(n);

  return factors;
}

void solve(void) {
  ll n, k;
  cin >> n >> k;
  auto pr = primes(k);
  vector<vector<ll>> vec(pr.size());
  for (ll i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    for (ll j = 0; j < pr.size(); ++j) {
      if (x % pr[j] == 0) {
        vec[j].push_back(x);
      }
    }
  }
  ll ans = 0;
  for (auto x : vec) {
    ll curr = accumulate(x.begin(), x.end(), 0LL);
    ans = max(ans, curr);
  }
  cout << ans << endl;

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
