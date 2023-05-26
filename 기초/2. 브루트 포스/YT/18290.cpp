/*
맨 처음에 풀이했을때 틀렸는데 알고보니 N이 세로고 M이 가로여서 그랬다..
최적화를 해주기 위해서 isValid의 조건을 좀 수정하고,
좌표를 pair로 기록하는 대신 sum을 더하는 방식으로 바꿨다.
*/

#include <iostream>

using namespace std;

int N, M, K, sum;
int maxSum = -40001;
int board[10][10];
bool visited[10][10];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};

bool isValid(int curr, int x, int y) {
  if (visited[y][x] == true)
    return false;

  for (int i = 0; i < 4; i++) {
    int cx = x + dx[i];
    int cy = y + dy[i];
    if (cx < 0 || cy < 0 || cx == M || cy == N)
      continue;
    if (visited[cy][cx] == true)
      return false;
  }
  return true;
}

void solution(int curr, int x, int y) {
  if (curr == K) {
    if (sum > maxSum) {
      maxSum = sum;
    }
    return;
  }

  for (int i = y; i < N; i++) {
    for (int j = x; j < M; j++) {
      if (isValid(curr, j, i) == false)
        continue;
      visited[i][j] = true;
      sum += board[i][j];
      if (x + 1 < M)
        solution(curr + 1, x + 1, y);
      else
        solution(curr + 1, 0, y + 1);
      visited[i][j] = false;
      sum -= board[i][j];
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> K;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
    }
  }

  solution(0, 0, 0);
  cout << maxSum << '\n';

  return 0;
}