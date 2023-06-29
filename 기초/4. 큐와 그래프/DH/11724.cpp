#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int>  graph[1001];
bool  visited[1001];

void  dfs(int position) {
  visited[position] = true;

  int next;
  for (int index = 0; index < graph[position].size(); ++index) {
    next = graph[position][index];
    if (!visited[next])
      dfs(next);
  }
}

void  bfs(int position) {
  queue<int>   que;
  que.push(position);
  visited[position] = true;

  int next;
  while (!que.empty()) {
    position = que.front();
    que.pop();

    for (int index = 0; index < graph[position].size(); ++index) {
      next = graph[position][index];
      if (!visited[next]) {
        que.push(next);
        visited[next] = true;
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;

  int u, v;

  for (int index = 0; index < M; ++index) {
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  int connect = 0;
  for (int position = 1; position <= N; ++position) {
    if (!visited[position]) {
      // dfs(position);
      bfs(position);
      connect++;
    }
  }

  cout << connect << '\n';

  return (0);
}
