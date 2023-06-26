#include <iostream>

using namespace std;

int N, schedule[16][2], dp[17];

int getMax(void) {
  int max_sum = 0;
  for (int index = 1; index <= N + 1; ++index) {
    max_sum = max(max_sum, dp[index]);
  }
  return max_sum;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;

  for (int index = 1; index <= N; ++index)
  {
    cin >> schedule[index][0];
    cin >> schedule[index][1];
  }

  for (int index = 1; index <= N; ++index) {
    for (int loop = 0; index + schedule[index][0] + loop <= N + 1; ++loop) {
        dp[index + schedule[index][0] + loop]  = max(dp[index + schedule[index][0] + loop], schedule[index][1] + dp[index]);
    }
  }

  cout << getMax() << '\n';

  return (0);
}
