#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,v;
	int num[100];
	int check[201];

	fill(check, check + 201,0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
		check[num[i] + 100]++;
	}
	cin >> v;

	cout << check[v + 100] << "\n";

	return 0;
}
