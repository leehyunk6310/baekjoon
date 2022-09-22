#include <string>
#include <vector>

using namespace std;

long  answer = 0;
long  sum1 = 0;
long  sum2 = 0;
long  target;
long  ptr1=0, ptr2=0;

void pop(vector<int>& queue1, vector<int>& queue2, long index)
{
    if (index == 1)
    {
        long val = queue1[ptr1];
        queue2.push_back(val);
        sum1 -= val;
        sum2 += val;
    }
    else
    {
        long val = queue2[ptr2];
        queue1.push_back(val);
        sum1 += val;
        sum2 -= val;
    }    
}

int solution(vector<int> queue1, vector<int> queue2) {        
    // 합을 계산
    for (auto n : queue1)
        sum1 += n;
    for (auto n : queue2)
        sum2 += n;
    
    long q1Size = queue1.size();
    long q2Size = queue2.size();
    
    if ((sum1 + sum2) %2 != 0)
        return -1;
    
    target = (sum1 + sum2)/2;
    
    while (sum1 != target && sum2 != target)
    {
        if (sum1 > sum2)
        {
            pop(queue1, queue2, 1);
            ptr1++;
        }
        else
        {
            pop(queue1, queue2, 2);
            ptr2++;
        }
           
        if (ptr1 >= q1Size + q2Size || ptr2 >= q1Size + q2Size)
        {
            return -1;
        }
        
        answer++;
        
        if (sum1 == 0 || sum2 == 0)
            return -1;
        
    }
    
    
    return answer;
}