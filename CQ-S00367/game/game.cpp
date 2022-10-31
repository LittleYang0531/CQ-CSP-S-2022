#include<bits/stdc++.h>
#define ll long long
using namespace std;
namespace pokopoko
{
const int N=1e5+5;
int n,m,q;
int a[N],b[N];
int lg[N],a1[N][21],a2[N][21],a3[N][21],a4[N][21];
int b1[N][21],b2[N][21];
void init()
{
	for(int i=2;i<=max(n,m);i++)lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++)a1[i][0]=a2[i][0]=a3[i][0]=a4[i][0]=a[i];
	for(int j=1;j<=lg[n];j++)
		for(int i=1,x,y;i+(1<<j)-1<=n;i++)
		{
			x=a1[i][j-1],y=a1[i+(1<<(j-1))][j-1];
			a1[i][j]=max(x,y);
			x=a2[i][j-1],y=a2[i+(1<<(j-1))][j-1];
			a2[i][j]=((y<0||(x<y&&x>=0))?x:y);
			x=a3[i][j-1],y=a3[i+(1<<(j-1))][j-1];
			a3[i][j]=((y>0||(x>y&&x<=0))?x:y);
			x=a4[i][j-1],y=a4[i+(1<<(j-1))][j-1];
			a4[i][j]=min(x,y);
		}
	for(int i=1;i<=m;i++)b1[i][0]=b2[i][0]=b[i];
	for(int j=1;j<=lg[m];j++)
		for(int i=1,x,y;i+(1<<j)-1<=m;i++)
		{
			x=b1[i][j-1],y=b1[i+(1<<(j-1))][j-1];
			b1[i][j]=min(x,y);
			x=b2[i][j-1],y=b2[i+(1<<(j-1))][j-1];
			b2[i][j]=max(x,y);			
		}
}
int aska1(int l,int r){int k=lg[r-l+1],x=a1[l][k],y=a1[r-(1<<k)+1][k];return max(x,y);}
int aska2(int l,int r){int k=lg[r-l+1],x=a2[l][k],y=a2[r-(1<<k)+1][k];return ((y<0||(x<y&&x>=0))?x:y);}
int aska3(int l,int r){int k=lg[r-l+1],x=a3[l][k],y=a3[r-(1<<k)+1][k];return ((y>0||(x>y&&x<=0))?x:y);}
int aska4(int l,int r){int k=lg[r-l+1],x=a4[l][k],y=a4[r-(1<<k)+1][k];return min(x,y);}
int askb1(int l,int r){int k=lg[r-l+1],x=b1[l][k],y=b1[r-(1<<k)+1][k];return min(x,y);}
int askb2(int l,int r){int k=lg[r-l+1],x=b2[l][k],y=b2[r-(1<<k)+1][k];return max(x,y);}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d %d %d",&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)scanf("%d",&b[i]);
	init();
	int x,y,z,w,k1,k2,k3,k4,w1,w2;
	while(q--)
	{
		ll ans=-2e18;
		scanf("%d %d %d %d",&x,&y,&z,&w);
		k1=aska1(x,y),k2=aska2(x,y),k3=aska3(x,y),k4=aska4(x,y);
		w1=askb1(z,w),w2=askb2(z,w);
		if(w1>=0&&k1>=0)ans=max(ans,1ll*w1*k1);
		if(w1<=0&&k2>=0)ans=max(ans,1ll*w1*k2);
		if(w2>=0&&k3<=0)ans=max(ans,1ll*w2*k3);
		if(w2<=0&&k4<=0)ans=max(ans,1ll*w2*k4);
		printf("%lld\n",ans);
	}
	return 0;
}
};
int main(){pokopoko::main();return 0;}
