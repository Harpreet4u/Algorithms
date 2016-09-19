#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main() {

    int n;
    cin>>n;

    vector<vector<int> > v;
    vector<int> s;

    s.push_back(1);
    v.push_back(s);

    if (n == 0) {
        cout<<0<<endl;
    }

    if (n == 1) {
        cout<<1<<endl;
    }

    for (int i=2;i<=n;i++) {
        vector<int> g;
        for (int j=1;j<=i;j++)  {
            if (j == 1 || j == i) 
                g.push_back(1);
            else {
                g.push_back(v[i-2][j-1]+v[i-2][j-2]);
            }
        }
        v.push_back(g);
    }

    for (int i=0;i<v.size();i++) {
        for (int j=0;j<=i;j++) {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
