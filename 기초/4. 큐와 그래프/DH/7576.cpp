#include <iostream>
#include <queue>
#include <string>

using namespace std;

int M, N, storage[1001][1001], date[1001][1001], max_date;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<pair<int, int> > que;

void bfs(void) {
   for (int height = 0; height < N; ++height) {
    for (int width = 0; width < M; ++width) {
      if (storage[height][width] == 1) {
        que.push(make_pair(height, width));
      }
    }
  }

  pair<int, int> curr;
  int next_x, next_y;
  while (!que.empty()) {
    curr = que.front();
    que.pop();

    for (int index = 0; index < 4; ++index) {
      next_x = curr.second + dx[index];
      next_y = curr.first + dy[index];

      if (next_x < 0 || next_y < 0 || next_x >= M || next_y >= N)
        continue;

      if (storage[next_y][next_x] == 0) {
        storage[next_y][next_x] = 1;
        date[next_y][next_x] = date[curr.first][curr.second] + 1;
        max_date = max(date[next_y][next_x], max_date);
        que.push(make_pair(next_y, next_x));
      }
    }
  }
}

void check_storage(void) {
   for (int height = 0; height < N; ++height) {
    for (int width = 0; width < M; ++width) {
      if (storage[height][width] == 0) {
        max_date = -1;
        return ;
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> M >> N;

  for (int height = 0; height < N; ++height) {
    for (int width = 0; width < M; ++width) {
      cin >> storage[height][width];
    }
  }

  bfs();

  check_storage();

  cout << max_date << '\n';

  return (0);
}
