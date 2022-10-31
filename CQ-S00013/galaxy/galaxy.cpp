#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 500012
inline int re()
{
	char ch=getchar();int x=0;bool fl=false;while((ch<'0')||('9'<ch))fl|=(ch=='-'),ch=getchar();
	while(('0'<=ch)&&(ch<='9'))x=x*10+(ch^'0'),ch=getchar();return fl?(-x):x;
}
int mod;
inline int ksm(int p,int k){int res=1;while(k){if(k&1)res=1ll*res*p%mod;k>>=1;p=1ll*p*p%mod;}return res;}
inline bool isp(int x){if(x==1)return false;for(int i=2;1ll*i*i<=x;i++)if(x%i==0)return false;return true;}
int n,m,Q,nw[N],inw[N],al[N],ial[N],su,all,X[N],Y[N],cm[N],qx[N],qy[N],a[N],fc[N],iv[N];bool ans[N];
inline void mul(int &x,int v){x=1ll*x*v%mod;}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	srand(19260817);
	n=re();m=re();int i,x,y;for(i=1;i<=m;i++){X[i]=re();Y[i]=re();++al[Y[i]];++nw[Y[i]];++su;}
	Q=re();for(i=1;i<=Q;i++)cm[i]=re(),qx[i]=re(),qy[i]=(cm[i]&1)?re():0;
	for(i=1;i<=Q;i++)
	{
		if(cm[i]==1){--nw[qy[i]];--su;ans[i]=(su==n);continue;}
		if(cm[i]==2){su-=nw[qx[i]];nw[qx[i]]=0;ans[i]=(su==n);continue;}
		if(cm[i]==3){++nw[qy[i]];++su;ans[i]=(su==n);continue;}
		if(cm[i]==4){su+=al[qx[i]]-nw[qx[i]];nw[qx[i]]=al[qx[i]];ans[i]=(su==n);continue;}
	}
	int T=8;
	while(T--)
	{
		mod=1;while(!isp(mod))mod=1ll*rand()*rand()%500000003*rand()%500000003*rand()%500000003+500000000;
		fc[0]=1;for(i=1;i<=n;i++)a[i]=1ll*rand()*rand()%(mod-2)+1,fc[i]=1ll*fc[i-1]*a[i]%mod,al[i]=ial[i]=1;
		iv[n]=ksm(fc[n],mod-2);for(i=n-1;i>=1;i--)iv[i]=1ll*iv[i+1]*a[i+1]%mod;
		for(i=1;i<=n;i++)iv[i]=1ll*fc[i-1]*iv[i]%mod;
		for(i=1;i<=m;i++)mul(al[Y[i]],a[X[i]]),mul(ial[Y[i]],iv[X[i]]);
		su=all=1;for(i=1;i<=n;i++)mul(all,a[i]),mul(su,al[i]),nw[i]=al[i],inw[i]=ial[i];
		for(i=1;i<=Q;i++)
		{
			x=qx[i];y=qy[i];
			if(cm[i]==1){mul(nw[y],iv[x]);mul(inw[y],a[x]);mul(su,iv[x]);ans[i]&=(su==all);continue;}
			if(cm[i]==2){mul(su,inw[x]);nw[x]=inw[x]=1;ans[i]&=(su==all);continue;}
			if(cm[i]==3){mul(nw[y],a[x]);mul(inw[y],iv[x]);mul(su,a[x]);ans[i]&=(su==all);continue;}
			if(cm[i]==4){mul(su,al[x]);mul(su,inw[x]);nw[x]=al[x];inw[x]=ial[x];ans[i]&=(su==all);continue;}
		}
	}
	for(i=1;i<=Q;i++)
	if(ans[i])putchar('Y'),putchar('E'),putchar('S'),putchar('\n');
	else putchar('N'),putchar('O'),putchar('\n');return 0;
}
