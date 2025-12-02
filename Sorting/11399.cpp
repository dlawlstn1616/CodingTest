#include <iostream>
#include <vector>

using namespace std;

static void insertion_sort(vector<pair<int, int>>& p, int n) {
	for (int i = 1; i < n; i++) {
		pair<int,int> key = p[i];
		int j = i - 1;

		while (j >= 0 && p[j].first > key.first) {
			p[j + 1] = p[j];
			j--;
		}
		p[j + 1] = key;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<pair<int, int>> p;
	for (int i = 1; i <= n; ++i) {
		int num = 0;
		cin >> num;
		p.push_back(pair(num, i));
	}

	insertion_sort(p, n);

	int sum = 0;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		sum += p[i].first;
		ans += sum;
	}

	cout << ans << "\n";

	return 0;
}