#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, cnt = 0;
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        char c;
        cin >> c;
        if(c == 'O') cnt++;
    }

    cout << (cnt >= (N+1)/2 ? "Yes\n" : "No\n");
}