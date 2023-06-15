#include <iostream>

using namespace std;

const int ARR_MAX = 1001;
int N, price[ARR_MAX], arr[ARR_MAX];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    arr[i] = 10001;
    cin >> price[i];
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= i; j++) {
      arr[i] = min(arr[i], arr[i - j] + price[j]);
    }
  }
  cout << arr[N] << '\n';

  return 0;
}