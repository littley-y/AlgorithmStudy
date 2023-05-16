#include <iostream>

using namespace std;

int N;

int f(int num) {
  int i = 1;
  int ans = 0;
  while (i * i <= num) {
    if (i * i == num)
      ans += i;
    else if (num % i == 0)
      ans += i + num / i;
    i++;
  }
  return ans;
}

int g(int num) {
  int ans = 0;
  for (int i = 1; i <= num; i++) {
    ans += f(i);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  cout << g(N) << "\n";
  return 0;
}