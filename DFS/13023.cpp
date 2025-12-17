#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief 인접 리스트 형태의 무방향 그래프
 * graph[i] : 정점 i와 연결된 모든 정점 목록
 */
vector<int> graph[2000];

/**
 * @brief DFS 경로 상에서의 방문 여부 체크 배열
 * 같은 경로에서 정점을 중복 방문하지 않기 위함
 */
bool isVisited[2000];

/**
 * @brief 길이 4의 친구 관계(A-B-C-D-E)가 존재하는지 여부
 * true가 되는 순간 탐색을 즉시 중단한다.
 */
bool check;

/**
 * @brief DFS를 이용해 특정 길이의 경로가 존재하는지 탐색
 *
 * @param cur    현재 방문 중인 정점
 * @param len    현재까지 이동한 간선 수
 * @param target 목표 간선 수 (문제에서는 4)
 *
 * @details
 * - 이미 check가 true이면 더 이상의 탐색은 불필요하므로 즉시 return
 * - len == target에 도달하면 조건을 만족하므로 check를 true로 설정
 * - 방문 배열을 이용해 같은 경로에서 정점 중복 방문 방지
 */
static void dfs(int cur, int len, int target) {

	// 이미 답을 찾았다면 더 이상 DFS 진행하지 않음
	if (check == true) return;

	// 목표 길이에 도달 → 조건 만족
	if (len == target) {
		check = true;
		return;
	}

	// 현재 정점과 연결된 모든 정점 탐색
	for (int next : graph[cur]) {
		if (!isVisited[next]) {
			isVisited[next] = true;
			dfs(next, len + 1, target);
			isVisited[next] = false; // 백트래킹
		}
	}
}

/**
 * @brief 프로그램 진입점
 *
 * @details
 * - 그래프를 입력받아 인접 리스트로 구성
 * - 모든 정점을 시작점으로 DFS 수행
 * - 길이 4의 경로가 존재하면 1, 아니면 0 출력
 */
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	// 친구 관계 입력 (무방향 그래프)
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	// 모든 정점을 시작점으로 DFS 시도
	for (int i = 0; i < n; ++i) {
		isVisited[i] = true;
		dfs(i, 0, 4);
		isVisited[i] = false;

		if (check == true) {
			cout << 1;
			return 0;
		}
	}

	cout << 0;
	return 0;
}
