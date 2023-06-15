#include <iostream>

using namespace std;

int N, dp[101][10];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  dp[1][1] = 1;
  dp[1][2] = 1;
  dp[1][3] = 1;
  dp[1][4] = 1;
  dp[1][5] = 1;
  dp[1][6] = 1;
  dp[1][7] = 1;
  dp[1][8] = 1;
  dp[1][9] = 1;
  for (int index = 2; index <= 100; ++index)
  {
    dp[index][0] = dp[index - 1][1] % 1000000000;
    dp[index][1] = (dp[index - 1][0] + dp[index - 1][2]) % 1000000000;
    dp[index][2] = (dp[index - 1][1] + dp[index - 1][3]) % 1000000000;
    dp[index][3] = (dp[index - 1][2] + dp[index - 1][4]) % 1000000000;
    dp[index][4] = (dp[index - 1][3] + dp[index - 1][5]) % 1000000000;
    dp[index][5] = (dp[index - 1][4] + dp[index - 1][6]) % 1000000000;
    dp[index][6] = (dp[index - 1][5] + dp[index - 1][7]) % 1000000000;
    dp[index][7] = (dp[index - 1][6] + dp[index - 1][8]) % 1000000000;
    dp[index][8] = (dp[index - 1][7] + dp[index - 1][9]) % 1000000000;
    dp[index][9] = dp[index - 1][8] % 1000000000;
  }
  cin >> N;

  cout << ((long long)dp[N][0] + dp[N][1] + dp[N][2] + dp[N][3] + dp[N][4] + dp[N][5] + dp[N][6] + dp[N][7] + dp[N][8] + dp[N][9]) % 1000000000 << '\n';

  return (0);
}

// 1 2 3 4 5 6 7 8 9 9

// 10 12, 21 23, 32 34, 43 45, 54 56, 65 67, 76 78, 87 89, 98 17

// 101 121 123, 210 212 232 234, 321 323 343 345, ... 987 989 33

//
