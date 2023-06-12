#include <iostream>

using namespace std;

int n, dp[1001];

void  calculate(void)
{
  dp[1] = 1;
  dp[2] = 2;
  for (int num = 3; num <= n; ++num)
  {
    dp[num] = (dp[num - 1] + dp[num - 2]) % 10007;
  }
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  calculate();

  cout << dp[n] << '\n';

  return (0);
}
