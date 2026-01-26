#include <iostream>
#include <algorithm>

using namespace std;

struct Edge {
	int u, v;
	int weight;

	bool operator<(const Edge& other) const {
		return weight < other.weight;
	}
};

int parents[10001];
Edge edges[100001];

static int findParent(int x) {
	if (parents[x] == x)
		return x;
	return parents[x] = findParent(parents[x]);
}

static bool unionNodes(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	if (a != b) {
		parents[a] = b;
		return true;
	}
	return false;
}

static long long solveMST(int v, int e)
{
	long long totalWeight = 0;
	int edgesCount = 0;

	sort(edges, edges + e);

	for (int i = 1; i <= v; ++i) {
		parents[i] = i;
	}

	for (int i = 0; i < e; ++i) {
		if (unionNodes(edges[i].u, edges[i].v)) {
			totalWeight += edges[i].weight;
			edgesCount++;

			if (edgesCount == v - 1) break;
		}
	}

	return totalWeight;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int v, e;
	cin >> v >> e;

	for (int i = 0; i < e; ++i) {
		cin >> edges[i].u >> edges[i].v >> edges[i].weight;
	}

	cout << solveMST(v, e) << "\n";

	return 0;
}