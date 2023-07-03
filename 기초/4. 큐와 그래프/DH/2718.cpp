#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N, M;
bool  visited[1001][1001];
int  route[1001][1001];
string maze[1001];
queue<pair<int, int> > que;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void  find_short() {
  que.push(make_pair(0, 0));
  visited[0][0] = true;
  route[0][0] = 1;

  pair<int, int> curr;
  while (!que.empty()) {
    curr = que.front();
    que.pop();

    int sur_x, sur_y;
    for (int index = 0; index < 4; ++index) {
      sur_x = curr.second + dx[index];
      sur_y = curr.first + dy[index];

      if (sur_x < 0 || sur_y < 0 || sur_x >= M || sur_y >= N)
        continue;

      if (!visited[sur_y][sur_x] && maze[sur_y][sur_x] == '1') {
        que.push(make_pair(sur_y, sur_x));
        visited[sur_y][sur_x] = true;
        route[sur_y][sur_x] = route[curr.first][curr.second] + 1;
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;

  for (int index = 0; index < N; ++index) {
    cin >> maze[index];
  }

  find_short();

  cout << route[N - 1][M - 1] << '\n';

  return (0);
}
