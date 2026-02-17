#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct AggStack{
    //each element is stored as (value ,current_min);
    stack<pair<ll,ll>>st;

    //push a new number : compute the new min.
    void push(ll x){
        ll curr_min = st.empty() ? x : min(x,st.top().second); 
        st.push({x,curr_min});
    }

    void pop(){
        st.pop();
    }

    ll agg()const{
        return st.top().second;
    }


};
struct AggQueue{
    AggStack in , out;

    void push(int x){
        in.push(x);
    }

    void pop(){
        if(out.st.empty()){
            while(!in.st.empty()){
                int v = in.st.top().first;
                in.pop();
                out.push(v);
            }
        }
        out.pop();
    }

    //Queary the current min
    int queary()const{
        if(in.st.empty()) return out.agg();
        if(out.st.empty()) return in.agg();

        return min(in.agg(),out.agg());
    }
};
void GreatSolver(){
    AggQueue mq;
    ll n, k;
    cin >> n >> k;
    ll x, a, b, c;
    cin >> x >> a >> b >> c;
    vector<ll>A(n);
    A[0] = x;
    for(int i = 1 ; i < n ; i++){
        A[i] = (A[i-1] * a + b) % c;
    }

    ll i = 0;
    ll wnd_xor = 0;
    for(ll j = 0 ; j < n ; j++){
        mq.push(A[j]);
        if(j - i + 1 < k)continue;
        wnd_xor = wnd_xor ^ mq.queary();
        mq.pop();
        i++;
    }
    cout << wnd_xor << endl;

}

int main(){
    GreatSolver();
}
