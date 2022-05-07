#include <bits/stdc++.h>

using namespace std;

int TEST;
string s;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream in("a-in.txt");
  // cin.rdbuf(in.rdbuf());

  // ofstream out("out.txt");
  // cout.rdbuf(out.rdbuf());

  cin >> TEST;
  for (int test = 1; test <= TEST; test++)
  {
    cin >> s;
    int count = 0;
    string output = "";
    for (int i = 0; i < s.length() - 1; i++)
    {
      if (s[i] == s[i + 1])
      {
        count++;
      }
      else
      {
        if (s[i] < s[i + 1])
        {
          for (int j = 0; j < count; j++)
          {
            output += s[i];
            // cout << "A" << output << endl;
          }

          output += s[i];
          // cout << "B" << output << endl;
        }
        count = 0;
      }
      output += s[i];
      // cout << "C" << output << endl;
    }
    output += s[s.length() - 1];
    cout << "Case #" << test << ": " << output << endl;
  }
}