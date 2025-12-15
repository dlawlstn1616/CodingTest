#include <iostream>
using namespace std;

/**
 * 주석 방법 중에서 Doxygen 방법으로 주석 처리
 * @brief  함수 요약
 * @param  매개변수 설명
 * @return 반환값 설명
 */


/**
 * @brief 주어진 정수가 소수인지 판별하는 함수
 *
 * @param num 판별할 정수
 * @return 소수이면 true, 아니면 false
 */
static bool isPrime(int num) {
    // 2 미만의 수는 소수가 아님
    if (num < 2) return false;

    // 2부터 sqrt(num)까지 나누어 떨어지는지 검사
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0)
            return false;
    }

    return true;
}

/**
 * @brief 신기한 소수를 DFS 방식으로 생성하는 함수
 *
 * @param cur    현재까지 만들어진 숫자
 * @param len    현재 숫자의 자리 수
 * @param target 목표 자리 수 (N)
 */
static void dfs(int cur, int len, int target) {
    // 목표 자리 수에 도달하면 출력
    if (len == target) {
        cout << cur << '\n';
        return;
    }

    // 다음 자리에 붙일 수 있는 후보 숫자들
    // (짝수와 5를 제외하여 소수 가능성만 유지)
    for (int d : {1, 2, 3, 5, 7, 9}) {
        int next = cur * 10 + d;

        // 새로 만든 숫자가 소수일 경우에만 재귀 탐색
        if (isPrime(next)) {
            dfs(next, len + 1, target);
        }
    }
}

/**
 * @brief 프로그램 진입점
 *
 * @return 정상 종료 시 0
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // 한 자리 소수부터 시작 (1은 소수가 아니므로 제외)
    for (int start : {2, 3, 5, 7}) {
        dfs(start, 1, n);
    }

    return 0;
}
