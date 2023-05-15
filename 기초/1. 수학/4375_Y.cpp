#include <iostream>

using namespace std;

unsigned short n;

int getAnswer(unsigned long long num, unsigned long long next, int cnt) {
  if (num % n == 0)
    return cnt;
  return getAnswer(num + next, next * 10, ++cnt);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  while (cin >> n)
    cout << getAnswer(1, 10, 1) << '\n';
  return 0;
}