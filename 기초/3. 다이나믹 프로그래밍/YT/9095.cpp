#include <iostream>

using namespace std;

int T;
int arr[11];

void solution() {}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;

  arr[1] = 1;
  arr[2] = 2;
  arr[3] = 4;
  for (int i = 4; i <= 10; i++) {
    arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
  }

  int n;
  for (int i = 0; i < T; i++) {
    cin >> n;
    cout << arr[n] << '\n';
  }

  return 0;
}