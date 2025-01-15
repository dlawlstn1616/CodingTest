#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s = "";
	int num[21] = { 0 };
	int M = 0, x = 0;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> s;

		if (s == "add") {
			cin >> x;
			if (num[x] == 0) num[x] = 1;
		}

		else if (s == "check") {
			cin >> x;
			if (num[x] == 0) cout << 0 << "\n";
			else cout << 1 << "\n";
		}

		else if (s == "remove") {
			cin >> x;
			if (num[x] == 1) num[x] = 0;
		}

		else if (s == "toggle") {
			cin >> x;
			if (num[x] == 1) num[x] = 0;
			else num[x] = 1;
		}

		else if (s == "all") {
			for (int i = 1; i <= 20; i++) num[i] = 1;
		}

		else if (s == "empty") {
			memset(num, 0, sizeof(num));
		}
	}

	return 0;
}