#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
    int n, arr[100000], cnt=0;
    stack<int> st;
    vector<char> vec;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        st.push(i);
        vec.push_back('+');
        
        while( !st.empty() && arr[cnt] == st.top()){
            if(cnt == n){
                break;
            }
            vec.push_back('-');
            st.pop();
            cnt++;
            
        }
        // cout << "I == " << i << endl;
    }
    
    if(!st.empty()){
        cout << "NO";
    }
    else{
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << "\n";
        }
        
    }
}
    

    

    
    
    
