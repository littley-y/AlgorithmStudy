#include <iostream>

using namespace std;

int T, n;
int ans[10];

int ansSum() {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += ans[i];
  }
  return sum;
}

void solution(int curr, int& cnt) {
  if (ansSum() == n) {
    cnt++;
    return;
  }

  for (int i = 1; i <= 3; i++) {
    ans[curr] = i;
    if (ansSum() <= n) {
      solution(curr + 1, cnt);
      ans[curr] = 0;
    } else {
      ans[curr] = 0;
      return;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> n;
    int cnt = 0;
    solution(0, cnt);
    cout << cnt << '\n';
  }

  return 0;
}