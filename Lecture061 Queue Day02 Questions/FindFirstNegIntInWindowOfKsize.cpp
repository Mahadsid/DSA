#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<stack>
using namespace std;



/* algo- using double ended que
process first K size and store it index
ans= dq.front();

then process age wali windows
remove wrong element
additinon 
*/
vector<long long> printFirstNegativeInteger(long long int A[], long long int N , long long int K){
    
    deque<long long int> dq;
    vector<long long> ans;

    //process first window of size k
    for (int i = 0; i < K; i++)
    {
        if (A[i]<0)
        {
            dq.push_back(i);
        }
        
    }
    // store ans for first k size window
    if (dq.size() > 0)
    {
        ans.push_back( A[dq.front()] );
    }
    else{
        ans.push_back(0);
    }

    //process for remaining windows
    for (int i = K; i < N; i++)
    {
        //removal

        if (!dq.empty() && i - dq.front() >= K)
        {
            dq.pop_front();
        }

        //addition
        if (A[i] < 0)
        {
            dq.push_back(i);
        }

        if (dq.size() > 0){
        ans.push_back( A[dq.front()] );
        }
        else{
            ans.push_back(0);
        }
    }
    return ans; 
}