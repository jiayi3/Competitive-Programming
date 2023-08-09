#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using Graph = vector<vector<pair<int, int>>>;

struct Candle {
  int m, b, i; 
  bool burns(const Candle& a) {
    return (a.m >= min(m, b) && a.m <= max(m, b));
  }
};

bool cmp(const Candle& a, const Candle& b) {
  return (pair<int, int>){ a.m, a.b } < (pair<int, int>){ b.m, b.b };
}


void brucia(int N, vi &M, vi &B, vector<ll> &T) {
  Graph g(N);

  // costruzione grafo
  vector<Candle> v(N);
  for(int i = 0; i < N; ++i) {
    v[i].m = M[i];
    v[i].b = B[i];
    v[i].i = i;
  }

  sort(all(v), cmp);

  stack<Candle> st;
  for(int i = 0; i < N; ++i) {
    while(st.size() && v[i].burns(st.top())) {
      Candle c = st.top();
      st.pop();
      g[v[i].i].push_back({ c.i, abs(v[i].m - c.m) });
    }
    st.push(v[i]);
  }

  while(st.size())
    st.pop();
  reverse(all(v));

  for(int i = 0; i < N; ++i) {
    while(st.size() && v[i].burns(st.top())) {
      Candle c = st.top();
      st.pop();
      g[v[i].i].push_back({ c.i, abs(v[i].m - c.m) });
    }
    st.push(v[i]);
  }


  // dijkstra
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  pq.push({0ll, 0});
  fill(all(T), INT64_MAX);
  T[0] = 0;

  while(pq.size()) {
    int u = pq.top().second;
    pq.pop();
    for(const auto& [next, dist] : g[u]) {
      ll alt = dist + T[u];
      if(alt < T[next]) {
        T[next] = alt;
        pq.push({alt, next});
      }
    }
  }

  for(auto& x:T) 
    if(x == INT64_MAX) x = -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  freopen("error.txt", "w", stderr);
    
	int n;
	cin >> n;
	
	vector <int> m(n), b(n);
	vector <ll> t(n, 0);
	
	for (int i = 0; i < n; i++)
		cin >> m[i] >> b[i];
	
	brucia(n, m, b, t);
	for (int i = 0; i < n; i++)
		cout << t[i] << " ";
	cout << "\n";
	
	return 0;	
}
