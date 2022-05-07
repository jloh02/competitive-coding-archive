#include <bits/stdc++.h>

using namespace std;

int TEST, R, C;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> TEST;
    for (int test = 1; test <= TEST; test++)
    {
        cin >> R >> C;
        cout << "Case #" << test << ":\n";

        //First line A
        cout << "..";
        for (int c = 1; c < C; c++)
            cout << "+-";
        cout << "+\n";

        //First line B
        cout << "..";
        for (int c = 1; c < C; c++)
            cout << "|.";
        cout << "|\n";

        string remRows = "";
        for (int c = 0; c < C; c++)
            remRows += "+-";
        remRows += "+\n";
        for (int c = 0; c < C; c++)
            remRows += "|.";
        remRows += "|\n";

        for (int r = 1; r < R; r++)
            cout << remRows;

        for (int c = 0; c < C; c++)
            cout << "+-";
        cout << "+\n";
    }
}