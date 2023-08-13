#include <bits/stdc++.h>
using namespace std;

static FILE* fr, * fw;

// Declaring variables
static int N;
static int M;
static int* A;
static int* B;
static int* inizio;
static int* fine;
static int tempo;

using ii = pair<int, int>;
using Graph = vector<vector<ii>>;
using vi = vector<int>;

int raggiungi(int N, int M, int A[], int B[], int inizio[], int fine[]) {
  Graph g(N);
  for(int i = 0; i < M; ++i) {
    g[A[i]].emplace_back(B[i], i);
    g[B[i]].emplace_back(A[i], i);
  }

  vi dist(N, INT_MAX); dist[0] = 0;
  priority_queue<ii, vector<ii>, greater<ii>> pq;
  pq.emplace(0, 0);

  while(pq.size()) {
    int u = pq.top().second;
    pq.pop();

    if(u == N - 1) break;

    for(const auto& [next, index] : g[u]) {
      if(dist[u] < fine[index]) {
        int d = max(dist[u], inizio[index]) + 1;
        if(d < dist[next]) {
          dist[next] = d;
          pq.emplace(d, next);
        }
      }
    }
  }

  return dist[N - 1] == INT_MAX ? -1 : dist[N - 1];
}

int main() {
  fr = stdin;
  fw = stdout;

  // Reading input
  fscanf(fr, " %d %d", &N, &M);
  A = (int*)malloc((M) * sizeof(int));
  B = (int*)malloc((M) * sizeof(int));
  inizio = (int*)malloc((M) * sizeof(int));
  fine = (int*)malloc((M) * sizeof(int));
  for(int i0 = 0; i0 < M; i0++) {
    fscanf(fr, " %d %d %d %d", &A[i0], &B[i0], &inizio[i0], &fine[i0]);
  }

  // Calling functions
  tempo = raggiungi(N, M, A, B, inizio, fine);

  // Writing output
  fprintf(fw, "%d\n", tempo);

  fclose(fr);
  fclose(fw);
  return 0;
}
