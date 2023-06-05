#include <iostream>

using namespace std;

int N, minSum = 2147483647;
int route[10];
int map[10][10];
bool visited[10];

void solution(int curr) {
  if (curr == N) {
    if (map[route[curr - 1]][route[0]] != 0) {
      int sum = 0;
      for (int i = 0; i < N - 1; i++) {
        sum += map[route[i]][route[i + 1]];
      }
      sum += map[route[curr - 1]][route[0]];
      if (sum < minSum)
        minSum = sum;
    }
    return;
  }

  for (int i = 0; i < N; i++) {
    if (visited[i] == true || (curr > 0 && map[route[curr - 1]][i] == 0))
      continue;
    route[curr] = i;
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
    for (int j = 0; j < N; j++) {
      cin >> map[i][j];
    }
  }

  solution(0);
  cout << minSum << '\n';

  return 0;
}