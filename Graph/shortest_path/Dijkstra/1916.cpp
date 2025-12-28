#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

const int INF = INT_MAX;
int n, m, start, fin;
vector<vector<pair<int, int>>> graph;
vector<int> dist;

const void dijkstra()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	dist[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int curNode = pq.top().second;
		int curDist = pq.top().first;
		pq.pop();

		if (curDist > dist[curNode]) continue;

		for (pair<int, int> next : graph[curNode]) {
			int nextNode = next.first;
			int weight = next.second;

			if (dist[nextNode] > curDist + weight) {
				dist[nextNode] = curDist + weight;
				pq.push({ dist[nextNode], nextNode });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	cin >> m;

	graph.assign(n + 1, vector<pair<int, int>>());
	dist.assign(n + 1, INF);

	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
	}

	cin >> start >> fin;

	dijkstra();

	cout << dist[fin] << "\n";

	return 0;
}