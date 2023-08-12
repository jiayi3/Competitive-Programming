#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ii = pair<int, int>;
using Graph = vector<vector<ii>>;

#define inf 1e9+5

/**
 * Dijkstra routine
*/
int dijkstra(Graph& g, int src, int target) {
	vi dist(g.size(), inf); dist[src] = 0;
	priority_queue<ii, vector<ii>, greater<ii>> pq; pq.emplace(0, src);

	while(pq.size()) {
		auto [d, u] = pq.top(); pq.pop(); // greedy: pick shortest unvisited vertex
		if(d > dist[u]) continue; // this check is important

		for(const auto& [next, w] : g[u]) { // all outgoing edges from u
			if(dist[u] + w < dist[next]) {
				dist[next] = dist[u] + w;      // relax operation
				pq.emplace(dist[next], next);
			}
		}
	} // note: this variant can cause duplicate items in the priority queue

	return dist[target];
}

int main() {
	Graph g(4);
	g[0].emplace_back(1, 1);
	g[0].emplace_back(2, 3);
	g[1].emplace_back(3, 2);
	g[2].emplace_back(3, 3);

	cout << dijkstra(g, 0, 3) << "\n"; // expected 3
}
