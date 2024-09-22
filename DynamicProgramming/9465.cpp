#include <iostream>
using namespace std;

int n, int stk[2][100000];

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int i=0; i<t; i++){
        cin >> n;
        for(int j=0; j<2; j++){
            for(int k=0; k<n; k++){
                cin >> stk[j][k];
            }
        }
    }

    
}