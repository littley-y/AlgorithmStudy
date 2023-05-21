/*
맨 처음에 완전탐색으로 풀려고 했는데 오류나서, DFS로 푸는 풀이를 참고했다.

1. x, y가 가운데일때를 기준으로, x +- 3, y +-3 좌표까지 모두 탐색하면 된다.
2. 방문한 노드를 표시하기 위해 visited를 true로 바꾼다.
   이렇게 하지 않으면 x, y + 1에서 탐색할 때 다시 이전 노드를 탐색하게 된다.
3. 재귀가 끝나면, 다음번 탐색할 때를 위해 visited를 false로 바꾼다(백트래킹).
*/

#include <iostream>
#include <vector>

using namespace std;

int N, M, biggest;
int paper[501][501];
bool visited[501][501];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

bool isValid(int x, int y) {
  if (x < 0 || y < 0 || x > M || y > N || visited[y][x] == true)
    return false;
  return true;
}

void DFS(int x, int y, int cnt, int curr) {
  if (cnt == 4) {
    if (curr > biggest) {
      biggest = curr;
    }
    return;
  }

  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (isValid(nx, ny)) {
      visited[y][x] = true;
      DFS(nx, ny, cnt + 1, curr + paper[y][x]);
      visited[y][x] = false;
    }
    if (x > 0 && y > 0 && x + 1 < M) {
      biggest = max(biggest, paper[y][x] + paper[y][x - 1] + paper[y - 1][x] +
                                 paper[y][x + 1]);
    }
    if (x > 0 && y > 0 && y + 1 < N) {
      biggest = max(biggest, paper[y][x] + paper[y][x - 1] + paper[y - 1][x] +
                                 paper[y + 1][x]);
    }
    if (x > 0 && y + 1 < N && x + 1 < M) {
      biggest = max(biggest, paper[y][x] + paper[y][x - 1] + paper[y + 1][x] +
                                 paper[y][x + 1]);
    }
    if (x + 1 < M && y > 0 && y + 1 < N) {
      biggest = max(biggest, paper[y][x] + paper[y][x + 1] + paper[y - 1][x] +
                                 paper[y + 1][x]);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> paper[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      DFS(j, i, 0, 0);
    }
  }

  cout << biggest << "\n";

  return 0;
}