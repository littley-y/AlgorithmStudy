#include <iostream>

using namespace std;

int N;

int f() {
  if (N == 1)
    return 1;
  else if (N == 2)
    return 3;

  int i = 1;
  int ans = 0;
  while (i * 2 < N) {
    if (N % i == 0)
      ans += i + N / i;
    i++;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  cout << f() << "\n";
  return 0;
}