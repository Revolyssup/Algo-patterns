#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
            vector<string> ans={""};
            for(int i=0;i<digits.size();i++){
                ans=cross(ans,keys(digits[i]));
            }
            return ans;
    }
    vector<string> cross(vector<string> a,vector<string> b){
        vector<string> answer;
        for(int i=0;i<a.size();i++){
            for(int j=0;j<b.size();j++){
                answer.push_back(a[i]+b[j]);
            }
        }
    return answer;
    }
    vector<string> keys(char digit){
        switch(digit){
            case '2' : 
                return {"a","b","c"};
            case '3':
                return {"d","e","f"};
            case '4':
                return {"g","h","i"};
            case '5':
                return {"j","k","l"};
            case '6':
                return {"m","n","o"};
            case '7':
                return {"p","q","r","s"};
            case '8':
                return {"t","u","v"};
            case '9':
                return {"w","x","y","z"};
            default:
                return {""};
        }
}
};
int main(){
    Solution sol;
    cout<<"ENTER THE DIGITS: ";
    string digitss;
    cin>>digitss;
    vector<string> ans= sol.letterCombinations(digitss); 
    for(auto s: ans){
        cout<<", "<<s<<" ";
    }

}
