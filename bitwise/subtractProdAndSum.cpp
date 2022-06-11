class Solution {
public:
    int subtractProductAndSum(int n) {
        
        int prod = 1;
        int sum = 0;
        
        while(n!=0) {
            
            int digit = n%10;
            prod = prod * digit;
            sum = sum + digit;
            
            n = n/10;
        }
        
        int answer = prod - sum;
        
        return answer;
    }
    
};

#include<iostream>
using namespace std;

int main(){
    
    Solution obj1;
    int ans;
    ans = obj1.subtractProductAndSum(234);
    cout<<ans;
}