// Find max customers ar a time in given arrival and departure times using sorting.

#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main() {

    int arr[] = {1, 3, 5}; // arivals
    int dep[] = {2, 6,  8}; // departures
    int k = 1;

    vector<int> a(arr, arr + 3);
    vector<int> d(dep, dep+3);

    // sorting both
    sort(a.begin(), a.end());
    sort(d.begin(), d.end());

    int i = 1, j=0, max_=0, curr = 1;

    while(i<a.size() && j<d.size()) {
        // nect guest arrived before previous departure so increment
        if (a[i] <= d[j]) {
            curr++;
            // calculate max guests so far
            if (curr>max_){
              max_ = curr;
                // check for max guest capacity
                if (max_ > k) {
                  cout<<"False";
                  return 0;
                }
            }
            i++;
        } else {
            // previous guest departed before next arrive so decrement guest count.
            curr--;
            j++;
        }
    }

    cout<<"True";
    return 0;
}
