// Binary search for left and right dups range algo
#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;


int main() {
    int arr[] = {1,2,3, 4, 4, 4, 4};
    int l=0, r = (sizeof(arr)/sizeof(arr[0])) - 1;
    int mid;

    // left start of dups.
    while (l<r) {
        mid = l + (r-l)/2; // mid is left biased due to floor of int.
        if (arr[mid]<4)
          l = mid + 1;
        else
          r = mid;
    }


    cout<<"Left start: "<<l<<endl;

    l = 0;
    r = (sizeof(arr)/sizeof(arr[0])) - 1;
    // right end of dups.
    while (l<r) {
        mid = l + (r-l)/2 + 1; // making mid right biased
        if (arr[mid]>4)
          r = mid-1;
        else
          l = mid;
    }

    cout<<"Right end: "<<r<<endl;


    return 0;
}
