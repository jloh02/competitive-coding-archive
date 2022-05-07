#include <bits/stdc++.h>

using namespace std;

int TEST, n, s[1000000];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> TEST;
  for (int test = 1; test <= TEST; test++)
  {
    map<int, int> idx;
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> s[i];
    if (n <= 4)
    {
      cout << "Case #" << test << ": " << n << endl;
      continue;
    }
    sort(s, s + n);
    int str = 0;
    for (int i = 0; i < n; i++)
    {
      if (s[i] > str)
        str++;
    }
    cout << "Case #" << test << ": " << str << endl;
  }
}