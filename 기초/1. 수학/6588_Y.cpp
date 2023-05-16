#include <iostream>

using namespace std;

int n;
const int ARR_MAX = 1000001;
bool arr[ARR_MAX] = {0};

bool isPrime(int num) {
  int i = 3;
  while (i * i <= num) {
    if (num % i == 0)
      return false;
    i += 2;
  }
  return true;
}

void fillPrime() {
  for (int i = 3; i < ARR_MAX; i + 2) {
    arr[i] = isPrime(i);
  }
}

void solution() {
  int A = 3, B = n - A;

  while (true) {
    if (A + B == n && arr[B])
      break;
    A += 2;
    while (arr[A] == false)
      A += 2;
    B = n - A;
  }
  cout << n << " = " << A << " + " << B << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  fillPrime();

  while (true) {
    cin >> n;
    if (n == 0)
      break;
    solution();
  }
  return 0;
}