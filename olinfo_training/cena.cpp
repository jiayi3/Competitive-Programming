#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define mp(x, y) make_pair(x, y)

#define mxS 100'002
#define mxP 50'002

int pre[100][mxS];
// pre[i][j] = primo indice >= j dove s[j] == i

int check(int l, int P, int p[]) {
  for(int i = 0; i < P; ++i) {
    if(pre[p[i]][l] == -1) return -1;
    l = pre[p[i]][l] + 1;
  }
  return l - 1;
};

ll conta(int S, int s[], int P, int p[]) {
  for(int i = 0; i < 100; ++i) {
    pre[i][S] = -1;
    for(int j = S - 1; j >= 0; --j) {
      if(s[j] == i)
        pre[i][j] = j;
      else
        pre[i][j] = pre[i][j + 1];
    }
  }

  ll ans = 0;
  for(int i = 0; i < S; ++i) {
    int end = check(i, P, p);
    if(end == -1) break;
    ans += ll(S - end);
  }
  return ans;
}

int main() {
  int S, P;
  assert(2 == scanf("%d %d", &S, &P));

  int* s = (int*)malloc(S * sizeof(int));
  int* p = (int*)malloc(P * sizeof(int));

  for(int i = 0; i < S; i++) assert(1 == scanf("%d", s + i));
  for(int i = 0; i < P; i++) assert(1 == scanf("%d", p + i));

  printf("%lld\n", conta(S, s, P, p));
  return 0;
}

