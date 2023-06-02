#include <algorithm>
#include <iostream>

using namespace std;

int N;
int arr[10001];

bool prev_permutation() {
  int i = N - 1, j = N - 1;
  while (i > 0 && arr[i] > arr[i - 1])
    --i;

  if (i == 0)
    return false;

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
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  if (prev_permutation(arr, arr + N)) {
    for (int i = 0; i < N; i++) {
      cout << arr[i] << ' ';
    }
  } else {
    cout << "-1";
  }
  cout << '\n';
  return 0;
}