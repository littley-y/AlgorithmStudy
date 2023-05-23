#include <iostream>

using namespace std;

int N;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  int div = 9, ans = 0, cnt = 1;
  while (true) {
    if (N - div < 0) {
      ans += cnt * N;
      break;
    } else {
      ans += cnt * div;
    }
    N -= div;
    div *= 10;
    cnt++;
  }

  cout << ans << '\n';
  return 0;
}

// 1 <= N < 10 N
// 10 <= N < 100 2N
// 100 <= N < 1000 3N
// 9 + 90 * 2 + 90 * 3 + 90 * 4 ...