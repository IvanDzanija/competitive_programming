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
    ll q;
    cin >> n >> m;
    cin >> q;
    vector<vector<ll>> vec(n + 2, vector<ll>(m + 2));
    vector<vector<ll>> dp(n + 2, vector<ll>(m + 2));
    vector<vector<ll>> row(n + 2, vector<ll>(m + 2));
    vector<vector<ll>> col(n + 2, vector<ll>(m + 2));
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= m; ++j) {
            cin >> vec[i][j];
        }
    }

    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= m; ++j) {
            ll curr = vec[i][j];
            ll up = curr < vec[i - 1][j];
            ll left = curr < vec[i][j - 1];
            ll c = up or left;

            dp[i][j] = c + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];

            row[i][j] = left + row[i][j - 1];
            col[i][j] = up + col[i - 1][j];
        }
    }
    for (ll i = 0; i < q; ++i) {
        ll ans = 0;
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x2 > x1 and y2 > y1) {
            ans = dp[y2][x2] - dp[y1][x2] - dp[y2][x1] + dp[y1][x1];
        }
        if (x2 > x1) {
            ans += row[y1][x2] - row[y1][x1];
        }
        if (y2 > y1) {
            ans += col[y2][x1] - col[y1][x1];
        }
        cout << ans << endl;
    }

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
