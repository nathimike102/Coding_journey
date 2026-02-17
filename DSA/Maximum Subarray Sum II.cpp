//https://cses.fi/problemset/task/1644
#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define pb push_back
#define F first
#define S second
#define pi pair<int,int>
#define MAX_X 1024
/*============================Run Debug code =============================*/
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" " ; _print(x); cerr<<endl;
#else
#define debug(x)    
#endif
/*----------------------------------------------------------------------------*/
#define rep(i,a,b) for(int i = a ; i < b ; i++)
#define rrep(i,a,b) for(int i = a ; i >= b ;i--);
#define vi vector<ll>
#define StoB(A) sort(A.begin(),A.end())
#define BtoS(A) sort(A.rbegin(),A.rend())
using namespace std;
const int mod = (int)1e9 + 7;
vector<ll>bit;
/*===============================debugging templates ==============================================*/
template<class T>void _print(T a){cerr << a;}
template<class T> void _print(vector<T>v1){cerr<<"[";for(T i : v1)cerr<<i<<" ";cerr<<"]";}
template<class T> void _print(set<T>st){cerr <<"[" ; for(T i : st)cerr<<i<<" ";cerr<<"]";}
template<class T, class U> void _print(map<T,U>mp){for(T i : mp){cerr << i.F <<" : "<<i.S;}}
template<class T, class U> void _print(unordered_map<T,U>mp){for(T i : mp){cerr << i.F <<" : "<<i.S;}}


/*======================================MATHS================================================*/
ll gcd(ll x, ll y){
    if(y == 0)return x;
    else return gcd(y,x % y);
}
ll power(ll a, ll b){
    if(b == 0)return 1;
    ll x = power(a , b / 2);
    if(b % 2){
        return (x%mod*x%mod*a%mod) % mod;
    }
    else{
        return (x*x) % mod;
    }
}
ll inverse(ll a){
    return power(a,mod-2);
}
// NcR -> Primes -
void Don() {
    ll n , a , b;
    cin >> n >> a >> b;
    vi A(n);
    for(int i = 0 ; i < n ; i++)cin >> A[i];
    vi prefix(n+1,0);
    for(ll i = 1 ; i <= n ; i++){
        prefix[i] = prefix[i-1] + A[i-1];
    }
    multiset<ll>ms;
    ll ans = LONG_MIN;

    for(ll i = a ; i <= n ; i++){
        if(i > b){
            ms.extract(prefix[i - b - 1]);
        }
        ms.insert(prefix[i-a]);
        ans = max(ans, prefix[i] - *ms.begin());
    }
    cout << ans << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    Don();
    return 0;
}
