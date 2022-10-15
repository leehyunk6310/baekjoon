#include <iostream>
using namespace std;

int arr[21] = {0, };
int M;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> M;
    for (int i=0; i<M; i++)
    {        
        string cmd;
        int num;
        
        cin >> cmd;

        if (cmd == "add")
        {
            cin >> num;            
            arr[num] = 1;
        }
        else if (cmd == "remove")
        {
            cin >> num;
            arr[num] = 0;
        }
        else if (cmd == "check")
        {
            cin >> num;
            cout << (arr[num] == 1 ? 1 : 0) << '\n';
        }
        else if (cmd == "toggle")
        {
            cin >> num;
            if (arr[num] == 1)
                arr[num] = 0;
            else
                arr[num] = 1;
        }
        else if (cmd == "all")
        {
            for (int j=1; j<=20; j++)
                arr[j] = 1;
        }
        else if (cmd == "empty")
        {
            for (int j=1; j<=20; j++)
                arr[j] = 0;
        }
        
        
    }
    
}