/*

    sum of subarray minimums 
    we have to sum the subarray minimum values 
    stack is used
    finding the number of subarrays where minimum is number -> (g1+1)*(g2+1)


*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){

    int arr[] = {2,9,7,8,3,4,6,1};
    int size = sizeof(arr)/sizeof(int);

    stack<int> s1, s2;
    // vector with size same as of array
    vector<int> next_smaller(size), prev_smaller(size);

    for(int i=0;i<size;i++){
        next_smaller[i] = size-i-1;
        prev_smaller[i] = i;
    }

    // calculation of next smaller element
    for(int i=0;i<size;i++){
        while(!s1.empty() && arr[s1.top()]>arr[i]){
            next_smaller[s1.top()] = i-s1.top()-1;
            s1.pop();
        }
        s1.push(i);
    }

    //calculating the prev smaller
    for(int i=size-1;i>=0;i--){
        while(!s2.empty() && arr[s2.top()]>arr[i]){
            next_smaller[s2.top()] = s2.top()-i-1;
            s1.pop();
        }
        s2.push(i);
    }

    int ans = 0;
    


}