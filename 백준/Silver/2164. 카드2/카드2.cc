#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n,cnt=1;
    queue<int> q;

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    while(q.size() != 1){
        if(cnt %2 != 0){
            q.pop();
        }
        else{
            q.push(q.front());
            q.pop();
        }
        cnt ++;
    }
    cout << q.front();
    
}