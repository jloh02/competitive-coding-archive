#include <bits/stdc++.h>

using namespace std;

int TEST, n, x;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> TEST;
  for (int test = 1; test <= TEST; test++)
  {
    cin >> n;
    uint64_t totSum = 0;
    for (int i = 0; i < 30; i++)
    {
      cout << (1 << i) << " ";
      totSum += (1 << i);
    }

    vector<int> bigs;
    for (int i = 0; i < n - 30; i++)
    {
      int v = (int)(1e9 - i);
      cout << v << " ";
      bigs.push_back(v);
      totSum += v;
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
      cin >> x;
      totSum += x;
      bigs.push_back(x);
    }

    sort(bigs.begin(),bigs.end(),greater<int>());

    totSum /= 2;

    // cout << "TARGET: " << totSum << endl;

    int bigI = 0;
    while (totSum > 1e9)
    {
      cout << bigs[bigI] << " ";
      totSum -= bigs[bigI];
      bigI++;
    }

    x = 1 << 30;
    while (totSum > 0)
    {
      // cout << x << " " << totSum << endl;
      if (totSum >= x)
      {
        totSum -= x;
        cout << x << " ";
      }
      x = x >> 1;
    }
    cout << endl;
  }
}