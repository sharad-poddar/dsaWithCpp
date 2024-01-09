/*

    next larger element of each element
    using the decreasing montone stack

*/

#include<iostream>
#include<unordered_map>
#include<stack>
using namespace std;
int main(){

    int arr[] = {7,2,1,6,9,5,4};
    // output = {9,6,6,9,x,x}
    int size = sizeof(arr)/sizeof(int);
    
    stack<int> s;
    unordered_map<int, int> m;

    for(int i=0;i<size;i++){
        if(s.empty()){
            s.push(arr[i]);
            continue;    
        }
        if(arr[i]<=s.top()){
            s.push(arr[i]);
        }else{
            while(arr[i]>s.top() && !s.empty()){
                m[s.top()] = arr[i];
                s.pop();
            }
            s.push(arr[i]);
        }
    }

    for(auto i: m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    return 0;
}