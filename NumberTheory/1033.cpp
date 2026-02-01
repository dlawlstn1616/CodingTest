#include <iostream>
#include <vector>

using namespace std;

long long getGCD(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long getLCM(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    return (a * b) / getGCD(a, b);
}

struct Edge {
    int target;
    int p, q;
};

int N;
vector<Edge> adj[10];
long long mass[10];
bool visited[10];

void dfs(int cur) {
    visited[cur] = true;

    for (const auto& edge : adj[cur]) {
        int next = edge.target;
        int p = edge.p;
        int q = edge.q;

        if (!visited[next]) {
            long long numerator = mass[cur] * q;

            if (numerator % p != 0) {

                long long scaler = p / getGCD(numerator, p);

                for (int i = 0; i < N; i++) {
                    mass[i] *= scaler;
                }

                numerator = mass[cur] * q;
            }

            mass[next] = numerator / p;

            dfs(next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int a, b, p, q;
        cin >> a >> b >> p >> q;

        int common = getGCD(p, q);
        p /= common;
        q /= common;

        adj[a].push_back({ b, p, q });
        adj[b].push_back({ a, q, p });
    }

    mass[0] = 1;
    dfs(0);

    long long globalGCD = mass[0];
    for (int i = 1; i < N; i++) {
        globalGCD = getGCD(globalGCD, mass[i]);
    }

    for (int i = 0; i < N; i++) {
        cout << mass[i] / globalGCD << " ";
    }
    cout << endl;

    return 0;
}