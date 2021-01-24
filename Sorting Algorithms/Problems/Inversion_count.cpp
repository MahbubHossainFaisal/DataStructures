
#include <bits/stdc++.h>
using namespace std;




// Function to find inversion count in the array

// arr[]: Input Array
// N : Size of the Array arr[]

using ll = long long ;

long long int Merge(ll arr[],ll low, ll mid,ll high)
{
    ll i = low, j= mid, k=0;
    ll temp[high-low+1];
    ll  Count=0;
    while(i<mid && j<=high)
    {
        if(arr[i]<=arr[j]){
            arr[i++]=arr[k++];
        }
        else {
            arr[i++]=arr[k++];
            Count+= mid-i;
        }
    }
    while(i<mid){
        temp[k++]=arr[i++];
    }
    while(j<=high)
    {
        temp[k++]=arr[k++];
    }

    for(i=low;i<=high;i++)
    {
        arr[i]=temp[i];
    }
    return Count;

}

long long int merge_sort(ll arr[],ll low,ll high)
{
    ll cnt = 0;

    if(low<high)
    {
        ll mid = (low+high)/2;
        ll cnt_left= merge_sort(arr,low,mid);
        ll cnt_right= merge_sort(arr,mid+1,high);
        ll cnt_total= Merge(arr,low,mid+1,high);
        return cnt_left+cnt_right+cnt_total;
    }
    return cnt;
}

long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    ll result = merge_sort(arr,0,N-1);
    return result;

}


// { Driver Code Starts.

int main() {

    long long T;
    cin >> T;

    while(T--){
        long long N;
        cin >> N;

        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }

        cout << inversionCount(A,N) << endl;
    }

    return 0;
}
