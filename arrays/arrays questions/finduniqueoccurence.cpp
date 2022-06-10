#include<bits/stdc++.h>
#include<vector>
using namespace std;
using std::cout; using std::endl;
using std::vector;




void countocc(int arr[], int n)
{
    // Mark all array elements as not visited
    vector<bool> visited(n, false);
 
    // Traverse through array elements and
    // count frequencies
    int z=0, x=0;
    int freq[100];
    for (int i = 0; i < n; i++) {

       for(int a=0;a<=z;a++)
		{
			if(i==freq[a])
			i++;
		}
        
 
        // Skip this element if already processed
        if (visited[i] == true)
            continue;
 
        // Count frequency
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                visited[j] = true;
                freq[z]=i;
                z++;
                count++;
            }
        }
        x=x^count;

        cout << arr[i] << " " << count << endl;
    }
    if(x==0)
	cout<<"False\n";
	else
	cout<<"True\n";
}
        // return countarr;


int main() {

    int arr[6] = {1,2,2,1,1,3};
    int brr[2] = {1,2};
    int crr[10] = {-3,0,1,-3,1,1,1,-3,10,0};
    

    countocc(arr, 6);

        
    return 0;
}