//      Bismillah-ir-Rahman-ir-Rahim


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
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
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define el << '\n'
#define pb push_back
#define PI 3.14159265358979323
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define fastIO	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
ll bin_expo(ll base, ll pow, ll m)
{       if (pow == 0) return 1;
        ll ret = bin_expo(base, pow / 2, m) % m;
        if (pow & 1)return (ret % m * ret % m * base % m) % m;
        else return (ret % m * ret % m) % m;}
ll mod_add(ll a, ll b, ll m) { return (a % m + b % m) % m; }
ll mod_sub(ll a, ll b, ll m) { return (a % m - b % m) % m; }
ll mod_mul(ll a, ll b, ll m) { return (a % m * b % m) % m; }
ll mod_div(ll a, ll b, ll m) { return (a % m * bin_expo(b, m - 2, m)) % m; }
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int dx[] = {0, 0, +1, -1, +1, -1, -1, +1};
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1};
const ll infLL = 1e18 ;
const ll inf = 1e17 + 7 ;
const ll mod = 1e9 + 7 ;
const int mx = 1e6 + 123 ;
const double eps = 1e-7 ;


ull Hash[mx] ;
ull prime[mx] ;
const ull p = 3797 ;
ull n , T = 0 ;
string s , t;


ull HashCount(int x,int y)
{
        return ( Hash[y] - ( Hash[x-1]*prime[y-x+1] ) ) ; 
}


ll check(ull H)
{
        ll ret = 0 ; 
        int len = t.size() ; 
        for(int i=1;i<s.size();i++)
        {
                int j = i + len - 1 ; 
                if(j<s.size()) 
                {
                        ull hashval = HashCount(i,j) ; 
                        if(H==hashval) ret ++  ;                
                }
        }
        return ret ; 
}


void solution()
{
        cin >> s >> t ;
        s = '0' + s ;  
        for(int i=1;i<s.size();i++)
        {
                Hash[i] = Hash[i-1]*p + s[i] ; 
        }
        ull H = 0 ; 
        for(int i=0;i<t.size();i++) 
        {
                H = H*p + t[i]  ; 
        }
        cout << "Case " << ++T << ": " ; 
        cout << check(H) << endl ; 
}


int main()
{
        fastIO;
        // file() ;

        prime[0] = 1 ; 
        for(int i=1;i<mx;i++) 
        {
                prime[i] = prime[i-1]*p ; 
        }
        int _ = 1; cin >> _;
        while (_--) solution();
        return 0;
}
