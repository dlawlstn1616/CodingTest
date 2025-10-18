#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, W, result = 0;
    cin >> N >> W;
    
    result = N*10;
    if(N >= 3) result += 20;
    if(N == 5) result += 50;

    if(W > 1000) result = max(0, result - 15);
    
    cout << result << "\n";
    
    return 0;
}