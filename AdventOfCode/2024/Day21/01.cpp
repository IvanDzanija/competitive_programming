#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <fstream>
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
#define INF (int)1e9
#define all(x) (x).begin(), (x).end()
#define MOD (int)(1e9 + 7)

using namespace __gnu_pbds;
using namespace std;
template <typename T>
using indexed_set =
	tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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

void product(const vector<vector<string>> &input,
			 vector<vector<string>> &result, vector<string> current = {},
			 size_t depth = 0) {
	if (depth == input.size()) {
		result.push_back(current);
		return;
	}

	for (const auto &item : input[depth]) {
		current.push_back(item);
		product(input, result, current, depth + 1);
		current.pop_back();
	}
}
vector<pair<char, char>> zip(const string &vec1, const string &vec2) {
	vector<pair<char, char>> zipped;
	auto size = min(vec1.size(), vec2.size());
	for (size_t i = 0; i < size; ++i) {
		zipped.emplace_back(vec1[i], vec2[i]);
	}
	return zipped;
}
vector<string> numpad = {"789", "456", "123", "X0A"};
vector<string> dirpad = {"XUA", "LDR"};
vector<string> solve(string line, vector<string> pad) {
	map<char, pair<int, int>> mp;
	for (ll r = 0; r < pad.size(); ++r) {
		for (ll c = 0; c < pad[r].size(); ++c) {
			if (pad[r][c] == 'X') {
				continue;
			}
			mp[pad[r][c]] = make_pair(r, c);
		}
	}
	map<pair<char, char>, vector<string>> dp;
	for (auto x : mp) {
		for (auto y : mp) {
			if (x == y) {
				dp[make_pair(x.first, y.first)].push_back("A");
				continue;
			}
			deque<tuple<int, int, string>> q;
			ll mn = INF;
			auto [sr, sc] = x.second;
			vector<string> pos;
			q.push_back(make_tuple(sr, sc, ""));
			while (!q.empty()) {
				auto [r, c, path] = q.front();
				q.pop_front();
				if (path.size() > mn) {
					continue;
				}
				vector<tuple<int, int, string>> next = {
					{0, 1, "R"}, {0, -1, "L"}, {1, 0, "D"}, {-1, 0, "U"}};
				for (auto [dr, dc, pc] : next) {
					int rr = r + dr;
					int cc = c + dc;
					string np = path + pc;
					if (rr < 0 || cc < 0 || rr >= pad.size() ||
						cc >= pad[0].size() || pad[rr][cc] == 'X') {
						continue;
					}
					if (pad[rr][cc] == y.first) {
						if (np.size() > mn) {
							break;
						}
						mn = np.size();
						pos.push_back(np + 'A');

					} else {
						q.push_back(make_tuple(rr, cc, np));
					}
				}
			}
			dp[make_pair(x.first, y.first)] = pos;
		}
	}
	vector<pair<char, char>> zipped = zip("A" + line, line);
	vector<vector<string>> res;
	for (pair<char, char> z : zipped) {
		res.push_back(dp[z]);
	}
	vector<vector<string>> ans;
	product(res, ans);
	vector<string> ret;
	for (auto x : ans) {
		string curr;
		for (auto y : x) {
			curr += y;
		}
		ret.push_back(curr);
	}

	return ret;
}
signed main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	string line;
	ifstream input("../input.txt");
	ll ans = 0;
	while (getline(input, line)) {
		vector<string> next = solve(line, numpad);
		for (int i = 0; i < 2; ++i) {
			vector<string> ppr;
			int mn = INF;
			for (auto x : next) {
				for (auto y : solve(x, dirpad)) {
					ppr.push_back(y);
					mn = min(mn, (int)y.size());
				}
			}
			next.clear();
			for (auto x : ppr) {
				if (x.size() == mn) {
					next.push_back(x);
				}
			}
		}
		ans += (next[0].size()) * stoll(line.substr(0, 4));
	}
	cout << ans << endl;
	return 0;
}
