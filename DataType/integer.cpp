// /////////////////////////////////////

// integer datatypes

// /////////////////////////////////////

// #char : 1byte -> 8bits
// - unsigned : 0~255
// - signed : -128~127

// e.g.
//  _   _   _   _   _   _   _   _ -> 8bits
// 2^7 2^6 2^5 2^4 2^3 2^2 2^1 2^0
// sign

// #short    : 2bytes -> 2^15-1 = 32767
// #int      : 4bytes -> 2^31-1 = (almost) 2.1 x 10^9
// #longlong : 8bytes -> 2^63-1 = (almost) 9.2 x 10^18

// //////////////////////////////////////

// integer overflow

// //////////////////////////////////////

// -> when an arithmetic operation attempts to create a numeric value that is 
// outside of the range that can be represented with a given number of digits – 
// either higher than the maximum or lower than the minimum representable value.
// 정수 값이 증가하면서 허용된 가장 큰 값보다 더 커져서 실제 저장되는 값은 의도하지 않게 
// 아주 작은 수이거나 음수가 되어 프로그램이 예기치 않게 동작 될 수 있는 보안 취약점

// e.g.
//  01111111 -> 127
// +00000001 -> 1
// =10000000 -> -128  (by signed)

// what we expected -> 128 but result is -128 == causes unexpected results

// //////////////////////////////////////

// code examples

// //////////////////////////////////////

// in c++

#include <iostream>
using namespace std;

void func1() {
  for(char s = 0; s < 128; s++) {
    cout << "hi";
  }
}                        // overflowed!!!!, -128 <= char s <= 127, so when s = 127, s++ results s = -128 -> endless loop
                         // char s -> int s (to solve this overflow problem)

int func2() {
  int r = 1;
  for(int i = 1; i <= 50; i++) {
    r = r * i % 61;
  }
  return r;
}

int func3() {
  int a = 10;
  int mod = 1000000007;
  for(int i = 0; i < 10; i++) {
    a = 10 * a % mod;
  }
  return a;
}                       // overflowed!!!!, when a = 10^9 -> overflowed
                        // int a -> longlong a