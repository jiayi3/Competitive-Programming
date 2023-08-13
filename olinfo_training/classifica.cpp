#include <bits/stdc++.h>
using namespace std;

int indices[1000001], P[1000001], N[1000001], mxN = 1;
int* _ids;
vector<int> tree;

void inizia(int n, int ids[]) {
  while(mxN < n) mxN <<= 1;
  tree.assign(mxN << 1, 0);
  for(int i = 0; i < n; ++i)
    tree[i + mxN] = 1;
  for(int i = mxN - 1; i > 0; --i)
    tree[i] = tree[i << 1] + tree[i << 1 | 1];

  _ids = ids;
  for(int i = 0; i < n; ++i) {
    indices[ids[i]] = i;
    P[ids[i]] = (i == 0 ? -1 : ids[i - 1]);
    N[ids[i]] = (i == n - 1 ? -1 : ids[i + 1]);
  }
}

void supera(int id) {
  int p = P[id], pp = P[p], n = N[id];
  int i = indices[id], j = indices[p];
  swap(_ids[i], _ids[j]);
  swap(indices[id], indices[p]);

  if(pp != -1) N[pp] = id;
  if(n != -1) P[n] = p;
  P[id] = pp;
  N[id] = p;
  P[p] = id;
  N[p] = n;
}

void squalifica(int id) {
  int pos = indices[id];
  for(tree[pos += mxN] = 0; pos > 1; pos >>= 1)
    tree[pos >> 1] = tree[pos] + tree[pos ^ 1];

  int p = P[id], n = N[id];
  if(p != -1) N[p] = n;
  if(n != -1) P[n] = p;
}

int partecipante(int pos) {
  int x = 1;
  while(x < mxN) {
    x <<= 1;
    if(tree[x] < pos) {
      pos -= tree[x];
      x |= 1;
    }
  }
  return _ids[x - mxN];
}

int main() {
  int n, q;
  cin >> n >> q;
  int a[n];
  for(int i = 0; i < n; ++i) cin >> a[i];
  inizia(n, a);

  while(q--) {
    char op; int m; cin >> op >> m;
    switch(op) {
      case 'x':
        squalifica(m);
        break;
      case 's':
        supera(m);
        break;
      case 'p':
        cout << partecipante(m) << " ";
        break;
    }
  }

  return 0;
}