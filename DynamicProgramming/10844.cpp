#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1000000000;

static long long countStairNumbers(int N) {
    long long dp[101][10] = { 0, };

    for (int i = 1; i <= 9; i++) {
        dp[1][i] = 1;
    }

    for (int len = 2; len <= N; len++) {
        for (int digit = 0; digit <= 9; digit++) {
            if (digit == 0) {
                dp[len][0] = dp[len - 1][1] % MOD;
            }
            else if (digit == 9) {
                dp[len][9] = dp[len - 1][8] % MOD;
            }
            else {
                dp[len][digit] = (dp[len - 1][digit - 1] + dp[len - 1][digit + 1]) % MOD;
            }
        }
    }

    long long totalCount = 0;
    for (int i = 0; i <= 9; i++) {
        totalCount = (totalCount + dp[N][i]) % MOD;
    }

    return totalCount;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (cin >> N) {
        cout << countStairNumbers(N) << endl;
    }

    return 0;
}