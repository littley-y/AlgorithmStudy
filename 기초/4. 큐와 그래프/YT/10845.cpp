#include <iostream>
#include <vector>

using namespace std;

vector<int> queue;
int N;

void solution(const string &tmp) {
  if (!tmp.compare("push")) {
    int a;
    cin >> a;
    queue.push_back(a);
  } else if (!tmp.compare("pop")) {
    if (queue.empty()) {
      cout << "-1\n";
    } else {
      cout << queue.front() << '\n';
      queue.erase(queue.begin());
    }
  } else if (!tmp.compare("size")) {
    cout << queue.size() << '\n';
  } else if (!tmp.compare("empty")) {
    cout << queue.empty() << '\n';
  } else if (!tmp.compare("front")) {
    if (queue.empty()) {
      cout << "-1\n";
    } else {
      cout << queue.front() << '\n';
    }
  } else if (!tmp.compare("back")) {
    if (queue.empty()) {
      cout << "-1\n";
    } else {
      cout << queue.back() << '\n';
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    string tmp;
    cin >> tmp;
    solution(tmp);
  }

  return 0;
}