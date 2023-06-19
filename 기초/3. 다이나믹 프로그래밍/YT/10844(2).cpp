/*
처음에는 규칙을 찾아서 점화식 형태로 문제를 풀려고 했는데, 하다 보니 한계가 있었다.
수가 너무 커지게 되면 실제 결과값과 오차가 생겨버렸다.

dp[i][j]는 i자리의 수일 때 끝자리가 j인 경우의 개수를 의미한다.
자리수가 추가되면 끝자리가 0이거나 9인 경우는 그 전의 자리수 개수와 같지만,
나머지 경우에는 경우의 수가 +-의 두갈래로 뻗어나가기 때문에 이를 더해주면 된다.
*/

#include <iostream>
#include <vector>

#define mod 1000000000
using namespace std;

int dp[101][10];

int main() {
  int n;
  cin >> n;

  for (int i = 1; i < 10; i++) {
    dp[1][i] = 1;
  }

  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < 10; j++) {
      if (j == 0)
        dp[i][0] = dp[i - 1][j + 1];
      else if (j == 9)
        dp[i][9] = dp[i - 1][j - 1];
      else
        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];

      dp[i][j] %= mod;
    }
  }

  int result = 0;
  for (int i = 0; i < 10; i++) {
    result = (result + dp[n][i]) % mod;
  }
  cout << result << "\n";

  return 0;
}