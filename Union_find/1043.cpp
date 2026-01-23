#include <iostream>
#include <vector>

using namespace std;

const int MAX_PEOPLE = 50;
int parents[MAX_PEOPLE + 1];

static void initialize_sets(int n) {
	for (int i = 1; i <= n; ++i)
		parents[i] = i;
}

static int find_root(int x) {
	if (parents[x] == x)
		return x;
	return parents[x] = find_root(parents[x]);
}

static void union_nodes(int x, int y) {
	int rootX = find_root(x);
	int rootY = find_root(y);

	if (rootX != rootY) {
		if (rootX < rootY) parents[rootY] = rootX;
		else parents[rootX] = rootY;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	int true_count;
	cin >> true_count;

	vector<int> true_knowers(true_count);
	for (int i = 0; i < true_count; ++i) {
		cin >> true_knowers[i];
	}

	vector<vector<int>> parties(m);

	initialize_sets(n);

	for (int i = 0; i < m; ++i) {
		int count;
		cin >> count;

		if (count > 0) {
			int first_person, next_person;
			cin >> first_person;
			parties[i].push_back(first_person);

			for (int j = 1; j < count; ++j) {
				cin >> next_person;
				parties[i].push_back(next_person);
				union_nodes(first_person, next_person);
			}
		}
	}

	int lie_party_count = 0;

	for (int i = 0; i < m; ++i) {
		bool possible_to_lie = true;

		int current_party_root = -1;

		if (!parties[i].empty()) {
			current_party_root = find_root(parties[i][0]);
		}

		for (int knower : true_knowers) {
			if (current_party_root != -1 && find_root(knower) == current_party_root) {
				possible_to_lie = false;
				break;
			}
		}

		if (possible_to_lie) {
			lie_party_count++;
		}
	}

	cout << lie_party_count << "\n";

	return 0;
}