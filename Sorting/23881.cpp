#include <iostream>

void selection_sort(int N, int K, int A[]) {
    int count = 0;

    // 선택 정렬: A[1..N]을 오름차순 정렬
    for (int last = N - 1; last > 0; last--) {
        int maxIdx = 0;
        
        // A[1..last] 중 가장 큰 수 A[maxIdx]를 찾는다
        for (int i = 1; i <= last; i++) {
            if (A[i] > A[maxIdx]) {
                maxIdx = i;
            }
        }

        // 교환이 일어날 경우
        if (maxIdx != last) {
            int temp = A[last];
            A[last] = A[maxIdx];
            A[maxIdx] = temp;
            count++; // 교환 횟수 증가
            
            // K번째 교환일 때 두 값 반환
            if (count == K) {
                std::cout << A[maxIdx] << " " << A[last] << "\n";
                return;
            }
        }
    }
    std::cout << -1 << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, K;
    std::cin >> N >> K;

    int* A = new int[N];
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    // 선택 정렬 실행
    selection_sort(N, K, A);

    delete[] A; // 동적 메모리 해제
    return 0;
}
