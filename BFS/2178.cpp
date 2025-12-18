#include <iostream>
#include <queue>
#include <string>

using namespace std;

/**
 * @brief 미로의 세로(N), 가로(M) 크기
 */
int n, m;

/**
 * @brief 미로 정보
 *        1: 이동 가능, 0: 이동 불가
 *        BFS 수행 시 거리 정보로 재활용
 *        인덱스는 1-based 사용
 */
int maze[101][101];

/**
 * @brief 상하좌우 이동을 위한 방향 벡터
 *        Flash에 저장되어 RAM 절약
 */
static const int dx[4] = { 1, -1, 0, 0 };
static const int dy[4] = { 0, 0, 1, -1 };

/**
 * @brief BFS를 이용해 (1,1)에서 (n,m)까지의 최단 거리 계산
 *
 * maze 배열을 거리 저장용으로 재활용하여 RAM 사용 최소화.
 * 도착 지점에 도달하면 즉시 종료하여 불필요한 탐색 방지.
 */
void BFS() {
    queue<pair<int, int>> q;
    q.push({ 1, 1 });

    // 시작점 거리 초기화
    maze[1][1] = 1;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 범위를 벗어나면 무시
            if (nx < 1 || nx > n || ny < 1 || ny > m)
                continue;

            // 이동 가능 + 미방문
            if (maze[nx][ny] == 1) {
                maze[nx][ny] = maze[x][y] + 1;

                // 목적지 도달 시 즉시 종료
                if (nx == n && ny == m)
                    return;

                q.push({ nx, ny });
            }
        }
    }
}

/**
 * @brief 프로그램 진입점
 *
 * 미로를 입력받고 BFS 수행 후 (n,m)까지의 최단 거리 출력
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    // 미로 입력 (문자열 → 정수 변환)
    // 입력이 붙어서 오기 때문에
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
            maze[i][j + 1] = s[j] - '0';
    }

    BFS();
    cout << maze[n][m] << "\n";

    return 0;
}
