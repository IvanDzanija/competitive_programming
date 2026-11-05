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
void operation(ll x, ll opcode) {}

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
	ll ind = 1;
	ll n = vec.size();
	ll ans = 0;
	A = 0;
	string res = "";
	bool found = false;
	// exploits the input but if all inputs are the same having only one change
	// of A per loop and that change being A >>= 3 then it should work for all
	while (found == false) {
		bool inner = false;
		while (inner == false) {
			ll top_a = A;
			B = 0;
			C = 0;
			for (ll i = 0; i < vec.size();) {
				if (vec[i] == 3 && A != 0) {
					i = vec[i + 1];
					continue;
				} else {
					ll opcode = vec[i];
					ll x = vec[i + 1];
					if (opcode == 0) {
						A = A >> combo(x);
					} else if (opcode == 1) {
						B = B ^ x;
					} else if (opcode == 2) {
						B = combo(x) % 8;
					} else if (opcode == 4) {
						B = B ^ C;
					} else if (opcode == 5) {
						ans = combo(x) % 8;
						if (ans == vec[n - ind]) {
							res += (to_string(ans)) + ',';
							inner = true;
							if (ind == n) {
								found = true;
							}
						}
						break;
					} else if (opcode == 6) {
						B = A >> combo(x);
					} else if (opcode == 7) {
						C = A >> combo(x);
					}
				}
				i += 2;
			}
			A = top_a;
			if (!inner) {
				++A;
			}
		}
		if (!found) {
			++ind;
			A <<= 3;
		}
	}
	cout << A << endl;
	return 0;
}
