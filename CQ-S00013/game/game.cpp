#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define N 100012
#define INF 0x3f3f3f3f
#define LL long long
inline int re()
{
	char ch=getchar();int x=0;bool fl=false;while((ch<'0')||('9'<ch))fl|=(ch=='-'),ch=getchar();
	while(('0'<=ch)&&(ch<='9'))x=x*10+(ch^'0'),ch=getchar();return fl?(-x):x;
}
int n,m,Q,Log[N];
struct Seq{
	int f1[N][19],f2[N][19],f3[N][19],f4[N][19],s[N];
	inline void bu(int n)
	{
		int i,j,x;
		for(i=1;i<=n;i++)
		{
			x=re();
			s[i]=(s[i-1]+(x==0));
			if(x>0)f1[i][0]=f2[i][0]=x,f3[i][0]=INF,f4[i][0]=-INF;
			if(x<0)f3[i][0]=f4[i][0]=x,f1[i][0]=-INF,f2[i][0]=INF;
			if(x==0)f1[i][0]=-INF,f2[i][0]=INF,f3[i][0]=INF,f4[i][0]=-INF;
		}
		for(j=1;j<=Log[n];j++)
		for(i=1;i+(1<<j)-1<=n;i++)
		{
			f1[i][j]=max(f1[i][j-1],f1[i+(1<<(j-1))][j-1]);
			f2[i][j]=min(f2[i][j-1],f2[i+(1<<(j-1))][j-1]);
			f3[i][j]=min(f3[i][j-1],f3[i+(1<<(j-1))][j-1]);
			f4[i][j]=max(f4[i][j-1],f4[i+(1<<(j-1))][j-1]);
		}
	}
	inline vector<int> Ask(int l,int r)
	{
		vector<int>an;int p=Log[r-l+1],v;
		if(s[r]>s[l-1])an.push_back(0);
		v=max(f1[l][p],f1[r-(1<<p)+1][p]);if(v!=(-INF))an.push_back(v);
		v=min(f2[l][p],f2[r-(1<<p)+1][p]);if(v!=(+INF))an.push_back(v);
		v=min(f3[l][p],f3[r-(1<<p)+1][p]);if(v!=(+INF))an.push_back(v);
		v=max(f4[l][p],f4[r-(1<<p)+1][p]);if(v!=(-INF))an.push_back(v);
		return an;
	}
}A,B;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	Log[0]=-1;for(int i=1;i<N;i++)Log[i]=Log[i>>1]+1;
	n=re();m=re();Q=re();int i,j,x,l1,r1,l2,r2;
	A.bu(n);B.bu(m);
	while(Q--)
	{
		l1=re(),r1=re(),l2=re(),r2=re();
		vector<int>a=A.Ask(l1,r1),b=B.Ask(l2,r2);
		LL a1=-0x3f3f3f3f3f3f3f3fll,a2;
		for(i=0;i<a.size();i++)
		{
			a2=0x3f3f3f3f3f3f3f3fll;
			for(j=0;j<b.size();j++)a2=min(a2,1ll*a[i]*b[j]);a1=max(a1,a2);
		}
		printf("%lld\n",a1);
	}
	return 0;
}
