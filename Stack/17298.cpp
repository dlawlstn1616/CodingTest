#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    int a[1000001];
    int nge[1000001];
    stack<int> s;
    
    cin >> N;
    
    for(int i=0; i<N; ++i) cin >> a[i];
    
    for(int i=0; i<N; ++i){
        while(!s.empty() && a[s.top()] < a[i]){
            nge[s.top()] = a[i];
            s.pop();
        }
        s.push(i);
    }
    
    while(!s.empty()){
        nge[s.top()] = -1;
        s.pop();
    }
    
    for(int i=0; i<N; ++i) cout << nge[i] << " ";
    
    return 0;
}