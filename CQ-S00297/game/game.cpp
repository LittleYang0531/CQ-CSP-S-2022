#include<bits/stdc++.h>
using namespace std;
#define eb(x) emplace_back(x)
#define mp(x,y) make_pair(x,y)
#define all(x) x.begin(),x.end()
const int N=1e5+10;
typedef long long LL;
template<typename T,typename L>inline void chkmx(T &x,L y){(x<y) && (x=y);}

int n,m,a[N],b[N],q;
int sa1[N][19],sa2[N][19],sa3[N][19],sa4[N][19];
int sb1[N][19],sb2[N][19],sb3[N][19],sb4[N][19];
bool za[N][19],zb[N][19];
int da[N],db[N];
void init()
{
	memset(sa2,-0x3f,sizeof sa1);
	memset(sa3,0x3f,sizeof sa3);
	for(int i=1;i<=n;i++)
	{
		if(a[i]<0) sa1[i][0]=sa2[i][0]=a[i];
		else if(a[i]>0) sa3[i][0]=sa4[i][0]=a[i];
		else za[i][0]=1;
	}
	for(int j=1;j<19;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
		{
			int pos=i+(1<<(j-1));
			za[i][j]=za[i][j-1]|za[pos][j-1];
			sa1[i][j]=min(sa1[i][j-1],sa1[pos][j-1]);
			sa2[i][j]=max(sa2[i][j-1],sa2[pos][j-1]);
			sa3[i][j]=min(sa3[i][j-1],sa3[pos][j-1]);
			sa4[i][j]=max(sa4[i][j-1],sa4[pos][j-1]);
		}
	
	memset(sb2,-0x3f,sizeof sb1);
	memset(sb3,0x3f,sizeof sb3);
	for(int i=1;i<=m;i++)
	{
		if(b[i]<0) sb1[i][0]=sb2[i][0]=b[i];
		else if(b[i]>0) sb3[i][0]=sb4[i][0]=b[i];
		else zb[i][0]=1;
	}
	for(int j=1;j<19;j++)
		for(int i=1;i+(1<<j)-1<=m;i++)
		{
			int pos=i+(1<<(j-1));
			zb[i][j]=zb[i][j-1]|zb[pos][j-1];
			sb1[i][j]=min(sb1[i][j-1],sb1[pos][j-1]);
			sb2[i][j]=max(sb2[i][j-1],sb2[pos][j-1]);
			sb3[i][j]=min(sb3[i][j-1],sb3[pos][j-1]);
			sb4[i][j]=max(sb4[i][j-1],sb4[pos][j-1]);
		}
}

int qryamn(int l,int r)//负数最小值 
{
	int len=log2(r-l+1);
	return min(sa1[l][len],sa1[r-(1<<len)+1][len]);
}
int qryamn2(int l,int r)//正数数最小值
{
	int len=log2(r-l+1);
	return min(sa3[l][len],sa3[r-(1<<len)+1][len]);
}
int qryamx2(int l,int r)//负数最大值 
{
	int len=log2(r-l+1);
	return max(sa2[l][len],sa2[r-(1<<len)+1][len]);
} 
int qryamx(int l,int r)//正数最大值 
{
	int len=log2(r-l+1);
	return max(sa4[l][len],sa4[r-(1<<len)+1][len]);
} 

int qrybmn(int l,int r)//负数最小值 
{
	int len=log2(r-l+1);
	return min(sb1[l][len],sb1[r-(1<<len)+1][len]);
}
int qrybmn2(int l,int r)//正数数最小值
{
	int len=log2(r-l+1);
	return min(sb3[l][len],sb3[r-(1<<len)+1][len]);
}
int qrybmx2(int l,int r)//负数最大值 
{
	int len=log2(r-l+1);
	return max(sb2[l][len],sb2[r-(1<<len)+1][len]);
} 
int qrybmx(int l,int r)//正数最大值 
{
	int len=log2(r-l+1);
	return max(sb4[l][len],sb4[r-(1<<len)+1][len]);
} 

bool qrya(int l,int r)
{
	int len=log2(r-l+1);
	return za[l][len]|za[r-(1<<len)+1][len];
}
bool qryb(int l,int r)
{
	int len=log2(r-l+1);
	return zb[l][len]|zb[r-(1<<len)+1][len];
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++) 
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]);
	init();
	
	while(q--)
	{
		LL ans=-2e18;
		int l1,r1,l2,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		int x1=qryamn(l1,r1),x2=qryamx(l1,r1),y1=qrybmn(l2,r2),y2=qrybmx(l2,r2);
		//负数最小值，正数最大值
		if(y1==0)//b无负数 
		{
			if(x2) ans=1ll*x2*qrybmn2(l2,r2);//a有正数 
			else if(x1!=0) ans=1ll*qryamx2(l1,r1)*y2;
		}
		else if(y2==0)//b无正数
		{
			if(x1!=0) ans=1ll*x1*qrybmx2(l2,r2);//a有负数 
			else if(x2) ans=1ll*qryamn2(l1,r1)*y1;
		} 
		else
		{
			if(x2) chkmx(ans,1ll*qryamn2(l1,r1)*y1);
			if(x1!=0) chkmx(ans,1ll*qryamx2(l1,r1)*y2);
		}
		if((ans>0 && qryb(l2,r2)) || (ans<0 && qrya(l1,r1))) ans=0;
		printf("%lld\n",ans);
	}
	return 0;
}
