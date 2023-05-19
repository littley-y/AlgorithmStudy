#include <iostream>
#include <vector>

using namespace std;

int N, M;
int arr[20];
vector<vector<int>> paper;

int aa(int x, int y) {
  if (x + 3 >= M)
    return -1;
  else
    return paper[y][x] + paper[y][x + 1] + paper[y][x + 2] + paper[y][x + 3];
}

int ba(int x, int y) {
  if (x + 1 >= M || y + 1 >= N)
    return -1;
  else
    return paper[y][x] + paper[y][x + 1] + paper[y + 1][x] +
           paper[y + 1][x + 1];
}

int ca(int x, int y) {
  if (x + 1 >= M || y + 2 >= N)
    return -1;
  else
    return paper[y][x] + paper[y + 1][x] + paper[y + 2][x] +
           paper[y + 2][x + 1];
}

int cb(int x, int y) {
  if (x + 2 >= M || y + 1 >= N)
    return -1;
  else
    return paper[y][x] + paper[y][x + 1] + paper[y][x + 2] + paper[y + 1][x];
}

int cc(int x, int y) {
  if (x + 1 >= M || y + 2 >= N)
    return -1;
  else
    return paper[y][x] + paper[y][x + 1] + paper[y + 1][x + 1] +
           paper[y + 2][x + 1];
}

int cd(int x, int y) {
  if (x + 2 >= M || y + 1 >= N)
    return -1;
  else
    return paper[y][x + 2] + paper[y + 1][x] + paper[y + 1][x + 1] +
           paper[y + 1][x + 2];
}

int da(int x, int y) {
  if (x + 1 >= M || y + 2 >= N)
    return -1;
  else
    return paper[y][x] + paper[y + 1][x] + paper[y + 1][x + 1] +
           paper[y + 2][x + 1];
}

int db(int x, int y) {
  if (x + 1 >= M || y + 2 >= N)
    return -1;
  else
    return paper[y][x + 1] + paper[y + 1][x] + paper[y + 1][x + 1] +
           paper[y + 2][x];
}

int ea(int x, int y) {
  if (x + 2 >= M || y + 1 >= N)
    return -1;
  else
    return paper[y][x] + paper[y][x + 1] + paper[y][x + 2] +
           paper[y + 1][x + 1];
}

int eb(int x, int y) {
  if (x + 2 >= M || y + 1 >= N)
    return -1;
  else
    return paper[y][x + 1] + paper[y + 1][x] + paper[y + 1][x + 1] +
           paper[y + 1][x + 2];
}

void checkTetromino(int x, int y) {
  arr[0] = aa(x, y);
  arr[1] = aa(y, x);
  arr[2] = ba(x, y);
  arr[3] = ca(x, y);
  arr[4] = ca(y, x);
  arr[5] = cb(x, y);
  arr[6] = cb(y, x);
  arr[7] = cc(x, y);
  arr[8] = cc(y, x);
  arr[9] = cd(x, y);
  arr[10] = cd(y, x);
  arr[11] = da(x, y);
  arr[12] = da(y, x);
  arr[13] = db(x, y);
  arr[14] = db(y, x);
  arr[15] = ea(x, y);
  arr[16] = ea(y, x);
  arr[17] = eb(x, y);
  arr[18] = eb(y, x);
}

void sortArr() {
  for (int i = 0; i < 19; i++) {
    for (int j = i + 1; j < 19; j++) {
      if (arr[i] > arr[j]) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  paper.resize(N);
  for (int i = 0; i < N; i++) {
    paper[i].resize(M);
    for (int j = 0; j < M; j++) {
      cin >> paper[i][j];
    }
  }

  int sum = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      checkTetromino(j, i);
      sortArr();
      if (sum < arr[18])
        sum = arr[18];
    }
  }
  cout << sum << "\n";
  return 0;
}