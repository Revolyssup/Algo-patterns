// Given a string and a number of lines k, print the string in zigzag form. In zigzag, characters are printed out diagonally from top left to bottom right until reaching the kth line, then back up to top right, and so on.

// For example, given the sentence "thisisazigzag" and k = 4, you should print:

// t     a     g
//  h   s z   a
//   i i   i z
//    s     g

#include<bits/stdc++.h>

using namespace std;
//step 1- calculate y coordinate based on some function that takes in input index and k & spits out y coordinate. 
//step 2- Create a map with the pair of coordinates as keys and actual characters as values.
//step 3- Loop till s.size()-1, the outside loop with go from y=0->k-1. Whenver we encounter a (x,y) pair that has an associated character, we print it
//else we print space.

void printZigZag(string s,int k){
    int n=s.size();
    if(k==0 || k==1){
        for(int i=0;i<s.size();i++){
            cout<<s[i];
        }
        return;
    }
    map<pair<int,int>,char> store;

    //step 1
    int p=0;
    bool godown=true;
    for(int i=0;i<s.size();i++){
        store[{i,p}]=s[i];
        //calculating if we wanna go down or up in next iteration.
        if(p==k-1) godown=false;
        if (p==0) godown=true;
        //setting p for next iteration. p is y coordinate
        if(godown) p++;
        else p--;
    }

    for(int y=0;y<k;y++){
        for(int x=0;x<s.size();x++){
            if(store[{x,y}]!=0){
                cout<<s[x];
            }else{
                cout<<" ";
            }
        }
        cout<<"\n";
    }

}

int main(){
    string s;
    int k;
    cout<<"Enter string: \n";
    cin>>s;
    cout<<"Enter height of zigzag: \n";
    cin>>k;
    printZigZag(s,k);
}