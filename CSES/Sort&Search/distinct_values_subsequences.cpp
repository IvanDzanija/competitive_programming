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
inline ll pow(ll a, ll b) {
    if (b == 0) {
        return 1;
    }
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

// Modular inverse for prime modulus
inline ll mod_inv(ll num) { return pow(num, MOD - 2); }

void solve(void) {
    ll n;
    cin >> n;
    map<ll, ll> c;
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        if (c.count(x)) {
            ++c[x];
            ll inv = mod_inv(c[x]);
            ll t = ((ans + 1) % MOD) * inv % MOD;
            ll r = (t * (c[x] - 1)) % MOD;
            ans = ((((2 * ans) % MOD) + 1) - r + MOD) % MOD;
        } else {
            ans *= 2;
            ans %= MOD;
            ++ans;
            ans %= MOD;
            c.insert(make_pair(x, 1));
        }
    }
    cout << ans << endl;
    return;
}

signed main(void) {
    std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
    ll tc = 1;
    // cin >> tc;
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
