/*
전 문제 참조를 하려고 했는데, 시간초과가 났다.
여러 테스트 케이스를 출력할 때는 메모리를 기록하는 방식이 좋다.

1. 에라토스테네스의 체 방식을 이용해 f(x)의 값을 기록한다.
2. g(x) = f(x) + g(x - 1) 임을 이용해 메모라이제이션 한다.
*/

#include <iostream>

using namespace std;

const int ARR_MAX = 1000001;
long long arr[ARR_MAX];
int num, N;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for (int i = 1; i < ARR_MAX; i++) {
    for (int j = i; j < ARR_MAX; j += i) {
      arr[j] += i;
    }
  }

  for (int i = 1; i < ARR_MAX; i++) {
    arr[i] += arr[i - 1];
  }

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> num;
    cout << arr[num] << '\n';
  }
  return 0;
}