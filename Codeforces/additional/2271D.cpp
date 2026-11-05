// #pragma GCC target("avx2,bmi,bmi2,fmi,lzcnt,popcnt")
#include <algorithm>
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
  ll n, m, k;
  cin >> n >> m >> k;
  vector<pair<ll, ll>> vec;
  vector<ll> prefix(1, 0);
  ll tot = 0;
  for (ll i = 0; i < n; ++i) {
    ll l, r;
    cin >> l >> r;
    vec.push_back({l, r});
    tot += (r - l + 1);
    prefix.push_back(tot);
  }

  prefix.push_back(tot);

  vec.push_back({1e16, 1e16});
  if (k == 0) {
    cout << vec.back().second + 1 << endl;
    return;
  }

  ll mx = 0;
  ll pos = 0;
  for (ll i = 0; i < n; ++i) {
    auto [l, r] = vec[i];

    auto it = upper_bound(vec.begin(), vec.end(), make_pair(l + m, -1));
    it = prev(it);
    ll dist = distance(vec.begin(), it);
    ll cm = prefix[dist] - prefix[i];

    if (l + m > vec[dist].first) {
      auto [ll, rr] = vec[dist];
      cm += min(l + m - ll, rr - ll + 1);
    }
    if (cm > mx) {
      mx = cm;
      pos = l;
    }
  }

  if (mx < k) {
    cout << -1 << endl;
    return;
  }
  if (mx == k) {
    cout << pos << endl;
    return;
  }

  vector<pair<ll, ll>> sol;
  for (ll i = 0; i < n; ++i) {
    auto [l, r] = vec[i];
    if (l >= pos) {
      sol.push_back(vec[i]);
    }
  }

  auto calc = [&](ll s) {
    auto it = upper_bound(sol.begin(), sol.end(), make_pair(s, -1LL));
    ll start = max((ll)distance(sol.begin(), it) - 1, 0LL);
    for (ll i = start; i < sol.size(); ++i) {
      auto [l, r] = sol[i];
      if (l <= s && r >= s) {
        ll cm = r - s + 1;
        for (ll j = i + 1; j < sol.size(); ++j) {
          auto [ll, rr] = sol[j];
          if (s + m <= ll) {
            break;
          } else {
            cm += min(s + m - ll, rr - ll + 1);
          }
        }
        return cm <= k;
      } else if (s < l) {
        ll cm = 0;
        for (ll j = i; j < sol.size(); ++j) {
          auto [ll, rr] = sol[j];
          if (s + m <= ll) {
            break;
          } else {
            cm += min(s + m - ll, rr - ll + 1);
          }
        }
        return cm <= k;
      }
    }
    return true;
  };

  ll left = pos, right = 1e16;
  while (left + 1 < right) {
    ll mid = (left + right) / 2;
    bool low = calc(mid);
    if (low) {
      right = mid;
    } else {
      left = mid;
    }
  }
  cout << right << endl;

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
