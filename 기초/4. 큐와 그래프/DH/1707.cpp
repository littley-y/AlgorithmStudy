#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

enum visit_type {
  NOT_VISIT,
  VISIT_RED,
  VISIT_BLACK
};

vector<int> graph[20001];
int  K, V, E, color;
int  visited[20001];
bool answer;

void  bfs(int position) {
  queue<int>  que;

  que.push(position);
  visited[position] = color;

  while (!que.empty()) {
    if (answer == false)
      return ;
    position = que.front();
    que.pop();

    for (int index = 0; index < (int)graph[position].size(); ++index) {
      if (answer == false)
        return ;

      if (visited[position] == visited[graph[position][index]]) {
        answer = false;
        return ;
      }

      if (visited[graph[position][index]] == NOT_VISIT) {
        if (visited[position] == color)
          color = (VISIT_RED == color ? VISIT_BLACK : VISIT_RED);
        que.push(graph[position][index]);
        visited[graph[position][index]] = color;
      }
    }
  }
}

void  dfs(int position) {
  if (answer == false)
    return ;
  visited[position] = color;

  for (int index = 0; index < (int)graph[position].size(); ++index) {
    if (answer == false)
        return ;

    if (visited[position] == visited[graph[position][index]]) {
      answer = false;
      return ;
    }
    if (visited[graph[position][index]] == NOT_VISIT) {
      if (visited[position] == color)
        color = (VISIT_RED == color ? VISIT_BLACK : VISIT_RED);
      dfs(graph[position][index]);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> K;

  int u, v;
  while (K--) {
    cin >> V >> E;

    memset(graph, 0, sizeof(graph));
    memset(visited, NOT_VISIT, sizeof(visited));
    while (E--) {
      cin >> u >> v;
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
    color = VISIT_RED;
    answer = true;
    for (int index = 1; index <= V; ++index) {
      if (visited[index] == NOT_VISIT)
        bfs(index);
      if (answer == false)
        break ;
    }
    cout << (answer == true ? "YES\n" : "NO\n");
  }

  return (0);
}
