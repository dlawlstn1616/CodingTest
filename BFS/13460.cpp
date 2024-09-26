#include <iostream>
#include <queue>

using namespace std;

// 코드 구조는 삼성 코딩테스트를 진행할 때, 사용하는 코드 구조를 그대로 가져왔습니다.
// main 함수, solution 함수, 연산 함수로 기본적으로 세팅이 되어 있습니다.
// 임의로 변경할 수 있도록 제공됩니다. 다만 삼성 코테 문제집임을 고려해서 구조를 유지합니다.


// BFS를 하기 위해서 구조체를 선언
// 보드를 기울이면 빨간 구슬과 파란 구슬이 같이 움직임
// 둘의 x,y 좌표가 각각 필요 
// Rx,Ry는 빨간 구슬, Bx, By는 파란 구슬 좌표
// 이동한 횟수 카운트를 위한 Count
struct step
{
    int Rx, Ry;
    int Bx, By;
    int Count;
};

// N, M의 최대값이 10
// 입력을 받기위한 map과 방문지점 체크를 위한 visit
// 위, 양옆, 아래 방문을 위한 dx, dy
int N,M;
char map[11][11];
bool visit[11][11][11][11];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// 보드의 이동에 따른 구슬의 움직임 계산
// #은 벽이고, O은 구멍이므로 더 이상 움직이지 않음
// 이동한 거리를 측정해서 좌표 업데이트
void move(int& rx, int& ry, int& distance, int& i)
{
    while(map[rx + dx[i]][ry + dy[i]] != '#' && map[rx][ry] != 'O')
    {
        rx += dx[i];
        ry += dy[i];
        distance += 1;
    }
}

// BFS 정의
void BFS(int Rx, int Ry, int Bx, int By)
{
    // 큐에 step을 삽입
    queue<step> q;
    q.push({Rx, Ry, Bx, By, 0});
    visit[Rx][Ry][Bx][By] = true;

    // 구슬의 위치를 큐에서 가져옴
    while(!q.empty())
    {
        int rx = q.front().Rx;
        int ry = q.front().Ry;
        int bx = q.front().Bx;
        int by = q.front().By;
        int count = q.front().Count;
        q.pop();

        // 10번 이하로 탈출 실패
        if(count >= 10) break;

        // 보드를 기울이는거에 따른 움직임 계산
        for(int i=0; i<4; i++)
        {
            int nrx = rx, nry = ry, nbx = bx, nby = by;
            int ncount = count + 1;
            int rc = 0, bc = 0;

            move(nrx, nry, rc, i);
            move(nbx, nby, bc, i);

            // 파란구슬은 구멍에 들어가면 실패 -> 반복문 종료
            if(map[nbx][nby] == 'O') continue;
            // 빨간 구슬이 구멍이 들어가서 움직임 횟수를 출력하고 종료
            if(map[nrx][nry] == 'O')
            {
                cout << ncount;
                return;
            }
            
            // 빨간 구슬과 파란 구슬이 충돌했을 시, 좌표 재조정
            if(nrx == nbx && nry == nby)
            {
                if(rc > bc) nrx -= dx[i], nry -= dy[i];
                else nbx -= dx[i], nby -= dy[i];
            }

            // 이미 탐색한 경로인 경우 큐에 삽입하지 않고 반복문 종료
            if(visit[nrx][nry][nbx][nby]) continue;

            // 탐색한 경로임을 visit에 저장하고 현재 위치를 큐에 삽입
            visit[nrx][nry][nbx][nby] = true;
            q.push({nrx, nry, nbx, nby, ncount});
        }
    }

    // 10회 초과되어 반복문에서 탈출했으니 실패인 -1을 출력
    cout << -1;
}

// map에 입력을 받고, 빨간 구슬과 파란 구슬의 위치를 저장함
void Solution()
{
    int Rx, Ry, Bx, By;
    cin >> N >> M;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin >> map[i][j];

            if(map[i][j] == 'R')
                Rx = i, Ry = j;
            else if(map[i][j] == 'B')
                Bx = i, By = j;
        }
    }
    BFS(Rx, Ry, Bx, By);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution();

    return 0;
}