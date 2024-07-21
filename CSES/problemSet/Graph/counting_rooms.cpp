#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using ll = int64_t;
ll n, m;
std::vector<std::string> grid;

void dfs(int r, int c) {
  grid.at(r).at(c) = '#';
  if (r + 1 < n && grid.at(r + 1).at(c) == '.')
    dfs(r + 1, c);
  if (r - 1 >= 0 && grid.at(r - 1).at(c) == '.')
    dfs(r - 1, c);
  if (c + 1 < m && grid.at(r).at(c + 1) == '.')
    dfs(r, c + 1);
  if (c - 1 >= 0 && grid.at(r).at(c - 1) == '.')
    dfs(r, c - 1);
}

int main(void) {
  std::cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    std::string row;
    for (int j = 0; j < m; ++j) {
      char c;
      std::cin >> c;
      row.push_back(c);
    }
    grid.push_back(row);
  }
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid.at(i).at(j) == '.') {
        ++ans;
        dfs(i, j);
      }
    }
  }
  std::cout << ans << std::endl;
  return 0;
}
