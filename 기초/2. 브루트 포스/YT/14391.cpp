#include <iostream>

using namespace std;

int N, M, maxSum;
int paper[4][4];
bool visited[4][4];

int calPaper(int n, int m) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int num = 0;
    for (int j = 0; j < m; j++) {
      num *= 10;
      num += paper[i][j];
    }
    sum += num;
  }
  return sum;
}

int solution1() {
  int line1 = N < M ? N : M;
  int line2 = N > M ? N : M;

  return calPaper(line1, line2);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> paper[i][j];
    }
  }

  if (N != M)
    cout << solution1();
  else if (N == M)
    cout << max(calPaper(N, M), calPaper(M, N));
  cout << '\n';

  return 0;
}