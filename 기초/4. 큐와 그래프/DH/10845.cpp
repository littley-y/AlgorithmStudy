#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;

vector<int> queue;

void exec(const string& cmd) {
  int num;
  if (cmd == "push") {
    cin >> num;
    queue.push_back(num);
  } else if (cmd == "pop") {
    if (queue.size() == 0) {
      cout << "-1\n";
      return ;
    }
    cout << queue.front() << '\n';
    queue.erase(queue.begin());
  } else if (cmd == "size") {
    cout << queue.size() << '\n';
  } else if (cmd == "empty") {
    if (queue.size() == 0)
      cout << 1 << '\n';
    else
      cout << 0 << '\n';
  } else if (cmd == "front") {
    if (queue.size() == 0) {
      cout << "-1\n";
      return ;
    }
    cout << queue.front() << '\n';
  } else if (cmd == "back") {
    if (queue.size() == 0) {
      cout << "-1\n";
      return ;
    }
    cout << queue.back() << '\n';
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
