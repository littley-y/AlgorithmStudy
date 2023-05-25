#include <iostream>

using namespace std;

int N, M;
int arr[8], ans[8];

void solution(int curr) {
  if (curr == M) {
    for (int i = 0; i < M; i++) {
      cout << ans[i] << ' ';
    }
    cout << '\n';
    return;
  }

  for (int i = 0; i < N; i++) {
    ans[curr] = arr[i];
    solution(curr + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (arr[i] > arr[j]) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
      }
    }
  }

  solution(0);

  return 0;
}