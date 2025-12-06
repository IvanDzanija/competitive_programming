// #pragma GCC target("avx2,bhi,bmi2,fmi,lzcnt,popcnt")
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

set<int> seen;
bool tbc(int e, const vector<vector<int>> &adj, vector<int> &reds,
         vector<int> &blacks) {
    bool c = false;
    seen.insert(e);

    for (int v = 0; v < adj[e].size(); ++v) {
        if (adj[e][v] == 1) {
            c = true;
            break;
        }
    }
    if (!c) {
        reds.push_back(e);
        return true;
    }

    map<int, int> fc;
    deque<pair<int, int>> q;
    q.push_back(make_pair(e, 0));
    bool succ = true;
    ll reds1 = 0;
    while (!q.empty()) {
        auto [v, c] = q.front();
        q.pop_front();

        if (fc.count(v) && fc[v] == c) {
            continue;
        } else if (fc.count(v) && fc[v] != c) {
            succ = false;
            break;
        }
        fc[v] = c;

        if (c == 0) {
            reds.push_back(v);
        } else {
            blacks.push_back(v);
        }
        seen.insert(v);

        for (int i = 0; i < adj[v].size(); ++i) {
            if (adj[v][i] == 1) {
                q.push_back(make_pair(i, 1 - c));
            }
        }
    }
    if (!succ) {
        return false;
    }
    return true;
}

void solve(void) {
    ll n, m;
    cin >> n >> m;
    ll a, b, c;
    cin >> a >> b >> c;
    ll red = b;
    ll black = a + c;

    vector<vector<int>> adj(n, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        --x, --y;
        adj[x][y] = 1;
        adj[y][x] = 1;
    }

    vector<vector<int>> dp(n + 1, vector<int>(red + 1));

    int prev_used = 0;
    dp[0][0] = 1;
    map<int, int> ump;
    map<int, pair<vector<int>, vector<int>>> rep;
    map<int, int> jumps;
    for (int i = 0; i < n; ++i) {
        if (seen.count(i)) {
            continue;
        }
        vector<int> reds;
        vector<int> blacks;
        bool succ = tbc(i, adj, reds, blacks);
        if (!succ) {
            cout << -1 << endl;
            return;
        }
        // for (auto x : reds) {
        //     cout << x << ' ';
        // }
        // cout << endl;

        // for (auto x : blacks) {
        //     cout << x << ' ';
        // }
        // cout << endl;
        int f = reds.size();
        int s = blacks.size();

        int used = seen.size();
        ump[used] = i;
        rep[i] = make_pair(reds, blacks);
        jumps[used] = prev_used;
        for (int j = 0; j <= red; ++j) {
            if (dp[prev_used][j] != 0) {
                dp[used][j + f] = 1;
                dp[used][j + s] = 2;
            }
        }
        prev_used = used;
    }
    if (dp[n][red] == 0) {
        cout << -1 << endl;
        return;
    }
    int used = n;
    vector<int> ans(n);
    int pr = ump[used];
    int path = dp[used][red];
    while (true) {
        vector<int> reds = (path == 1) ? rep[pr].first : rep[pr].second;
        vector<int> blacks = (path == 2) ? rep[pr].first : rep[pr].second;
        for (auto v : reds) {
            ans[v] = 2;
            --red;
        }
        for (auto v : blacks) {
            if (a > 0) {
                ans[v] = 1;
                --a;
            } else {
                ans[v] = 3;
                --c;
            }
        }

        if (jumps.count(used)) {
            used = jumps[used];
        }
        if (used == 0) {
            break;
        }
        pr = ump[used];
        path = dp[used][red];
    }
    for (auto x : ans) {
        cout << x << ' ';
    }
    cout << endl;
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
