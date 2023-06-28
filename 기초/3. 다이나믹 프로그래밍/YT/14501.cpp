#include <iostream>

using namespace std;

int N;
int T[16];
int P[16];
int DP[16];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> T[i] >> P[i];
  }

  for (int i = N; i >= 1; i--) {
    if (i + T[i] > N + 1) {
      DP[i] = DP[i + 1];
    } else {
      DP[i] = max(DP[i + 1], DP[i + T[i]] + P[i]);
    }
  }
  cout << DP[1] << '\n';

  return 0;
}
