#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 100'000;

int parents[MAXN + 1];
bool visited[MAXN + 1];
vector<int> adj[MAXN + 1];

static void findParents(int n) {
	queue<int> q;
	visited[1] = true;
	q.push(1);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int next : adj[cur]) {
			if (visited[next] == false) {
				visited[next] = true;
				parents[next] = cur;
				q.push(next);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n-1; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	findParents(n);

	for (int i = 2; i <= n; ++i) {
		cout << parents[i] << "\n";
	}

	return 0;
}