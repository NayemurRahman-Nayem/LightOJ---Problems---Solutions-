//      BISMILLAH-IR-RAHMAN-IR-RAHIM


#include <bits/stdc++.h>
#include<unordered_map> 
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef unsigned long long ull ;
typedef vector<ll> vl ;
typedef vector<vl> vvl ;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds ;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
#define el << '\n'
#define pb push_bachk
#define PI 3.14159265358979323
#define fastIO() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
ll bin_expo(ll base, ll pow, ll m )
{       if (pow == 0) return 1 ;
        ll ret = bin_expo(base, pow / 2, m) % m ;
        if (pow & 1)return (ret % m * ret % m * base % m) % m ;
        else return (ret % m * ret % m) % m;}
ll mod_add(ll a, ll b, ll m) { return ( ( a % m ) + ( b % m ) ) % m ; }
ll mod_sub(ll a, ll b, ll m) { return ( ( a % m ) - ( b % m ) ) % m ; }
ll mod_mul(ll a, ll b, ll m) { return ( ( a % m ) * ( b % m ) ) % m ; }
ll mod_div(ll a, ll b, ll m) { return ( ( a % m ) * bin_expo(b, m - 2, m) ) % m ; }
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
ll dx[] = {0, 0, +1, -1, +1, -1, -1, +1} ;
ll dy[] = {+1, -1, 0, 0, +1, -1, +1, -1} ;
const ll infLL = 1e18 ;
const ll inf = 1e17 + 7 ;
const ll mod = 1000000000000000002 ;
const ll mod2 = 1e9 + 9 ; 
const ll mx = 2e6 + 123 ;
const double eps = 1e-7 ;


// forever-striver 


ll tc = 0 ; 


vector<ll> nextsmall(ll n , vector<ll>&a) {

        stack<ll>st ; 
        st.push(-1) ; 
        vl arr(n) ; 
        for(ll i=n-1;i>=0;i--) {
              ll curr = a[i] ; 
              while(st.top()!=-1 && a[st.top()]>=curr) { 
                     st.pop() ;    
              } 
              arr[i] = st.top() ; 
              st.push(i) ; 
        } 
        return arr ; 
}


vector<ll> presmall(ll n, vector<ll>&a) {

        stack<ll>st ; 
        st.push(-1) ; 
        vl arr(n) ; 
        for(ll i=0;i<n;i++) { 
                ll curr = a[i] ; 
                while(st.top()!=-1 && a[st.top()]>=curr) { 
                        st.pop() ; 
                } 
                arr[i] = st.top() ; 
                st.push(i) ; 
        } 
        return arr ; 
}


void solution() {    

        ll n , ans = 0 ; 
        cin >> n ;  
        vl a(n) ; 
        for(int i=0;i<n;i++) {
                cin >> a[i] ; 
        }
        cout << "Case " << ++tc << ": " ; 
        vl nextmin = nextsmall(n,a) ; 
        vl premin = presmall(n,a) ; 
        for(int i=0;i<n;i++) {
                ll r = nextmin[i] ; 
                ll l = premin[i] ; 
                if(nextmin[i]==-1) r = n ; 
                ll k = r-l-1 ; 
                ll temp = a[i] * k ; 
                ans = max(ans,temp) ; 
        }
        cout << ans << endl ; 
}


int main() {
        fastIO();
        // file() ; 
        ll _ = 1; cin >> _;
        while (_--) solution();
        return 0;
}
