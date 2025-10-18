#pragma GCC optimization("Ofast,unroll-loops")
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
    ll n;
    cin >> n;
    if (n == 1) {
        cout << "! " << 1 << endl;
        cout << "! " << 1 << endl;
        return;
    }
    vector<int> temp(n);
    ll mx = 0;
    for (int i = 2; i <= n; ++i) {
        cout << "? " << 1 << ' ' << i << endl;
        ll x;
        cin >> x;
        mx = max(mx, x);
        temp[i - 1] = x;
    }
    if (mx == n - 1) {
        cout << "! 1 ";
        for (int i = 1; i < n; ++i) {
            cout << temp[i] + 1 << ' ';
        }
        cout << endl;
        cout << "! " << n << ' ';
        for (int i = 1; i < n; ++i) {
            cout << n - temp[i] << ' ';
        }
        cout << endl;
    } else {
        ll pos1 = n - mx, pos2 = 1 + mx;
        vector<pair<int, int>> ans1(n, make_pair(pos1, pos1));
        vector<pair<int, int>> ans2(n, make_pair(pos2, pos2));
        pair<ll, ll> first, second;
        for (int i = 1; i < n; ++i) {
            ll t1 = pos1 + temp[i], t2 = pos1 - temp[i];
            if (t1 > n) {
                t1 = t2;
            }
            if (t2 < 1) {
                t2 = t1;
            }
            if (t1 == t2 && (t1 == n || t1 == 1)) {
                first = make_pair(i, t1);
            }
            ans1[i] = make_pair(t1, t2);
            ll r1 = pos2 + temp[i], r2 = pos2 - temp[i];
            if (r1 > n) {
                r1 = r2;
            }
            if (r2 < 1) {
                r2 = r1;
            }
            if (r1 == r2 && (r1 == n || r1 == 1)) {
                second = make_pair(i, r1);
            }
            ans2[i] = make_pair(r1, r2);
        }

        cout << endl;
        if (ans1 == ans2) {
            vector<int> next(n);
            set<int> seen;
            for (int i = 1; i < n; ++i) {
                auto x1 = ans1[i];
                cout << x1.first << ' ' << x1.second << endl;
                if (x1.first != x1.second) {
                    seen.insert(temp[i]);
                    for (int j = i + 1; j < n; ++j) {
                        auto x2 = ans1[j];
                        if (seen.count(temp[j])) {
                            continue;
                        }
                        seen.insert(temp[j]);
                        cout << "? " << i + 1 << ' ' << j + 1 << endl;
                        cin >> next[j];
                    }
                    break;
                }
            }
            set<pair<int, int>> seen1;
            ll x = ans1[1].first, y = ans1[1].second;
            seen1.insert(make_pair(x, y));
            for (int i = 2; i < n; ++i) {
                auto x1 = ans1[i];
                if (seen1.count(x1)) {
                    ans1[i] = make_pair(x1.second, x1.first);
                    continue;
                } else if (seen1.count(make_pair(x1.second, x1.first))) {
                    continue;
                }
                if (x + next[i] != x1.first && x - next[i] != x1.first) {
                    ans1[i] = make_pair(x1.second, x1.first);
                }
                seen1.insert(ans1[i]);
            }

            cout << "! " << ans1[0].first << ' ';
            for (int i = 1; i < n; ++i) {
                cout << ans1[i].first << ' ';
            }
            cout << endl;

            cout << "! " << ans1[0].first << ' ';
            for (int i = 1; i < n; ++i) {
                cout << ans1[i].second << ' ';
            }
            cout << endl;
            return;
        }
        set<pair<pair<int, int>, int>> seen1;
        set<pair<pair<int, int>, int>> seen2;
        for (int i = 0; i < n; ++i) {
            auto x1 = ans1[i];
            auto x2 = ans2[i];
            if (x1.first != x1.second) {
                cout << "? " << first.first + 1 << ' ' << i + 1 << endl;
                ll x;
                cin >> x;
                ll curr;
                if (first.second == n) {
                    curr = n - x;
                } else {
                    curr = 1 + x;
                }
                for (int j = i + 1; j < n; ++j) {
                    if (ans1[j] == x1) {
                        ll rem = (x1.first == curr) ? x1.second : x1.first;
                        ans1[j] = make_pair(rem, rem);
                    }
                }
                ans1[i] = make_pair(curr, curr);

                if (second.second == n) {
                    curr = n - x;
                } else {
                    curr = 1 + x;
                }
                for (int j = i + 1; j < n; ++j) {
                    if (ans2[j] == x2) {

                        ll rem = (x2.first == curr) ? x2.second : x2.first;
                        ans2[j] = make_pair(rem, rem);
                    }
                }
                ans2[i] = make_pair(curr, curr);
            }
        }
        cout << "! ";
        for (auto x : ans1) {
            cout << x.first << ' ';
        }
        cout << endl;

        cout << "! ";
        for (auto x : ans2) {
            cout << x.first << ' ';
        }
        cout << endl;
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
