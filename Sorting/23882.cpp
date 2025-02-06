#include<iostream>

int selection_sort(int N, int K, int A[]) {
    int count = 0;
    // A[1..N]을 오름차순 정렬한다.
    for(int last=N-1; last>0; last--){
        int max = A[0];
        int idx = 0;
        int i;
        for(i=0; i<=last; i++){
            if(A[i]>max)
            {
                max = A[i];
                idx = i;
            }
        }
        if(last != idx)
        {
            int temp = A[last];
            A[last] = A[idx];
            A[idx] = temp;
            count++;
            if(count == K) return 1;
        }
    }
    return -1;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N,K;
    std::cin >> N >> K;
    
    int* A = new int[N];
    for(int i=0; i<N; i++)
        std::cin >> A[i];
    
    int ans = selection_sort(N,K,A);
    if(ans==1)
    {
        for(int i=0; i<N; i++)
            std::cout << A[i] << " ";
    }
    else std::cout << "-1";
    delete[] A;
    return 0;
}