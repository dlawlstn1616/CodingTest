#include <iostream>

using namespace std;

static int getGCD(int a, int b) {
	if (b == 0) return a;
	return getGCD(b, a % b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	
	for (int i = 0; i < t; ++i) {
		int a, b;
		cin >> a >> b;

		int gcd = getGCD(a, b);

		long long result = (long long)a * b / gcd;

		cout << result << "\n";
	}

	return 0;
}