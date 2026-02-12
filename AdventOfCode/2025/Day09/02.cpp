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
struct Point {
  ll x, y;

  bool operator==(const Point &other) const { return x == other.x && y == other.y; }
};

void solve(void) {
  string line;
  vector<Point> pts;
  vector<pair<Point, Point>> edges;
  set<ll> xss, yss;

  Point prev = {-1, -1};
  while (getline(cin, line)) {
    int ind = line.find(',');
    string first = line.substr(0, ind);
    string second = line.substr(ind + 1);
    Point p = {stoll(first), stoll(second)};
    pts.push_back(p);
    edges.push_back(make_pair(prev, p));
    prev = p;
    xss.insert(p.x);
    yss.insert(p.y);
  }
  vector<ll> xs(xss.begin(), xss.end());
  vector<ll> ys(yss.begin(), yss.end());

  edges[0].first = prev;
  sort(all(xs));
  sort(all(ys));
  ll ans = 0;

  map<pair<ll, ll>, vector<pair<ll, ll>>> inside;
  for (ll i = 1; i < xs.size(); ++i) {
    ll left = xs[i - 1];
    ll right = xs[i];
    vector<ll> active;
    for (auto [lp, rp] : edges) {
      if (lp.y != rp.y) {
        continue;
      }
      ll lx = min(lp.x, rp.x);
      ll rx = max(lp.x, rp.x);
      if (lx <= left && rx >= right) {
        active.push_back(lp.y);
      }
    }
    sort(all(active));
    bool ins = false;
    ll prevy = -1;
    for (int j = 0; j < active.size(); ++j) {
      ll curry = active[j];
      if (ins) {
        inside[make_pair(left, right)].push_back(make_pair(prevy, curry));
      }
      prevy = curry;

      ins = !ins;
    }
  }
  for (auto f : pts) {
    for (auto s : pts) {
      if (f.x < s.x && f.y < s.y) {
        bool ins = false;
        // cout << f.x << ' ' << f.y << ' ' << s.x << ' ' << s.y << endl;
        for (auto [seg, ys] : inside) {
          if (seg.first < f.x || seg.second > s.x) {
            continue;
          }
          ins = false;
          // cout << "seg: " << seg.first << ' ' << seg.second << endl;
          for (auto [y1, y2] : ys) {
            // cout << y1 << ' ' << y2 << endl;
            assert(y1 < y2);
            if ((y2 >= s.y && y1 <= f.y)) {
              ins = true;
            }
            //  cout << "ins: " << ins << endl;
          }
          if (!ins) {
            break;
          }
        }
        // cout << "ins: " << ins << endl;
        if (ins) {
          ll ca = (s.x - f.x + 1) * (s.y - f.y + 1);
          ans = max(ans, ca);
        }
      } else if (f.x > s.x && f.y < s.y) {
        bool ins = false;
        for (auto [seg, ys] : inside) {
          if (seg.first < s.x || seg.second > f.x) {
            continue;
          }
          ins = false;
          for (auto [y1, y2] : ys) {
            assert(y1 < y2);
            if ((y2 >= s.y && y1 <= f.y)) {
              ins = true;
            }
          }
          if (!ins) {
            break;
          }
        }
        if (ins) {
          ll ca = (f.x - s.x + 1) * (s.y - f.y + 1);
          ans = max(ans, ca);
        }
      }
    }
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
