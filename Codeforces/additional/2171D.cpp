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

vector<ll> link, len, mx;

int find(int x) {
    if (link[x] == x) {
        return x;
    }
    return link[x] = find(link[x]);
}

bool same(int a, int b) { return find(a) == find(b); }

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) {
        return;
    }
    if (mx[a] < mx[b])
        swap(a, b);

    len[a] += len[b];
    link[b] = a;
    mx[a] = max(mx[a], mx[b]);
}

void solve(void) {
    ll n;
    cin >> n;

    link.resize(n + 1);
    len.resize(n + 1);
    mx.resize(n + 1);

    vector<ll> vec(n);
    for (ll i = 0; i < n; ++i) {
        cin >> vec[i];
        len[i + 1] = 1;
        link[i + 1] = i + 1;
        mx[i + 1] = i + 1;
    }
    vector<vector<ll>> adj(n + 1);

    set<ll> reps;
    for (ll i = n - 1; i >= 0; --i) {
        ll curr = vec[i];
        vector<ll> oreps;
        ll nrep = 0;
        auto it = reps.upper_bound(curr);
        bool f = true;

        while (it != reps.end()) {
            f = false;
            ll f = min(curr, *it);
            ll s = max(curr, *it);
            adj[f].push_back(s);

            unite(curr, *it);

            ll rep = max(mx[curr], mx[*it]);
            oreps.push_back(*it);
            nrep = max(nrep, rep);

            it = next(it);
        }
        if (f) {
            reps.insert(curr);
        } else {
            for (auto x : oreps) {
                reps.erase(x);
            }
            reps.insert(nrep);
        }
    }
    if (len[find(1)] == n) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
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
