/*
    1. monotone stack(line wise)
    concept of decreasing and increasing stack
    used when -> next greater/previous greater or smaller element
    smaller element -> increasing stack
*/

//1. next smaller element of an element of an array
#include<iostream>
#include<stack>
#include<unordered_map>
using namespace std;
int main(){

    int arr[] = {6,2,9,4,3,1,5};
    // output = {2,1,4,3,1,,x,x}
    int size = sizeof(arr)/sizeof(int);
    stack<int> s;
    unordered_map<int,int> m;

    for(int i=0;i<size;i++){

        if(s.empty()){
            s.push(arr[i]);
            continue;
        }
        if(s.top()<=arr[i]){
            s.push(arr[i]);
        }else{
            while(!s.empty() && s.top()>arr[i]){
                m[s.top()] = arr[i];
                s.pop();
            }
            s.push(arr[i]);
        }
        
    }

    for(auto l: m){
        cout<<l.first<<" "<<l.second<<endl;
    }

    return 0;
}