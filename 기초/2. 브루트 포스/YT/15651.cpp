#include <iostream>

using namespace std;

int M, N;
int arr[8];

void solution(int curr) {
  if (curr == M) {
    for (int i = 0; i < M; i++) {
      cout << arr[i] << ' ';
    }
    cout << '\n';
    return;
  }

  for (int i = 1; i <= N; i++) {
    arr[curr] = i;
    solution(curr + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  solution(0);

  return 0;
}