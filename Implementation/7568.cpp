#include <iostream>
#include <algorithm>

using namespace std;

struct person {
	int x, y, rank = 1;
};

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;
	person p[50];
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> p[i].x >> p[i].y;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (p[i].x < p[j].x && p[i].y < p[j].y) p[i].rank++;
			else if (p[i].x > p[j].x && p[i].y > p[j].y)p[j].rank++;
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << p[i].rank << " ";
	}

	return 0;
}