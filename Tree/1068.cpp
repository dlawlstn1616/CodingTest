#include <iostream>
#include <vector>

using namespace std;

int leafCount = 0;
int root, delNode;
vector<int> children[51];

static void dfs(int cur) {
	if (cur == delNode) return;

	int childCount = 0;
	for (int next : children[cur]) {
		if (next == delNode) continue;
		dfs(next);
		childCount++;
	}
	
	if (childCount == 0) leafCount++;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int parent;
		cin >> parent;
		if (parent == -1) root = i;
		else children[parent].push_back(i);
	}
	cin >> delNode;

	if (delNode == root)
		cout << 0 << "\n";
	else {
		dfs(root);
		cout << leafCount << "\n";
	}

	return 0;
}