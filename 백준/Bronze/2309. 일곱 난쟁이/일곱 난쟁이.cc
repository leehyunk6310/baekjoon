#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 모든 난쟁이의 키의 합을 찾아본다.
// 순열
vector<int> height;
vector<int> answer;
int main()
{
    for (int i=0; i<9; i++)
    {
        int h;
        cin >> h;
        height.push_back(h);
    }
    sort(height.begin(), height.end());

    do
    {
        int sum = 0;
        for (int i=0; i<7; i++)
        {
            sum += height[i];
        }
        if (sum == 100)
        {
            for (int j=0; j<7; j++)
                answer.push_back(height[j]);
            break;
        }
    } while (next_permutation(height.begin(), height.end()));
    

    for (auto h : answer)
        cout << h << '\n';

    
}