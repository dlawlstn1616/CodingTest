#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]){   
    int R;
    double answer;
    double pi = acos(-1);
    
    cin >> R;
    
    answer = pi * R * R;
    printf("%.6f\n", answer);
    
    answer = R * R * 2;
    printf("%.6f\n", answer);
    
    return 0;
}