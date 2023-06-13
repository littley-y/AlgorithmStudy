#include <iostream>

using namespace std;

int n, dp[1001];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  dp[1] = 1;
  dp[2] = 3;

  for (int num = 3; num <= n; ++num)
  {
    dp[num] = (dp[num - 1] + (dp[num - 2]) * 2) % 10007;
  }

  cout << dp[n] << '\n';

  return (0);
}
