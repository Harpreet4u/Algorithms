#include<iostream>
#include<cstdio>
#include<vector>

#define FOR(x) for (int i=0;i<x;i++)

using namespace std;


void another_solution(vector<int> &v) {
    
    //Alternate solution
    // Swap all positives to their respective indexed
    for(int i=0;i<v.size();i++){
      if(v[i]>0 && v[i]<=v.size()){
          int pos = v[i]-1;
          if(v[pos]!=v[i]){
              swap(v[pos],v[i]);
              i--;
          }
      }
    }

    for (int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;


  for(int i=0;i<v.size();i++){
      if(v[i]!=i+1) return i+1;
  }

  cout<< v.size()+1;
}

int main() {

    int n, tmp;
    vector<int> v;
    cin>>n;
    while (n--) {
        cin>>tmp;
        v.push_back(tmp);
    }

    // moving all -ve and 0 numbers to left side.
    int j = 0;
    for (int i=0;i<v.size();i++) {
        if (v[i] <= 0) {
            tmp = v[j];
            v[j] = v[i];
            v[i] = tmp;
            j++;
        }
    }

    //cout<<"j: "<<j<<endl;

    int s = v.size() - j;
    // make all postive number index positions -ve
    for(int i=j;i<v.size();i++) {
        if (abs(v[i])-1+j<v.size() && v[abs(v[i])-1+j]>0){
                v[j+abs(v[i])-1] = -v[j+abs(v[i])-1];
        }
    }

    for (int i = j;i<v.size();i++) {
        cout<<endl<<v[i]<<" ";
    }
    cout<<endl;
    for(int i=j;i<v.size();i++) {
      // in positive range find first positive element, it's index is missing integer :)
      if (v[i]>0) {
          cout<<i+1-j<<endl;
          return 0;

        }
    }

    cout<<s+1;
    return 0;
}
