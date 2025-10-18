#include<iostream>

using namespace std;

int main(int* argc, int** argv){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        int brain, zombies;
        cin >> brain >> zombies;
        if(brain < zombies) cout << "NO BRAINS" << "\n";
        else cout << "MMM BRAINS" << "\n";
    }
    
    return 0;
}