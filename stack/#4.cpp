/*

    previous larger element of each element in an array in map
    using the decreasing montone stack

*/

#include<iostream>
#include<unordered_map>
#include<stack>
using namespace std;
int main(){

    int arr[] = {7,2,1,6,9,5,4};
    // output = {x,7,2,7,x,9,5}
    int size = sizeof(arr)/sizeof(int);
    
    stack<int> s;
    unordered_map<int, int> m;

    for(int i=size-1;i>=0;i--){
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