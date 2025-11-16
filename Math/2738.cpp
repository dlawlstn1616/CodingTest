#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M;
    cin >> N >> M;

    int a[100][100];
    int b[100][100];

    for(int i=0; i<N; ++i)
        for(int j=0; j<M; ++j)
            cin >> a[i][j];

    for(int i=0; i<N; ++i)
        for(int j=0; j<M; ++j)
            cin >> b[i][j];

    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cout << a[i][j] + b[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}