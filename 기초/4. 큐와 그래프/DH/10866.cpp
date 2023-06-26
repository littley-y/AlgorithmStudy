#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> deque;

int N;

void  exec(const string& cmd) {
  int num;

  if (cmd == "push_front") {
    cin >> num;
    deque.insert(deque.begin(), num);
  } else if (cmd == "push_back") {
    cin >> num;
    deque.push_back(num);
  } else if (cmd == "pop_front") {
    if (deque.size() == 0) {
      cout << -1 << '\n';
      return ;
    }
    cout << deque.front() << '\n';
    deque.erase(deque.begin());
  } else if (cmd == "pop_back") {
    if (deque.size() == 0) {
      cout << -1 << '\n';
      return ;
    }
    cout << deque.back() << '\n';
    deque.pop_back();
  } else if (cmd == "size") {
    cout << deque.size() << '\n';
  } else if (cmd == "empty") {
  if (deque.size() == 0)
      cout << 1 << '\n';
    else
      cout << 0 << '\n';
  } else if (cmd == "front") {
    if (deque.size() == 0) {
      cout << -1 << '\n';
      return ;
    }
    cout << deque.front() << '\n';
  } else if (cmd == "back") {
    if (deque.size() == 0) {
      cout << -1 << '\n';
      return ;
    }
    cout << deque.back() << '\n';
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;

  string cmd;

  while (N--) {
    cin >> cmd;
    exec(cmd);
  }

  return (0);
}
