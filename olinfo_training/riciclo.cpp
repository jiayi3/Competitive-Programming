#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;

#define all(x) (x).begin(), (x).end()

ll riciclo(int N, int M, vi T, vi P) {
  
}

int main() {
  int N, M;

  cin >> N >> M;

  vi T(N), P(M);

  for(int i = 0; i < N; i++) {
    cin >> T[i];
  }
  for(int i = 0; i < M; i++) {
    cin >> P[i];
  }

  cout << riciclo(N, M, T, P) << endl;

  return 0;
}
