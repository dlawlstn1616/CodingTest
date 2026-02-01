#include <iostream>

using namespace std;

int n;
int answer = 0;

bool isUsed1[40];
bool isUsed2[40]; // (/) -> x + y
bool isUsed3[40]; // (\) -> x - y + n - 1

static void findQueen(int cur) {
    if (cur == n) {
        answer++;
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (isUsed1[i] == true || isUsed2[cur + i] == true || isUsed3[cur - i + n - 1] == true)
            continue;

        isUsed1[i] = true;
        isUsed2[cur + i] = true;
        isUsed3[cur - i + n - 1] = true;

        findQueen(cur + 1);

        isUsed1[i] = false;
        isUsed2[cur + i] = false;
        isUsed3[cur - i + n - 1] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    findQueen(0);

    cout << answer << "\n";

    return 0;
}