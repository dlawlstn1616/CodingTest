#include <iostream>

using namespace std;

void Solution(int idx1, int idx2)
{
	int p1 = idx1;
	int p2 = idx2;
	if (p1 > p2) p2++;

	for (int i = 0; i < p1; i++) cout << 1;
	for (int i = 0; i < p1; i++) cout << 4;

	for (int i = 0; i < p2; i++) cout << 1;
	for (int i = 0; i < p2-1; i++) cout << 4;
}

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, idx1 = 0, idx2 = 0;
	cin >> N;

	string s[100];

	for (int i = 0; i < N; i++)
	{
		cin >> s[i];
		if (s[i] == "KBS1")	idx1 = i;
		else if (s[i] == "KBS2") idx2 = i;
	}

	Solution(idx1, idx2);

	return 0;
}