#include <iostream>

using namespace std;

const int MAXN = 1'000'000;

int parent[MAXN + 1];
int rankArr[MAXN + 1];

// 경로 압축
static int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

// 랭크 기반 합치기
static void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return;

    if (rankArr[a] < rankArr[b]) {
        parent[a] = b;
    }
    else if (rankArr[a] > rankArr[b]) {
        parent[b] = a;
    }
    else {
        parent[b] = a;
        rankArr[a]++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i <= n; ++i) {
        parent[i] = i;
        rankArr[i] = 0;
    }

    while (m--) {
        int op, a, b;
        cin >> op >> a >> b;

        if (op == 0) {
            unite(a, b);
        }
        else {
            if (find(a) == find(b))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}