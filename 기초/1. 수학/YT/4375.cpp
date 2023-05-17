#include <iostream>

using namespace std;

unsigned short mod;

int getAnswer(int num, int cnt) {
  if (num % mod == 0)
    return cnt;
  return getAnswer((num * 10 + 1) % mod, cnt + 1);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  while (cin >> mod) {
    cout << getAnswer(1, 1) << '\n';
  }
  return 0;
}