#include <iostream>

using namespace std;

void Solution(string word) 
{
	int cnt = 0;
	char ans;
	int alpha[26] = { 0 };

	for (int i = 0; word[i] != '\0'; i++)
	{
		if (word[i] >= 'a') word[i] -= 32;
		alpha[word[i]-'A']++;
	}

	for (int i = 0; i < 26; i++) 
	{
		if (cnt < alpha[i])
		{
			cnt = alpha[i];
			ans = i;
		}
		else if (cnt == alpha[i]) ans = '?';
	}
	
	if (ans == '?') cout << ans << "\n";
	else cout << char(ans+65) << "\n";
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	string word;

	cin >> word;

	Solution(word);

	return 0;
}