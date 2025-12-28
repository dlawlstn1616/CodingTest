#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const long long INF = LLONG_MAX;

struct Edge {
	int from, to;
	int cost;
};

int n, m;
vector<Edge> edges;
vector<long long> dist;

bool bellmanFord(int start) {
	dist[start] = 0;

	// 1) N-1번 완화
	for (int i = 1; i <= n - 1; ++i) {
		for (auto& e : edges) {
			if (dist[e.from] == INF) continue;
			if (dist[e.to] > dist[e.from] + e.cost) {
				dist[e.to] = dist[e.from] + e.cost;
			}
		}
	}

	// 2) N번째 완화 → 음수 사이클 체크
	for (auto& e : edges) {
		if (dist[e.from] == INF) continue;
		if (dist[e.to] > dist[e.from] + e.cost) {
			return true; // 음수 사이클 존재
		}
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	edges.resize(m);
	dist.assign(n + 1, INF);

	for (int i = 0; i < m; ++i) {
		cin >> edges[i].from >> edges[i].to >> edges[i].cost;
	}

	// 벨만 포드 실행
	if (bellmanFord(1)) {
		cout << -1 << '\n';
		return 0;
	}

	// 결과 출력
	for (int i = 2; i <= n; ++i) {
		if (dist[i] == INF) cout << -1 << '\n';
		else cout << dist[i] << '\n';
	}

	return 0;
}