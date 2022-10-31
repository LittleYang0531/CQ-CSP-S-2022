#include<bits/stdc++.h> 
using namespace std; 
const int N=2500,M=10000;
typedef long long ll;
ll p[N+5];
vector<int>nxt[N+5];
bitset<N+5>to[2][N+5];
int lu[M+5],lv[M+5];
ll f1[N+5],f2[N+5],f3[N+5];
int f1p[N+5],f2p[N+5];
void pr(__int128 x)
{
	int s[60],len=0;
	while(x){
		s[++len]=x%10;
		x/=10;
	}
	while(len--)
		putchar(char(s[len+1]+'0'));
}
__int128 anss,t;
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	int n,m,k;scanf("%d %d %d",&n,&m,&k) ;
	for(int i=2;i<=n;i++)scanf("%lld",&p[i]);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&lu[i],&lv[i]);
		int u=lu[i],v=lv[i];
		to[0][u][v]=to[0][v][u]=1;
	}
	for(int i=1;i<=k;i++)
	{
		int pp=i&1;
		for(int uu=1;uu<=n;uu++)
			to[pp][uu]|=to[pp^1][uu];
		for(int j=1;j<=m;j++)
		{
			int u=lu[j],v=lv[j];
			to[pp][u]|=to[pp^1][v];
			to[pp][v]|=to[pp^1][u];
		}
	}
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=n;j++)
//			if(to[k&1][i][j])printf("%d->%d\n",i,j);
	for(int j=2;j<=n;j++)
	{
		for(int i=2;i<=n;i++)
		{
			if(i==j)continue;
			if(to[k&1][1][i]&to[k&1][i][j])
			{
				if(p[i]>=f1[j])
				{
					f3[j]=f2[j];f2[j]=f1[j];f2p[j]=f1p[j];
					f1[j]=p[i];f1p[j]=i;
				}
				else if(p[i]>=f2[j])
				{
					f3[j]=f2[j];f2[j]=p[i];
					f2p[j]=i;
				}
				else f3[j]=max(f3[j],p[i]);
			}
		}
	}		
	//1->a->i,1->b->j;
	for(int i=2;i<=n;i++)
		for(int j=2;j<=n;j++)
		{
			if(i==j||f1[j]==0||f1[i]==0||to[k&1][i][j]==0)continue;
			int a=f1p[i],b=f1p[j];
			ll fa=f1[i],fb=f1[j];
			if(a==j){a=f2p[i];fa=f2[i];}
			if(b==i){b=f2p[j];fb=f2[j];}
			if(a==0||b==0)continue;
			t=p[i]+p[j];
			if(a!=b)anss=max(anss,t+fa+fb);
			else
			{
				if(f3[j])anss=max(anss,t+fa+f3[j]);
				if(f3[i])anss=max(anss,t+f3[i]+fb);
			}
		}
	pr(anss);
	return 0;
}
