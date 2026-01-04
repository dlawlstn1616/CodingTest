#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

const long long NEG_INF = LLONG_MIN;

struct Edge {
	int from, to;
	int cost;
};

int n, m, answer;
vector<Edge> edges;
vector<long long> dist;
vector<int> earn;
vector<bool> inCycle;
vector<vector<int>> graph;

bool canReachEnd(int start, int end) {
	vector<bool> visited(n, false);
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (cur == end) return true;

		for (int nxt : graph[cur]) {
			if (!visited[nxt]) {
				visited[nxt] = true;
				q.push(nxt);
			}
		}
	}
	return false;
}

static void bellman_ford(int start)
{
	dist[start] = earn[start];

	for (int i = 0; i < n - 1; ++i) {
		for (Edge next : edges) {
			long long value = dist[next.from] - next.cost + earn[next.to];
			if (dist[next.from] == NEG_INF) continue;
			if (dist[next.to] < value) {
				dist[next.to] = value;
			}
		}
	}

	for (Edge next : edges) {
		if (dist[next.from] == NEG_INF) continue;
		if (dist[next.to] < dist[next.from] - next.cost + earn[next.to]) {
			inCycle[next.to] = true;
		}
	}
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int start, end;

	cin >> n >> start >> end >> m;

	edges.resize(m);
	dist.assign(n, NEG_INF);
	earn.resize(n);
	inCycle.assign(n, false);
	graph.resize(n);

	for (int i = 0; i < m; ++i) {
		cin >> edges[i].from >> edges[i].to >> edges[i].cost;
		graph[edges[i].from].push_back(edges[i].to);
	}

	for (int i = 0; i < n; ++i) {
		cin >> earn[i];
	}

	bellman_ford(start);

	for (int i = 0; i < n; i++) {
		if (inCycle[i] && canReachEnd(i, end)) {
			cout << "Gee\n";
			return 0;
		}
	}

	if (dist[end] == NEG_INF) cout << "gg" << "\n";
	else cout << dist[end] << "\n";


	return 0;
}