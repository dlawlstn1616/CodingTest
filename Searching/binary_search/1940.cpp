#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> materials;

static int countArmor(int n, int m, vector<int>& materials)
{
	int count = 0;
	int left = 0;
	int right = n - 1;

	while (left < right) {
		int sum = materials[left] + materials[right];
		
		if (sum == m) {
			count++;
			left++;
			right--;
		}
		else if (sum < m) {
			left++;
		}
		else {
			right--;
		}
	}

	return count;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	materials.resize(n);

	for (int i = 0; i < n; ++i)
		cin >> materials[i];

	sort(materials.begin(), materials.end());
	cout << countArmor(n, m, materials) << "\n";

	return 0;
}