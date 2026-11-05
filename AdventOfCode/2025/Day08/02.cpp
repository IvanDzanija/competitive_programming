// #pragma GCC target("avx2,bmi,bmi2,fmi,lzcnt,popcnt")
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
vector<ll> link;
vector<ll> len;

int find(int x) {
  if (x == link[x]) {
    return x;
  }
  return link[x] = find(link[x]);
}
bool same(int a, int b) { return find(a) == find(b); }
void unite(int a, int b) {
  a = find(a);
  b = find(b);
  if (len[a] < len[b]) swap(a, b);
  len[a] += len[b];
  link[b] = a;
}
struct Point {
  ll x, y, z;
  bool operator==(const Point &o) { return o.x == x && o.y == y && o.z == z; }
};

void solve(void) {
  string line;
  vector<Point> pts;
  while (getline(cin, line)) {
    auto first = line.substr(0, line.find(','));
    line = line.substr(line.find(',') + 1);
    auto second = line.substr(0, line.find(','));
    line = line.substr(line.find(',') + 1);
    auto third = line.substr(0, line.find(','));
    line = line.substr(line.find(',') + 1);
    ll x = stoll(first), y = stoll(second), z = stoll(third);
    pts.push_back({x, y, z});
  }
  int n = pts.size();
  link.resize(n);
  len.resize(n);
  for (ll i = 0; i < n; ++i) {
    link[i] = i;
    len[i] = 1;
  }
  vector<tuple<int, int, int>> dist;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      auto f = pts[i], s = pts[j];
      ll temp = (f.x - s.x) * (f.x - s.x) + (f.y - s.y) * (f.y - s.y) +
                (f.z - s.z) * (f.z - s.z);
      int cd = sqrt(temp);
      dist.push_back({cd, i, j});
    }
  }
  sort(all(dist));
  ll ans = 1;
  ll i = 0;
  while (true) {
    auto [dis, x, y] = dist[i];
    if (!same(x, y)) {
      unite(x, y);
      if (len[find(x)] == n || len[find(y)] == n) {
        ans = pts[x].x * pts[y].x;
        break;
      }
    }
    ++i;
  }
  cout << ans << endl;

  return;
}

signed main(void) {
  std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
  ll tc = 1;
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
