#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

int N, M, V;
int arr[1001];
bool connected[1001][1001];
bool visited[1001];

void DFS(int curr) {
  cout << curr << " ";
  visited[curr] = true;

  for (int i = 1; i <= N; i++) {
    if (connected[curr][i] && !visited[i])
      DFS(i);
  }
}

void BFS(int start) {
  queue<int> Q;
  Q.push(start);
  visited[start] = true;

  while (!Q.empty()) {
    int curr = Q.front();
    cout << curr << " ";

    Q.pop();

    for (int i = 1; i <= N; i++) {
      if (connected[curr][i] && !visited[i]) {
        Q.push(i);
        visited[i] = true;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> V;
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    connected[a][b] = connected[b][a] = true;
  }

  DFS(V);
  cout << '\n';

  memset(visited, 0, sizeof(visited));

  BFS(V);
  cout << '\n';

  return 0;
}