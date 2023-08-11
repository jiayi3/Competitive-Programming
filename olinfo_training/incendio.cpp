#include <bits/stdc++.h>
using namespace std;

int alzati(int N, int M, int X[], int Y[]) { // time: O(M ^ 2)
                                             // space: O(M)
  int dist[M];
  unordered_set<int> vis;
  for(int i = 0; i < M; ++i) {
    vis.insert(i);
    dist[i] = min(N - Y[i] - 1, X[i]);
  }

  while(vis.size()) {
    int curr = *vis.begin();
    for(const int& u : vis)
      if(dist[u] < dist[curr]) curr = u;

    vis.erase(curr);

    for(const int& next : vis) {
      int dx = abs(X[curr] - X[next]), dy = abs(Y[curr] - Y[next]),
        t = (dx == 0 || dy == 0) - 1;
      int w = (dx + dy + t) / 2, d = max(dist[curr], w);
      if(d < dist[next]) dist[next] = d;
    }
  }

  int ans = N;
  for(int i = M - 1; i >= 0; --i)
    ans = min(max(dist[i], min(N - X[i] - 1, Y[i])), ans);
  return ans - 1;
}

int main() {
  int N, M;

  assert(2 == scanf("%d %d", &N, &M));

  int* X = (int*)malloc(M * sizeof(int));
  int* Y = (int*)malloc(M * sizeof(int));

  for(int i = 0; i < M; i++)
    assert(2 == scanf("%d %d", X + i, Y + i));

  printf("%d\n", alzati(N, M, X, Y));
  return 0;
}
