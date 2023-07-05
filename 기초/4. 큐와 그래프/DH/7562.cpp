#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int T, l, dest_x, dest_y, route[301][301];
int dx[8] = {1, 2,  2,  1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1,  1,  2};
bool  visited[301][301];
queue<pair<int, int> > que;

void  bfs(void) {
  pair<int, int> curr;
  int next_x, next_y;

  while (!que.empty()) {
    curr = que.front();
    que.pop();
    if (curr.second == dest_x && curr.first == dest_y)
        return ;

    for (int index = 0; index < 8; ++index) {
      next_x = curr.second + dx[index];
      next_y = curr.first + dy[index];

      if (next_x < 0 || next_y < 0 || next_x >= l || next_y >= l)
        continue;

      if (!visited[next_y][next_x]) {
        route[next_y][next_x] = route[curr.first][curr.second] + 1;
        visited[next_y][next_x] = true;
        que.push(make_pair(next_y, next_x));
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> T;

  int x, y;
  while (T--) {
    cin >> l >> x >> y >> dest_x >> dest_y;
    que.push(make_pair(y, x));
    bfs();
    cout << route[dest_y][dest_x] << "\n";

    memset(route, 0, sizeof(route));
    memset(visited, 0, sizeof(visited));
    while (!que.empty())
      que.pop();
  }

  return (0);
}
