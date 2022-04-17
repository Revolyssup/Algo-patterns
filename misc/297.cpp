#include<bits/stdc++.h>

using namespace std;

// At a popular bar, each customer has a set of favorite drinks, and will happily accept any drink among this set. For example, in the following situation, customer 0 will be satisfied with drinks 0, 1, 3, or 6.

// preferences = {
//     0: [0, 1, 3, 6],
//     1: [1, 4, 7],
//     2: [2, 4, 7, 5],
//     3: [3, 2, 5],
//     4: [5, 8]
// }
// A lazy bartender working at this bar is trying to reduce his effort by limiting the drink recipes he must memorize. Given a dictionary input such as the one above, return the fewest number of drinks he must learn in order to satisfy all customers.

// For the input above, the answer would be 2, as drinks 1 and 5 will satisfy everyone.
void p(){
    cout<<"here";
}
int minDrinks(map<int,vector<int>> pref,int n){
    float delta= 1/n;
    vector<float> Weight;
    for(auto i: pref){
        p();
        for(auto j:i.second){
            Weight[i.first]+=delta;
        }
    } 
    int ans=0;
    int total=0;
    sort(Weight.begin(),Weight.end());

    while (total<1){
        float i=*(Weight.end());
        if(total+i>=1){
            ans++;
            break;
        }
        total+=i;
        ans++;
    }
    return ans;
}

int main(){
    p();
    map<int,vector<int>> pref;
    pref.insert(pair<int,vector<int>>(0,{0,1,3,6}));
    pref.insert(pair<int,vector<int>>(1,{1, 4, 7}));
    pref.insert(pair<int,vector<int>>(2,{2, 4, 7, 5}));
    pref.insert(pair<int,vector<int>>(3,{3, 2, 5}));
    pref.insert(pair<int,vector<int>>(4,{5,8}));
    std::cout<<minDrinks(pref,5);
}
