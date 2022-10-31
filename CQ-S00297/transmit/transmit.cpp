#include<bits/stdc++.h>
using namespace std;
#define eb(x) emplace_back(x)
#define mp(x,y) make_pair(x,y)
#define all(x) x.begin(),x.end()
const int N=2e5+10,mod=998244353;
typedef long long LL;
template<typename T>inline void read(T &x)
{
	int f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=f; 
} 
template<typename T,typename ...L>inline void read(T &x,L &...l)
{
	read(x),read(l...);
}
template<typename T>inline void print(T x)
{
	if(x<0) putchar('-'),x=-x;
	int t=0;
	char c[32];
	do{
		c[t++]=x%10+'0';
		x/=10;
	}while(x);
	while(t--)	putchar(c[t]);
	putchar('\n');
}
template<typename T,typename L>inline void chkmx(T &x,L y){(x<y) && (x=y);}
template<typename T,typename L>inline void chkmn(T &x,L y){(x>y) && (x=y);}
int inc(const int &a,const int &b){return (a+b>=mod?a+b-mod:a+b);}
int mul(const int &a,const int &b){return 1ll*a*b%mod;}
void Inc(int &a,const int &b){a=(a+b>=mod?a+b-mod:a+b);}
void Mul(int &a,const int &b){a=1ll*a*b%mod;}
int n,q,k,val[N];
vector<int>v1,v2;
int h[N],e[N],ne[N],idx,dep[N],fa[N][20];
LL f[N],s[N];
void add(int a,int b)
{
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;
}
vector<int>tmp;
void DFS(int u,int f)
{
	dep[u]=dep[f]+1;
	s[u]=s[f]+val[u];
	fa[u][0]=f;
	for(int i=1;i<20;i++)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=h[u];i!=-1;i=ne[i])
	{
		int v=e[i];
		if(v==f) continue;
		DFS(v,u);
	}
}

int LCA(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=19;i>=0;i--)
		if(dep[fa[x][i]]>=dep[y])
			x=fa[x][i];
	if(x==y) return x;
	for(int i=19;i>=0;i--)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	
	memset(h,-1,sizeof h);
	cin>>n>>q>>k;
	for(int i=1;i<=n;i++)
		scanf("%d",&val[i]);
	for(int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	DFS(1,0);
	while(q--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		if(k==1)
		{
			int fat=LCA(u,v);
			printf("%lld\n",s[u]+s[v]-s[fat]-s[fa[fat][0]]);
		}
		else
		{
			v1.clear(),v2.clear(),tmp.clear();
			int fat=LCA(u,v);
			int tu=u,tv=v;
			while(tu!=fat)
			{
				v1.eb(tu);
				tu=fa[tu][0];
			}
			v1.eb(fat);
			while(tv!=fat)
			{
				v2.eb(tv);
				tv=fa[tv][0];
			}
			reverse(v2.begin(),v2.end());
			for(auto x:v1) tmp.eb(x);
			for(auto x:v2) tmp.eb(x);
			f[0]=val[tmp[0]];
			for(int i=1;i<(int)tmp.size();i++)
			{
				f[i]=2e18;
				int lst=i-k;
				lst=max(lst,0);
				for(int j=lst;j<i;j++)
					f[i]=min(f[i],f[j]+val[tmp[i]]);
			}
			printf("%lld\n",f[tmp.size()-1]);
		}
	}
	
	return 0;
}
