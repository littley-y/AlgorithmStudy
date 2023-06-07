#include <iostream>
#include <string>

using namespace std;

int M ,S;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> M;

  string  cmd = "";
  int     num = 0;

  while (M)
  {
    cin >> cmd;
    if (cmd != "all" && cmd != "empty")
      cin >> num;

    if (cmd == "add")
    {
      S = S | (1 << num);
    }
    else if (cmd == "remove")
    {
      S = S & ~(1 << num);
    }
    else if (cmd == "check")
    {
      if(((S & (1 << num)) >> num) == 1)
        cout << 1;
      else
        cout << 0;
      cout << '\n';
    }
    else if (cmd == "toggle")
    {
      if(((S & (1 << num)) >> num) == 1)
        S = S & ~(1 << num);
      else
        S = S | (1 << num);
    }
    else if (cmd == "all")
    {
      S = 2147483647 >> (32 - num);
    }
    else if (cmd == "empty")
    {
      S = 0;
    }

    cmd.clear();
    num = 0;
    --M;
  }
  return (0);
}
