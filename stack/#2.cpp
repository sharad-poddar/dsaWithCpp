/*

    previous smaller element in an array
    simply reversing the array of the previous example, reversing the traversal

*/

#include<iostream>
#include<stack>
#include<unordered_map>
using namespace std;
int main(){

    int arr[] = {6,2,9,4,3,1,5};
    int size = sizeof(arr)/sizeof(int);
    
    stack<int> s;
    unordered_map<int, int> m;

    //changes made here...
    for(int i=size-1;i>=0;i--){
        if(s.empty()){
            s.push(arr[i]);
            continue;
        }
        if(s.top()<=arr[i]){
            s.push(arr[i]);
        }else{
            while(arr[i]<s.top() && !s.empty()){
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