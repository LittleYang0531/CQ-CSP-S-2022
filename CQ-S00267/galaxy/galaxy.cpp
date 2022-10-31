#include<bits/stdc++.h>
using namespace std;
struct node{
	int to,tag;
	node(int to_,int tag_){
		to=to_,tag=tag_;
	}
};
int n,m,d[500005],cnt,tim;
int vis[500005];
bool fl;
vector<node>vec[500005];
void dfs(int now){
	if(vis[now]==tim){
		fl=1;
		return;
	}
	vis[now]=tim;
	for(auto to:vec[now]){
		if(to.tag==1)dfs(to.to);
	}
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);
		d[x]++;
		vec[x].push_back(node(y,1));
	}
	for(int i=1;i<=n;i++)if(d[i]==1)cnt++;
	int q;
	scanf("%d",&q);
	while(q--){
		int op,x,y;
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d",&x,&y);
			for(int i=0;i<vec[x].size();i++){
				if(vec[x][i].to==y)vec[x][i].tag=0;
			}
			d[x]--;
			if(d[x]==1)cnt++;
			if(d[x]==0)cnt--;
		}
		if(op==2){
			scanf("%d",&x);
			for(int i=1;i<=n;i++){
				for(int j=0;j<vec[i].size();j++){
					if(vec[i][j].to==x&&vec[i][j].tag==1){
						vec[i][j].tag=0,d[i]--;
						if(d[i]==1)cnt++;
						if(d[i]==0)cnt--;
					}
				}
			}
		}
		if(op==3){
			scanf("%d%d",&x,&y);
			for(int i=0;i<vec[x].size();i++){
				if(vec[x][i].to==y)vec[x][i].tag=1;
			}
			d[x]++;
			if(d[x]==1)cnt++;
			if(d[x]==2)cnt--;
		}
		if(op==4){
			scanf("%d",&x);
			for(int i=1;i<=n;i++){
				for(int j=0;j<vec[i].size();j++){
					if(vec[i][j].to==x&&vec[i][j].tag==0){
						vec[i][j].tag=1,d[i]++;
						if(d[i]==1)cnt++;
						if(d[i]==2)cnt--;
					}
				}
			}
		}
		if(cnt!=n){
			puts("NO");
			continue;
		}
		++tim;
		fl=0;
		for(int i=1;i<=n&&!fl;i++)if(vis[i]!=tim)dfs(i);
		if(!fl)puts("NO");
		else puts("YES");
	}
	return 0;
} 
