#include <iostream>

int bubble_sort(int N, int K, int A[]) { 
    int count = 0;
    
    // A[1..N]을 오름차순 정렬한다.
    for(int last = N-1; last > 0; last--){
        for(int i=0; i<last; i++){
            if(A[i] > A[i+1]){
                int temp = A[i];
                A[i] = A[i+1];
                A[i+1] = temp;
                count++;
                if(count==K) return 1;
            }
        }
    }
    return -1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N,K;
    std::cin >> N >> K;
    
    int* A = new int[N];
    for(int i=0; i<N; i++)
        std::cin >> A[i];
    
    int ans = bubble_sort(N,K,A);
    if(ans==1){
        for(int i=0; i<N; i++)
            std::cout << A[i] << "\n";
    } else{
        std::cout << "-1" << "\n";
    }
    
    delete[] A;
    return 0;
}