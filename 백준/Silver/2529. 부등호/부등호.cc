#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 0 ~ 9의 숫자를 하나씩 사용해본다.
// 매 번 부등호 관계를 체크하면서 성립되지 않는 경우는 바로 종료한다.
// 백트래킹으로 보인다.
int k;
vector<char> v;
bool visited[10] = {false, };
string maxVal = "-1";
string minVal = "9876543210";

bool check(int A, int B, int cnt)
{
    if (v[cnt] == '>')
    {
        return A > B;
    }
    else
        return A < B;
}

void dfs(int num, int cnt, string val)
{
    if (cnt == k)
    {
        if (stoll(maxVal) < stoll(val))
            maxVal = val;
        if (stoll(minVal) > stoll(val))
            minVal = val;
        return;
    }
    
    for (int i=0; i<=9; i++)
    {
        if (!visited[i] && check(num, i, cnt))
        {
            visited[i] = true;
            dfs(i, cnt+1, val+to_string(i));
            visited[i] = false;
        }
    }
}

int main()
{
    cin >> k;
    for (int i=0; i<k; i++)
    {
        char c;
        cin >> c;
        v.push_back(c);
    }

    for (int i=0; i<=9; i++)
    {
        visited[i] = true;
        dfs(i, 0, to_string(i));
        visited[i] = false;
    }
    
    cout << maxVal << '\n' << minVal;
    
}