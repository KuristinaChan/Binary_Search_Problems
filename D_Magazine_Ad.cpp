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
int k,cnt;
vll words;
int works(ll x){
    cnt = 0;
    ll cur = 0;
    for(auto i : words){
        if(i>x)return k+1;
        if(cur+i>x){
            ++cnt;
            cur=0;
        }
        cur+=i;
    }
    if(cur>0)++cnt;
    return cnt;
}
void solve(){
    cin >> k;
    cin.ignore();
    string s;
    getline(cin, s);
    words.pb(0);
    rep(i,0,sz(s)){
        words.back()++;
        if(s[i]==' ' || s[i]=='-'){
            words.pb(0);
        }
    }
    ll l = 0, r = sz(s)+1;
    while(l<r){
        ll m = l+((r-l)>>1);
        if(works(m)<=k){
            r = m;
        }else{
            l=m+1;
        }
    }
    cout<<r<<ln;
}
int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;}