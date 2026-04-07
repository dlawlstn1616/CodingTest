#include <iostream>

using namespace std;

int colors[51];

static double same_color(int type, int pick, int total) {
	double answer = 0;
	double a = 0, b = 1;
	for (int i = 0; i < pick; ++i) {
		b *= (total - i);
		b /= i + 1;
	}

	for (int i = 0; i < type; ++i) {
		double c = 1;
		for (int j = 0; j < pick; ++j) {
			c *= (colors[i] - j);
			c /= j + 1;
		}
		a += c;
	}

	answer = a / b;

	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int M;
	cin >> M;

	int total = 0;

	for (int i = 0; i < M; ++i) {
		cin >> colors[i];
		total += colors[i];
	}

	int K;
	cin >> K;

	cout << fixed;
	cout.precision(15);
	cout << same_color(M, K, total) << "\n";

	return 0;
}