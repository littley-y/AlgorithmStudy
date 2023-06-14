#include <iostream>

using namespace std;

const int ARR_MAX = 100001;
int T, arr[ARR_MAX];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  arr[1] = 1;
  arr[2] = 1;
  arr[3] = 3;
  arr[4] = 3;
  for (int i = 1; i < ARR_MAX; i++) {
  }

  cin >> T;
  for (int i = 0; i < T; i++) {
    int n;
    cin >> n;
    cout << arr[n] << '\n';
  }
  return 0;
}

/*
1

2

1 + 2
2 + 1
3

1 + 2 + 1
1 + 3
3 + 1

2 + 1 + 2
1 + 3 + 1
2 + 3
3 + 2

1 + 2 + 3
1 + 3 + 2
2 + 1 + 3
2 + 3 + 1
3 + 1 + 2
3 + 2 + 1
1 + 2 + 1 + 2
2 + 1 + 2 + 1


1
1
3
3
4
8


*/