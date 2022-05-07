#include <bits/stdc++.h>

using namespace std;

int TEST, n, p;
pair<int, int> v[1000];
map<int, uint64_t> dp[1000]; //custNum > level > steps
uint64_t solve(int cusNo, int currLevel)
{
  // cout << "Eval: " << numSteps << " " << cusNo << " " << currLevel << " " << v[cusNo].first << " " << v[cusNo].second << endl;
  if (cusNo == n)
    return 0;
  if (dp[cusNo].count(currLevel))
    return dp[cusNo][currLevel];

  int diff = v[cusNo].second - v[cusNo].first;

  if (currLevel > v[cusNo].second)
    return dp[cusNo][currLevel] = diff + currLevel - v[cusNo].second + solve(cusNo + 1, v[cusNo].first);
  if (currLevel < v[cusNo].first)
    return dp[cusNo][currLevel] = diff + v[cusNo].first - currLevel + solve(cusNo + 1, v[cusNo].second);

  // cout << diff << " " << v[cusNo].first << " " << v[cusNo].second << endl;

  uint64_t upDown = diff + v[cusNo].second - currLevel + solve(cusNo + 1, v[cusNo].first);
  uint64_t downUp = diff + currLevel - v[cusNo].first + solve(cusNo + 1, v[cusNo].second);

  if (upDown < downUp)
    return dp[cusNo][currLevel] = upDown;
  return dp[cusNo][currLevel] = downUp;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream in("in-inf.txt");
  // cin.rdbuf(in.rdbuf());

  // ofstream out("out.txt");
  // cout.rdbuf(out.rdbuf());

  cin >> TEST;
  for (int test = 1; test <= TEST; test++)
  {
    cin >> n >> p;
    int x[n][p];
    // for(int i=0;i<n;i++)
    //   for(int j=0;j<p;j++)

    for (int i = 0; i < n; i++)
    {
      int low = 1e9, high = 0;
      dp[i].clear();
      for (int j = 0; j < p; j++)
      {
        cin >> x[i][j];
        if (x[i][j] < low)
          low = x[i][j];
        if (x[i][j] > high)
          high = x[i][j];
      }
      v[i] = make_pair(low, high);
    }
    uint64_t sol = solve(0, 0);
    cout << "Case #" << test << ": " << sol << endl;
  }
}