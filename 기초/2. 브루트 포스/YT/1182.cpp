#include <iostream>

using namespace std;

int N, S, cnt, sum;
int arr[20];
bool visited[20];

void solution(int curr) {
  if (curr && sum == S) {
    cnt++;
  }

  for (int i = curr; i < N; i++) {
    if (visited[i] == true)
      continue;
    sum += arr[i];
    visited[i] = true;
    solution(i + 1); // 이미 지나온 수는 안봐도 되기 때문
    visited[i] = false;
    sum -= arr[i];
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> S;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  solution(0);
  cout << cnt << '\n';

  return 0;
}