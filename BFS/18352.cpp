#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, K, X;
vector<vector<int>> graph;
vector<int> dist;

void bfs(int start) {
    queue<int> q;
    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur]) {
            if (dist[next] == -1) {
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K >> X;

    graph.resize(N + 1);
    dist.assign(N + 1, -1);

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
    }

    bfs(X);

    bool found = false;
    for (int i = 1; i <= N; i++) {
        if (dist[i] == K) {
            cout << i << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << -1 << "\n";
    }

    return 0;
}
