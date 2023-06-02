#include <algorithm>
#include <iostream>

using namespace std;

int N, arr[8];

bool next_permutation() {
  int i = N - 1, j = N - 1;
  while (i > 0 && arr[i - 1] > arr[i])
    --i;

  if (i == 0) {
    return false;
  }

  while (arr[i - 1] > arr[j])
    --j;
  swap(arr[i - 1], arr[j]);
  reverse(arr + i, arr + N);
  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    arr[i - 1] = i;
    cout << i << ' ';
  }
  cout << '\n';

  while (next_permutation()) {
    for (int i = 0; i < N; i++) {
      cout << arr[i] << ' ';
    }
    cout << '\n';
  }

  return 0;
}