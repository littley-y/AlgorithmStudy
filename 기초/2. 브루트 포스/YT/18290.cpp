#include <iostream>

using namespace std;

int N, M, K;
int maxSum = -40001;
int board[10][10];
bool visited[10][10];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};
pair<int, int> ans[3];

int calSum() {
  int sum = 0;
  for (int i = 0; i < K; i++) {
    sum += board[ans[i].second][ans[i].first];
  }
  return sum;
}

bool promising(int curr, int x, int y) {
  if (visited[y][x] == true)
    return false;

  for (int i = 0; i < curr; i++) {
    int cx = ans[i].first;
    int cy = ans[i].second;
    for (int j = 0; j < 4; j++) {
      if (x + dx[j] < 0 || y + dy[j] < 0 || x + dx[j] == N || y + dy[j] == M)
        continue;
      if (x + dx[j] == cx && y + dy[j] == cy)
        return false;
    }
  }
  return true;
}

void solution(int curr, int x, int y) {
  if (curr == K) {
    int sum = calSum();
    if (sum > maxSum) {
      maxSum = sum;
    }
    return;
  }

  for (int i = y; i < M; i++) {
    for (int j = x; j < N; j++) {
      if (promising(curr, j, i) == false) {
        continue;
      }
      visited[i][j] = true;
      ans[curr] = make_pair(j, i);
      if (x < M)
        solution(curr + 1, x + 2, y);
      else
        solution(curr + 1, 0, y + 1);
      visited[i][j] = false;
      ans[curr] = make_pair(-1, -1);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> K;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }

  for (int i = 0; i < 3; i++) {
    ans[i] = make_pair(-1, -1);
  }

  solution(0, 0, 0);
  cout << maxSum << '\n';

  return 0;
}