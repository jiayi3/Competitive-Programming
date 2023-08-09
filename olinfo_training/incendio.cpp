#include <bits/stdc++.h>
using namespace std;

using Grid = vector<vector<bool>>;

int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
int n;

bool bfs(Grid& g) {
  Grid vis = g;
  if (g[0][0] || g[n - 1][n - 1]) return false;

  queue<pair<int, int>> q;
  q.emplace(0, 0);
  vis[0][0] = 1;

  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();

    for (int l = 0; l < 4; ++l) {
      int x = i + dx[l], y = j + dy[l];
      if (x >= 0 && x < n && y >= 0 && y < n && !vis[x][y]) {
        vis[x][y] = 1;
        q.emplace(x, y);
      }
    }
  }
  return vis[n - 1][n - 1];
}

void advance(Grid& g) {
  vector<int> I, J;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (g[i][j]) {
        I.push_back(i);
        J.push_back(j);
      }
    }
  }
  for (int l = 0; l < I.size(); ++l) {
    int i = I[l], j = J[l]; 
    for (int l = 0; l < 4; ++l) {
      int x = i + dx[l], y = j + dy[l];
      if (x >= 0 && x < n && y >= 0 && y < n)
        g[x][y] = 1;
    }
  }
}

int alzati(int N, int M, int X[], int Y[]) {
  Grid g(N, vector<bool>(N, 0));
  n = N;
  for (int i = 0; i < M; ++i) {
    g[X[i]][Y[i]] = 1;
  }
  int ans = 1;
  advance(g);

  while (bfs(g)) {
    ++ans;
    advance(g);
  }

  return ans - 1;
}

int main() {
  int N, M;
  freopen("error.txt", "w", stderr);

  assert(2 == scanf("%d %d", &N, &M));

  int* X = (int*)malloc(M * sizeof(int));
  int* Y = (int*)malloc(M * sizeof(int));

  for (int i = 0; i < M; i++)
    assert(2 == scanf("%d %d", X + i, Y + i));

  printf("%d\n", alzati(N, M, X, Y));
  return 0;
}
