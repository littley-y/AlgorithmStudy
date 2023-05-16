#include <iostream>
#include <vector>

using namespace std;

int N, cnt;

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
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  int num;
  for (int i = 0; i != N; i++) {
    cin >> num;
    cnt += isPrime(num);
  }
  cout << cnt << "\n";
  return 0;
}