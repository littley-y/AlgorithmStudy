#include <iostream>
#include <vector>

using namespace std;

int N;
int maxSnack;
vector<string> board;

void checkBoardGaro(vector<string> check) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j + 1 < N; j++) {
      if (isalpha(check[i][j])) {
        int a = i, b = j;
        int cnt = 1;
        while (b + 1 < N && check[a][b] == check[a][b + 1]) {
          check[a][b] = 1;
          cnt++;
          b++;
        }
        if (cnt > maxSnack)
          maxSnack = cnt;
      }
    }
  }
}

void checkBoardSero(vector<string> check) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j + 1 < N; j++) {
      if (isalpha(check[j][i])) {
        int a = i, b = j;
        int cnt = 1;
        while (b + 1 < N && check[b][a] == check[b + 1][a]) {
          check[b][a] = 1;
          cnt++;
          b++;
        }
        if (cnt > maxSnack)
          maxSnack = cnt;
      }
    }
  }
}

void Bomboni() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j + 1 < N; j++) {
      if (board[i][j] != board[i][j + 1]) {
        char tmp = board[i][j];
        board[i][j] = board[i][j + 1];
        board[i][j + 1] = tmp;
        checkBoardGaro(board);
        checkBoardSero(board);
        tmp = board[i][j];
        board[i][j] = board[i][j + 1];
        board[i][j + 1] = tmp;
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j + 1 < N; j++) {
      if (board[j][i] != board[j + 1][i]) {
        char tmp = board[j][i];
        board[j][i] = board[j + 1][i];
        board[j + 1][i] = tmp;
        checkBoardGaro(board);
        checkBoardSero(board);
        tmp = board[j][i];
        board[j][i] = board[j + 1][i];
        board[j + 1][i] = tmp;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  board.reserve(N);

  for (int i = 0; i < N; i++) {
    string tmp;
    cin >> tmp;
    board.push_back(tmp);
  }

  Bomboni();
  cout << maxSnack << '\n';
  return 0;
}