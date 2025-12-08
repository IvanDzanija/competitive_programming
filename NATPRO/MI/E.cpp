// #pragma GCC target("avx2,bmi,bmi2,fmi,lzcnt,popcnt")
#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define INF (ll) LLONG_MAX
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
    vector<ll> vec(n + 1);
    vector<ll> pref(n + 1, 0);
    for (ll i = 1; i <= n; ++i) {
        cin >> vec[i];
        pref[i] = pref[i - 1] + vec[i];
    }
    vector<ll> dp(n + 2, -INF);
    dp[n + 1] = 0;

    for (ll i = n; i > 0; --i) {
        dp[i] = dp[i + 1] - vec[i];

        for (ll j = i; j <= n; ++j) {
            ll w = pref[j] - pref[i - 1];
            ll l = (w + 1) / 2;
            ll tpref = l + pref[j];

            auto it = lower_bound(all(pref), tpref);
            if (it == pref.end()) {
                continue;
            }

            ll ind = distance(pref.begin(), it);

            ll cl = pref[ind] - pref[j];
            ll prof = w - cl + dp[ind + 1];

            dp[i] = max(dp[i], prof);
        }
    }

    cout << dp[1] << endl;

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
