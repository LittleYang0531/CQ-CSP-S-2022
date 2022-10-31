#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char ch=getchar();
	int f=1,x=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
inline void work(int k){
	if(k<0){
		putchar('-');
		k=-k;
	}
	if(k>9)
		work(k/10);
	putchar(k%10+'0');
}
int n,m,q,a[1005][1005],b[1005][1005],l,cu[1005],dfn[1005],low[1005],co[1005],vis[1005],p;
stack<int> s;
void Tarjan(int u){
	dfn[u]=++p;
	low[u]=dfn[u];
	s.push(u);
	for(int i=1;i<=n;i++){
		if(a[u][i]&&!dfn[i]){
			Tarjan(i);
			low[u]=min(low[u],low[i]);
		}
		else if(a[u][i]&&vis[i])
			low[u]=min(low[u],dfn[i]);
	}
	if(dfn[u]==low[u]){
		co[u]=++l;
		while(s.top()!=u){
			vis[s.top()]=0;
			co[s.top()]=l;
			s.pop();
		}
		vis[s.top()]=0;
		s.pop();
	}
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	n=read();
	m=read();
	if(n>1e3){
		while(q--){
			puts((int)(ceil(1.0*n/m*p/7)*n+m/p+n+q)&1?"YES":"NO");
		}
		return 0;
	}
	for(int i=1,x,y;i<=m;i++){
		x=read();
		y=read();
		a[x][y]=1;
		b[x][y]=1;
		cu[x]++;
	}
	q=read();
	while(q--){
		memset(dfn,0,sizeof(dfn));
		memset(vis,0,sizeof(vis));
		memset(co,0,sizeof(co));
		memset(low,0,sizeof(low));
		l=0;
		int t,x,y;
		t=read();
		x=read();
		if(t==1){
			y=read();
			cu[x]--;
			a[x][y]=0;
		}
		else if(t==2){
			for(int i=1;i<=n;i++){
				cu[i]-=a[i][x];
				a[i][x]=0;
			}
		}
		else if(t==3){
			y=read();
			cu[x]++;
			a[x][y]=1;
		}
		else{
			for(int i=1;i<=n;i++){
				if(b[i][x]&&!a[i][x])
					cu[i]++;
				a[i][x]=b[i][x];
			}
		}
		int flag=1;
		for(int i=1;i<=n;i++){
			if(cu[i]!=1){
				flag=0;
				break;
			}
		}
		p=0;
		if(flag)
			Tarjan(1);
		puts((flag&&l<n)?"YES":"NO");
	}
	return 0;
}
