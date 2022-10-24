#include <iostream>
#include <vector>
using namespace std;

// 백트래킹
int N;
long maxVal = -1000000000;
long minVal = 1000000000;
vector<int> values;
int op[4] = {0, };

void dfs(int cnt, int sum)
{
            
    // 탈출 조건
    if (cnt == N)
    {           
        // 값 갱신
        if (sum > maxVal)
            maxVal = sum;
        if (sum < minVal)
            minVal = sum;
        
        return;
    }
    
    for (int i=0; i<4; i++)
    {
        if (op[i] != 0)
        {
            // +
            if (i == 0)
            {
                op[i] -= 1;
                dfs(cnt+1, sum + values[cnt]);
                op[i] += 1;                
            }
            // -
            if (i == 1)
            {
                op[i] -= 1;
                dfs(cnt+1, sum - values[cnt]);
                op[i] += 1;
            }
            // *
            if (i == 2)
            {
                op[i] -= 1;
                dfs(cnt+1, sum * values[cnt]);
                op[i] += 1;
            }
            // /
            if (i == 3)
            {
                op[i] -= 1;
                dfs(cnt+1, sum / values[cnt]);
                op[i] += 1;
            }
        }
    }
}

int main()
{
   cin >> N;
   for (int i=0; i<N; i++)
   {
        int val;
        cin >> val;
        values.push_back(val);
   }
   // 덧셈, 뺄셈, 곱셈 ,나눗셈의 개수
   for (int i=0; i<4; i++)
   {
        cin >> op[i];        
   }

   dfs(1, values[0]);    

   cout << maxVal << '\n' << minVal;
}