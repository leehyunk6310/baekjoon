#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m, a, b, c;
    vector<vector<int>> g(102, vector<int>(102, 1e9));

    for (int i=0; i<102; i++)
        g[i][i] = 0;

    cin >> n >> m;

    for (int i=0; i<m; i++)
    {
        cin >> a >> b >> c;

        if (g[a][b] > c)
            g[a][b] = c;
    }

    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            for (int k=1; k<=n; k++)
            {
                g[j][k] = min(g[j][k], g[j][i] + g[i][k]);
            }

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            if (g[i][j] == 1e9)
                cout << 0 << " ";
            else        
                cout << g[i][j] << " ";
        }
            
        cout << endl; 
    }
}