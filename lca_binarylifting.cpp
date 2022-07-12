#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim)
{
    uniform_int_distribution<int> uid(0, lim - 1);
    return uid(rang);
}
const int mod = 1000000007;
ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}
 
ll mod_mul(ll a, ll b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}
 
ll mod_add(ll a, ll b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}
 
ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b);}
 
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
 
int mpow(int base, int exp)
{
    base %= mod;
    int result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result = ((ll)result * base) % mod;
        base = ((ll)base * base) % mod;
        exp >>= 1;
    }
    return result;
}
/*
const int N=1e5+1;
int a[N],tree[4*N];
void construct_maxSegTree(int node,int st,int end){
    if(st==end) {
        tree[node]=a[st];
        return;
    }
    int mid=(st+end)/2;
    construct_maxSegTree(2*node,st,mid);
    construct_maxSegTree(2*node+1,mid+1,end);
    tree[node]=max(tree[2*node],tree[2*node+1]);
}
int queryMax(int node,int st,int end,int l,int r){
  if(end<l || st>r) return INT_MIN;
   if(st>=l && end<=r) return tree[node];
   int mid=(st+end)/2;
   int q1=queryMax(2*node, st, mid,l,r);
   int q2=queryMax(2*node+1,mid+1,end,l,r);
   return max(q1,q2);
}
void updateMax(int node,int st,int end,int ind,int val){
   if(st==end){
       a[st]=val;
       tree[node]=val;
       return;
   }
   int mid=(st+end)/2;
   if(ind<=mid){
       updateMax(2*node,st,mid,ind,val);
   }
   else if(ind>mid){
       updateMax(2*node+1,mid+1,end,ind,val);
   }
   tree[node]=max(tree[2*node],tree[2*node+1]);
}*/
// Binary index tree
// int bit[10000010]={0};
// int sum(int i){
//     int ans=0;
//     for(;i>0;i-=(i&-i)){
//         ans+=bit[i];
//     }
//     return ans;
// }
// void update(int i,int val){
//       for(;i<=(10000005);i+=(i&-i)){
//           bit[i]+=val;
//       }
// }
// string DecimalToBinaryString(int a)
// {
//     string binary = "";
//     int mask = 1;
//     for(int i = 0; i < 31; i++)
//     {
//         if((mask&a) >= 1)
//             binary = "1"+binary;
//         else
//             binary = "0"+binary;
//         mask<<=1;
//     }
//     cout<<binary<<endl;
//     return binary;
// }

// const int N=1e5+10;
// int fact[N];
// int in[N];
// void factorial(){
// fact[0]=1;
//     int i;
//     for( i=1;i<N;i++){
//         fact[i]=(fact[i-1]*1ll*i)%mod;
//     }
  
// }
// int ncr(int n,int r){
//     factorial();
//     if(n<r || r<0 || n<0)return 0;
//     int ans=(fact[n]+mod)%mod;
// //     int den=(fact[r]*1ll*fact[n-r]+mod)%mod;
// //     ans= (ans*1ll*mpow(den,mod-2)+mod)%mod;
   
// //     return ans;
// // }
// const int N = 100000+1;
// int par[N];
// int depth[N];
// void makeset()
// {
//     for (int i = 1; i < N; i++)
//     {
//         par[i] = i;
//         depth[i] = 0;
//     }
// }
// int find_par(int i)
// {
//     if (par[i] == i)
//         return i;
//     return par[i] = find_par(par[i]);
// }
// void Union(int a, int b)
// {
//     int u = find_par(a);
//     int v = find_par(b);
//     if (depth[u] < depth[v])
//     {
//         par[u] = v;
//     }
//     else if (depth[u] > depth[v])
//     {
//         par[v] = u;
//     }
//     else
//     {
//         par[u] = v;
        
//         depth[v]++;
//     }
// }

//#@copyrightMUKESH
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*
int cnt=1;
void dfs(int node,int par,vvi &adj,vvi &up,vi &timein,vi &timeout){
    up[node][0]=par;
    timein[node]=cnt++;
    for(int i=1;i<=20;i++){
        up[node][i]=up[up[node][i-1]][i-1];
    }
    for(auto &it:adj[node]){
        if(it==par)continue;
        dfs(it,node,adj,up,timein,timeout);
    }
    timeout[node]=cnt++;
}
bool is_lca(int u,int v,vi &timein,vi &timeout){
    if(timein[u]<=timein[v] && timeout[u]>=timeout[v])return true;
    else return false;
}
int lca(int u,int v,vvi &up,vi &timein,vi &timeout){
    if(is_lca(u,v,timein,timeout))return u;
    if(is_lca(v,u,timein,timeout)) return v;
    for(int i=20;i>=0;i--){
       if(!is_lca(up[u][i],v,timein,timeout)){
           u=up[u][i];
       }
    }
    return up[u][0];
}
void solve(){
   int n;
   cin>>n;
   vvi adj(n+1);
   for(int i=1;i<=n-1;i++){
       int u,v;
       cin>>u>>v;
       adj[u].pb(v);
       adj[v].pb(u);
   }
   vi timein(n+1,0);
   vi timeout(n+1,0);
   
   vvi up(n+1,vi(22,-1));
   dfs(1,1,adj,up,timein,timeout);
   int q;
   cin>>q;
   while(q--){
       int u,v;
       cin>>u>>v;
     
       cout<<lca(u,v,up,timein,timeout)<<" ";
   }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    
    int t = 1;
    cin>>t;
    
    while (t--)
    {  
       solve();
      
   
    }

    return 0;
}
