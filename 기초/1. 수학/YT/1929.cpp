#include <iostream>

using namespace std;

int M, N;

bool isPrime(int num) {
  if (num == 1)
    return false;
  if (num == 2 || num == 3)
    return true;

  int i = 2;
  while (i * i <= num) {
    if (num % i == 0)
      return false;
    i++;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> M >> N;

  while (M <= N) {
    if (isPrime(M))
      cout << M << '\n';
    M++;
  }
  cout << '\n';
  return 0;
}