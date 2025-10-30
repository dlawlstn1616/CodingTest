#include <iostream>
#include <vector>
using namespace std;

static int board[1002][1002];

int main(int argc, char* argv[]){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    for (int i = 0; i <= 1001; ++i) {
        for (int j = 0; j <= 1001; ++j) board[i][j] = 0;
    }
    
    struct Rect{int x, y, w, h;};
    vector<Rect> rects(N+1); 
    int maxX = 0, maxY = 0;
    
    for(int i = 1; i <= N; ++i){
        int x,y,w,h;
        cin >> x >> y >> w >> h;
        rects[i] = {x,y,w,h};
        maxX = max(maxX, x + w);
        maxY = max(maxY, y + h);
    }
    
    for(int i = 1; i <= N; ++i){
        int x = rects[i].x;
        int y = rects[i].y;
        int w = rects[i].w;
        int h = rects[i].h;
        
        for (int xi = x; xi < x + w; ++xi) {
            for (int yi = y; yi < y + h; ++yi) {
                board[xi][yi] = i;
            }
        }
    }
    
    vector<int> area(N+1, 0);
    for (int xi = 0; xi < maxX; ++xi) {
        for (int yi = 0; yi < maxY; ++yi) {
            int idx = board[xi][yi];
            if (idx > 0) area[idx]++;
        }
    }

    for (int i = 1; i <= N; ++i) {
        cout << area[i] << '\n';
    }
    
    return 0;
}