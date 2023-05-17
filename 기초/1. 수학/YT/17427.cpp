/*
처음 접근 방식은 일일이 계산해서 모든 수를 더하는 방식이었다.
하지만 자세히 써보면 조건이 있다.

1
1 2
1   3
1 2   4
1       5
1 2 3     6
1           7
1 2   4       8
1   3           9
1 2     5        10

1 = 10 / 1의 몫 개수만큼 있음
2 = 10 / 2의 몫 개수만큼 있음
3 = 10 / 3의 몫 개수만큼 있음
...

이 패턴이 반복되기 때문에 함수를 간단히 만들 수 있다.
*/

#include <iostream>

using namespace std;

int N;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;

  long long ans = 0;
  for (int i = 1; i <= N; i++) {
    ans += (N / i) * i;
  }
  cout << ans << '\n';
  return 0;
}
