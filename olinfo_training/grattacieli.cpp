#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vi = vector<int>;
using pli = pair<ll, int>;

#define all(x) (x).begin(), (x).end()

using Graph = vector<vector<pair<int, int>>>;

ll costruisci(int N, int M, vll& H, vi& A, vi& B, vi& C) {
  Graph g(N);
  for (int i = 0; i < M; ++i) {
    g[A[i]].push_back({ B[i], C[i] });
  }

  priority_queue<pli, vector<pli>, greater<pli>> q;
  unordered_set<int> vis, heads;
  for (int i = 1; i < N; ++i) vis.insert(i);

  q.emplace(H[0], 0);

  do {
    while (q.size()) {
      auto [dist, u] = q.top();
      q.pop();

      for (const auto& [next, val] : g[u]) {
        ll alt = dist + val;
        if (H[next] > alt) {
          H[next] = alt;
          vis.erase(next);
          q.emplace(alt, next);
        }
      }
    }
    if (vis.empty()) return accumulate(all(H), 0ll);
    q.emplace(H[*vis.begin()], *vis.begin());
    vis.erase(vis.begin());
  }
  while (true);

  return 0;
}

int main() {
  // Input da file:
  // freopen("input.txt", "r", stdin);

  // Output su file:
  freopen("error.txt", "w", stderr);

  int n, m;
  cin >> n >> m;
  vll h(n);
  vi a(m), b(m), c(m);

  for (size_t i = 0; i < n; i++) {
    cin >> h[i];
  }
  for (size_t j = 0; j < m; j++) {
    cin >> a[j] >> b[j] >> c[j];
  }
  cout << costruisci(n, m, h, a, b, c) << endl;
  return 0;
}
