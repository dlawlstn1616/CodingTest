#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
	int u, v, weight;
	bool operator<(const Edge& other) const {
		return weight < other.weight;
	}
};

int parents[51];

static int find_parent(int x) {
	if (parents[x] == x) return x;
	return parents[x] = find_parent(parents[x]);
}

static bool union_sets(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);
	if (a != b) {
		parents[b] = a;
		return true;
	}
	return false;
}

int charToWeight(char c) {
	if (c >= 'a' && c <= 'z') return c - 'a' + 1;
	if (c >= 'A' && c <= 'Z') return c - 'A' + 27;
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<Edge> edges;
	int total_length = 0;

    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < n; j++) {
            int w = charToWeight(line[j]);
            total_length += w;
            if (i != j && w > 0) {
                edges.push_back({ i, j, w });
            }
        }
        parents[i] = i;
    }

    sort(edges.begin(), edges.end());

    int used_length = 0;
    int count = 0;

    for (Edge edge : edges) {
        if (union_sets(edge.u, edge.v)) {
            used_length += edge.weight;
            count++;
        }
    }

    if (count == n - 1 || n == 1) {
        // N이 1인 경우 연결할 간선이 필요 없으므로 바로 total 출력
        if (n == 1) cout << total_length << endl;
        else cout << total_length - used_length << endl;
    }
    else {
        cout << -1 << endl;
    }

	return 0;
}