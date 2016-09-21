// http://www.geeksforgeeks.org/given-an-array-arr-find-the-maximum-j-i-such-that-arrj-arri/
#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int maxx(vector<int> &v) {
    int maxDiff;
    int i, j;
 
        int n = v.size();
    vector<int> LMin;
    vector<int> RMax;
 
    LMin.push_back(v[0]);
    for (i = 1; i < v.size(); ++i)
        LMin.push_back(min(v[i], LMin[i-1]));
 
    RMax.push_back(v[n-1]);
    for (j = n-2; j >= 0; --j)
        RMax.push_back(max(v[j], RMax[n-j-2]));
 
    reverse(RMax.begin(), RMax.end());
    i = 0, j = 0, maxDiff = -1;

    while (j < n && i < n) {
        if (LMin[i] < RMax[j]) {
            maxDiff = max(maxDiff, j-i);
            j++;;
        }
        else
            i++;
    }
 
    return maxDiff;
}

int main() {
    vector<int> v;
    int n, tmp;
    cin>>n;
    while (n--) {
        cin>>tmp;
        v.push_back(tmp);
    }

    cout<<maxx(v);

    return 0;
}
