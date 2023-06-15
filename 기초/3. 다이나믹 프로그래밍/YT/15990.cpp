/*
풀이를 참고해보니 DP를 2중 배열 형식으로 만들어서 사용한다는 거를 알 수 있었다.
연속으로 같은 숫자를 사용하지 못하기 때문에 마지막에 오는 숫자를 배열로 구분한다.

마지막으로 오는 수가 1이면? 그 앞에 올 수 있는 숫자는 2 또는 3이 된다.
마지막으로 오는 수가 2이면? 그 앞에 올 수 있는 숫자는 1 또는 3이 된다.
마지막으로 오는 수가 3이면? 그 앞에 올 수 있는 숫자는 1 또는 2이 된다.

D[n][i]를 마지막에 오는 수가 i일 때, 숫자의 합으로 정수 n을 만드는 케이스라 하자. 그러면

D[n][1] = D[n - 1][2] + D[n - 1][3]
D[n][2] = D[n - 2][1] + D[n - 2][3]
D[n][3] = D[n - 3][1] + D[n - 3][2]
현재 총 경우의 수 = D[n][1] + D[n][2] + D[n][3]
*/

#include <iostream>

using namespace std;

const int ARR_MAX = 100001;
int T;
long long dp[ARR_MAX][4];

void solution() {
  dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;
  for (int i = 4; i <= ARR_MAX; i++) {
    dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % 1000000009;
    dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % 1000000009;
    dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % 1000000009;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  solution();

  cin >> T;
  for (int i = 0; i < T; i++) {
    int n;
    cin >> n;
    cout << (dp[n][1] + dp[n][2] + dp[n][3]) % 1000000009 << '\n';
  }
  return 0;
}
