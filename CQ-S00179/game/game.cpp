#include<bits/stdc++.h>
using namespace std;
int n,m,q;
long long int a[1005],b[1005];
long long int c[1005][1005];
long long int tree[1005][4005];
void Build(int h,int x,int l,int r){
	if(l==r){
		tree[h][x]=c[h][l];
		return;
	}
	Build(h,x*2,l,(l+r)/2);
	Build(h,x*2+1,(l+r)/2+1,r);
	tree[h][x]=min(tree[h][x*2],tree[h][x*2+1]);
	return;
}
long long int query(int h,int x,int l,int r,int L,int R){
	if(l>=L&&r<=R)return tree[h][x];
	if(l>R||r<L)return 1e17;
	return min(query(h,x*2,l,(l+r)/2,L,R),query(h,x*2+1,(l+r)/2+1,r,L,R));
}
int main(){
	freopen("game.in","r",stdin);//´òfreopen!!!
	freopen("game.out","w",stdout);//´òfreopen!!!
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++)scanf("%lld",&b[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			c[i][j]=a[i]*b[j];
			
	for(int i=1;i<=n;i++)Build(i,1,1,m);
	for(int i=1;i<=q;i++){
		int l1,r1,l2,r2;
		scanf("%d %d %d %d",&l1,&r1,&l2,&r2);
		long long int ans=-1e17;
		for(int j=l1;j<=r1;j++)ans=max(ans,query(j,1,1,m,l2,r2));
		cout<<ans<<endl;
	}
	return 0;
}
