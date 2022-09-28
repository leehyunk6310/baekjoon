#include <iostream>
using namespace std;

int n;
int arr[100001];
int answer = -1e9;
int main()
{
    cin >> n;
    for (int i=0; i<n; i++)
    {
        int num;
        cin >> num;

        if (i == 0)
        {
            arr[i] = num;            
        }
        else
        {
            if (num + arr[i-1] > num)
            {
                arr[i] = num + arr[i-1];
            }
            else
                arr[i] = num;
        }
        answer = (arr[i] > answer ? arr[i] : answer);
    }

    cout << answer;
}