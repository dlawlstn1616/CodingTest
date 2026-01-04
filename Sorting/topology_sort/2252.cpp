#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> indegree;
vector<int> answer;

static void topologySort()
{
	queue<int> q;

	for (int i = 1; i <= n; ++i) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()){
		int cur = q.front();
		q.pop();
		answer.push_back(cur);
		
		for (int next : graph[cur]) {
			if (--indegree[next] == 0) 
				q.push(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	graph.resize(n + 1);
	indegree.assign(n + 1, 0);

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		indegree[b]++;
	}

	topologySort();

	for (int i = 0; i < n; ++i) {
		cout << answer[i] << " ";
	}

	return 0;
}