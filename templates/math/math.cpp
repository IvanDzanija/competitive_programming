// Includes and typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

// Constants
const ll MOD = 1e9 + 7;
const ll maxN = 5e5 + 5;

// Ceil division
inline ll ceil_div(ll a, ll b) { return (a + b - 1) / b; }

// Modular
// Addition
inline ll add(ll a, ll b) {
	ll ret = a + b;
	if (ret >= MOD)
		return ret - MOD;
	if (ret < 0)
		return ret + MOD;
	return ret;
}
// Multiplication
inline ll mul(ll a, ll b) { return (a * b) % MOD; }

// Exponantiation by squaring
inline ll pow(ll a, ll b) {
	if (b == 0) {
		return 1;
	}
	ll res = 1;
	while (b > 0) {
		if (b & 1) {
			res = (res * a) % MOD;
		}
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}

// Modular inverse for prime modulus
inline ll mod_inv(ll num) { return pow(num, MOD - 2); }

// Factorials
ll factorial[maxN];
inline void precalc_factorial(void) {
	factorial[0] = 1;
	for (ll i = 1; i < maxN; i++) {
		factorial[i] = mul(factorial[i - 1], i);
	}
}

inline ll nCr(ll n, ll r) {
	return factorial[n] * mod_inv(factorial[r]) % MOD *
		   mod_inv(factorial[n - r]) % MOD;
}
