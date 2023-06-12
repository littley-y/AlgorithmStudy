#include <iostream>

using namespace std;

int N, dp[1000001];

void calculate(void)
{
  for (int num = 2; num <= N; ++num)
  {
    dp[num] = dp[num - 1] + 1;
    if (num % 3 == 0 && dp[num] > dp[num / 3] + 1)
      dp[num] = dp[num / 3] + 1;
    if (num % 2 == 0 && dp[num] > dp[num / 2] + 1)
      dp[num] = dp[num / 2] + 1;
  }
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;

  calculate();

  cout << dp[N] << '\n';

  return (0);
}
