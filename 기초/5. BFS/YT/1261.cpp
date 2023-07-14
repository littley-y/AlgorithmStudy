#include <deque>
#include <iostream>

using namespace std;

int N, M;
int mX[] = {-1, 0, 0, 1};
int mY[] = {0, -1, 1, 0};
char maze[100][100];
bool visited[100][100];

struct info {
  int x, y, sum;
};

bool isValid(int x, int y) { return x >= 0 and y >= 0 and x < M and y < N; }

void BFS() {
  deque<info> deq;
  deq.push_back({0, 0, 0});
  visited[0][0] = true;

  while (true) {
    auto curr = deq.front();
    deq.pop_front();

    if (curr.x == M - 1 and curr.y == N - 1) {
      cout << curr.sum << '\n';
      return;
    }

    for (int i = 0; i < 4; i++) {
      int cX = curr.x + mX[i];
      int cY = curr.y + mY[i];
      int cSum = curr.sum;

      if (isValid(cX, cY) == false or visited[cY][cX] == true)
        continue;

      visited[cY][cX] == true;

      if (maze[cY][cX] == '0')
        deq.push_front({cX, cY, cSum});
      else if (maze[cY][cX] == '1')
        deq.push_back({cX, cY, cSum + 1});
    }
  }
}

int main() {
  // ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin >> M >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> maze[i][j];
    }
  }

  BFS();
  return 0;
}