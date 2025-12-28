#include <iostream>
#include <vector>
using namespace std;

// DFS를 수행하기 위해 vector와 visited 배열을 선언
vector<int> graph[1001];
bool visited[1001];

// DFS 함수 정의
// node는 현재 방문 중인 노드
// 방문하지 않은 인접 노드를 재귀적으로 방문
// 방문한 노드는 visited 배열에 true로 표시
// 그래프의 모든 노드를 방문할 때까지 반복
void DFS(int node){
    visited[node] = true;

    for(int neighbor : graph[node]){
        if(!visited[neighbor]){
            DFS(neighbor);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // 그래프의 간선 정보를 입력받아 인접 리스트를 구성
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // 모든 노드를 순회하며 방문하지 않은 노드에서 DFS를 시작
    int component_count = 0;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            DFS(i);
            component_count++;
        }
    }

    cout << component_count << '\n';

    return 0;
}