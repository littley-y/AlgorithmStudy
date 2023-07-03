#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int mX[] = {-1, 0, 0, 1};
int mY[] = {0, -1, 1, 0};

bool isValid(int x, int y) { return x > -1 && x < M && y > -1 && y < N; }

void BFS(vector<string> &miro, vector<vector<int>> &dist) {
  queue<pair<int, int>> Q;
  Q.push(make_pair(0, 0));
  miro[0][0] = '1';

  while (!Q.empty()) {
    int currX = Q.front().first;
    int currY = Q.front().second;

    if (currX == M - 1 && currY == N - 1)
      return;

    Q.pop();

    for (int i = 0; i < 4; i++) {
      int checkX = currX + mX[i];
      int checkY = currY + mY[i];
      if (isValid(checkX, checkY) && miro[checkY][checkX] == '1') {
        dist[checkY][checkX] = dist[currY][currX] + 1;
        miro[checkY][checkX] = '0';
        Q.push(make_pair(checkX, checkY));
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  vector<string> miro;
  vector<vector<int>> dist;
  dist.resize(N);
  for (int i = 0; i < N; i++) {
    string tmp;
    cin >> tmp;
    miro.push_back(tmp);
    dist[i].resize(M);
  }

  dist[0][0] = 1;
  BFS(miro, dist);
  cout << dist[N - 1][M - 1] << '\n';

  return 0;
}