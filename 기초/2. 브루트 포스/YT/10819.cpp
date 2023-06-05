#include <iostream>

using namespace std;

int N, maxSum = 0;
int arr[8], ans[8];
bool visited[8];

void solution(int curr) {
  if (curr == N) {
    int sum = 0;
    for (int i = 0; i < N - 1; i++) {
      sum += abs(ans[i + 1] - ans[i]);
    }
    if (sum > maxSum)
      maxSum = sum;
    return;
  }

  for (int i = 0; i < N; i++) {
    if (visited[i] == true)
      continue;
    ans[curr] = arr[i];
    visited[i] = true;
    solution(curr + 1);
    visited[i] = false;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  solution(0);
  cout << maxSum << '\n';

  return 0;
}