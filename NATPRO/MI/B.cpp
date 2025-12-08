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
    vector<ll> vec;
    ll tot = 0;
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        if (x == 0) {
            continue;
        }
        tot += (2 * x);
        vec.push_back(sqrtl(x));
    }
    n = vec.size();

    if (n == 0) {
        cout << 0 << endl;
        return;
    } else if (n == 1) {
        cout << tot << endl;
        return;
    } else if (n == 2) {
        ll diff = abs(vec[0] - vec[1]);
        cout << tot - (diff * diff) << endl;
        return;
    }

    sort(all(vec));
    deque<ll> q;
    for (auto x : vec) {
        q.push_back(x);
    }

    deque<ll> aq;

    ll mid = q.back();
    q.pop_back();
    aq.push_back(mid);

    aq.push_back(q.front());
    q.pop_front();

    if (!q.empty() && q.size() == 1) {
        ll f = q.front();
        q.pop_front();
        if (abs(aq.front() - f) > abs(aq.back() - f)) {
            aq.push_front(f);
        } else {
            aq.push_back(f);
        }
    } else {
        aq.push_front(q.front());
        q.pop_front();
    }

    ll beg = false;

    while (q.size() > 2) {
        // for (auto x : aq) {
        //     cout << x << ' ';
        // }
        // cout << endl;
        if (beg) {
            ll f = q.front();
            q.pop_front();
            bool l = false;
            if (abs(aq.front() - f) > abs(aq.back() - f)) {
                aq.push_front(f);
                l = true;
            } else {
                aq.push_back(f);
            }
            if (!q.empty()) {
                f = q.front();
                q.pop_front();

                if (l) {
                    aq.push_back(f);
                } else {
                    aq.push_front(f);
                }
                // if (abs(aq.front() - f) > abs(aq.back() - f)) {
                //     aq.push_front(f);
                // } else {
                //     aq.push_back(f);
                // }
            }
        } else {
            ll f = q.back();
            q.pop_back();
            bool l = false;
            if (abs(f - aq.front()) > abs(f - aq.back())) {
                aq.push_front(f);
                l = true;
            } else {
                aq.push_back(f);
            }
            if (!q.empty()) {
                f = q.back();
                q.pop_back();
                if (l) {
                    aq.push_back(f);
                } else {
                    aq.push_front(f);
                }
                // cout << f << endl;
                // if (abs(f - aq.front()) > abs(f - aq.back())) {
                //     aq.push_front(f);
                // } else {
                //     aq.push_back(f);
                // }
            }
        }
        // for (auto x : aq) {
        //     cout << x << ' ';
        // }
        // cout << endl;
        beg = !beg;
    }

    if (!q.empty()) {
        if (beg) {
            ll f = q.front();
            q.pop_front();
            if (abs(aq.front() - f) > abs(aq.back() - f)) {
                aq.push_front(f);
            } else {
                aq.push_back(f);
            }
            if (!q.empty()) {
                f = q.front();
                q.pop_front();

                if (abs(aq.front() - f) > abs(aq.back() - f)) {
                    aq.push_front(f);
                } else {
                    aq.push_back(f);
                }
            }
        } else {
            ll f = q.back();
            q.pop_back();
            if (abs(f - aq.front()) > abs(f - aq.back())) {
                aq.push_front(f);
            } else {
                aq.push_back(f);
            }
            if (!q.empty()) {
                f = q.back();
                q.pop_back();
                if (abs(f - aq.front()) > abs(f - aq.back())) {
                    aq.push_front(f);
                } else {
                    aq.push_back(f);
                }
            }
        }
    }

    ll prev = aq.front();
    aq.pop_front();
    while (!aq.empty()) {
        ll curr = aq.front();
        aq.pop_front();
        ll diff = abs(prev - curr);
        tot -= diff * diff;

        prev = curr;
    }
    cout << tot << endl;

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
