#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int alpa[26];
	fill(alpa, alpa + 26, 0);

	string s;
	cin >> s;
	//getline(cin, s);

	cout << s.size() << ' ' << s.length() << "\n";

	for (int c : s)
		alpa[c - 'a']++;
	for (int i = 0; i < 26; i++)
		cout << alpa[i] << ' ';
	return 0;
}