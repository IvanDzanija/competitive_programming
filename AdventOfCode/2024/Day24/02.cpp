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
map<string, bool> dp;
map<string, tuple<string, string, string>> cons;
bool vix(string w, string bit);
bool vcb(string w, string bit);
bool vdc(string w, string bit);
bool vrc(string w, string bit);
bool vz(string w, string bit);

bool vix(string w, string bit) {
	if (!cons.count(w)) {
		return false;
	}
	if (bit.size() < 2) {
		bit = '0' + bit;
	}
	auto [f, s, op] = cons[w];
	if (op != "XOR") {
		return false;
	}
	auto p1 = make_pair('x' + bit, 'y' + bit);
	auto p2 = make_pair('y' + bit, 'x' + bit);
	auto cp = (make_pair(f, s));
	return cp == p1 || cp == p2;
}
bool vdc(string w, string bit) {
	if (!cons.count(w)) {
		return false;
	}
	if (bit.size() < 2) {
		bit = '0' + bit;
	}
	auto [f, s, op] = cons[w];
	if (op != "AND") {
		return false;
	}
	auto p1 = make_pair('x' + bit, 'y' + bit);
	auto p2 = make_pair('y' + bit, 'x' + bit);
	auto cp = (make_pair(f, s));
	return cp == p1 || cp == p2;
}
bool vrc(string w, string bit) {
	if (!cons.count(w)) {
		return false;
	}
	if (bit.size() < 2) {
		bit = '0' + bit;
	}
	auto [f, s, op] = cons[w];
	if (op != "AND") {
		return false;
	}
	return (vix(f, bit) && vcb(s, bit)) || (vix(s, bit) && vcb(f, bit));
}

bool vcb(string w, string bit) {
	if (!cons.count(w)) {
		return false;
	}
	if (bit.size() < 2) {
		bit = '0' + bit;
	}

	auto [f, s, op] = cons[w];
	if (bit == "01") {
		auto x1 = make_pair((string) "x00", (string) "y00");
		auto x2 = make_pair((string) "y00", (string) "x00");
		auto cx = make_pair(f, s);
		return op == "AND" && (cx == x1 || cx == x2);
	}
	if (op != "OR") {
		return false;
	}
	return (vdc(f, to_string(stoi(bit) - 1)) &&
			vrc(s, to_string(stoi(bit) - 1))) ||
		   (vdc(s, to_string(stoi(bit) - 1)) &&
			vrc(f, to_string(stoi(bit) - 1)));
}
bool vz(string w, string bit) {
	if (!cons.count(w)) {
		return false;
	}
	if (bit.size() < 2) {
		bit = '0' + bit;
	}
	auto [f, s, op] = cons[w];
	if (op != "XOR") {
		return false;
	}
	if (bit == "00") {
		auto x1 = make_pair((string) "x00", (string) "y00");
		auto x2 = make_pair((string) "y00", (string) "x00");
		auto cx = make_pair(f, s);
		return cx == x1 || cx == x2;
	}
	return (vix(f, bit) && vcb(s, bit)) || (vix(s, bit) && vcb(f, bit));
}

int prog() {
	for (ll i = 0; i < 45; ++i) {
		string c = to_string(i);
		if (i < 10) {
			c = '0' + c;
		}
		if (!(vz('z' + c, c))) {
			return i;
			break;
		}
	}
	return 45;
}

signed main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ifstream input("../input.txt");
	string line;
	int reading = 0;
	string x;
	string y;

	while (getline(input, line)) {
		if (line.empty()) {
			reading = 1;
			continue;
		}
		if (reading == 0) {
			dp[line.substr(0, line.find(':'))] =
				stoi(line.substr(line.find(' ') + 1));
			if (line[0] == 'x') {
				x += line.substr(line.find(' ') + 1);
			} else {
				y += line.substr(line.find(' ') + 1);
			}
		} else {
			string first = line.substr(0, line.find(' '));
			line = line.substr(line.find(' ') + 1);
			string op = line.substr(0, line.find(' '));
			line = line.substr(line.find(' ') + 1);
			string second = line.substr(0, line.find(' '));
			line = line.substr(line.find(' ') + 1);
			line = line.substr(line.find(' ') + 1);
			cons[line] = make_tuple(first, second, op);
		}
	}

	set<string> sw;
	ll mx = prog();
	for (ll i = 0; i < 4; ++i) {
		for (auto x : cons) {
			for (auto y : cons) {
				if (mx == 45) {
					break;
				}
				if (x == y) {
					continue;
				}
				cons[x.first] = y.second;
				cons[y.first] = x.second;
				if (prog() > mx) {
					mx = prog();
					sw.insert(x.first);
					sw.insert(y.first);
					break;
				}
				cons[x.first] = x.second;
				cons[y.first] = y.second;
			}
			if (mx == 45) {
				break;
			}
		}
		if (mx == 45) {
			break;
		}
	}
	string ans = "";
	for (auto x : sw) {
		ans += x + ',';
	}
	ans.pop_back();
	cout << ans << endl;

	return 0;
}
