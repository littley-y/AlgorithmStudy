#include <iostream>
#include <queue>

using namespace std;

const int ARR_MAX = 100001;
int N, K;
int arr[ARR_MAX];

void BFS() {
  queue<int> Q;
  Q.push(N);

  while (!Q.empty()) {
    int curr = Q.front();
    Q.pop();

    if (curr == K)
      break;

    int ways[3] = {curr + 1, curr - 1, curr * 2};
    for (const auto &way : ways) {
      if (way < 0 || way >= ARR_MAX || arr[way] != 0)
        continue;
      Q.push(way);
      arr[way] = arr[curr] + 1;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;

  BFS();
  cout << arr[K] << '\n';

  return 0;
}