#include<iostream>

//THE PROPERTY(for element to be found): (p1)Smallest number (p2)in the set of numbers(from given numbers) all larger from required element.

//THE RULE- Each element tells us something about the entire array depending on which element we ask. The rule is; for every element f(n-1)<=fn<=fn+1
//Thus expanding we would get nC2 rules,each element has some rule with each other element. like f(1)<=f(12).

//The strategy: keep jumping right untill p2 is not satisifed. If its satisfied, we are in the set,but still haven't coverd p1. So dont jump, increment by 1 and try jumping now. repeat.




void fillArr(int* arr,int size){
    for(int i=0;i<size;i++) arr[i]=2*i;
}

//Returns left closest (because i started from left) number index to given number.
int binSearch(int* arr,int size,int n){
    int k=0;
    for(int jump=size/2 ; jump>=1 ; jump/=2){

        while( k+jump<size  && arr[k+jump]<=n)       k+=jump;          //JUMP further 
    }

    //we are now as close to the element as we could. Either this is the element or its not here.
    return k;
}
int main(){
    int* arr=new int[1000];
    fillArr(arr,1000);
    int x;
    std::cout<<"Enter the number to find:\n";
    std::cin>>x;
    std::cout<<"Index of "<<x<<" is: "<<binSearch(arr,1000,x)<<"\n";
    delete[] arr;


}