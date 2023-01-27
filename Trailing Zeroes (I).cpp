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
#define el << '\n'
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
const int mx = 1e6 + 123 ;
const int mxx = 3e6+123 ;
const double eps = 1e-7 ;


// forever-striver


bitset<mx>vis ;
vector<ll> prime ;
ll tc = 0 ;
void sieve()
{
        vis[1]=1;
        for(int i=3;i*i<mx;i+=2)
        {
                if(!vis[i])
                {
                        for(int j=i*i;j<mx;j+=2*i)
                        {
                                vis[j] = 1 ;
                        }
                }
        }
        for(int i=4;i<mx;i+=2) vis[i]=1 ;
        prime.push_back(2) ;
        for(int i=3;i<mx;i+=2)
        {
                if(!vis[i]) prime.push_back(i) ;
        }
}

ll nod(ll n)
{
        ll ret = 1 ;
        for(auto i:prime)
        {
                if(i*i>n) break ;
                if(n%i==0)
                {
                        int cnt = 1 ;
                        while(n%i==0)
                        {
                                cnt ++ ;
                                n/=i ;
                        }
                        ret = ret*cnt ;
                }
        }
        if(n!=1)
        {
                ret = ret * 2 ;
        }
        return ret ;
}


void solution() {

        ll n;
        cin >> n;
        cout << "Case " << ++tc << ": " << nod(n)-1 el ;
}


int main()
{
        fastIO ;
        // file() ;
        sieve() ;
        int _ = 1; cin >> _ ;
        while (_--) solution() ;
        return 0 ;
}
