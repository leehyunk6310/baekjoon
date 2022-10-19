#include <iostream>
#include <vector>
using namespace std;

// dp
// 경우의 수를 고려하여 점화식을 세운다.
int T;
vector<int> v;
int main()
{
    cin >> T;
    {
        for (int i=0; i<T; i++)
        {
            int n;
            cin >> n;
            int sticker[2][100001];
            for (int i=0; i<2; i++)
            {   
                for (int j=0; j<n; j++)
                    cin >> sticker[i][j];
            }
        
            sticker[0][1] = sticker[1][0] + sticker[0][1];
            sticker[1][1] = sticker[0][0] + sticker[1][1];
            
            for (int i=2; i<n; i++)
            {
                // 대각선 한칸 또는 가로로 두번 이동한 대각선
                sticker[0][i] = max(sticker[1][i-2], sticker[1][i-1]) + sticker[0][i];
                sticker[1][i] = max(sticker[0][i-2], sticker[0][i-1]) + sticker[1][i];
            }            
            v.push_back(max(sticker[0][n-1], sticker[1][n-1]));
        }
        
        for (auto num : v)
            cout << num << '\n';
    }
    
    
}