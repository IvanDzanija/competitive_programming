#include <bits/stdc++.h>

#include <algorithm>
#include <climits>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <string>
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define INF (ll)1e9
#define all(x) (x).begin(), (x).end()
#define MOD (ll)(1e9 + 7)

using namespace __gnu_pbds;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
using indexed_set =
    tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
struct custom_hash {
  static ull splitmix64(ull x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(ull x) const {
    static const ull FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
ll n;
string as;
vector<int> v;

bool finds(int pos, bool small, string &ans) {
  if (pos == as.size()) {
    return true;
  }
  int curr = as[pos] - '0';
  for (int i = n - 1; i >= 0; --i) {
    int dig = v[i];
    if (!small && dig > curr) {
      continue;
    }
    ans += dig + '0';
    if (finds(pos + 1, small || dig < curr, ans)) {
      return true;
    }
    ans.pop_back();
  }
  return false;
}

bool findb(int pos, bool big, string &ans) {
  if (pos == as.size()) {
    return true;
  }
  int curr = as[pos] - '0';
  for (int i = 0; i < n; ++i) {
    int dig = v[i];
    if (pos == 0 && dig == 0) {
      continue;
    }
    if (!big && dig < curr) {
      continue;
    }
    ans += dig + '0';
    if (findb(pos + 1, big || dig > curr, ans)) {
      return true;
    }
    ans.pop_back();
  }
  return false;
}
ll cnt = 0;

void solve(void) {
  ll a;
  cin >> a >> n;
  v.resize(n);
  ++cnt;
  for (ll i = 0; i < n; ++i) {
    cin >> v[i];
  }

  if (v.size() == 1 && v[0] == 0) {
    cout << a << endl;
    return;
  }
  sort(all(v));
  as = to_string(a);
  bool sup = true;
  for (auto c : as) {
    int curr = c - '0';
    if (!ranges::contains(v.begin(), v.end(), curr)) {
      sup = false;
      break;
    }
  }
  if (sup) {
    cout << 0 << endl;
    return;
  }
  ll ans = LLONG_MAX;

  ll smaller = -1, bigger = -1;
  string sm, bg;
  if (finds(0, false, sm)) {
    smaller = stoll(sm);
  }
  if (findb(0, false, bg)) {
    bigger = stoll(bg);
  }
  if (smaller == -1) {
    int len = as.size() - 1;
    if (len > 0) {
      smaller = 0;
      for (int i = 0; i < len; ++i) {
        smaller *= 10;
        smaller += v[v.size() - 1];
      }
    }
  }
  if (bigger == -1) {
    int len = as.size();
    bigger = v[0];
    if (v[0] == 0) {
      bigger = v[1];
    }
    for (ll i = 0; i < len; ++i) {
      bigger *= 10;
      bigger += v[0];
    }
  }
  if (smaller != -1) {
    ans = min(abs(a - smaller), ans);
  }
  if (bigger != -1) {
    ans = min(abs(a - bigger), ans);
  }
  cout << ans << endl;

  return;
}

signed main(void) {
  std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
  ll tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
#ifdef LOCAL
    cout << "--------------------------------------------" << endl;
#endif
  }

#ifdef LOCAL
  cerr << "Finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
  return 0;
}
