#include <iostream>

using namespace std;

void Solution(int H, int W, int N, int M)
{
	int cnt = 0;
	if (H % (N + 1) == 0)
		cnt += (H / (N + 1));
	else
		cnt += (H / (N + 1)) + 1;

	if (W % (M + 1) == 0)
		cnt *= (W / (M + 1));
	else
		cnt *= (W / (M + 1)) + 1;

	cout << cnt << "\n";
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int H, W, N, M;
	cin >> H >> W >> N >> M;

	Solution(H, W, N, M);

	return 0;
}