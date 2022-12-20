#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    vector<double> v;
    double score, maxScore, avg=0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> score;
        v.push_back(score);
    }

    maxScore = v[0];
    for (int i = 0; i < n; i++)
    {
        if (v[i] > maxScore){
            maxScore = v[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        v[i] = v[i]/maxScore*100;
        avg += v[i];
    }
    avg /= n;
    cout << avg;
    
    

    
    
    
    
}