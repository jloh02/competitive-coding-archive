#include <bits/stdc++.h>

using namespace std;

int TEST, n;
uint64_t f[100001];
vector<int> children[100001];
pair<uint64_t, uint64_t> states[100001]; //<max val, fun>
/*
1
8
46036861 413240500 110036075 5864556 572658487 530756603 106818683 871946486
0 1 2 1 2 3 1 3

Correct answer: 2128217120
*/

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> TEST;
  for (int test = 1; test <= TEST; test++)
  {
    cin >> n;
    children[0].clear();
    states[0] = make_pair(0, 0);
    for (int i = 1; i <= n; i++)
    {
      cin >> f[i];
      states[i] = make_pair(f[i], 0);
      children[i].clear();
    }
    for (int i = 1; i <= n; i++)
    {
      int p;
      cin >> p;
      children[p].push_back(i);
    }

    for (int i = n; i > 0; i--)
    {
      if (children[i].size() == 0)
        continue;
      if (children[i].size() == 1)
      {
        uint64_t newMaxV = states[children[i][0]].first > states[i].first ? states[children[i][0]].first : states[i].first;
        states[i] = make_pair(newMaxV, states[children[i][0]].second);

        // cout << "State [" << i << "] : " << states[i].first << " " << states[i].second << endl;
        continue;
      }
      vector<pair<uint64_t, uint64_t>>
          childs;
      for (int j = 0; j < children[i].size(); j++)
        childs.push_back(states[children[i][j]]);

      sort(childs.begin(), childs.end());

      uint64_t newMaxV = states[i].first, newFun = childs[0].second;
      for (int j = 1; j < childs.size(); j++)
        newFun += childs[j].first + childs[j].second;
      if (childs[0].first > states[i].first)
      {
        newMaxV = childs[0].first;
      }
      else
      {
      }
      states[i] = make_pair(newMaxV, newFun);

      // cout << "State [" << i << "] : " << states[i].first << " " << states[i].second << endl;
    }

    uint64_t finalFun = 0;
    for (int j = 0; j < children[0].size(); j++)
    {
      // cout << "Summing " << children[0][j] << " : " << states[children[0][j]].first << " " << states[children[0][j]].second << " " << states[children[0][j]].first + states[children[0][j]].second << endl;
      finalFun += states[children[0][j]].first + states[children[0][j]].second;
    }

    cout << "Case #" << test << ": " << finalFun << endl;
  }
}