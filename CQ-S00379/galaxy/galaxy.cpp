#include<bits/stdc++.h>
using namespace std;
void read(int &x){
	x=0;
	int ch=getchar();
	while(ch>'9'||ch<'0')ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
}
int n,m,q;
int h[1000005];
unsigned long long p[1000005],sum1,sum,SUM,KK[1000005],K[1000005];
map<int,int>f[1000005];
struct st{
	int u,op;
	st(){}
	st(int OP,int U){
		u=U,op=OP;
	}
};
vector<st>V[1000005];
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	read(n),read(m);
	p[0]=1;
	for(int i=1;i<=n;i++)p[i]=p[i-1]*13331,SUM+=p[i],h[i]=i;
	for(int i=1,u,v;i<=m;i++){
			read(u),read(v);
		f[v][u]=1;
		K[v]++;
		KK[v]+=p[u];
		sum1+=p[u];
		sum++;
	}
	read(q);
	for(int i=1,op,u,v,kk;i<=q;i++){
		kk=0;
		read(op);
		if(op==1){
			read(u),read(v);
			if(f[h[v]][u])sum--,sum1-=p[u],f[h[v]][u]=0,kk=1;
		}else if(op==2){
			read(v);
			for(int j=V[v].size()-1;j>=0;j--){
				if(V[v][j].op==1)f[h[v]][V[v][j].u]=1,sum1+=p[V[v][j].u],sum++;
				if(V[v][j].op==3)f[h[v]][V[v][j].u]=0,sum1-=p[V[v][j].u],sum--;
			}
			if(h[v]==v)sum-=K[v],sum1-=KK[v];
			h[v]=v+n;
			V[v].clear();
		}else if(op==3){
			read(u),read(v);
			if(!f[h[v]][u])sum++,sum1+=p[u],f[h[v]][u]=1,kk=1;
		}else if(op==4){
			read(v);
			for(int j=V[v].size()-1;j>=0;j--){
				if(V[v][j].op==1)f[h[v]][V[v][j].u]=1,sum1+=p[V[v][j].u],sum++;
				if(V[v][j].op==3)f[h[v]][V[v][j].u]=0,sum1-=p[V[v][j].u],sum--;
			}
			if(h[v]==v+n)sum+=K[v],sum1+=KK[v];
			h[v]=v;
			V[v].clear();
		}
		if(sum==n&&sum1==SUM)putchar('Y'),putchar('E'),putchar('S'),putchar('\n');
		else putchar('N'),putchar('O'),putchar('\n');
		if(kk)V[v].push_back(st(op,u));
	}
	return 0;
}

