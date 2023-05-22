/*
맨 처음에는 단순 덧셈으로 해결하려고 했고
그 다음에는 visited 배열 이용해서 이미 탐색한 점을 체크하는 식으로 하려고 했는데
둘다 시간초과가 떴다.
풀이를 찾아보니 최소공배수를 이용하는 방식으로 하면 된다.

1. M과 N의 최소공배수를 구한다. 이것이 루프의 최대값이 된다.
2. i를 x로 고정시켜놓고, i년일때 i를 n으로 나눈 나머지값(ny)을 확인한다.
3. y가 1부터 시작하기 때문에 ny == 0이면 y는 최대값(N)이라는 의미.
4. ny == y이면 원하는 y값을 찾았다는 의미이므로 종료.
*/

#include <cstring>
#include <iostream>

using namespace std;

int T, M, N, x, y;

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int lcm(int a, int b) { return (a * b) / gcd(a, b); }

void solution() {
  int ans = -1;
  int maxI = lcm(M, N);
  for (int i = x; i <= maxI; i += M) {
    int ny = i % N;
    if (ny == 0)
      ny = N;
    if (ny == y) {
      ans = i;
      break;
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> M >> N >> x >> y;
    solution();
  }

  return 0;
}