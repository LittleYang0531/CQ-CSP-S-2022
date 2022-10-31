#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e3+5;

int n,m,q;
int mp[maxn][maxn];
bool vis[maxn][maxn];
bool v[maxn],fll;
bool vi[maxn][maxn];

void dfs(int q,int ki){
	if(v[q]==1){
		fll=1;
		return;
	}
	if(fll){
		return;
	}
	v[q]=1;
	if(ki>=50){
		return;
	}
	for(int i=1;i<=n;i++){
		if(mp[q][i]&&vi[q][i]){
			fll=1;
			return;
		}
		else if(mp[q][i]){
			vi[q][i]=1;
			dfs(i,ki+1);
		}
	}
}

ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}

int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=m;i++){
		int u,v;
		u=read();
		v=read();
		mp[u][v]=1;
		vis[u][v]=1;
	}
	q=read();
	for(int i=1;i<=q;i++){
		int t;
		t=read();
		if(t==1){
			int x,y;
			x=read();
			y=read();
			mp[x][y]=0;
		}
		else if(t==2){
			int x;
			x=read();
			for(int i=1;i<=n;i++){
				mp[i][x]=0;
			}
		}
		else if(t==3){
			int x,y;
			x=read();
			y=read();
			mp[x][y]=1;
		}
		else{
			int x;
			x=read();
			for(int i=1;i<=n;i++){
				if(vis[i][x]){
					mp[i][x]=1;
				}
			}
		}
		bool fl=0;
		int sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(mp[i][j]){
					sum++;
				}
			}
			if(sum!=1){
				printf("NO\n");
				fl=1;
				break;
			}
		}
		if(fl){
			continue;
		}
		memset(v,0,sizeof(v));
		memset(vi,0,sizeof(vi));
		for(int i=1;i<=n;i++){
			fll=0;
			dfs(i,0);
			if(!fll){
				printf("NO\n");
				fl=1;
				break;
			}
		}
		if(fl){
			continue;
		}
		puts("YES");
	}
	return 0;
}
