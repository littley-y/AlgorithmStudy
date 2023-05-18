#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
string broken;

int calCnt(int num) {
  int tmp = num / 10;
  int cnt = 1;

  while (tmp) {
    tmp /= 10;
    cnt++;
  }
  return cnt;
}

int findNear() {
  int maxNum = pow(10, calCnt(N) + 1);  // 여기서 calCnt(N) + 1 안해서 틀림..
  int click = abs(N - 100);

  for (int i = 0; i <= maxNum; i++) {
    string tmp = to_string(i);
    size_t j = 0;
    for (; j < tmp.size(); j++) {
      if (broken.find(tmp[j]) != string::npos)
        break;
    }
    if (j != tmp.size())
      continue;
    int now_click = abs(N - i) + calCnt(i);
    if (now_click < click)
      click = now_click;
  }
  return click;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  broken.resize(M);
  for (int i = 0; i < M; i++) {
    cin >> broken[i];
  }

  int ngd = abs(N - 100);
  if (ngd < 4) {
    cout << ngd << '\n';
    return 0;
  }

  cout << findNear() << '\n';
  return 0;
}