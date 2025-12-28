#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

const int INF = INT_MAX;
int v, e, k;
vector<vector<pair<int, int>>> graph;
vector<int> dist;

const void dijkstra()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	dist[k] = 0;
	pq.push({ 0, k });

	while (!pq.empty())
	{
		int curDist = pq.top().first;
		int curNode = pq.top().second;
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

	cin >> v >> e >> k;

	graph.assign(v + 1, vector<pair<int, int>>());
	dist.assign(v + 1, INF);

	for (int i = 0; i < e; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
	}

	dijkstra();

	for (int i = 1; i <= v; ++i) {
		if (dist[i] == INF)
			cout << "INF" << "\n";
		else
			cout << dist[i] << "\n";
	}

	return 0;
}