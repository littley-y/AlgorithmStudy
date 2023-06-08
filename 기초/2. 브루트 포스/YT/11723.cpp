#include <iostream>

using namespace std;

int M, num;
string command;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> M;
  long long bitmask = 0LL;

  while (M--) {
    cin >> command;
    if (command == "add") {
      cin >> num;
      bitmask |= 1 << num;
    } else if (command == "remove") {
      cin >> num;
      bitmask &= ~(1 << num);
    } else if (command == "check") {
      cin >> num;
      if (bitmask & (1 << num))
        cout << 1 << '\n';
      else
        cout << 0 << '\n';
    } else if (command == "toggle") {
      cin >> num;
      if (bitmask & (1 << num))
        bitmask &= ~(1 << num);
      else
        bitmask |= 1 << num;
    } else if (command == "all") {
      bitmask = (1 << 21) - 1;
    } else if (command == "empty") {
      bitmask = 0;
    }
  }

  return 0;
}