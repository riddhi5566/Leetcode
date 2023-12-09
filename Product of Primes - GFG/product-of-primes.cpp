//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long primeProduct(long long L, long long R){
        // code here
        long long int M = pow(10, 9) + 7;
        long long int ans =1 ;
        vector<bool> seg = segSieve(L , R);
        
        for(int i = 0; i <seg.size(); i++)
        {
            if(seg[i])
            {
                ans = (ans * (i + L)) % M;
            }
        }
        return ans;
    }
    
    vector<bool> Sieve(long long n)
    {
        vector<bool> sieve(n+1 , true);
        sieve[0] = sieve[1] = false;
        
        for(int i = 2; i * i <= n ; i++)
        {
            if(sieve[i])
            {
                int j = i * i;
                while( j <= n)
                {
                    sieve[j] = false;
                    j += i;
                }
            }
        }
        
        return sieve;
    }
    
    vector<bool> segSieve(long long L, long long R)
    {
        vector<bool> sieve = Sieve(sqrt(R));
        vector<int> basePrimes;
        for(int i = 0; i < sieve.size(); i++)
        {
            if(sieve[i])
            basePrimes.push_back(i);
        }
        
        vector<bool> segSieve(R - L + 1, true);
        if(L == 1)
        {
            segSieve[0] = false;
        }
        
        for(auto prime : basePrimes)
        {
            int firstMul = (L / prime) * prime;
            if(firstMul < L)
            {
                firstMul += prime;
            }
            
            int j = max(firstMul, prime * prime);
            while(j <= R)
            {
                segSieve[j - L] = false;
                j += prime;
            }
        }
        
        return segSieve;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long L, R;
        cin>>L>>R;
        
        Solution ob;
        cout<<ob.primeProduct(L, R)<<"\n";
    }
    return 0;
}
// } Driver Code Ends