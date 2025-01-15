#include <iostream>

using namespace std;

void Solution(int T, int h[21])
{
	int ans = 0;
	for (int i = 1; i <= 20; i++)
	{
		for (int j = i + 1; j <= 20; j++) {
			if (h[j] < h[i]) ans++;
		}
	}

	cout << T << " " << ans << "\n";
}

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int P = 0, T = 0;
	int h[21] = { 0 };
	cin >> P;

	for (int i = 0; i < P; i++)
	{
		cin >> T;
		for (int j = 1; j <= 20; j++) cin >> h[j];

		Solution(T, h);
	}

	return 0;
}