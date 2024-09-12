// ///////////////////////////////

// STL(Standard Template Library)

// ///////////////////////////////

// # library provided by c++

// # vector : variable array? 가변적인 배열?

// e.g.

#include <iostream>
#include <vector>
using namespace std;

void func1(vector<int> v) {
  v[10] = 7;
}
int main(void) {
  vector<int> v(100);
  func1(v);
  cout << v[10];     // result is '0' -> because it is smiliar to structure, so func1 gets copy of vector v
  return 0;
}

bool cmp1(vector<int> v1, vector<int> v2, int idx){
  return v1[idx] > v2[idx];                        // it's time complexity is O(N) because cmp1 copies v1, v2 vector so it takes N times.
                                                   // 위에서 보았듯이 vector는 구조체와 비슷하게 값을 복사해서 넘기는데, 이 복사하는 시간이 N이니깐 시간 복잡도도 O(N)이다.
}

/////// now we can make O(N) to O(1) by using references

// e.g.

bool cmp2(vector<int>& v1, vector<int>& v2, int idx){  // using reference
  return v1[idx] > v2[idx];                        // it's time complexity is O(1) because cmp2 no longer copies entire v1, v2 vector, just address information
                                                   // 더 이상 복사하는 시간이 없기 때문에 주소 정보만을 가지고 단순 비교만 진행되므로 시간 복잡도가 O(1ㅈ)이다.
}


// ////////////////////////////////

// examples

// ////////////////////////////////

// sort(배열의 시작점 주소 a, 배열의 마지막 주소+1 a+10) // a~a+10 즉 a부터 10개의 원소가 있는 배열을 정렬시켜줌 
// reverse(시작반복자 a, 종료 반복자 b);  // a~b번째 원소에 대해서 순서를 거꾸로 뒤집어 준다.