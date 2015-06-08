/*
** Generates every subset of the set {0, 1, 2, 3, 4, 5, ..., N-1}.
*/
#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main() {
    int N = 3;
    for(int mask = 0; mask < (1<<N); mask++) {
        vector<int> subset;
        for(int val = 0; val < N; val++)
            if(mask & (1 << val))
                subset.push_back(val);

        cout << "{";
        for(int i=0; i < subset.size(); i++) {
            if(i)
                cout << ", ";
            cout << subset[i];
        }
        cout << "}" << endl;
    }
    return 0;
}
