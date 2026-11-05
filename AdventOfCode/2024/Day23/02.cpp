#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <fstream>
#include <set>
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
#define INF (int)1e9
#define all(x) (x).begin(), (x).end()
#define MOD (int)(1e9 + 7)

using namespace __gnu_pbds;
using namespace std;
template <typename T>
using indexed_set = tree<T, null_type, std::less<T>, rb_tree_tag,
                         tree_order_statistics_node_update>;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
map<string, set<string>> graph;
set<string> nodes;
ll mx = 0;
string ans = "";
void clique(set<string> R, set<string> P, set<string> X) {
    if (P.empty() && X.empty()) {
        if (R.size() > mx) {
            mx = R.size();
            ans = "";
            set<string> curr;
            for (auto x : R) {
                curr.insert(x);
            }
            for (auto x : curr) {
                ans += x;
                ans += ',';
            }
        }
    }

    while (!P.empty()) {
        auto v = *P.begin();
        set<string> newR = R;
        newR.insert(v);
        set<string> newP;
        for (auto p : P) {
            if (graph[v].count(p)) {
                newP.insert(p);
            }
        }
        set<string> newX;
        for (auto x : X) {
            if (graph[v].count(x)) {
                newX.insert(x);
            }
        }
        clique(newR, newP, newX);
        P.erase(v);
        X.insert(v);
    }
}

signed main(void) {
    std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
    ifstream input("../input.txt");
    string line;

    while (getline(input, line)) {
        string first = line.substr(0, line.find('-'));
        string second = line.substr(line.find('-') + 1);
        nodes.insert(first);
        nodes.insert(second);
        graph[first].insert(second);
        graph[second].insert(first);
    }
    clique(set<string>(), nodes, set<string>());
    ans.pop_back();
    cout << ans << endl;

    return 0;
}
