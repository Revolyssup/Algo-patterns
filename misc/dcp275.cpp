#include<bits/stdc++.h>
using namespace std;


// Good morning! Here's your coding interview problem for today.

// This problem was asked by Epic.

// The "look and say" sequence is defined as follows: beginning with the term 1, each subsequent term visually describes the digits appearing in the previous term. The first few terms are as follows:

// 1
// 11
// 21
// 1211
// 111221
// As an example, the fourth term is 1211, since the third term consists of one 2 and one 1.

// Given an integer N, print the Nth term of this sequence.

//First approach
string lookAndSay(int n){
    int temp1=1;
    string tempStr="";
    for(int i=2;i<=n;i++){
        string temp=to_string(temp1);
        int currCount=1;
        for(int j=0;j<tempStr.size()-1;j++){
                if(tempStr[j]==tempStr[j]+1){
                    currCount++;
                }else{
                    string lol=to_string((10*currCount+tempStr[j]));
                    temp+=lol;
                    cout<<"lol "<<temp<<"\n";
                    currCount=1;
                }
        }
    }
    return tempStr;
}

int main(){
    int n;
    cout<<"ENTER NUMBER\n";
    cin>>n;
    string ans=lookAndSay(n);
    cout<<"ANS IS "<<ans<<"\n";
}