#include<bits/stdc++.h>
using namespace std;

int isSorted(int *arr, int n){
    if(n==0 || n==1){
        return true;
    }
    if(arr[0] <= arr[1] && isSorted(arr+1, n-1)){
        return true;
    }
    return false;
}

int FirstOcc(int *arr, int n, int key){
    if(n==0){
        return -1;
    }
    int sub = FirstOcc(arr+1, n-1, key);
    if(sub == -1){
        if(arr[0]==key) return 0;
        else return -1;
    }
    return sub+1;
}

int LastOcc(int *arr, int n,int key){
    //finish off the function
}

int main(){
    int arr[] = {2, 7, 8, 12};
    int length = sizeof(arr)/sizeof(arr[0]);
    //int res = isSorted(arr, length);
    int ans = FirstOcc(arr, length, 8);
    //printf("%d\n", res);
    printf("%d", ans);
}