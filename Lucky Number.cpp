//      BISMILLAH-IR-RAHMAN-IR-RAHIM


#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef unsigned long long ull ;
typedef vector<int> vi ;
typedef vector<ll> vl ;
typedef vector<vi> vvi ;
typedef vector<vl> vvl ;
typedef pair<int, int> pii ;
typedef pair<float, float> pff ;
typedef pair<double, double> pdd ;
typedef pair<ll, ll> pll ;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds ;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
#define pb push_back
#define PI 3.14159265358979323
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define fastIO	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0) ;
ll bin_expo(ll base, ll pow, ll m)
{       if (pow == 0) return 1 ; 
        ll ret = bin_expo(base, pow / 2, m) % m ;
        if (pow & 1)return (ret % m * ret % m * base % m) % m ; 
        else return (ret % m * ret % m) % m;}
ll mod_add(ll a, ll b, ll m) { return ( ( a % m ) + ( b % m ) ) % m ; }
ll mod_sub(ll a, ll b, ll m) { return ( ( a % m ) - ( b % m ) ) % m ; }
ll mod_mul(ll a, ll b, ll m) { return ( ( a % m ) * ( b % m ) ) % m ; }
ll mod_div(ll a, ll b, ll m) { return ( ( a % m ) * bin_expo(b, m - 2, m) ) % m ; }
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b) ; }
int dx[] = {0, 0, +1, -1, +1, -1, -1, +1} ; 
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1} ;  
const ll infLL = 4e18 + 123 ; 
const ll inf = 1e17 + 7 ; 
const ll mod = 1e9 + 7 ; 
const ll mod2 = 1e9 + 9 ; 
const int mx = 1e5 + 123 ;
const int mxx = 3e6+123 ;  
const double eps = 1e-7 ; 


// forever-striver 


int tc = 0 ;  
ordered_set<int>st ; 

void precalculate() {

        for(int i=1;i<=mxx;i+=2) {
                st.insert(i) ; 
        }
        int curr_pos = 2 ; 
        int curr_key = 3 ; 
        while(st.size()>=curr_key) {
                int delcnt = 0 ; 
                int sz = st.size() ; 
                for(int i=curr_key;i<=sz;i+=curr_key) {
                        int index = i - 1 - delcnt ;
                        st.erase(st.find_by_order(index)) ; 
                        delcnt ++  ;  
                }
                curr_key = *(st.find_by_order(curr_pos)) ; 
                curr_pos ++ ; 
        }
}


void solution()
{
        int n ; 
        cin >> n  ; 
        cout << "Case " << ++tc << ": " << *(st.find_by_order(n-1)) ; 
        cout << endl ; 
}       


int main() 
{ 
        fastIO ;
        // file() ;
        precalculate() ; 
        int _ = 1; cin >> _ ;
        while (_--) solution() ;
        return 0 ;
}
