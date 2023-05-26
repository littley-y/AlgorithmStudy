#include <iostream>

using namespace std;

int N, sum, maxSum;
int T[16], P[16];

void solution(int curr) {
  if (sum > maxSum)
    maxSum = sum;

  for (int i = curr; i < N; i++) {
    if (i + T[i] > N)
      continue;
    sum += P[i];
    solution(i + T[i]);
    sum -= P[i];
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> T[i] >> P[i];
  }

  solution(0);
  cout << maxSum << '\n';

  return 0;
}