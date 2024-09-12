#include <iostream>
#include <string>
using namespace std;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;

    while (N--) {
        int a[26] = {};
        string s1, s2;
        cin >> s1 >> s2;

        for (auto c : s1) a[c - 'a']++;
        for (auto c : s2) a[c - 'a']--;

        bool isposs = true;

        for (int i : a) {
            if (i != 0)
                isposs = false;
        }
        if (isposs)
            cout << "Possible\n";
        else
            cout << "Impossible\n";
    }
}