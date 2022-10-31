#include<bits/stdc++.h>
using namespace std;
inline void read(int &x){
	x=0;
	bool f=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	if(f) x=-x;
	return ;
}
inline void read(long long &x){
	x=0;
	bool f=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1ll)+(x<<3ll)+(c^48ll);
		c=getchar();
	}
	if(f) x=-x;
	return ;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10+48);
}
inline void write(long long x){
	if(x<0ll){
		putchar('-');
		x=-x;
	}
	if(x>9ll) write(x/10ll);
	putchar(x%10ll+48);
}
int n,m;
int G[1005][1005];
int vis[1005];
int dp[1005];
int b[1005];
bool check1(){
	for(int i=1;i<=n;i++){
		dp[i]=0;
		bool flag=0;
		for(int j=1;j<=n;j++) vis[j]=0;
		queue<int> q;
		q.push(i);
		while(!q.empty()){
			int rt=q.front();
			q.pop();
			if(vis[rt] || dp[rt]){
				flag=1;
				break;
			}
			vis[rt]=1;
			for(int k=1;k<=n;k++){
				if(G[k][rt]==1) q.push(k);
			}
		}
		if(!flag) return false;
		dp[i]=1;
	}
	return true;
}
bool check2(){
	for(int i=1;i<=n;i++){
		int flag=0;
		for(int j=1;j<=n;j++){
			if(G[j][i]==1) flag++;
		}
		if(flag!=1) return false;
	}
	return true;
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	read(n),read(m);
	for(int i=1,u,v;i<=m;i++){
		read(u),read(v);
		G[v][u]=1;
		b[u]++;
	}
	int q;
	read(q);
	while(q--){
		int t;
		read(t);
		if(t==1){
			int u,v;
			read(u),read(v);
			G[v][u]=-1;
			b[u]--;
		}
		if(t==2){
			int u;
			read(u);
			for(int i=1;i<=n;i++){
				if(G[u][i]==1) G[u][i]=-1,b[i]--;
			}
		}
		if(t==3){
			int u,v;
			read(u),read(v);
			G[v][u]=1;
			b[u]++;
		}
		if(t==4){
			int u;
			read(u);
			for(int i=1;i<=n;i++){
				if(G[u][i]==-1) G[u][i]=1,b[i]++;
			}
		}
		if(check2() && check1()) puts("YES");
		else puts("NO");
	}
	return 0;
}

