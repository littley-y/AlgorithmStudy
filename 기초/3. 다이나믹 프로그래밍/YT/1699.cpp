#include <iostream>

using namespace std;

int N;
int DP[100001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 1; i <= N; i++) {
    DP[i] = i;
    for (int j = 1; j * j <= i; j++) {
      DP[i] = min(DP[i], DP[i - j * j] + 1);
    }
  }
  cout << DP[N] << '\n';

  return 0;
}