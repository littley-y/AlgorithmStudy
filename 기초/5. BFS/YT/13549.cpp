#include <deque>
#include <iostream>

using namespace std;

const int MAX = 1000001;
int N, K;
int location[MAX];
deque<int> deq;

void BFS() {
  deq.push_back(N);
  location[N] = 1;

  while (true) {
    int curr = deq.front();
    deq.pop_front();

    if (curr == K)
      break;

    if (curr * 2 < MAX && location[curr * 2] == 0) {
      location[curr * 2] = location[curr];
      deq.push_front(curr * 2);
    }
    if (curr > 0 && location[curr - 1] == 0) {
      location[curr - 1] = location[curr] + 1;
      deq.push_back(curr - 1);
    }
    if (curr < MAX - 1 && location[curr + 1] == 0) {
      location[curr + 1] = location[curr] + 1;
      deq.push_back(curr + 1);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;

  BFS();
  cout << location[K] - 1 << '\n';

  return 0;
}