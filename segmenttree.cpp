#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int a[N],tree[4*N];
/* 
   // sum segment tree
void construct_segmentTree(int node,int st,int end){
    if(st==end){
        tree[node]=a[st];
        return;
    }
    int mid=(st+end)/2;
    construct_segmentTree(2*node,st,mid);
    construct_segmentTree(2*node+1,mid+1,end);
    tree[node]=tree[2*node]+tree[2*node+1];
}
int query(int node,int st,int end,int l,int r){
    if(st>r || end<l) return 0;
    if(st>=l && end<=r) return tree[node];
    int mid=(st+end)/2;
    int q1=query(2*node,st,mid,l,r);
    int q2=query(2*node+1,mid+1,end,l,r);
    return q1+q2; 
} */
// BELOW THREE FUNCTION IS FOR FINDING MAX IN A SUB SUB INTERVAL L,R 
// 1ST FUN FOR CUNSTRUCTING SEGMENTREE 2ND FINDING ANS OF QUERY 3RD UPDATING OF NUMBER AT GIVEN INDEX
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
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    construct_maxSegTree(1,0,n-1);
  
   int q;
   cin>>q;
   while(q--){
      int type;
      cin>>type;
      if(type==1){
          int l,r;
          cin>>l>>r;
          cout<<queryMax(1,0,n-1,l,r)<<"\n";
      }
      else if(type==2){
          int ind,val;
          cin>>ind>>val;
          updateMax(1,0,n-1,ind,val);
      }
   }

}
