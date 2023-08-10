#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ii = pair<int, int>;
using Graph = vector<vector<ii>>;

#define inf 1e9+5

/**
 * Function to return the maximum weight in the widest path of the given graph
*/
int widestPath(Graph& g, int src, int target) {
	vi widest(g.size(), -inf); // To keep track of widest distance
	widest[src] = inf;

	// Use of Minimum Priority Queue to keep track minimum
	// widest distance vertex so far in the algorithm
	priority_queue<ii, vector<ii>, greater<ii>> q;
	q.emplace(0, src);

	while (q.size()) {
		auto curr = q.top().second;
		q.pop();

		for (const auto& [next, w] : g[curr]) {

			// Finding the widest distance to the vertex
			// using current_source vertex's widest distance
			// and its widest distance so far
			int dist = min(widest[curr], w);

			// Relaxation of edge and adding into Priority Queue
			if (dist > widest[next]) {

				// Updating bottle-neck distance
				widest[next] = dist;

				// Adding the relaxed edge in the priority queue
				q.emplace(dist, next);
			}
		}
	}

	return widest[target];
}

int main() {
	Graph g(4);
	g[0].emplace_back(1, 1);
	g[0].emplace_back(2, 3);
	g[1].emplace_back(3, 2);
	g[2].emplace_back(3, 3);

	cout << widestPath(g, 0, 3) << "\n"; // expected 3
}
