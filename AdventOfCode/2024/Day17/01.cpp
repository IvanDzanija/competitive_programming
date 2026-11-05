#include <bits/stdc++.h>
#include <cassert>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define INF (int)1e9
#define all(x) (x).begin(), (x).end()
#define MOD (int)(1e9 + 7)

using ll = int64_t;
using ull = uint64_t;
using ld = long double;
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
string res = "";
ll A;
ll B;
ll C;
ll combo(ll x) {
	assert(x != 7);
	if (x == 4) {
		return A;
	} else if (x == 5) {
		return B;
	} else if (x == 6) {
		return C;
	}
	return x;
}
void operation(ll x, ll opcode) {

	if (opcode == 0) {
		A = A >> x;
	} else if (opcode == 1) {
		B = B ^ x;
	} else if (opcode == 2) {
		B = x & 7;
	} else if (opcode == 4) {
		B = B ^ C;
	} else if (opcode == 5) {
		res += to_string(x & 7) + ',';
	} else if (opcode == 6) {
		B = A >> x;
	} else if (opcode == 7) {
		C = A >> x;
	}
}

signed main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ifstream input("../input.txt");
	string line;
	vector<ll> vec;
	for (ll i = 0; i < 5; ++i) {
		getline(input, line);
		if (i == 0) {
			A = stoll(line.substr(line.find(':') + 2));
		} else if (i == 1) {
			B = stoll(line.substr(line.find(':') + 2));
		} else if (i == 2) {
			C = stoll(line.substr(line.find(':') + 2));
		} else if (i == 4) {
			line = line.substr(line.find(' '));
			while (line.find(',') != string::npos) {
				vec.push_back(stoll(line.substr(0, line.find(','))));
				line = line.substr(line.find(',') + 1);
			}
			vec.push_back(stoll(line));
		}
	}
	for (ll i = 0; i < vec.size();) {
		if (vec[i] == 3 && A != 0) {
			i = vec[i + 1];
			continue;
		} else {
			if (vec[i] == 1 || vec[i] == 4) {
				operation(vec[i + 1], vec[i]);
			} else {
				operation(combo(vec[i + 1]), vec[i]);
			}
		}
		i += 2;
	}
	res.pop_back();
	cout << res << endl;
	return 0;
}
