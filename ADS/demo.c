//Brute Force
#include<stdio.h>
#include<string.h>
int numberOfSubstrings(char* s) {
    int len=strlen(s);
    int count=0;
    for(int i=0;i<len;i++){
        int ones=0,zeros=0;
        for(int j=i;j<len;j++){
            if(s[j]=='0'){
                zeros++;
            }
            else{
                ones++;
            }
            if(zeros*zeros <= ones){
                count++;
            }
        }
    }
    return count;
}

//Prefix algorithm

// int numberOfSubstrings(char* s) {
//     int len=strlen(s);
//     int count=0;
//     for(int i=0;i<len;i++){
//         printf("Nathi is cool\n");
        
//     }
//     return count;
// }


#include<bits/stdc++.h>
using namespace std;
 
string binaryConvert(int n, string res, int j){
    if(n==0){
        return res;
    }
    int rem = n % 2;
    res = res + to_string(rem);
    return binaryConvert(n/2, res, j+1);
}
 
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        string res = binaryConvert(n, "", 0);
        cout<<res<<endl;
    }
}