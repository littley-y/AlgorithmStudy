#include <cstring>
#include <iostream>

using namespace std;

int T, M, N, x, y;

void solution() {
  int curr = 1, a = 1, b = 1;
  int visited[M][N];
  memset(visited, 0, sizeof(int) * M * N);

  while (!(a == x && b == y)) {
    if (visited[a - 1][b - 1] == true) {
      cout << -1 << '\n';
      return;
    }
    visited[a - 1][b - 1] = true;
    if (a == M)
      a = 0;
    if (b == N)
      b = 0;
    a++;
    b++;
    curr++;
  }
  cout << curr << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> M >> N >> x >> y;
    solution();
  }

  return 0;
}