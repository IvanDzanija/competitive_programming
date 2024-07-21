#include <cmath>
#include <cstring>
#include <iostream>
using ll = int64_t;

const ll MAXN = 1e6;
const ll MOD = 1e9 + 7;

ll cache[MAXN];

ll solve(ll number) {
  if (cache[number] != 0) {
    return cache[number];
  } else {
    for (int i = 1; i <= 6; ++i) {
      if (number - i >= 0) {
        cache[number] += solve(number - i);
        cache[number] %= MOD;
      }
    }
    return cache[number];
  }
}
int main(void) {
  ll n;
  std::cin >> n;
  cache[0] = 1;
  std::cout << solve(n) << std::endl;
  return 0;
}
