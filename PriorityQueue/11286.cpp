#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct cmp {
    bool operator()(int a, int b){
        if (abs(a) == abs(b)) return a > b;
        return abs(a) > abs(b);
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, cmp> pq;

    for(int i=0; i<N; ++i){
        int x;
        cin >> x;

        if (x == 0) {
            if (pq.empty()) cout << 0 << "\n";
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        } else {
            pq.push(x);
        }
    }

    return 0;
}