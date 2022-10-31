#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans,cnt;
int graph[2501][2501];
int val[2501];
int read() {
	int w=0,f=1;
	char c=getchar();
	while(!isalnum(c)) {
		if(c=='-') {
			f=-1;
		}
		c=getchar();
	}
	while(isalnum(c)) {
		w*=10;
		w+=c-'0';
		c=getchar();
	}
	return w*f;
}
void dfs(int start) {
	int maxx=0,tar;
	cnt++;
	for(int i=1; i<=n; i++) {
		if(graph[start][i]) {
			if(cnt==4) {
				if(val[i]>maxx&&graph[1][i]) {
					maxx=val[i];
					tar=i;
				}
			} else {
				if(val[i]>maxx) {
					maxx=val[i];
					tar=i;
				}
			}
		}
	}
	
	cout<<tar<<" "<<maxx<<endl; 
	
	ans+=maxx;
	if(cnt==4) {
		return;
	}
	dfs(tar);
}
int main() {
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=2; i<=n; i++) {
		val[i]=read();
	}
	int x,y;
	for(int i=1; i<=m; i++) {
		cin>>x>>y;
		graph[x][y]=1;
		graph[y][x]=1;
	}
	dfs(1);
	cout<<ans;
	return 0;
}

