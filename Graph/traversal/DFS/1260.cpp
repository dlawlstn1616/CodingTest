/**
 * @file dfs_bfs.cpp
 * @brief 그래프를 DFS와 BFS로 탐색하여 방문 순서를 출력하는 프로그램
 *
 * 정점 번호가 작은 것부터 방문하도록 인접 리스트를 정렬한 후,
 * DFS(깊이 우선 탐색)와 BFS(너비 우선 탐색)를 각각 수행한다.
 *
 * BOJ 1260 - DFS와 BFS
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/**
 * @brief 인접 리스트 그래프
 *
 * graph[i]는 정점 i와 연결된 정점들의 리스트를 의미한다.
 */
vector<int> graph[1001];

/**
 * @brief 탐색 결과를 저장하는 벡터
 *
 * DFS 또는 BFS 수행 시 방문한 정점을 순서대로 저장한다.
 */
vector<int> ans;

/**
 * @brief 정점 방문 여부 배열
 *
 * isVisited[i]가 true이면 정점 i는 이미 방문된 상태이다.
 */
bool isVisited[1001];

/**
 * @brief 방문 배열과 결과 벡터를 초기화한다.
 *
 * @param n 정점의 개수 (1 ~ n 까지만 초기화)
 */
static void init(int n) {
    for (int i = 1; i <= n; ++i)
        isVisited[i] = false;
    ans.clear();
}

/**
 * @brief 깊이 우선 탐색(DFS)을 수행한다.
 *
 * 현재 정점을 방문 처리한 뒤,
 * 인접한 정점 중 방문하지 않은 정점을 재귀적으로 탐색한다.
 *
 * @param cur 현재 방문 중인 정점
 */
static void dfs(int cur) {
    isVisited[cur] = true;
    ans.push_back(cur);

    for (int next : graph[cur]) {
        if (!isVisited[next]) {
            dfs(next);
        }
    }
}

/**
 * @brief 너비 우선 탐색(BFS)을 수행한다.
 *
 * 큐(queue)를 사용하여 현재 정점과 인접한 정점들을
 * 가까운 순서(레벨 순서)대로 탐색한다.
 *
 * @param cur 탐색을 시작할 정점
 */
static void bfs(int cur) {
    queue<int> q;

    q.push(cur);
    isVisited[cur] = true;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        ans.push_back(now);

        for (int next : graph[now]) {
            if (!isVisited[next]) {
                isVisited[next] = true;
                q.push(next);
            }
        }
    }
}

/**
 * @brief 프로그램의 시작점
 *
 * 입력으로 그래프를 구성한 뒤,
 * DFS 결과와 BFS 결과를 각각 출력한다.
 *
 * @return 프로그램 종료 상태
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, v;
    cin >> n >> m >> v;

    // 간선 정보 입력 (양방향 그래프)
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // 정점 번호가 작은 것부터 방문하기 위해 정렬
    for (int i = 1; i <= n; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }

    // DFS 수행 및 출력
    init(n);
    dfs(v);
    for (int x : ans) cout << x << " ";
    cout << "\n";

    // BFS 수행 및 출력
    init(n);
    bfs(v);
    for (int x : ans) cout << x << " ";

    return 0;
}
