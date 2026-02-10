#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

struct Edge {
    int to;
    long long weight;
};

static vector<long long> dijkstra(int startNode, int n, const vector<vector<Edge>>& adj) {
    vector<long long> dist(n + 1, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

    dist[startNode] = 0;
    pq.push({ 0, startNode });

    while (!pq.empty()) {
        long long currentDist = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        if (dist[currentNode] < currentDist) continue;

        for (const auto& edge : adj[currentNode]) {
            long long nextDist = currentDist + edge.weight;
            if (nextDist < dist[edge.to]) {
                dist[edge.to] = nextDist;
                pq.push({ nextDist, edge.to });
            }
        }
    }
    return dist;
}

static void solve() {
    int N, M, A, B;
    if (!(cin >> N >> M >> A >> B)) return;

    vector<vector<Edge>> adj(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }

    vector<long long> distFromA = dijkstra(A, N, adj);
    vector<long long> distFromB = dijkstra(B, N, adj);

    long long shortestPath = distFromA[B];

    vector<int> resultNodes;
    for (int i = 1; i <= N; ++i) {
        if (distFromA[i] == INF || distFromB[i] == INF) continue;

        if (distFromA[i] + distFromB[i] == shortestPath) {
            resultNodes.push_back(i);
        }
    }

    cout << resultNodes.size() << "\n";
    for (int i = 0; i < resultNodes.size(); ++i) {
        cout << resultNodes[i] << (i == resultNodes.size() - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}