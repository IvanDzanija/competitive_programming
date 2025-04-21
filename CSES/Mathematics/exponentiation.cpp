#include <iostream>
using ll = int64_t;

int main(void) {
	int n;
	std::cin >> n;
	ll MOD = 1e9 + 7;
	for (; n > 0; --n) {
		ll a, b;
		std::cin >> a >> b;
		ll ans = 1;
		while (b > 0) {
			if (b & 1)
				ans = (ans * a) % MOD;
			a = (a * a) % MOD;
			b /= 2;
		}
		std::cout << ans << std::endl;
	}
	return 0;
}
