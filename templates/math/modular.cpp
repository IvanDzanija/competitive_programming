long long MOD = 1e9 + 7;
long long add(long long a, long long b) {
	long long ret = a + b;
	if (ret >= MOD)
		return ret - MOD;
	if (ret < 0)
		return ret + MOD;
	return ret;
}
long long mul(long long a, long long b) { return (a * b) % MOD; }

long long pow(long long a, long long b) {
	if (b == 0) {
		return 1;
	}
	long long res = 1;
	while (b > 0) {
		if (b & 1) {
			res = (res * a) % MOD;
		}
		a = (a * a) % MOD;
		b /= 2;
	}
	return res;
}
