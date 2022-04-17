#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int start=0,end=height.size()-1;
        cleanup(height,start,end);
        while((end-start)>1){
            int n=nonZero(height,start,end);
            ans+=(end-start+1)-n;
            levelDown(height,start,end);
            cleanup(height,start,end);
        }      
        return ans;
    }
    void cleanup(vector<int>& h,int& start,int& end){
        while(start<h.size() && h[start]<=0 ){
            start++;
        }
        while(end>=0 &&h[end]<=0 ){
            end--;
        }
    }
    void levelDown(vector<int>& h,int start,int end){
        int i=start;
        while(i<=end){
            h[i]--;
            i++;
        }
    }
    int nonZero(vector<int>& h,int start,int end){
        int count=0;
        int i=start;
        while(i<=end){
            if(h[i]>0) count++;
           i++;
        }
        return count;
    }

};


int main(){
    Solution sol;
    vector<int> h={2,0,2};
    int ans=sol.trap(h);
    std::cout<<"ANSWER IS "<<ans;
}
