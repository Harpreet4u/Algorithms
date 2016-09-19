// joining list of integers to form largest number
#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

bool comp(string a, string b) {
    return a+b>b+a;
}

int main() {

    int n, tmp;
    vector<int> A;

    cin>>n;
    while(n--) {
        cin>>tmp;
        A.push_back(tmp);
    }

    vector<string> num;

    for (int i=0;i<A.size();i++) {
        num.push_back(to_string(A[i]));
    }
    
    sort(num.begin(), num.end(), comp);
    string str;
    for(int i=0;i<num.size();i++)
      str += num[i];

    cout<<str<<endl;

    return 0;
}
