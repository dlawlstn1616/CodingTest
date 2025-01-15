#include <iostream>

using namespace std;

void Solution(int n)
{
	int a = 2, b = 5, cnt = 2;

	while (1)
	{
		if (n >= a && n <= a + b)
		{
			cout << cnt << "\n";
			break;
		}

		a += b + 1;
		b += 6;
		cnt++;
	}
}

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	if (n == 1) cout << 1 << "\n";
	else Solution(n);

	return 0;
}