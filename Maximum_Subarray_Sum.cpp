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
ll inv(ll i)
{
    if (i == 1)
        return 1;
    return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;
}

ll mod_mul(ll a, ll b)
{
    a = a % mod;
    b = b % mod;
    return (((a * b) % mod) + mod) % mod;
}

ll mod_add(ll a, ll b)
{
    a = a % mod;
    b = b % mod;
    return (((a + b) % mod) + mod) % mod;
}

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll ceil_div(ll a, ll b) { return a % b == 0 ? a / b : a / b + 1; }

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

class Node
{
public:
    int totalsum;
    int maxprefixsum = INT_MIN, maxsuffixsum = INT_MIN, maxsubarraysum = INT_MIN;
};
const int N = 2*1e5 + 10;
vi a(N, -1);
vector<Node> tree(4 * N + 1);
Node mergeNode(Node leftchild, Node rightchild)
{
    Node parnode;
    parnode.maxprefixsum = max(leftchild.maxprefixsum, leftchild.totalsum + rightchild.maxprefixsum);
    parnode.maxsuffixsum = max(rightchild.maxsuffixsum, rightchild.totalsum + leftchild.maxsuffixsum);
    parnode.totalsum = leftchild.totalsum + rightchild.totalsum;
    parnode.maxsubarraysum = max({leftchild.maxsuffixsum + rightchild.maxprefixsum, leftchild.maxsubarraysum, rightchild.maxsubarraysum});
    return parnode;
}
void segmenttree(int node, int st, int end)
{
    if (st == end)
    {
        tree[node].maxprefixsum = a[st];
        tree[node].maxsuffixsum = a[st];
        tree[node].maxsubarraysum = a[st];
        tree[node].totalsum = a[st];
        return;
    }
    int mid = (st + end) / 2;
    segmenttree(2 * node, st, mid);
    segmenttree(2 * node + 1, mid + 1, end);
    tree[node] = mergeNode(tree[2 * node], tree[2 * node + 1]);
}
void update(int node,int st,int end,int ind,int val){
    if(st==end){
        a[st]=val;
        tree[node].maxprefixsum=val;
        tree[node].maxsubarraysum=val;
        tree[node].maxsuffixsum=val;
        tree[node].totalsum=val;
        return;
    }
    int mid=(st+end)/2;
    if(ind<=mid){
        update(2*node,st,mid,ind,val);
    }
    else if(ind>mid){
        update(2*node+1,mid+1,end,ind,val);
    }
    tree[node]=mergeNode(tree[2*node],tree[2*node+1]);
}
Node query(int node,int st,int end,int rs,int re){
    if(rs>end || st>re){
        Node nullnode ;
        return nullnode;
    }
    if(rs>=st && re<=end){
        return tree[node];
    }
    int mid=(st+end)/2;
    Node q1=query(2*node,st,mid,rs,re);
    Node q2=query(2*node+1,mid+1,end,rs,re);
    Node ans=mergeNode(q1,q2);
    return ans;
}

//#@copyrightMUKESH
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*


       
    


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
