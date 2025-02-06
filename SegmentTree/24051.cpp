#include <iostream>
using namespace std;

int insertion_sort(int N, int K, int A[]) { 
    // 저장 횟수
    int count = 0;
    
    // A[1..N]을 오름차순 정렬한다.
    for(int i=1; i<N; i++)
    {
        int loc;
        int newItem = A[i];
        
        for(loc = i-1; loc>=0 && newItem < A[loc]; loc--)
        {
            A[loc+1] = A[loc];
            count++;
            
            if(count == K) return A[loc+1];
        }
        
        if(loc+1 != i)
        {
            A[loc+1] = newItem;
            count++;
            
            if(count == K) return A[loc+1];
        }
    }
    return -1;
}

int main(int argc, char** argv[])
{
    int N, K;
    scanf("%d %d", &N, &K);
    
    // 동적 할당
    int* A = new int[N];
    for(int i=0; i<N; i++)
        scanf("%d", &A[i]);
    
    printf("%d\n", insertion_sort(N,K,A));

    // 메모리 해제
    delete[] A;
    return 0;
}