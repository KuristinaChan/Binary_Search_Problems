#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define si set<int>
#define sll set<long long>
#define sc set<char>
#define vc vector<char>
#define ld long double
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repb(i,a,b) for(int i=a;i<=b;i++)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define ff first
#define ss second
#define ln endl

#define mp make_pair
#define pqueue priority_queue
#define pb push_back

ll gcd(const ll a, const ll b){return(b==0?a:gcd(b,a%b));}
ll lcm(const ll a, const ll b){return a/gcd(a,b)*b;}
ll binpow(ll a,ll n){ll ans=1;for(;n;n/=2,a*=a)if(n&1)ans*=a;return ans;}
ll binpow(ll a,ll n,const ll&mod){ll ans=1;for(;n;n/=2,a=a*a%mod)if(n&1)ans=ans*a%mod;return ans;}
ll cdiv(const ll&a,const ll&b){return(a/b+((a^b)>0 && a%b));}
ll fdiv(const ll&a,const ll&b){return a/b-((a^b)<0 && a%b);}
const ll mod = 1000000007;
// const ll mod = 998244353;
vector<ld> v;
vector<ld> loc;
ld err_max = 1e-8;
int n;
ld max_time(ld x){
    ld m = 0;
    rep(i,0,n){
        if(loc[i]==x)continue;
        m = max(m,((ld)(abs(x-loc[i]))/v[i]));
    }
    return m;
}

void solve(){
    cin>>n;
    v.resize(n);
    loc.resize(n);
    ld high=0;
    rep(i,0,n){
        cin>>loc[i];
        high = max(high,loc[i]);
    }
    rep(i,0,n)cin>>v[i];
    ld l = 0, r = high;
    while(r-l>err_max){
        ld m1 = l+((ld)(r-l)/3);
        ld m2 = r-((ld)(r-l)/3);
        if(max_time(m1)>max_time(m2)){
            l = m1;
        }else{
            r = m2;
        }
    }
    cout<<fixed<<setprecision(7)<<max_time(l)<<ln;
}
int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;}