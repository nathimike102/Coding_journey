// #include<stdio.h>
// int main(){
// 	int n;
// 	scanf("%d",&n);
// 	int arr[n];
// 	for(int i=0;i<n;i++){
// 		scanf("%d",&arr[i]);
// 	}
// 	for(int i=0;i<n;i++){
// 		for(int j=i;j<n;j++){
// 			for(int k=i;k<=j;k++){
// 				printf("%d ",arr[k]);
// 			}
// 			printf("\n");
// 		}
// 	}
// 

//Power set for subsequences
#include<stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			int mask=(1<<j);
			if((i & mask) > 0){
				printf("%d", arr[j]);
			}
		}
		printf("\n");		
	}
}

// //Problem 1 in cpp
// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int n;
//     cin>>n;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     bool flag=false;
//     int sum=0;
//     for(int i=0;i<(1<<n);i++){
//         for(int j=0;j<n;j++){
//             if(i&(1<<j)){
//                 sum+=arr[j];
//             }
//             else{
//                 sum-=arr[j];
//             }
//         }
//         if(sum==0 || sum==360){
//             flag=true;
//             break;
//         }
//         sum=0;
//     }
//     if(flag==true) cout<<"YES";
//     else cout<<"NO";
// }