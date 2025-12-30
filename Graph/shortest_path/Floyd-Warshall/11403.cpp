#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
int dist[101][101];

static void floydWarshall()
{
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (dist[i][k] && dist[k][j]) {
					dist[i][j] = 1;
				}
			}
		}
	}
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> dist[i][j];
		}
	}

	floydWarshall();

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << dist[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}