#include <iostream>
using namespace std;

<<<<<<< HEAD
// n의 최대값이 100,000
#define MAX 100000

// Dynamic Programming
// TopDown, BottomUp 중 BottomUp 방식
// TopDown : 재귀 호출 방식이라 재귀 깊이에 따라, 메모이제이션에 따라 느릴 수 있음
// BottomUp : 반복문 형식이라 함수 호출 오버헤드가 없고, 중복 계산 발생 X, 더 빠를 수 있음

// 메인함수
=======
int n, int stk[2][100000];

>>>>>>> 019e58d3318b4d8a6560ecea54be18cfc431b805
int main(int argc, char** argv)
{
    // 성능향상을 위한 option
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

<<<<<<< HEAD
    int t, n;
    // 배열 요소를 0으로 초기화
    int stk[2][MAX] = {0};
    int dp[MAX + 1][3] = {0};

    cin >> t;

    // 테스트 케이스에 따라 진행
    // 스티커는 2xn 배열 -> j와 k로 2xn에 값을 입력
    for(int i=0; i<t; i++){

        cin >> n;
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < n; k++){
                cin >> stk[j][k];
            }
        }

        // DP 배열 초기화
        for(int j = 0; j <= n; j++) {
            dp[j][0] = dp[j][1] = dp[j][2] = 0;
        }

        // 0: 왼쪽에 어떠한 스티커도 뜯기지 않은 상태
        // 1: 왼쪽 첫번째 칸의 스티커가 뜯긴 상태
        // 2: 왼쪽 두번째 칸의 스티커가 뜯긴 상태
        for(int i=0; i<n; i++){

            // i번째 열에서 스티커를 선택하지 않는 경우
            // i-1 열에서 
            // 아무 스티커도 선택하지 않거나, 
            // 첫 번째 또는 두 번째 스티커를 선택한 상태에서의 최대 점수를 비교
            // i번째 열에서 스티커를 선택하지 않았더라도, i-1번째 선택의 영향을 받게 됨.
            dp[i + 1][0] = max(dp[i + 1][0], max(dp[i][0], max(dp[i][1], dp[i][2])));

            // i번째 열에서 첫 번째 줄 스티커를 선택하는 경우
            // i-1 열에서 스티커를 선택하지 않거나 
            // 두 번째 줄 스티커를 선택한 상태에서 i 열의 첫 번째 줄 스티커 값을 더한 최대 점수를 비교
            dp[i + 1][1] = max(dp[i + 1][1], max(dp[i][0], dp[i][2]) + stk[0][i]);

            // i번째 열에서 두 번째 줄 스티커를 선택하는 경우
            // 위와 마찬가지로 진행
            dp[i + 1][2] = max(dp[i + 1][2], max(dp[i][0], dp[i][1]) + stk[1][i]);
        }

        // 스티커 점수의 최대값은 n번째에 저장되어 있음.
        cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << "\n";
    }

    return 0;
=======
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

    
>>>>>>> 019e58d3318b4d8a6560ecea54be18cfc431b805
}