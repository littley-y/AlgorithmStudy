#include <iostream>

using namespace std;

int N, sequence[1001], dp[1001][1001];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;

  for (int index = 1; index <= N; ++index)
    cin >> sequence[index];

  int max_len = 0, max_index = 0;;

  for (int index = 1; index <= N; ++index)
  {
    for (int loop = 0; loop < index; ++loop)
    {
      if (sequence[loop] < sequence[index])
      {
        if (dp[index][0] < dp[loop][0] + 1)
        {
          dp[index][0] = dp[loop][0] + 1;
          int fill = 1;
          for (; dp[loop][fill]; ++fill)
          {
            dp[index][fill] = dp[loop][fill];
          }
          dp[index][fill] = sequence[index];
        }
      }
    }
    if (max_len < dp[index][0])
    {
      max_len = dp[index][0];
      max_index = index;
    }
  }

  cout << max_len << '\n';
  for (int index = 1; dp[max_index][index]; ++index)
   cout << dp[max_index][index] << ' ';
  cout << '\n';

  return (0);
}
