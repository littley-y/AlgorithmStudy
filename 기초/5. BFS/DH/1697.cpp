#include <iostream>
#include <queue>

using namespace std;

int N, K, sec[100001];
queue<int> que;

void bfs(void) {
  int curr;

  while (!que.empty()) {
    curr = que.front();
    que.pop();

    if (curr == K)
      return ;

    if (curr + 1 <= 100000 && !sec[curr + 1]) {
      que.push(curr + 1);
      sec[curr + 1] = sec[curr] + 1;
    }
    if (curr - 1 >= 0 && !sec[curr - 1]) {
      que.push(curr - 1);
      sec[curr - 1] = sec[curr] + 1;
    }
    if (curr * 2 <= 100000 && !sec[curr * 2]) {
      que.push(curr * 2);
      sec[curr * 2] = sec[curr] + 1;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> K;

  que.push(N);
  bfs();

  cout << sec[K] << '\n';

  return (0);
}
