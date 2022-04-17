#include<bits/stdc++.h>

using namespace std;


struct Node{
    char c;
    struct Node* next;
};

int CompareTwoLists(struct Node* n1,struct Node* n2){
    Node* temp1=n1;
    Node* temp2=n2;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->c==temp2->c){
            temp1=temp1->next;
            temp2=temp2->next;
            continue;
        }
        else if(int(temp1->c)>int(temp2->c)){
            return 1;
        }
        else return -1;
    }
    if(temp1!=NULL){
        return 1;
    }else if(temp2!=NULL){
        return -1;
    }
    return 0;
}

int main(){

}