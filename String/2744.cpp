#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    
    int len = s.length();

    for(int i=0; i<len; ++i){
        if (isupper(s[i])) s[i] = tolower(s[i]);
        else if (islower(s[i])) s[i] = toupper(s[i]);
    }
    
    cout << s << "\n";
    
    return 0;
}