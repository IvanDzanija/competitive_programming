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

vector<string> split(const std::string &s, const char &delim) {
    std::vector<std::string> ans;
    size_t n = s.size();
    size_t start = 0;
    for (size_t i = 0; i < n; ++i) {
        char curr = s[i];
        if (curr == delim) {
            ans.push_back(s.substr(start, i - start));
            start = i + 1;
        } else if (i == n - 1) {
            ans.push_back(s.substr(start));
        }
    }
    return ans;
}

map<pair<string, string>, ll> memo;
map<string, vector<string>> mp;
ll cnt(string src, string dst) {
    auto key = make_pair(src, dst);
    if (memo.count(key)) {
        return memo[key];
    }
    if (src == dst) {
        return 1;
    }
    ll ans = 0;
    for (auto x : mp[src]) {
        ans += cnt(x, dst);
    }
    memo[key] = ans;
    return ans;
}

void solve(void) {
    string line;
    string start = "svr", end = "out";

    while (getline(cin, line)) {
        string key, rest;
        vector<string> conns;

        for (ll i = 0; i < line.size(); ++i) {
            char curr = line[i];
            if (curr == ':') {
                key = line.substr(0, i);
                rest = line.substr(i + 2);
                conns = split(rest, ' ');
                break;
            }
        }
        mp[key] = conns;
    }
    ll ans = 0;
    string fft = "fft";
    string dac = "dac";
    ans += cnt(start, fft) * cnt(fft, dac) * cnt(dac, end);
    ans += cnt(start, dac) * cnt(dac, fft) * cnt(fft, end);
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
