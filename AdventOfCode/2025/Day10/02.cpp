// #pragma GCC target("avx2,bmi,bmi2,fmi,lzcnt,popcnt")
#include <bits/stdc++.h>
#include <z3++.h>

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
using namespace z3;
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
struct row {
  vector<int> a;
  vector<vector<int>> b;
  vector<int> c;
};

void solve(void) {
  string line;

  vector<row> rows;
  ll res = 0;
  while (getline(cin, line)) {
    row r;
    string first = line.substr(1, line.find(']') - 1);
    line = line.substr(line.find(']') + 2);
    vector<int> ra(first.size());
    for (int i = 0; i < first.size(); ++i) {
      if (first[i] == '#') {
        ra[i] = 1;
      }
    }
    r.a = ra;
    int ind;
    vector<vector<int>> rb;
    while ((ind = line.find(')')) != string::npos) {
      string second = line.substr(1, ind);
      line = line.substr(ind + 2);
      int curr = 0;
      vector<int> inn;
      for (auto x : second) {
        if (x == ',' || x == ')') {
          inn.push_back(curr);
          curr = 0;
        } else {
          curr = curr * 10 + (x - '0');
        }
      }
      rb.push_back(inn);
    }
    r.b = rb;

    line = line.substr(1);
    vector<int> rc;
    int curr = 0;
    for (auto x : line) {
      if (x == ',' || x == '}') {
        rc.push_back(curr);
        curr = 0;
      } else {
        curr = curr * 10 + (x - '0');
      }
    }
    r.c = rc;
    rows.push_back(r);

    context ctx;
    optimize opt(ctx);
    expr_vector all_vars(ctx);

    for (int i = 0; i < rb.size(); i++) {
      std::string name = "x" + std::to_string(i);
      expr var = ctx.int_const(name.c_str());

      opt.add(var >= 0);
      all_vars.push_back(var);
    }

    for (size_t i = 0; i < rc.size(); ++i) {
      expr sum_expr = ctx.int_val(0);
      for (int j = 0; j < rb.size(); ++j) {
        auto x = rb[j];
        bool curr = false;
        for (auto idx : x) {
          if (idx == i) {
            curr = true;
          }
        }
        if (curr) {
          sum_expr = sum_expr + all_vars[j];
        }
      }
      opt.add(sum_expr == rc[i]);
    }

    opt.minimize(z3::sum(all_vars));
    if (opt.check() == sat) {
      model m = opt.get_model();
      expr ans = m.eval(z3::sum(all_vars));
      res += ans.as_int64();
    } else {
      cout << "UNSAT" << endl;
    }
  }
  cout << res << endl;
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
