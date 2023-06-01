/*
처음에 재귀로 풀려고 하다가 시간초과가 떠서, 인터넷에 있는 풀이를 참고했다.
Next Permutation은 STL algorithm에도 구현되어 있는 친구다.

< 내림차순 순열 찾기 >
1. i를 마지막 값에서부터 시작해 arr[i - 1] < arr[i] 값을 찾는다.
2. 이 값이 0이면 내림차순 정렬이라는 뜻이므로 return false(다음 순열 없음).
3. j 또한 마지막에서 시작해 arr[i - 1] < arr[j] 값을 찾는다.
4. 1번의 값과 3번의 값 swap.
5. 1번 인덱스부터 시작해 끝까지 값을 reverse.
*/

#include <algorithm>
#include <iostream>

using namespace std;

int N;
int arr[10000];

bool next_permutation() {
  int i = N - 1;
  int j = N - 1;
  while (i > 0 && arr[i - 1] > arr[i]) {
    i--;
  }

  if (i == 0) {
    return false;
  };

  while (arr[i - 1] >= arr[j])
    j--;
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

  if (next_permutation() == false) {
    cout << "-1\n";
  } else {
    for (int i = 0; i < N; i++) {
      cout << arr[i] << ' ';
    }
    cout << '\n';
  }
  return 0;
}