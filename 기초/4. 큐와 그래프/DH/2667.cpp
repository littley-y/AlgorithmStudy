#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int N, house;
vector<int> answer;
string  town[25];
bool    visited[25][25];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int height, int width) {
  queue<pair<int, int> > que;
  que.push(make_pair(height, width));
  visited[height][width] = true;
  house++;

  while (!que.empty()) {
    height = que.front().first;
    width = que.front().second;
    que.pop();

    for (int loop = 0; loop < 4; ++loop) {
      int nx = width + dx[loop];
      int ny = height + dy[loop];

      if (nx < 0 || ny < 0 || nx >= N || ny >= N)
        continue ;

      if (town[ny][nx] == '1' && !visited[ny][nx]) {
        que.push(make_pair(ny, nx));
        visited[ny][nx] = true;
        house++;
      }
    }
  }
}

void dfs(int height, int width) {
  visited[height][width] = true;
  house++;

  for (int loop = 0; loop < 4; ++loop) {
    int nx = width + dx[loop];
    int ny = height + dy[loop];

    if (nx < 0 || ny < 0 || nx >= N || ny >= N)
      continue;

    if (town[ny][nx] == '1' && !visited[ny][nx]) {
      dfs(ny, nx);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;

  string tmp;
  for (int index = 0; index < N; ++index) {
    cin >> town[index];
  }

  answer.push_back(0);
  for (int height = 0; height < N; ++height) {
    for (int width = 0; width < N; ++width) {
      if (town[height][width] == '1' &&!visited[height][width]) {
        house = 0;
        bfs(height, width);
        answer.push_back(house);
        answer[0]++;
      }
    }
  }

  sort(answer.begin() + 1, answer.end());
  for (const auto &it : answer) {
    cout << it << '\n';
  }

  return (0);
}
