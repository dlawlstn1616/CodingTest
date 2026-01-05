#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<vector<int>> graph;
vector<int> indegree;
vector<int> buildTime;
vector<int> dp;

vector<int> topologicalSort() {
    queue<int> q;
    vector<int> order;

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        order.push_back(cur);

        for (int next : graph[cur]) {
            if (--indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    return order;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    graph.resize(n + 1);
    indegree.assign(n + 1, 0);
    buildTime.resize(n + 1);
    dp.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> buildTime[i];
        int pre;
        while (cin >> pre) {
            if (pre == -1) break;
            graph[pre].push_back(i); // pre → i
            indegree[i]++;
        }
    }

    vector<int> topo = topologicalSort();

    for (int cur : topo) {
        dp[cur] = max(dp[cur], buildTime[cur]);
        for (int next : graph[cur]) {
            dp[next] = max(dp[next], dp[cur] + buildTime[next]);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dp[i] << '\n';
    }

    return 0;
}
