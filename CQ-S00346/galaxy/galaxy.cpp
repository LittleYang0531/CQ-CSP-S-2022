#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
int n,m,q;
struct finl{
	int arrv;
	int brk;//0 fine 1 broke 2 image
	finl(int rv,int bk){
		arrv=rv;
		brk=bk;
	}
};
int vis[500005];
vector<finl>e[500005];
bool swpatk(int x,int nf){
	for(int i=0;i<(int)e[x].size();i++){
		if(e[x][i].brk==0&&vis[e[x][i].arrv]==0){
			if(e[x][i].arrv==nf){
				return true;
			}
			vis[e[x][i].arrv]=1;
			swpatk(e[x][i].arrv,nf);
			vis[e[x][i].arrv]=0;
		}
	}
}
bool lxcs(int nf){
	int cnt=0;
	for(int i=0;i<(int)e[nf].size();i++){
		if(e[nf][i].brk==0){
			cnt++;
		}
	}
	return cnt==1;
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	int u,v;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		e[u].push_back(finl(v,0));
		e[v].push_back(finl(u,2));
	}
	int op;
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d",&op);
		if(op%2==1){
			scanf("%d%d",&u,&v);
		}else{
			scanf("%d",&u);
		}
		if(op==1){
			for(int i=0;i<(int)e[u].size();i++){
				if(e[u][i].arrv==v&&e[u][i].brk==0){
					e[u][i].brk=1;
				}
			}
		}
		else if(op==2){
			for(int i=0;i<(int)e[u].size();i++){
				if(e[u][i].brk==2){
					for(int j=0;j<(int)e[e[u][i].arrv].size();j++){
						if(e[e[u][i].arrv][j].arrv==u&&e[e[u][i].arrv][j].brk==0){
							e[e[u][i].arrv][j].brk=1;
							break;
						}
					}
				}
			}
		}
		else if(op==3){
			for(int i=0;i<(int)e[u].size();i++){
				if(e[u][i].arrv==v&&e[u][i].brk==1){
					e[u][i].brk=0;
				}
			}
		
		}else if(op==4){
			for(int i=0;i<(int)e[u].size();i++){
				if(e[u][i].brk==2){
					for(int j=0;j<(int)e[e[u][i].arrv].size();j++){
						if(e[e[u][i].arrv][j].arrv==u&&e[e[u][i].arrv][j].brk==1){
							e[e[u][i].arrv][j].brk=0;
							break;
						}
					}
				}
			}
		}
		int flag=0;
		for(int i=1;i<=n;i++){
			if(!(swpatk(i,i)&&lxcs(i))){
				cout<<"NO";
				flag=1;
				break;
			}
		}
		if(flag==0){
			cout<"YES";
		}
		cout<<endl;
	}

	return 0;
}

