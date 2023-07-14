#include <iostream>
#include <queue>
#include <cstring>
#include <climits>

using namespace std;

int N, K, sec[200001];
queue<int> que;
bool visited[200001];

void bfs() {
  int curr;

  que.push(N);
  visited[N] = true;

  while (!que.empty()) {
    curr = que.front();
    que.pop();

    if (curr + 1 <= 200000) {
      if (!visited[curr + 1]) {
        sec[curr + 1] = INT_MAX;
        visited[curr + 1] = true;
      }
      if (sec[curr] + 1 < sec[curr + 1]) {
        sec[curr + 1] = sec[curr] + 1;
        que.push(curr + 1);
      }
    }

    if (curr - 1 >= 0) {
      if (!visited[curr - 1]) {
        sec[curr - 1] = INT_MAX;
        visited[curr - 1] = true;
      }
      if (sec[curr] + 1 < sec[curr - 1]) {
        sec[curr - 1] = sec[curr] + 1;
        que.push(curr - 1);
      }
    }

    if (curr * 2 <= 200000) {
      if (!visited[curr * 2]) {
        sec[curr * 2] = INT_MAX;
        visited[curr * 2] = true;
      }
      if (sec[curr] < sec[curr * 2]) {
        sec[curr * 2] = sec[curr];
        que.push(curr * 2);
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  std::cout.tie(0);

  cin >> N >> K;

  bfs();

  std::cout << sec[K] << '\n';

  return (0);
}
