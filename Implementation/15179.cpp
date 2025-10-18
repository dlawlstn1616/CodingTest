#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int score_t1 = 0, score_t2 = 0;
	string t1, t2;
	string s; 
	int slen;

	getline(cin, t1);
	getline(cin, t2);
	cin >> slen >> s;

	for (int i = 0; i < slen; i++) {
		if (i & 1) {
			if (s[i] == 'H') score_t2++;
			else if (s[i] == 'D') score_t2 += 2;
			else if (s[i] == 'O') score_t1++;
		}
		else {
			if (s[i] == 'H') score_t1++;
			else if (s[i] == 'D') score_t1 += 2;
			else if (s[i] == 'O') score_t2++;
		}

		if (score_t1 > 6) {
			score_t1 = 7;
			cout << t1 << ' ' << score_t1 << ' ' << t2 << ' ' << score_t2 << '.' << ' ' << t1 << " has won.";
			return 0;
		}
		else if (score_t2 > 6) {
			score_t2 = 7;
			cout << t1 << ' ' << score_t1 << ' ' << t2 << ' ' << score_t2 << '.' << ' ' << t2 << " has won.";
			return 0;
		}
	}

	if (score_t1 > score_t2) cout << t1 << ' ' << score_t1 << ' ' << t2 << ' ' << score_t2 << '.' << ' ' << t1 << " is winning.";
	else if (score_t1 < score_t2) cout << t1 << ' ' << score_t1 << ' ' << t2 << ' ' << score_t2 << '.' << ' ' << t2 << " is winning.";
	else cout << t1 << ' ' << score_t1 << ' ' << t2 << ' ' << score_t2 << '.' << ' ' << "All square.";
}