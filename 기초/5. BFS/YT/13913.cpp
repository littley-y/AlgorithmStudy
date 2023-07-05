#include <iostream>
#include <queue>

#define CNT 0
#define PREV 1

using namespace std;

const int MAX = 100001;
int N, K;
queue<int> Q;
int BFSdata[MAX][2];

void BFS() {
  Q.push(N);

  while (!Q.empty()) {
    int curr = Q.front();
    Q.pop();
    if (curr == K)
      break;

    int ways[3] = {curr + 1, curr - 1, curr * 2};
    for (const auto &way : ways) {
      if (way < 0 || way >= MAX || BFSdata[way][CNT] != 0)
        continue;
      Q.push(way);
      BFSdata[way][CNT] = BFSdata[curr][CNT] + 1;
      BFSdata[way][PREV] = curr;
    }
  }
}

void printResult() {
  deque<int> route;
  route.push_back(K);

  int idx = K;
  while (idx != N) {
    route.push_front(BFSdata[idx][PREV]);
    idx = BFSdata[idx][PREV];
  }

  cout << BFSdata[K][CNT] << '\n';
  for (auto &i : route) {
    cout << i << ' ';
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;
  BFS();
  printResult();

  return 0;
}