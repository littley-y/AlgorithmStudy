#include <iostream>
#include <queue>

using namespace std;

int N, M, day, cnt;
int tomato[1000][1000];
int mX[] = {-1, 0, 0, 1};
int mY[] = {0, -1, 1, 0};
queue<pair<int, int>> Q;

bool isValid(int x, int y) { return x > -1 && y > -1 && x < M && y < N; }

void BFS() {
  while (!Q.empty()) {
    int currX = Q.front().first;
    int currY = Q.front().second;
    day = tomato[currY][currX] - 1;
    Q.pop();

    for (int i = 0; i < 4; i++) {
      int checkX = currX + mX[i];
      int checkY = currY + mY[i];
      if (isValid(checkX, checkY) && tomato[checkY][checkX] == 0) {
        Q.push(make_pair(checkX, checkY));
        tomato[checkY][checkX] = tomato[currY][currX] + 1;
        cnt--;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> M >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> tomato[i][j];
      if (tomato[i][j] == 1)
        Q.push(make_pair(j, i));
      else if (tomato[i][j] == 0)
        cnt++;
    }
  }

  BFS();

  if (cnt == 0)
    cout << day << '\n';
  else
    cout << "-1\n";
  return 0;
}