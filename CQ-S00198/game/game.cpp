#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,q;
ll a[100005],b[100005],minn[1000006],maxn[1000006];
ll max(ll a,ll b){
	if(a>b)return a;
	else return b;
}
ll min(ll a,ll b){
	if(a<b)return a;
	else return b;
}
void pushup(int u){
	maxn[u]=max(maxn[u*2],maxn[u*2+1]);
	minn[u]=min(minn[u*2],minn[u*2+1]);
}
void build(int u,int L,int R){
	if(L==R){
		maxn[u]=b[L];
		minn[u]=b[L];
		return;
	}
	int mid=(L+R)/2;
	build(u*2,L,mid);
	build(u*2+1,mid+1,R);
	pushup(u);
}
ll query1(int u,int L,int R,int l,int r){ //max
	if(R<l||r<L)return -1e15;
	if(l<=L&&R<=r)return maxn[u];
	int mid=(L+R)/2;
	return max(query1(u*2,L,mid,l,r),query1(u*2+1,mid+1,R,l,r));
}
ll query2(int u,int L,int R,int l,int r){ //min
	if(R<l||r<L)return 1e15;
	if(l<=L&&R<=r)return minn[u];
	int mid=(L+R)/2;
	return min(query2(u*2,L,mid,l,r),query2(u*2+1,mid+1,R,l,r));
}

ll maxn2[1000006];
void pushup2(int u){
	maxn2[u]=max(maxn2[u*2],maxn2[u*2+1]);
}
void build2(int u,int L,int R){
	if(L==R){
		maxn2[u]=a[L];
		return;
	}
	int mid=(L+R)/2;
	build2(u*2,L,mid);
	build2(u*2+1,mid+1,R);
	pushup2(u);
}
ll query22(int u,int L,int R,int l,int r){ //max
	if(R<l||r<L)return -1e15;
	if(l<=L&&R<=r)return maxn2[u];
	int mid=(L+R)/2;
	return max(query22(u*2,L,mid,l,r),query22(u*2+1,mid+1,R,l,r));
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>q;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<=0)flag=0;
	}
	for(int j=1;j<=m;j++){
		cin>>b[j];
		if(b[j]<=0)flag=0;
	}
	build2(1,1,n);
	build(1,1,m);
	while(q--){
		int l1,r1,l2,r2;
		ll ans=-1e15;
		cin>>l1>>r1>>l2>>r2;
		if(flag){
			cout<<query22(1,1,n,l1,r1)*query2(1,1,m,l2,r2)<<endl;
			continue;
		}
		for(int i=l1;i<=r1;i++){
			if(a[i]>0){
				ans=max(ans,a[i]*query2(1,1,m,l2,r2));
			}
			if(a[i]<0){
				ans=max(ans,a[i]*query1(1,1,m,l2,r2));
			}
			if(a[i]==0){
				ans=max(ans,0);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
