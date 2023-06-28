#include <iostream>
#include <strings.h>
#include <queue>

using namespace std;

int N, M, V;
bool  graph[1001][1001];
bool  visited[1001];
queue<int>  que;

void  dfs(int position) {
  visited[position] = true;
  cout << position << ' ';

  for (int index = 1; index <= N; ++index) {
    if (graph[position][index] && !visited[index]) {
      dfs(index);
    }
  }
}

void  bfs(int position) {
  que.push(position);
  visited[position] = true;

  while (!que.empty()) {
    position = que.front();
    cout << position << ' ';
    que.pop();

    for (int index = 1; index <= N; ++index) {
      if (graph[position][index] && !visited[index]) {
        que.push(index);
        visited[index] = true;
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M >> V;

  int point_1, point_2;
  for (int index = 0; index < M; ++index) {
    cin >> point_1 >> point_2;
    graph[point_1][point_2] = true;
    graph[point_2][point_1] = true;
  }

  dfs(V);

  bzero(visited, sizeof(visited));
  cout << '\n';

  bfs(V);

  return (0);
}
