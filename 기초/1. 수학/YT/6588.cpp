/*
시간초과가 나는 이유는 소수를 채울 때 연산량이 너무 많아서 그렇다.
이때는 에라토스테네스의 체를 이용하면 된다.

1. i = 2부터 시작해 i * i <= ARR_MAX 까지 i의 배수를 모두 체크
2. 체크를 할 때, j = i * i 부터 시작할 수 있다.
3. 조건을 잘 생각하자(arr[a] == true면 소수가 아니라는 뜻).
*/

#include <iostream>

using namespace std;

int n;
const int ARR_MAX = 1000001;
int arr[ARR_MAX] = {0};

void fillPrime() {
  for (int i = 2; i * i <= ARR_MAX; i++) {
    if (arr[i])
      continue;
    for (int j = i * i; j < ARR_MAX; j += i) {
      arr[j] = 1;
    }
  }
}

void solution() {
  int a = 3, b = n - a;
  while (a + b == n && arr[b]) {
    a += 2;
    while (arr[a])
      a += 2;
    b = n - a;
  }
  cout << n << " = " << a << " + " << b << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  fillPrime();

  while (true) {
    cin >> n;
    if (n == 0)
      break;
    solution();
  }
  return 0;
}