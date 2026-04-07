#include <iostream>

using namespace std;

int rooms[15][15];

static void init_rooms() {
	for (int i = 1; i < 15; ++i) {
		rooms[0][i] = i;
	}

	for (int i = 1; i < 15; ++i) {
		for (int j = 1; j < 15; ++j) {
			rooms[i][j] = rooms[i - 1][j] + rooms[i][j-1];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	init_rooms();

	for (int i = 0; i < T; ++i) {
		int k, n;
		cin >> k >> n;
		cout << rooms[k][n] << "\n";
	}

	return 0;
}