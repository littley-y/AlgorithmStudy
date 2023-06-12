#include <iostream>

using namespace std;

int N;
const int ARR_MAX = 1000001;
int arr[ARR_MAX];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  arr[2] = 1;
  arr[3] = 1;

  for (int i = 4; i <= N; i++) {
    if (i % 2 == 0 && i % 3 == 0) {
      arr[i] = min(arr[i / 2], arr[i / 3]);
    } else if (i % 3 == 0) {
      arr[i] = min(arr[i - 1], arr[i / 3]);
    } else if (i % 2 == 0) {
      arr[i] = min(arr[i - 1], arr[i / 2]);
    } else {
      arr[i] = arr[i - 1];
    }
    arr[i]++;
  }

  cout << arr[N] << '\n';
}
