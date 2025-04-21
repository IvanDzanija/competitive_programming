#include <bits/stdc++.h>
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
int count_bits(ll number) { return (int)log2(number) + 1; }

// equivalent to bitset<32>.count()
int hamming(bitset<32> a, bitset<32> b) {
	return __builtin_popcount(a.to_ulong() ^ b.to_ulong());
}
// this is the fastest solution
int BitCount(int u) {
	unsigned int uCount;
	uCount = u - ((u >> 1) & 033333333333) - ((u >> 2) & 011111111111);
	return ((uCount + (uCount >> 3)) & 030707070707) % 63;
}
int main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ll n, k;
	cin >> n >> k;
	vector<bitset<32>> a;
	for (ll i = 0; i < n; ++i) {
		string x;
		cin >> x;
		bitset<32> y(x);
		a.push_back(y);
	}
	ll ans = INF;
	for (ll i = 0; i < n; ++i) {
		for (ll j = i + 1; j < n; ++j) {
			ll curr = BitCount(a[i].to_ulong() ^ a[j].to_ulong());
			if (curr < ans) {
				ans = curr;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
