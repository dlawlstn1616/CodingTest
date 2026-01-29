#include <iostream>

using namespace std;

static int getGCD(long long a, long long b) {
	if (b == 0) return a;
	return getGCD(b, a % b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long a, b;
	cin >> a >> b;

	int count = getGCD(a, b);

	for (long long i = 0; i < count; ++i) {
		cout << '1';
	}
	cout << "\n";

	return 0;
}