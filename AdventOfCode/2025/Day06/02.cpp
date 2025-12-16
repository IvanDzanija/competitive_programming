// #pragma GCC target("avx2,bmi,bmi2,fmi,lzcnt,popcnt")
#include <bits/stdc++.h>
#include <cctype>
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
    string line;
    vector<char> ops;
    map<int, vector<ll>> mp;
    vector<string> grid;

    ll m = 0;
    while (getline(cin, line)) {
        grid.push_back(line);
        m = max(m, (ll)line.size());
    }
    for (auto &x : grid) {
        while (x.size() < m) {
            x.push_back(' ');
        }
    }
    ll n = grid.size();
    ll ans = 0;
    vector<ll> operands;
    for (ll i = m - 1; i >= 0; --i) {
        string curr;
        for (ll j = 0; j < n; ++j) {
            char c = grid[j][i];
            if (j == n - 1) {
                if (c == ' ') {
                    if (curr.empty()) {
                        continue;
                    }
                    operands.push_back(stoll(curr));
                } else if (c == '*') {
                    operands.push_back(stoll(curr));
                    ll tot = 1;
                    for (auto x : operands) {
                        tot *= x;
                    }
                    ans += tot;
                    operands.clear();
                } else if (c == '+') {
                    operands.push_back(stoll(curr));
                    ll tot = 0;
                    for (auto x : operands) {
                        tot += x;
                    }
                    ans += tot;
                    operands.clear();
                }
            } else if (c == ' ') {
                continue;
            } else {
                curr += c;
            }
        }
    }

    cout << ans << endl;

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
