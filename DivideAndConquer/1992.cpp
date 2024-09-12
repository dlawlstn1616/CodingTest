#include <iostream>
#include <string>

// 이름(변수, 함수, 클래스 등)이 충돌하지 않도록 묶어서 관리하는 공간
// Java에서는 상단에 package가 동일한 역할을 수행
// Python에서는 import되는 네임스페이스가 존재
// import math -> math.xxx 
using namespace std;

// new나 malloc을 통해 동적할당 할 수 있으나, 정적 할당이 성능면에서 조금 더 이득
// 다만 재귀함수의 규모가 커지거나 하면 스택 오버플로우가 발생할 수 있으니 주의
// 스택 오버플로우 : 스택(메모리 중에서 함수호출, 지역변수를 저장하는 공간)에 
// 할당된 메모리 이상의 데이터가 쌓이면 발생
int video[64][64];

// 문제해결을 위한 함수
// 4개의 영역으로 나누어 진행
// -> x좌표와 y좌표, 사이즈가 필요함 
// -> 시작 좌표와 좌표 최대값을 설정하기 위해서
// 반복되는 과정 -> 재귀함수로 처리
void compressVideo(int size, int x, int y)
{
    int start = video[x][y];

    for (int i = x; i < x+size; i++)
    {
        for (int j = y; j < y+size; j++)
        {
            if (video[i][j] != start)
            {
                cout << "(";
                compressVideo(size / 2, x, y);
                compressVideo(size / 2, x, y + (size / 2));
                compressVideo(size / 2, x + (size / 2), y);
                compressVideo(size / 2, x + (size / 2), y + (size / 2));
                cout << ")";
                return;
            }
        }
    }
    cout << start;
}

// 메인 함수
int main(int argc, char** argv)
{
    // 기본적으로 C++은 C와 동기화 되어 있음.
    // 표준입출력도 마찬가지인데 C++의 표준입출력(cin, cout)과 
    // C의 표준입출력(scanf, printf)의 순서를 보장하는 기능을 끄는 명령어
    // 더 이상 순서 보장을 하지 않으니 표준입출력의 속도가 향상됨
    ios::sync_with_stdio(false);

    // 기본적으로 cin과 cout은 연결되어 있어 cin이 입력을 받으면 
    // cout은 출력 버퍼에 있는 데이터를 즉시 화면에 출력함
    // -> 입력을 받으면 출력부분이 처리되고 다시 입력을 받게됨.
    // -> 입력이 많으면 출력부분이 처리되는 것을 기다리고 입력을 받게되어 속도가 느려짐
    // -> 성능 향상을 위해 연결을 끊는 것
    // -> 다만 출력 순서 보장이 없어지니 문제가 발생할 수 있음
    cin.tie(nullptr);

    int n;
    string input;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> input;
        for (int j = 0; j < n; j++)
            video[i][j] = input[j] - '0';
    }

    compressVideo(n, 0, 0);

    return 0;
}