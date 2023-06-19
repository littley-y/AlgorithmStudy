#include <iostream>

using namespace std;

int N;
long dp[91][2];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  dp[1][1] = 1;
  dp[2][0] = 1;

  for (int i = 3; i <= N; i++) {
    dp[i][0] = dp[i - 1][1] + dp[i - 1][0];
    dp[i][1] = dp[i - 1][0];
  }

  cout << dp[N][0] + dp[N][1] << '\n';
  return 0;
}

/*
1 -> 10

10 -> 100, 101

100 -> 1001, 1000

101 -> 1010

1000 -> 10000, 10001

1001 -> 10010

1010 -> 10100, 10101

끝의 자리가 0이면 그 다음에는 0과 1 둘다 올 수 있다.
끝의 자리가 1이면 그 다음에는 0만 올 수 있다.
*/