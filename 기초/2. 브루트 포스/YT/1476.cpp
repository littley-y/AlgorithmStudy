#include <iostream>

using namespace std;

int E, S, M, ans = 1;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> E >> S >> M;

  int e = 1, s = 1, m = 1;
  while (e != E || s != S || m != M) {
    e++;
    s++;
    m++;
    if (e == 16)
      e = 1;
    if (s == 29)
      s = 1;
    if (m == 20)
      m = 1;
    ans++;
  }
  cout << ans << '\n';
  return 0;
}