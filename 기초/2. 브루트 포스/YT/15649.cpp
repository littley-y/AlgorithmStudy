#include <iostream>

using namespace std;

int N, M;
int arr[9];
bool visited[9];

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
    if (visited[i] == false) {
      visited[i] = true;
      solution(curr + 1);
      visited[i] = false;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  solution(0);

  return 0;
}