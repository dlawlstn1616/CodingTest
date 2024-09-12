#include <iostream>

using namespace std;

void func1(int a) {
  a = 5;
}
int main(void) {
  int t = 0;
  func1(t);
  cout << t;       // t = 0 -> func1 just copy variable int a's value 단순히 a의 값을 복사한 값으로 처리했기에 반영이 되지 x
  return 0;
}

void func2(int arr[]) {
  arr[0] = 10;
}
int main(void) {
  int arr[3] = {1,2,3};
  func2(arr);
  cout << arr[0];    // arr[0] = 10 -> func2 gets address of arr[3] 배열을 넘겨주면 배열의 시작주소를 넘겨주게 되니 반영 
  return 0;
}

// -> So we should use pointer!!

// //////////////////////////////

// Reference

// //////////////////////////////

// we can use reference instead of pointer in c++

// e.g.
void swap1(int* a, int* b) {
  int c = *a;
  *a = *b;
  *b = c;
}

void swap2(int& a, int& b) {     // & : reference!!
  int c = a;
  a = b;
  b = c;
}

//swap1 and swap2 get same results!!!! 