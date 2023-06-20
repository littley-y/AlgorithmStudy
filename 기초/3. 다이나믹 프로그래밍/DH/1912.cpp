#include <iostream>

using namespace std;

int n, sequence[1000001], dp[1000001];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  for (int index = 1; index <= n; ++index)
    cin >> sequence[index];

  int max_sum = -2147483648;
  for (int index = 1; index <= n; ++index)
  {
    dp[index] = max(sequence[index], dp[index - 1] + sequence[index]);
    max_sum = max(max_sum, dp[index]);
  }

  cout << max_sum << '\n';

  return (0);
}
