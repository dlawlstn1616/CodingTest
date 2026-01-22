#include <iostream>

using namespace std;

static const int MAXN = 200;

int parent[MAXN + 1];
int rankArr[MAXN + 1];

static int find(int x)
{
	if (parent[x] == x)
		return x;
	return parent[x] = find(parent[x]);
}

static void unite(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a == b) return;

	if (rankArr[a] < rankArr[b]) parent[a] = b;
	else if (rankArr[a] > rankArr[b]) parent[b] = a;
	else {
		parent[b] = a;
		rankArr[a]++;
	}
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		parent[i] = i;
		rankArr[i] = 0;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			int op;
			cin >> op;
			if (op == 1) unite(i, j);
		}
	}
	
	int first_city;
	cin >> first_city;
	int root = find(first_city);
	bool check = true;

	for (int i = 1; i < m; ++i) {
		int next_city;
		cin >> next_city;
		if (root != find(next_city)) {
			check = false;
		}
	}

	if (check == true) cout << "YES" << "\n";
	else cout << "NO" << "\n";

	return 0;
}