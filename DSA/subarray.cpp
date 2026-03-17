/*
count subarrays
    1. exactly k disctinct
    2. each disctinct appears at least m times

    1.segment one and two (type 1 and type 2 read)

*/
// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     unordered_map<int, int> mpp;
//     int i=0, j=0, k=2, m=2, ans=0;
//     long long count = 0;
//     vector<int> arr = {1, 2, 1, 3, 2};
//     while(j<arr.size()){
//         mpp[arr[j]]++;
//         while(mpp.size()>=k){
//             mpp[arr[i]]--;
//             if(mpp[arr[i]]==0) mpp.erase(arr[i]);
//             i++;
//             count++;
//         }
//     }
//     cout << count << endl;
// }

bool check(vector<int> &freq1, vector<int> &freq2){
    for(int i=0; i<26; i++){
        if(freq1[i]>freq2[i]) return false;
    }
    return true;
}

string solve(string &s, string &p){
    vector<int> freq1(26), freq2(26);
    for(int i=0; i<p.size(); i++){
        freq1[p[i]-'a']++;
    }
    int i=0, j=0;
    int start = -1, end = -1;
    int ans = INT_MAX;
    while(j<s.size()){
        freq2[s[j]-'a']++;
        while(check(freq1, freq2)){
            if(ans>j-i+1){
                ans = j-i+1;
                start = i;
                end = j;
            }
            freq2[s[i]-'a']--;
            i++;
        }
        j++;
    }
    if(ans==INT_MAX) return "";
    return s.substr(start, ans);
}
