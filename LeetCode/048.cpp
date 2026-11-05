#include <bits/stdc++.h>
using namespace std;

class Solution {
  using ll = int64_t;

 public:
  ll n;
  void transpose(vector<vector<int>> &mat) {
    for (ll i = 0; i < n; ++i) {
      for (ll j = i + 1; j < n; ++j) {
        swap(mat[i][j], mat[j][i]);
      }
    }
  }
  void reverse_columns(vector<vector<int>> &mat) {
    for (ll col = 0; col < n / 2; ++col) {
      ll r = n - col - 1;
      for (ll i = 0; i < n; ++i) {
        swap(mat[i][col], mat[i][r]);
      }
    }
  }
  void rotate(vector<vector<int>> &matrix) {
    n = matrix.size();

    transpose(matrix);
    reverse_columns(matrix);
  }
};
