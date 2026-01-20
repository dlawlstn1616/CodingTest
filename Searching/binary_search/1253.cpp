#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> numbers;

static bool find_good(int target_idx, int n) {
	int left = 0;
	int right = n - 1;

	while (left < right) {
		if (left == target_idx) {
			left++;
			continue;
		}
		if (right == target_idx) {
			right--;
			continue;
		}

		long long sum = numbers[left] + numbers[right];

		if (sum == numbers[target_idx])
			return true;
		else if (sum < numbers[target_idx])
			left++;
		else
			right--;
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	numbers.resize(n);

	for (int i = 0; i < n; ++i) {
		cin >> numbers[i];
	}

	sort(numbers.begin(), numbers.end());
	
	int answer = 0;
	for (int i = 0; i < n; ++i) {
		if (find_good(i, n)) answer++;
	}

	cout << answer << "\n";

	return 0;
}