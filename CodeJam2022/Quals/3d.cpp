#include <bits/stdc++.h>

using namespace std;

int TEST, x, mi[4];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> TEST;
  for (int test = 1; test <= TEST; test++)
  {
    for (int i = 0; i < 4; i++)
      cin >> mi[i];
    for (int i = 0; i < 4; i++)
    {
      cin >> x;
      if (x < mi[i])
        mi[i] = x;
    }
    for (int i = 0; i < 4; i++)
    {
      cin >> x;
      if (x < mi[i])
        mi[i] = x;
    }

    x = -1000000;
    for (int i = 0; i < 4; i++)
      x += mi[i];
    cout << "Case #" << test << ":";
    if (x < 0)
    {
      cout << " IMPOSSIBLE" << endl;
    }
    else
    {
      int i = 0;
      while (x > 0)
      {
        int rm = x > mi[i] ? mi[i] : x;
        mi[i] -= rm;
        x -= rm;
        i++;
      }
      for (int i = 0; i < 4; i++)
        cout << " " << mi[i];
      cout << endl;
    }
  }
}