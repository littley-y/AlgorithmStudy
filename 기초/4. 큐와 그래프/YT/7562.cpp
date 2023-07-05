#include <iostream>
#include <queue>

using namespace std;

int length, T, dX, dY, cnt;
int board[300][300];
int mX[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int mY[] = {-1, 1, -2, 2, -2, 2, -1, 1};

bool isValid(int x, int y) { return x > -1 && y > -1 && x < length && y < length; }

void resetBoard() {
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length; j++) {
      board[i][j] = 0;
    }
  }
}

void BFS(int x, int y) {
  queue<pair<int, int>> Q;
  Q.push(make_pair(x, y));
  board[y][x] = 1;

  while (true) {
    int currX = Q.front().first;
    int currY = Q.front().second;
    cnt = board[currY][currX] - 1;

    if (currX == dX && currY == dY)
      return;

    Q.pop();

    for (int i = 0; i < 8; i++) {
      int checkX = currX + mX[i];
      int checkY = currY + mY[i];

      if (isValid(checkX, checkY) && board[checkY][checkX] == 0) {
        Q.push(make_pair(checkX, checkY));
        board[checkY][checkX] = board[currY][currX] + 1;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int i = 0; i < T; i++) {
    int a, b;
    cin >> length >> a >> b >> dX >> dY;

    if (i)
      resetBoard();
    BFS(a, b);
    cout << cnt << '\n';
  }

  return 0;
}