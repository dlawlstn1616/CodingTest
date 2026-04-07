#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> graph;
vector<int> visited;
vector<int> result;
int visit_id = 1;

int bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = visit_id;
    int cnt = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur]) {
            if (visited[next] != visit_id) {
                visited[next] = visit_id;
                q.push(next);
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    graph.resize(N + 1);
    visited.resize(N + 1, 0);

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        graph[B].push_back(A);
    }

    int max_cnt = 0;
    vector<int> cnt(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        cnt[i] = bfs(i);
        max_cnt = max(max_cnt, cnt[i]);
        visit_id++;
    }

    for (int i = 1; i <= N; i++) {
        if (cnt[i] == max_cnt) {
            cout << i << " ";
        }
    }

    return 0;
