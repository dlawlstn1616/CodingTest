#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;
	cin >> N;

	if (N % 2 == 0) cout << "CY" << "\n";
	else cout << "SK" << "\n";

	return 0;
}