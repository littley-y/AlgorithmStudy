/*
이 문제는 유클리드 호제법을 이용해서 풀면 된다.
https://sectumsempra.tistory.com/77

1. 큰 숫자를 작은 숫자로 나눈 나머지 = r
2. 1의 값으로 작은 숫자 다시 나눔
3. 나머지가 0이 되면 탈출하고, 이때 나눈 값이 최대공약수
*/

#include <iostream>
#include <vector>

using namespace std;

int A, B;

int gcd(int a, int b) {
  int r = a % b;
  if (r == 0) {
    return b;
  }
  return gcd(b, r);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> A >> B;

  int C = gcd(A, B);
  cout << C << '\n' << A * B / C << '\n';
  return 0;
}
