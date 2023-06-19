#include <iostream>

using namespace std;

int N;
long long dp[91][2];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;

  dp[1][1] = 1;
  for (int index = 2; index <= N; index++)
  {
    dp[index][0] = dp[index - 1][0] + dp[index - 1][1];
    dp[index][1] = dp[index - 1][0];
  }

  cout << dp[N][0] + dp[N][1] << '\n';

  return 0;
}
