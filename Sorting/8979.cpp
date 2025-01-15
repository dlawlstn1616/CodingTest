#include <iostream>
#include <algorithm>

using namespace std;

struct Cty {
	int num, g, s, b;
};

bool compareCty(Cty a, Cty b)
{
	if (a.g > b.g) return true;
	else if (a.g == b.g) {
		if (a.s > b.s) return true;
		if (a.s == b.s) {
			if (a.b > b.b) return true;
		}
	}

	return false;
}

void Solution(int N, int K, Cty ctys[1000])
{
	int ans = 0, tmp = 0;
	sort(ctys, ctys + N, compareCty);

	for (int i = 0; i < N; i++)
	{
		if (ctys[i].num == K) {
			ans = i;
			break;
		}
	}

	for (int i = ans-1;; i--)
	{
		if (ctys[i].g != ctys[ans].g || ctys[i].s != ctys[ans].s || ctys[i].b != ctys[ans].b) break;
		tmp++;
	}

	cout << ans - tmp + 1 << "\n";
}

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0, K = 0;

	Cty ctys[1000] = {0};

	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> ctys[i].num >> ctys[i].g >> ctys[i].s >> ctys[i].b;
	}

	Solution(N, K, ctys);

	return 0;
}