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
        int cnt = 1;
        while (j + 1 < N && check[i][j] == check[i][j + 1]) {
          check[i][j] = 1;
          cnt++;
          j++;
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
        int cnt = 1;
        while (j + 1 < N && check[j][i] == check[j + 1][i]) {
          check[j][i] = 1;
          cnt++;
          j++;
        }
        if (cnt > maxSnack)
          maxSnack = cnt;
      }
    }
  }
}

// 전부 돌면서 체크하고, 체크 끝나면 다시 보드 되돌려놓기
void Bomboni() {
  char tmp;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j + 1 < N; j++) {
      if (board[i][j] != board[i][j + 1]) {
        tmp = board[i][j];
        board[i][j] = board[i][j + 1];
        board[i][j + 1] = tmp;
        checkBoardGaro(board);
        checkBoardSero(board);
        tmp = board[i][j];
        board[i][j] = board[i][j + 1];
        board[i][j + 1] = tmp;
      }
      if (board[j][i] != board[j + 1][i]) {
        tmp = board[j][i];
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