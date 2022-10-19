#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

// 조합 문제
// 종류가 여러개인 경우
// 1 ~ 종류수를 고르는 방법
int t;

vector<int> ans;

int main()
{
    cin >> t;
    for (int i=0; i<t; i++)
    {
        // 종류별로 몇개가 들어있는지 체크한다.
        unordered_map<string, int> m;
        int answer = 1;
        int n;
        cin >> n;
        for (int i=0; i<n; i++)
        {
            string name;
            string kind;

            cin >> name >> kind;
            m[kind]++;
        }

        // 종류별로 갯수를 체크해서 벡터에 집어넣는다.
        vector<int> v;
        for (auto mm : m)
        {
            // 입지 않는 경우까지 포함
            answer *= (mm.second + 1);
        }
        
        // 아무것도 안 입는 경우를 제외
        answer -= 1;
        ans.push_back(answer);

    }

    for (auto num : ans)
        cout << num << '\n';
}