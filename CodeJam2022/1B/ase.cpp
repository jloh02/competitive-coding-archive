#include <bits/stdc++.h>

using namespace std;

int TEST, n;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream in("in.txt");
  // cin.rdbuf(in.rdbuf());

  // ofstream out("out.txt");
  // cout.rdbuf(out.rdbuf());

  cin >> TEST;
  for (int test = 1; test <= TEST; test++)
  {
    cout << "11111111" << endl;
    cin >> n;
    do
    {
      if (n > 4)
      {
        cout << "11111111" << endl;
      }
      else if (n == 1)
      {
        cout << "10000000" << endl;
      }
      else if (n == 2)
      {
        cout << "11000000" << endl;
      }
      else if (n == 3)
      {
        cout << "11100000" << endl;
      }
      else if (n == 4)
      {
        cout << "11110000" << endl;
      }
      cin >> n;
    } while (n > 0);
    if (n == -1)
      break;
  }
}