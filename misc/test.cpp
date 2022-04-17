#include<bits/stdc++.h>
using namespace std;

void cleanup(vector<int>& h){
         while(h[0]==0 && h.size()!=0){
            std::cout<<"DELETING FIRST";
            h.erase(h.begin());
        }
        while(h[h.size()-1]==0 && h.size()!=0){
            std::cout<<"DELETING LAST";
            h.erase(h.end());
        }
}
int main(){
  
    vector<int> h={1,0,2,1,0,1,3,2,1,2,1};

    cleanup(h);
    for(int i=0;i<h.size();i++){
        cout<<" "<<h[i];
    }
}
