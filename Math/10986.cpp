#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N,M;
    long long psum = 0, cnt = 0;
    long long mod[1001]={0};
    
    cin >> N >> M;

    for(int i=0; i<N; ++i){
        int num;
        cin >> num;
        psum = (psum + num) % M;
        mod[psum]++;
    }

    for(int i=0; i<M; ++i)
        cnt += mod[i] * (mod[i] - 1) / 2;

    cout << cnt + mod[0] << "\n";

    return 0;
}