#include<iostream>

//THE PROPERTY (for the element just before the answer, answer would then simply be next element from this): Most rightward element which has the property: f(n)<f(n+1))
// PS: You could modify the property according to how you wanna solve this question. Like if you started from right,it would be different. Think if you can ;)


//THE RULE: One part of the array follow the rule : fn<fn+1. The other part follows the inverse. We have to find the element which follows both. So we would find the 
//rightmost of first


//Strategy: Keep jumping(with decreasing size jumps) right untill property is satsified. When property isn't satisfied, increment one and jump.

//First we assume that the functions is f(i)=n; Where i is the index of array and n=arr[i]. 
// We are given first that the funcion has only one global peak ,hence we have to find it.
// CORE: When we land on an element, then based on the rule it follows with its neighbours, we ask it the question resonating the rule.
// Based on what it says, we control our jump. 



int globalPeak(int* arr,int n){
    int k=0;
    for(int jump=n/2;jump>=1;jump/=2){
        while(jump+k<n && arr[jump+k+1]>arr[k]) k+=jump;
    }

    //we are going towards maximum element that 
    return k+1;
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10,11,12,14,60,5,4,3,2,1,0};
    int i=globalPeak(arr,20);
    std::cout<<"Peak is at index: "<<i<<" with values "<<arr[i]<<"\n";
}