#include <iostream>
#include <vector>

using namespace std;

vector<int> deque;
int N;

void solution(const string &tmp) {
  if (!tmp.compare("push_front")) {
    int a;
    cin >> a;
    deque.emplace(deque.begin(), a);
  } else if (!tmp.compare("push_back")) {
    int a;
    cin >> a;
    deque.emplace_back(a);
  } else if (!tmp.compare("pop_front")) {
    if (deque.empty()) {
      cout << "-1\n";
    } else {
      cout << deque.front() << '\n';
      deque.erase(deque.begin());
    }
  } else if (!tmp.compare("pop_back")) {
    if (deque.empty()) {
      cout << "-1\n";
    } else {
      cout << deque.back() << '\n';
      deque.pop_back();
    }
  } else if (!tmp.compare("size")) {
    cout << deque.size() << '\n';
  } else if (!tmp.compare("empty")) {
    cout << deque.empty() << '\n';
  } else if (!tmp.compare("front")) {
    if (deque.empty()) {
      cout << "-1\n";
    } else {
      cout << deque.front() << '\n';
    }
  } else if (!tmp.compare("back")) {
    if (deque.empty()) {
      cout << "-1\n";
    } else {
      cout << deque.back() << '\n';
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