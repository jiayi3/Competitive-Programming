#include <bits/stdc++.h>
using namespace std;

int pulisci(int N, int M, vector<string> S) {
  vector<int> R(N, 0), C(M, 0);
  for(int i = 0; i < (int)S.size(); ++i) {
    for(int j = 0; j < (int)S[0].size(); ++j) {
      if(S[i][j] == '1') {
        R[i] += 1;
        C[j] += 1;
      }
    }
  }

  do {
    auto it1 = R.begin();
    for(; it1 != R.end(); ++it1) {
      if(*it1 == M || *it1 == 0) break;
    }

    if(it1 != R.end()) {
      if(*it1 > 0)
        for(int& x : C) --x;
      R.erase(it1);
      --N;
    }
    else {
      auto it = C.begin();
      for(; it != C.end(); ++it) {
        if(*it == N || *it == 0) break;
      }

      if(it != C.end()) {
        if(*it > 0)
          for(int& x : R) --x;
        C.erase(it);
        --M;
      } else {
        return N * M;
      }
    }
  } while(true);

  return 0;
}

int main() {
  int N, M;
  cin >> N >> M;

  vector<string> S(N);

  for(int i = 0; i < N; i++) {
    cin >> S[i];
  }

  cout << pulisci(N, M, S) << endl;

  return 0;
}
