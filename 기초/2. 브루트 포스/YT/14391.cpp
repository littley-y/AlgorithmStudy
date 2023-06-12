#include <iostream>

using namespace std;

int N, M;
int Map[5][5];
bool visited[5][5];
int ans;

void dfs(int r, int c) {
  if (r == 4) {
    int sum = 0;
    for (int r = 0; r < N; r++) {
      int temp = 0;
      for (int c = 0; c < M; c++) {
        if (visited[r][c])
          temp = temp * 10 + Map[r][c];
        else {
          sum += temp;
          temp = 0;
        }
      }
      sum += temp;
    }
    for (int c = 0; c < M; c++) {
      int temp = 0;
      for (int r = 0; r < N; r++) {
        if (!visited[r][c])
          temp = temp * 10 + Map[r][c];
        else {
          sum += temp;
          temp = 0;
        }
      }
      sum += temp;
    }
    ans = max(ans, sum);
    return;
  }
  if (c == 4) {
    dfs(r + 1, 0);
    return;
  }
  visited[r][c] = true;
  dfs(r, c + 1);

  visited[r][c] = false;
  dfs(r, c + 1);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  string str;
  for (int r = 0; r < N; r++) {
    cin >> str;
    for (int c = 0; c < M; c++)
      Map[r][c] = str[c] - '0';
  }

  dfs(0, 0);
  cout << ans << "\n";

  return 0;
}