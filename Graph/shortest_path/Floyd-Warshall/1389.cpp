#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = 1e9;
int n, m;
int dist[101][101];

static void floydWarshall()
{
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		dist[a][b] = 1;
		dist[b][a] = 1;
	}

	floydWarshall();

	int answer = 0;
	int minSum = INF;

	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			sum += dist[i][j];
		}

		if (sum < minSum) {
			minSum = sum;
			answer = i;
		}
	}

	cout << answer << "\n";

	return 0;
}