// #pragma GCC target("avx2,bmi,bmi2,fmi,lzcnt,popcnt")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef long long ll;
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
vector<string> split(const std::string &s, const char &delim) {
    std::vector<std::string> ans;
    size_t n = s.size();
    size_t start = 0;
    for (size_t i = 0; i < n; ++i) {
        char curr = s[i];
        if (curr == delim or i == n - 1) {
            ans.push_back(s.substr(start, i));
            start = i + 1;
        }
    }
    return ans;
}

void solve(void) {
    string line;
    ll ans = 0;

    set<pair<ll, ll>> ranges;
    while (getline(cin, line)) {
        if (line.empty()) {
            break;
        }
        auto s = split(line, '-');
        auto [l, r] = make_pair(stoll(s[0]), stoll(s[1]));
        vector<pair<int, int>> deleted;
        for (auto x : ranges) {
            auto [ll, rr] = x;
            if (l <= ll and r >= rr) {
                deleted.push_back(x);
            } else if (l >= ll and l <= rr) {
                l = ll, r = max(rr, r);
                deleted.push_back(x);
            } else if (r <= rr and r >= ll) {
                l = min(ll, l), r = rr;
                deleted.push_back(x);
            }
        }
        for (auto x : deleted) {
            ranges.erase(x);
        }
        ranges.insert(make_pair(l, r));
    }
    bool change = true;
    while (change) {
        change = false;
        for (auto [l, r] : ranges) {
            vector<pair<ll, ll>> deleted;
            deleted.push_back(make_pair(l, r));
            for (auto x : ranges) {
                if (x == make_pair(l, r)) {
                    continue;
                }
                auto [ll, rr] = x;
                if (l <= ll and r >= rr) {
                    deleted.push_back(x);
                } else if (l >= ll and l <= rr) {
                    l = ll, r = max(rr, r);
                    deleted.push_back(x);
                } else if (r <= rr and r >= ll) {
                    l = min(ll, l), r = rr;
                    deleted.push_back(x);
                }
            }
            if (deleted.size() > 1) {
                change = true;
                for (auto x : deleted) {
                    ranges.erase(x);
                }
                ranges.insert(make_pair(l, r));
                break;
            }
        }
    }

    for (auto [l, r] : ranges) {
        ans += r - l + 1;
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
