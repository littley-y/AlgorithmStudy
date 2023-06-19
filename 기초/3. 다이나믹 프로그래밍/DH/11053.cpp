#include <iostream>

using namespace std;

int N, sequence[1001], dp[1001];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;

  for (int index = 1; index <= N; ++index)
    cin >> sequence[index];

  dp[1] = 1;
  int max_len = 0;
  for (int index = 1; index <= N; ++index)
  {
    for (int loop = 0; loop <= index; ++loop)
    {
      if (sequence[index] > sequence[loop])
      {
        if (dp[index] < dp[loop] + 1)
          dp[index] = dp[loop] + 1;
      }
    }
    if (dp[index] > max_len)
    {
      max_len = dp[index];
    }
  }

  cout << max_len << '\n';

  return (0);
}
