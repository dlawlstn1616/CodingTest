#include <iostream>

using namespace std;

bool isPrime[1000001];

static void find_primeNumber(int n) {
	for (int i = 2; i * i <= n; ++i) {
		if (isPrime[i]) {
			for (int j = i * i; j <= n; j += i) {
				isPrime[j] = false;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int m, n;
	cin >> m >> n;
	
	for (int i = 2; i <= n; ++i) isPrime[i] = true;
	isPrime[0] = isPrime[1] = false;

	find_primeNumber(n);

	for (int i = m; i <= n; ++i)
	{
		if(isPrime[i] == true) cout << i << "\n";
	}
	return 0;
}