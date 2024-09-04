#include<bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" " ; _print(x); cerr <<endl;
#else
#define debug(x);
#endif

#define FOR(i,a,b) for(int i = a ; i < b ; i++)

using namespace std;
//======================= debugging templates ========================
void _print(int a){cerr << a;}
void _print(char a){cerr << a;}
void _print(string a){cerr << a;}
template<class T, class V> void _print(T a, T b){_print(a); _print(b);}
template<class T> void _print(vector<T>v1){cerr<<"[ ";for(T i : v1)cerr<<i<<" ";cerr<<"]";}
template<class T> void _print(set<T>st){ cerr<<"[ ";for(auto i : st)cerr<<i<<" ";cerr<<"]";}
template<class T, class V> void _print(pair<T,V>p){cerr<<"( ";_print(p.first);cerr<<" , ";_print(p.second);cerr<<" )";}

//=====================================================================
int main(){
    #ifndef ONLINE_JUDGE
    freopen("Error.txt","w",stderr);
    #endif
    int a = 20 , b = 100;

    //lot code here

    a *= a;
    debug(a);
    debug(b);
    //lot code
    vector<int>v1 = {1, 2, 3};
    debug(v1);
    v1[2] = 100;
    debug(v1);
}