#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define int long long
const int INF=1e18+5;
ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int a[3005],b[3005],c[3005][3005];
int n,m,q;
int l1,r1,l2,r2;

struct jjy{
	int l,r;
	int minv,maxv;
}t[2][400005];

void pushup(int o,int d){
	t[d][o].minv=min(t[d][o<<1].minv,t[d][o<<1|1].minv);
	t[d][o].maxv=max(t[d][o<<1].maxv,t[d][o<<1|1].maxv);
}

void build(int o,int l,int r,int d){
	t[d][o].l=l,t[d][o].r=r;
	if(l==r){
		if(d==0)t[d][o].minv=t[d][o].maxv=a[l];
		else t[d][o].minv=t[d][o].maxv=b[l];
		return;
	}
	int mid=(l+r)>>1;
	build(o<<1,l,mid,d);
	build(o<<1,mid+1,r,d);
	pushup(o,d);
}

int qma(int o,int l,int r,int d){
	if(l<=t[d][o].l&&t[d][o].r<=r)return t[d][o].maxv;
	int mid=(t[d][o].l+t[d][o].r)>>1;
	int ans=-INF;
	if(l<=mid)ans=max(ans,qma(o<<1,l,r,d));
	if(mid<r)ans=max(ans,qma(o<<1|1,l,r,d));
	return ans;
}

int qmi(int o,int l,int r,int d){
	if(l<=t[d][o].l&&t[d][o].r<=r)return t[d][o].minv;
	int mid=(t[d][o].l+t[d][o].r)>>1;
	int ans=INF;
	if(l<=mid)ans=min(ans,qmi(o<<1,l,r,d));
	if(mid<r)ans=min(ans,qmi(o<<1|1,l,r,d));
	return ans;
}

namespace sub1{
	void main(){
		int maxL=-INF;
		for(int i=l1;i<=r1;i++){
			int t=INF;
			// for(int j=l2;j<=r2;j++){
			// 	t=min(a[i]*b[j],t);
			// }
			t=min(t,a[i]*qmi(1,l2,r2,1));
			if(maxL<t){
				maxL=t;
			}
			//cout<<maxL<<endl;
		}
		printf("%lld\n",maxL);
	}
}

namespace sub3{
	void main(){
		int maxL=-INF;
		for(int i=l1;i<=r1;i++){
			int t=INF;
			for(int j=l2;j<=r2;j++){
				t=min(a[i]*b[j],t);
			}
			if(maxL<t){
				maxL=t;
			}
			//cout<<maxL<<endl;
		}
		printf("%lld\n",maxL);
	}
}

signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read(),m=read(),q=read();
	int f1=1;
	for(int i=1;i<=n;i++){a[i]=read();if(a[i]<=0)f1=0;}
	for(int j=1;j<=m;j++){b[j]=read();if(b[j]<=0)f1=0;}
	// for(int i=1;i<=n;i++)
	// 	for(int j=1;j<=n;j++)
	// 		c[i][j]=a[i]*b[j];
	build(1,1,n,0);
	build(1,1,m,1);
	while(q--){
		l1=read(),r1=read(),l2=read(),r2=read();
		if(n<=200)sub3::main();
		else if(f1)sub1::main();
		//else if(l2=r2)sub2::main();
		else sub3::main();
		
	}
	return 0;
}