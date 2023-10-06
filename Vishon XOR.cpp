// Bismillahir Rahmanir Rahim


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
typedef pair<ll, ll> pll ;
typedef pair<float, float> pff ;
typedef pair<double, double> pdd ;
typedef pair<ll, ll> pll ;
#define pb push_back
#define el << '\n' ;
#define all(a) (a).begin(),(a).end()
#define allr(a) (a).begin(),(a).end()
#define F first
#define S second
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds ;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
#define pb push_back
#define PI 3.14159265358979323
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define fastIO	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0) ;
ll bin_expo(ll base, ll pow, ll m) {
    if (pow == 0) return 1;ll ret = bin_expo(base, pow / 2, m) % m ;
    if (pow & 1) return (ret % m * ret % m * base % m) % m;else return (ret % m * ret % m) % m ; }
ll ncr(ll n , ll r) {ll mul = 1 ; for(ll i=1;i<=r;i++) {mul = mul * (n-i+1) ; mul = mul/i ; }return mul ; }
ll mod_add(ll a, ll b, ll m) { return ((a % m) + (b % m)) % m ; }
ll mod_sub(ll a, ll b, ll m) { return (a-b+m)%m ; }
ll mod_mul(ll a, ll b, ll m) { return ((a % m) * (b % m)) % m ; }
ll mod_div(ll a, ll b, ll m) { return ((a % m) * bin_expo(b, m - 2, m)) % m ; }
ll aModB(ll a , ll b) { if(a<0 ) { return ((a+(abs(a)/b)*b)+b)%b ; } else { return a%b; } }
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b) ; }
int dx[] = {0, 0, +1, -1, +1, -1, -1, +1} ;
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1} ;
const ll infLL = 4e18 + 123 ;
const ll inf = 1e12 + 7 ;
const ll mod = 1e9 + 7 ;
const ll mod2 = 998244353 ;
const ll mx = 1e5 + 10 ;
const ll LOG = 20 ;
const ll mk = 60 ;
// ---------------------------------------------------------------------------------------------------------------------


struct Node {
    Node * links[2] ;
    bool containsKey(ll bit) {
        return (links[bit]!=NULL) ;
    }
    Node * get(ll bit) {
        return links[bit] ;
    }
    void put(ll bit, Node * node) {
        links[bit] = node ;
    }
};


class Trie {
private: Node * root ;
public:
    Trie() {
        root = new Node() ;
    }
public:

    void insert(ll num) {
        Node * node = root ;
        for(int i=mk;i>=0;i--) {
            ll bit = ( 1LL << i ) & num ;
            if(bit) bit = 1 ;
            if(!node->containsKey(bit)) {
                node->put(bit,new Node()) ;
            }
            node = node->get(bit) ;
        }
    }
public:

    ll findMax(ll num , ll d , ll &x) {
        Node * node = root ;
        ll cnt = 0 ;
        ll maxNum = 0 ;
        ll f1 = 0 ;
        for(ll i=mk;i>=0;i--) {
            ll bit = ( 1LL<<i ) & num ;
            if(bit) bit = 1 ;
            if(cnt>=d) {
                if(node->containsKey(!bit)) {
                    maxNum = maxNum | (1LL<<i) ;
                    node = node->get(!bit) ;
                    if(f1==0) {
                        f1 = maxNum ;
                    }
                }
                else {
                    node = node->get(bit) ;
                }
            }
            else {
                node = node->get(bit) ;
            }
            cnt ++ ;
        }
        x = f1 ;
        return maxNum ;
    }

public :

    bool isPossible(ll num, ll d) {
        Node * node = root ;
        for(ll i=mk;i>=0 and d>0;i--) {
            ll bit = (1LL<<i) & num ;
            if(bit) bit = 1 ;
            if(node->containsKey(bit)) {
                d-- ;
                node = node->get(bit) ;
            }
            else{
                return false ;
            }
        }
        return true ;
    }
};


void solution(ll cs) {

    ll n ;
    cin >> n;
    vl a(n)  ;
    set<ll>st ;
    for(ll i=0;i<n;i++) {
        cin >> a[i] ;
        st.insert(a[i]) ;
    }
    cout << "Case " << cs << ": " ;
    if(st.size()!=n) {
        cout << 0 el ;
    }
    else {
        ll ans = infLL ;
        Trie T ;
        T.insert(a[0]) ;
        for(ll i=1;i<n;i++) {
            for(ll j=0;j<=mk;j++) {
                if(T.isPossible(a[i],j)) {
                    ll x = 0 ;
                    ll m = T.findMax(a[i],j,x) ;
                    ll y = m-x ;
                    ans = min(ans,x-y) ;
                }
                else {
                     break ;
                }
            }
            T.insert(a[i]) ;
        }
        cout << ans << endl ;
    }
}


int main() {

    fastIO  ;
    #ifndef ONLINE_JUDGE
    file() ;
    #endif
    ll cs = 1 ;
    cin >> cs ;
    for(ll i=1;i<=cs;i++) solution(i) ;
    return   0 ;
}
