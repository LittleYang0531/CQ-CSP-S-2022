#include<bits/stdc++.h>
using namespace std;
int n,m,q,head[500010],cnt,in[500010],out[500010];
struct node{
	int from,to,next,save;
}e[500010];
void add(int u,int v){
	e[++cnt].from=u,e[cnt].to=v,e[cnt].next=head[u],e[cnt].save=1,head[u]=cnt;
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		++out[u],++in[v];
	}
	scanf("%d",&q);
	for(int i=1;i<=q;++i){
		int t,u,v;
		scanf("%d%d",&t,&u);
		int pos;
		for(int j=1;j<=cnt;++j){
			if(e[j].from==u&&e[j].to==v){
				pos=j;
				break;
			}
		}
		if(t==1){
			scanf("%d",&v);
			--out[u],--in[v];
			e[pos].save=0;
		}else if(t==2){
			for(int j=1;j<=cnt;++j){
				if(e[j].to==u&&e[j].save==1){
					--in[u],--out[e[j].from];
					e[j].save=0;
				}
			}
		}else if(t==3){
			scanf("%d",&v);
			e[pos].save=1;
			++out[u],++in[v];
		}else{
			for(int j=1;j<=cnt;++j){
				if(e[j].to==u&&e[j].save==0){
					++in[u],++out[e[j].from];
					e[j].save=1;
				}
			}
		}
		int flag=1;
		for(int j=1;j<=n;++j){
			cout<<out[j]<<endl;
			if(out[j]!=1){
				flag=0;
				break;
			}
			if(out[j]==0){
				flag=0;
				break;
			}
		}
		if(flag==0)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
