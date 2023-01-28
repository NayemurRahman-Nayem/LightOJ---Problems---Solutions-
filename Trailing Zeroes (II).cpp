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


int tc = 0 ;

ll twocnt(ll n) {
        ll cnt = 0 ;
        while(n) {
                cnt += n/2 ;
                n/=2 ;
        }
        return cnt ;
}

ll fivecnt(ll n){
        ll cnt = 0 ;
        while(n) {
                cnt += n/5 ;
                n/=5 ;
        }
        return cnt ;
}


void solution() {

        ll n , r , p , q , two = 0 , five = 0 ;
        cin >> n >> r >> p >> q ;
        while(p>0 and p%2==0) {
                two ++ ;
                p/=2 ;
        }
        while(p>0 and p%5==0) {
                five ++ ;
                p/=5 ;
        }
        two*=q ;
        five*=q ;
        ll tw = twocnt(n) + two - twocnt(r) - twocnt(n-r) ;
        ll fv = fivecnt(n) + five - fivecnt(r) - fivecnt(n-r) ;
        cout << "Case " << ++tc << ": " ;
        cout << min(tw,fv) el ;
}


int main() {
        fastIO();
        // file() ;
        ll _ = 1; cin >> _;
        while (_--) solution();
        return 0;
}
