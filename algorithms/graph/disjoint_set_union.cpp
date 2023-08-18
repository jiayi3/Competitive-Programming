#include <bits/stdc++.h>
using namespace std;

struct DSU {
  vector<int> e; // e[x] contains the negation of the size of x's component if
                 // x is the representative of its component, and the parent of 
                 // x otherwise.

  DSU(int N) { e.assign(N, -1); }

  // get representive component (uses path compression)
  int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

  bool same_set(int a, int b) { return get(a) == get(b); }

  int size(int x) { return -e[get(x)]; }

  bool unite(int x, int y) {  // union by size
    x = get(x), y = get(y);
    if(x == y) return false;

    if(e[x] > e[y]) swap(x, y);
    e[x] += e[y];
    e[y] = x;
    return true;
  }
};
