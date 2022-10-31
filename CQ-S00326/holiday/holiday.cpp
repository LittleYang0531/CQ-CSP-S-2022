#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const ull inf=0x3f3f3f3f;
const ull N=1e6+10;
struct node{
	ull w,to,next;
}edge[N<<1];
ull head[N<<1],cnt=1;
void add(ull u,ull v/*,ull w*/){
	edge[cnt].to=v;
	//edge[cnt].w=w;
	edge[cnt].next=head[u];
	head[u]=cnt++;
}
ull n,m,k,ans=0;
ull f[N];
bool vis[N];
ull mem[2505][105][10];
//loc指的是现在所处位置,num指的是跳过几个点,tot现在路径答案,way景点数 
void dfs(ull loc,ull num,ull tot,ull way){
	if(loc==1&&way==4){
		ans=max(ans,tot);
		return;
	}
	else{
		ull u=loc;
		for(ull i=head[u];i;i=edge[i].next){
			ull v=edge[i].to;
			if(!vis[v]){
				if(num<k){
					dfs(v,num+1,tot,way);
				}
				if(way<4){
					vis[v]=1;
					dfs(v,0,tot+f[v],way+1);
					vis[v]=0;
				}
			}
			else if(num<k){
				dfs(v,num+1,tot,way);
			}
			else if(v==1&&way==4){
				dfs(v,num,tot,way);
			}
		}
	}
}
ull memdfs(ull loc,ull num,ull tot,ull way){
	if(mem[loc][num][way]) return mem[loc][num][way];
	if(loc==1&&way==4){
		return mem[1][num][way]=max(mem[1][num][way],tot);
	}
	else{
		ull u=loc;
		for(ull i=head[u];i;i=edge[i].next){
			ull v=edge[i].to;
			if(!vis[v]){
				if(num<k){
					mem[v][num+1][way]=max(mem[v][num+1][way],memdfs(v,num+1,tot,way));
				}
				if(way<4){
					vis[v]=1;
					mem[v][0][way+1]=max(mem[v][0][way+1],memdfs(v,0,tot+f[v],way+1));
					vis[v]=0;
				}
			}
			else if(num<k){
				mem[v][num+1][way]=max(mem[v][num+1][way],memdfs(v,num+1,tot,way));
			}
			else if(v==1&&way==4){
				mem[v][num][way]=max(mem[v][num][way],memdfs(v,num,tot,way));
			}
		}
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%llu%llu%llu",&n,&m,&k);
	for(ull i=2;i<=n;i++){
		scanf("%llu",&f[i]);
	}
	for(ull i=1;i<=m;i++){
		ull u,v;
		scanf("%llu%llu",&u,&v);
		add(u,v);add(v,u);
	}
	if(k<=5){
		vis[1]=1;
		dfs(1,0,0,0);
		printf("%llu",ans);
	}
	else{
		mem[1][0][0]=0;
		vis[1]=1;
		memdfs(1,0,0,0);
		for(int i=0;i<=k;i++){
			ans=max(mem[1][i][k],ans);
		}
		printf("%llu",ans);
	}
	return 0;
}
