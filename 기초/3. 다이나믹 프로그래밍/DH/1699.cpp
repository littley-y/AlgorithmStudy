#include <iostream>
#include <cmath>

using namespace std;

int N, dp[100001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;

  int tmp, square = 1;
  for (int index = 1; index <= N; ++index) {
    dp[index] = index;
    for (int loop = 1; loop * loop <= index; ++loop) {
      dp[index] = min(dp[index], dp[index - loop * loop] + 1);
    }
  }

  cout << dp[N] << '\n';

  return (0);
}

/*
1 1^2
2 1^2 + 1^2
3 1^2 + 1^2 + 1^2
4 2^2
5 2^2 + 1^2
6 2^2 + 1^2 + 1^2
7 2^2 + 1^2 + 1^2 + 1^2
8 2^2 + 2^2

*/
