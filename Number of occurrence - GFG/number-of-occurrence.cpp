//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
		
	int findLast(int nums[], int n,  int target)
    {
        int start = 0;
        int end = n  - 1;
        int mid = start + (end - start)/2;
        int index = -1;

        while(start <= end)
        {
            if(nums[mid] == target)
            {
                index = mid;
                start = mid + 1;
            }
            else if(target > nums[mid])
            {
                start = mid +1 ;
            }
            else
            end = mid  - 1;

            mid = start + (end - start)/2;
        }

        return index;
    }
    
    int findFirst(int nums[],int n, int target)
    {
        int start = 0;
        int end = n - 1;
        int mid = start + (end - start)/2;
        int index = -1;

        while(start <= end)
        {
            if(nums[mid] == target)
            {
                index = mid;
                end = mid -1;
            }
            else if(target > nums[mid])
            {
                start = mid +1 ;
            }
            else
            end = mid  - 1;

            mid = start + (end - start)/2;
        }

        return index;
    }
	int count(int arr[], int n, int x) {
	    // code here
	    int first = findFirst(arr,n, x );
	    int last = findLast(arr, n, x);
	    
	    if(last == first && (last < 0))
	    return 0;
	    else
	    return (last - first + 1);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends