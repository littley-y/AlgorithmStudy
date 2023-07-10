#include <iostream>
#include <queue>
#include <vector>
#include <deque>

using namespace std;

int N, K, sec[100001], route[100001];
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
      route[curr + 1] = curr;
    }
    if (curr - 1 >= 0 && !sec[curr - 1]) {
      que.push(curr - 1);
      sec[curr - 1] = sec[curr] + 1;
      route[curr - 1] = curr;
    }
    if (curr * 2 <= 100000 && !sec[curr * 2]) {
      que.push(curr * 2);
      sec[curr * 2] = sec[curr] + 1;
      route[curr * 2] = curr;
    }
  }
}

void print_root(void) {
  deque<int> print;

  for (int pos = K; pos != N; pos = route[pos]) {
    print.push_front(pos);
  }
  print.push_front(N);

  for (auto &it : print)
    cout << it << ' ';

  cout << '\n';
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> K;

  que.push(N);
  bfs();

  cout << sec[K] << '\n';

  print_root();

  return (0);
}
