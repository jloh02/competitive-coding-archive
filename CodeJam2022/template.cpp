#include <bits/stdc++.h>

using namespace std;

int TEST, n;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream in("in.txt");
  cin.rdbuf(in.rdbuf());

  ofstream out("out.txt");
  cout.rdbuf(out.rdbuf());

  cin >> TEST;
  for (int test = 1; test <= TEST; test++)
  {
    cin >> n;
    int result = n;
    cout << "Case #" << test << ": " << result << endl;
  }
}