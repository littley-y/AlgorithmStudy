#include <iostream>

using namespace std;

const int MAX_NUM = 9;
int arr[MAX_NUM + 1];
int ans[7];
int sum, fakeA, fakeB;

void findFake() {
  for (int i = 0; i < MAX_NUM; i++) {
    for (int j = i + 1; j < MAX_NUM; j++) {
      if (sum - (arr[i] + arr[j]) == 100) {
        fakeA = i;
        fakeB = j;
        return;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < MAX_NUM; i++) {
    cin >> arr[i];
    sum += arr[i];
  }

  findFake();

  // fakeA와 fakeB에 해당하는 인덱스는 건너뜀
  int i = 0, j = 0;
  while (i != 7) {
    if (j == fakeA || j == fakeB) {
      j++;
      continue;
    }
    ans[i] = arr[j];
    i++;
    j++;
  }

  // 정렬
  for (int i = 0; i < 7; i++) {
    for (int j = i + 1; j < 7; j++) {
      if (ans[i] > ans[j]) {
        int tmp = ans[i];
        ans[i] = ans[j];
        ans[j] = tmp;
      }
    }
  }

  for (int i = 0; i < 7; i++) {
    cout << ans[i] << '\n';
  }

  return 0;
}