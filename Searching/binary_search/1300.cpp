#include <iostream>

using namespace std;

long long n, k;

static long long countLessOrEqual(long long mid) {
	long long cnt = 0;

	for (long long i = 1; i <= n; ++i) {
		cnt += min(n, mid / i);
	}

	return cnt;
}

static long long binarySearch() {
	long long low = 1;
	long long high = k;
	long long result = 0;

	while (low <= high) {
		long long mid = (low + high) / 2;

		long long cnt = countLessOrEqual(mid);

		if (cnt >= k) {
			result = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}

	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;

	cout << binarySearch() << "\n";

	return 0;
}