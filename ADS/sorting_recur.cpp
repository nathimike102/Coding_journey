#include<bits/stdc++.h>
using namespace std;

// void bubbleSort(int *arr, int n){
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n-i-1;j++){
//             if(arr[j]>arr[j+1]){
//                 int temp=arr[j];
//                 arr[j]=arr[j+1];
//                 arr[j+1]=temp;
//             }
//         }
//     }
// }

// void bubbleSort(int *arr, int n,int i){
//     if(n==0 || i==n-1){
//         return;
//     }
//     if(arr[i]>arr[i+1]){
//         int temp=arr[i];
//         arr[i]=arr[i+1];
//         arr[i+1]=temp;
//     }
//     bubbleSort(arr,n,i+1);    
//     bubbleSort(arr,n-1,0);
// }

void merge(int *arr, int low, int mid, int high){
    int res[(high-low)+1], i = low, j = mid + 1, k = 0;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            res[k++] = arr[i++];
        } else {
            res[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        res[k++] = arr[i++];
    }
    while (j <= high) {
        res[k++] = arr[j++];
    }
    for(i = low, k = 0; i <= high; i++, k++){
        arr[i] = res[k];
    } 
}
void merge_sort(int *arr, int low, int high){
    if(low>=high){
        return;
    }
    int mid = (low+high) >> 1;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid+1, high);
    merge(arr, low, mid, high);
}
int main(){
    int arr[]={9,4,7,3,8,2,17,0,12,6,40};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Before sorting"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\nAfter sorting"<<endl;
    // bubbleSort(arr, n, 0);
    merge_sort(arr, 0, n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }     
}