#include <iostream>
#include <string>
using namespace std;

void swap(string &s, int nIndex, int maxIndex){
    char temp;
    temp = s[nIndex];
    s[nIndex] = s[maxIndex];
    s[maxIndex] = temp;
}

void select_sort(string &s, int len){
    for(int i = 0; i < len - 1; i++){
        int maxIndex = i;
        for(int j = i + 1; j < len; j++){
            if(s[j] > s[maxIndex]){
                maxIndex = j;
            }
        }
        if(maxIndex != i){
            swap(s, i, maxIndex);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int len = s.length();

    select_sort(s, len);

    cout << s << "\n";

    return 0;
}