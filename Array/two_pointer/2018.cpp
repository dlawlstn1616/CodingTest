#include <iostream>

using namespace std;

static int countConsecutiveSum(int N) {
    int count = 1;
    int start = 1;
    int end = 1;
    int sum = 1;

    while (end != N) {
        if (sum == N) {
            count++;
            end++;
            sum += end;
        }
        else if (sum > N) {
            sum -= start;
            start++;
        }
        else {
            end++;
            sum += end;
        }
    }

    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    cout << countConsecutiveSum(N) << endl;

    return 0;
}