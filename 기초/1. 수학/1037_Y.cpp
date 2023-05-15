#include <iostream>

using namespace std;

int cnt, minimum = 2147483647, maximum = 0;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> cnt;
  int tmp;
  for (int i = 0; i != cnt; i++) {
    cin >> tmp;
    if (tmp < minimum)
      minimum = tmp;
    if (tmp > maximum)
      maximum = tmp;
  }
  cout << minimum * maximum << '\n';
  return 0;
}