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
    ll n, q;
    cin >> n >> q;
    vector<ll> c(1, 0);
    vector<ll> t;
    for (ll i = 1; i < n; ++i) {
        ll x;
        cin >> x;
        c.push_back(x);
    }
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        t.push_back(x);
    }
    vector<ll> prefix(n);
    for (ll i = 1; i < n; ++i) {
        prefix[i] = prefix[i - 1] + c[i];
    }
    vector<ll> l(n);
    l[0] = t[0];
    ll lbest = t[0];
    for (ll i = 1; i < n; ++i) {
        ll curr = t[i] - prefix[i];
        lbest = min(lbest, curr);
        l[i] = prefix[i] + lbest;
    }
    vector<ll> r(n);
    r[n - 1] = t[n - 1];
    ll rbest = t[n - 1] + prefix[n - 1];
    for (ll i = n - 2; i >= 0; --i) {
        ll curr = t[i] + prefix[i];
        rbest = min(rbest, curr);
        r[i] = rbest - prefix[i];
    }

    vector<ll> com(n);
    for (ll i = 0; i < n; ++i) {
        com[i] = min(l[i], r[i]);
    }
    for (ll i = 0; i < q; ++i) {
        ll x, y;
        cin >> x >> y;
        --x, --y;
        cout << min(abs(prefix[y] - prefix[x]), com[x] + com[y]) << endl;
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
