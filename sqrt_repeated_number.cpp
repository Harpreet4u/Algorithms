#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

class Solution {
public:
    int repeatedNumber(const vector<int> &V) {
        if (V.size() <= 1) return -1;
        
        int valueRange = V.size() - 1; // 1 to N when the size is N+1.
        int range = sqrt(valueRange);
        if (range * range < valueRange) range++;
        int count[range + 1];
        memset(count, 0, sizeof(count));

        for (int i = 0; i < V.size(); i++) {
            // detect each element range and increment range count
            count[(V[i] - 1) / range]++;
        }

        for (int i=0;i<sizeof(count)/sizeof(count[0]);i++)
          cout<<count[i]<<" ";

        cout<<endl;
    
        int repeatingRange = -1;
        int numRanges = ((valueRange - 1) / range) + 1;
        for (int i = 0; i < numRanges && repeatingRange == -1; i++) {
            // while diving array initial ranges will be of perfect size as range.
            // if count is > range that is the repeating range
            if (i < numRanges - 1 || valueRange % range == 0) {
                if (count[i] > range) repeatingRange = i;

            } else {
                // Last portion of range might not be of size == range eg. 5%2  range sizes[2, 2, 1] 
                // last range is of size 1
                if (count[i] > valueRange % range) repeatingRange = i;
            }
        }
        if (repeatingRange == -1) return -1;
        memset(count, 0, sizeof(count));
        for (int i = 0; i < V.size(); i++) {
            // mark elemnts in that range in map
            if ((V[i] - 1) / range == repeatingRange) count[(V[i] - 1) % range]++;
        }
        for (int i = 0; i < range; i++) {
            if (count[i] > 1) {
                // get repeating elements  and get their origina values.
                return repeatingRange * range + i + 1;
            }
        }
        return -1;
    }

    int slow_fast_solution(const vector<int> &A) {
        int slow = A[0];
        int fast = A[A[0]];
        while(slow != fast) {
            slow = A[slow];
            fast = A[A[fast]];
        }
        // slow and fast pointer collided that means something repeated and caused it
     
        // Find repeated element by comparing single step slow pointers
        fast = 0;
        while (slow!=fast) {
            slow = A[slow];
            fast = A[fast];
        }
        return slow;
    }
};

int main() {

    int arr[] = {1, 2, 3, 1};
    vector<int> v(arr, arr + sizeof(arr)/sizeof(arr[0]));
    Solution *s = new Solution();
    cout<<s->repeatedNumber(v);

    return 0;
}
