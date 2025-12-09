#include <iostream>

using namespace std;

bool isPrime[10000001];

static void findPrime(int b) {
	for (long long i = 2; i<= 10000000; ++i) {
		if (isPrime[i] == true) {
			for (long long j = i * i; j <= 10000000; j += i) {
				isPrime[j] = false;
			}
		}
	}
}

static long long findAlmostPrime(long long ans, long long a, long long b) {
	for (long long i = 2; i <= 10000000; ++i) {
		if (isPrime[i] == true) {
			long long ap = i * i;
			while (ap <= b) {
				if (ap >= a) ans++;
				if (ap > b / i) break;
				ap *= i;
			}
		}
	}

	return ans;
}

static void init() {
	for (int i = 2; i < 10000001; ++i) isPrime[i] = true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long a, b;
	cin >> a >> b;

	isPrime[0] = false;
	isPrime[1] = false;
	init();

	findPrime(b);

	long long ans = 0;
	ans = findAlmostPrime(ans, a, b);

	cout << ans << "\n";

	return 0;
}