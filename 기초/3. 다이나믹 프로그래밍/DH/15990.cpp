#include <iostream>

using namespace std;

long long T, dp[100001][4];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  dp[1][1] = 1;
  dp[2][2] = 1;
  dp[3][1] = dp[3][2] = dp[3][3] = 1;

  for (int index = 4; index <= 100000; ++index)
  {
    dp[index][1] = (dp[index - 1][2] + dp[index - 1][3]) % 1000000009;
    dp[index][2] = (dp[index - 2][1] + dp[index - 2][3]) % 1000000009;
    dp[index][3] = (dp[index - 3][1] + dp[index - 3][2]) % 1000000009;
  }

  cin >> T;

  int tmp;
  while (T--)
  {
    cin >> tmp;
    cout << (long long)(dp[tmp][1] + dp[tmp][2] + dp[tmp][3]) % 1000000009 << '\n';
  }

  return (0);
}
