#include<bits/stdc++.h>
using namespace std;
int N,M,Q,out_deg[500005],cnt1,Op[500005],U[500005],V[500005];
set<int> From[500005],Del[500005];
void solve1(){
	cnt1=0;
	for(int i=1;i<=N;++i)if(out_deg[i]==1)++cnt1;
	for(int i=1;i<=Q;++i){
		if(Op[i]==1){
			--out_deg[U[i]];
			From[V[i]].erase(U[i]);
			Del[V[i]].insert(U[i]);
			if(out_deg[U[i]]==1)++cnt1;
			if(out_deg[U[i]]==0)--cnt1;
		}else if(Op[i]==2){
			for(auto v:From[U[i]]){
				--out_deg[v];
				Del[U[i]].insert(v);
				if(out_deg[v]==1)++cnt1;
				if(out_deg[v]==0)--cnt1;
			}
			From[U[i]].clear();
		}else if(Op[i]==3){
			++out_deg[U[i]];
			From[V[i]].insert(U[i]);
			Del[V[i]].erase(U[i]);
			if(out_deg[U[i]]==1)++cnt1;
			if(out_deg[U[i]]==2)--cnt1;
		}else{
			for(auto v:Del[U[i]]){
				++out_deg[v];
				From[U[i]].insert(v);
				if(out_deg[v]==1)++cnt1;
				if(out_deg[v]==2)--cnt1;
			}
			Del[U[i]].clear();
		}
		if(cnt1==N)puts("YES");
		else puts("NO");
	}
}
void solve2(){
	cnt1=0;
	for(int i=1;i<=N;++i)if(out_deg[i]==1)++cnt1;
	for(int i=1;i<=Q;++i){
		if(Op[i]==1){
			--out_deg[U[i]];
			From[V[i]].erase(U[i]);
			Del[V[i]].insert(U[i]);
			if(out_deg[U[i]]==1)++cnt1;
			if(out_deg[U[i]]==0)--cnt1;
		}else if(Op[i]==2){
			for(auto v:From[U[i]]){
				--out_deg[v];
				Del[U[i]].insert(v);
				if(out_deg[v]==1)++cnt1;
				if(out_deg[v]==0)--cnt1;
			}
			From[U[i]].clear();
		}else if(Op[i]==3){
			++out_deg[U[i]];
			From[V[i]].insert(U[i]);
			Del[V[i]].erase(U[i]);
			if(out_deg[U[i]]==1)++cnt1;
			if(out_deg[U[i]]==2)--cnt1;
		}else{
			for(auto v:Del[U[i]]){
				++out_deg[v];
				From[U[i]].insert(v);
				if(out_deg[v]==1)++cnt1;
				if(out_deg[v]==2)--cnt1;
			}
			Del[U[i]].clear();
		}
		if(cnt1==N)puts("YES");
		else puts("NO");
	}
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
    scanf("%d%d",&N,&M);
    for(int i=1;i<=M;++i){
    	int u,v;
    	scanf("%d%d",&u,&v);
    	From[v].insert(u);
    	++out_deg[u];
	}
	scanf("%d",&Q);
	bool flag=true;
    for(int i=1;i<=Q;++i){
    	scanf("%d",&Op[i]);
    	if(Op[i]==2||Op[i]==4){
    		scanf("%d",&U[i]);
         	if(Op[i]==4)flag=false;
		}else scanf("%d%d",&U[i],&V[i]);
	}
    if((N<=1000 && M<=10000 && Q<=1000) || flag) solve1();
    else solve2();
	return 0;
}
