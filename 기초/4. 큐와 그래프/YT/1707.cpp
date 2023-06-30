#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define RED 1
#define BLUE -1

using namespace std;

const int MAX = 20001;
int K, V, E, ans;
vector<int> graph[MAX];
int vertex[MAX];

void DFS(int curr, int color) {
  vertex[curr] = color;

  for (const auto &it : graph[curr]) {
    if (vertex[it] == color) {
      ans = -1;
      return;
    } else if (vertex[it] == 0) {
      DFS(it, -color);
    }
  }
}

void BFS(int start) {
  queue<int> Q;
  Q.push(start);
  vertex[start] = BLUE;

  while (!Q.empty()) {
    int curr = Q.front();
    int color = vertex[curr];
    Q.pop();

    for (const auto &it : graph[curr]) {
      if (vertex[it] == color) {
        ans = -1;
        return;
      } else if (vertex[it] == 0) {
        Q.push(it);
        vertex[it] = -color;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> K;
  while (K--) {
    cin >> V >> E;
    memset(graph, 0, sizeof(graph));
    memset(vertex, 0, sizeof(vertex));
    ans = 0;
    for (int i = 0; i < E; i++) {
      int a, b;
      cin >> a >> b;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }

    for (int i = 1; i <= V; i++) {
      if (vertex[i] == 0)
        BFS(i);
      if (ans == -1) {
        cout << "NO\n";
        break;
      }
    }
    if (ans == 0)
      cout << "YES\n";
  }

  return 0;
}