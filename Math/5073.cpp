#include <iostream>
#include <algorithm>

using namespace std;

void Solution(int a, int b, int c)
{
    if(c >= a+b)
        cout << "Invalid" << "\n";
    else if(a==b && b==c)
        cout << "Equilateral" << "\n";
    else if(a==b || b==c || a==c)
        cout << "Isosceles" << "\n";
    else
        cout << "Scalene" << "\n";
}

int main(int argc, char* argv[])
{
    int a,b,c,num[3];

    while(1) {
        cin >> num[0] >> num[1] >> num[2];
        sort(num, num+3);
        a = num[0], b = num[1], c = num[2];

        if(a==0 && b==0 && c==0)
            break;

        Solution(a,b,c);
    }
    return 0;
}