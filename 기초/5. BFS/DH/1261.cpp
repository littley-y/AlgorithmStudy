#include <iostream>
#include <string>
#include <deque>

using namespace std;

int N, M, breaking[101][101];
string maze[101];
deque<pair<int, int>> dq;
bool visited[101][101];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void  bfs(void) {
  dq.push_back({0, 0});
  visited[0][0] = true;

  pair<int, int> curr;
  int curr_x, curr_y, next_x, next_y;
  while (!dq.empty()) {
    curr = dq.front();
    dq.pop_front();

    curr_x = curr.second;
    curr_y = curr.first;

    if (curr_x == M - 1 && curr_y == N - 1)
      return ;

    for (int index = 0; index < 4; ++index) {
      next_x = curr_x + dx[index];
      next_y = curr_y + dy[index];

      if (next_x < 0 || next_y < 0 || next_x >= M || next_y >= N)
        continue ;

      if (!visited[next_y][next_x]) {
        if (maze[next_y][next_x] == '0') {
          visited[next_y][next_x] = true;
          breaking[next_y][next_x] = breaking[curr_y][curr_x];
          dq.push_front({next_y, next_x});
        }
        else if (maze[next_y][next_x] == '1') {
          visited[next_y][next_x] = true;
          breaking[next_y][next_x] = breaking[curr_y][curr_x] + 1;
          dq.push_back({next_y, next_x});
        }
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> M >> N;

  for (int index = 0; index < N; ++index)
    cin >> maze[index];

  bfs();

  cout << breaking[N - 1][M - 1] << '\n';

  return (0);
}
