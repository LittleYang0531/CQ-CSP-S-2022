//Linkwish's code
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
int n,Q,K;
vector<int> e[N],pnt[3][N];
vector<int> pa,pb,path;
ll val[N];
ll f[N];
int dep[N],fa[N][20];
void dfs(int x,int pre){
	fa[x][0]=pre,dep[x]=dep[pre]+1;
	for(int i=1;i<=19;i++)fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int to:e[x])
		if(to!=pre)dfs(to,x);
}
inline int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=19;i>=0;i--)
		if(dep[x]-dep[y]>=(1<<i))x=fa[x][i];
	if(x==y)return x;
	for(int i=19;i>=0;i--)
		if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
inline void get_path(int x,int y){
	int k=lca(x,y);
	pa.clear(),pb.clear(),path.clear();
	while(x!=k){
		pa.push_back(x);
		x=fa[x][0];
	}
	pa.push_back(k);
	while(y!=k){
		pb.push_back(y);
		y=fa[y][0];
	}
	reverse(pb.begin(),pb.end());
	for(int i:pa)path.push_back(i);
	for(int i:pb)path.push_back(i);
//	for(int i:path)cout<<i<<' ';
//	cout<<endl;
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&Q,&K);
	for(int i=1;i<=n;i++)scanf("%lld",&val[i]);
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++){
		for(int j:e[i]){
			pnt[0][i].push_back(j);
			if(K>=2){
				for(int k:e[j]){
					if(k!=i){
						pnt[1][i].push_back(k);
						if(K>=3){
							for(int l:e[k])
								if(l!=i&&l!=j)pnt[2][i].push_back(l);
						}
					}
				}
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int k=0;k<=2;k++){
//			cout<<"ITS "<<i<<' '<<k<<endl;
//			for(int l:pnt[k][i])cout<<l<<' ';
//			cout<<endl;
//		}
//	}
	int x,y,k;
	while(Q--){
		scanf("%d%d",&x,&y);
		get_path(x,y);
		for(int i=0;i<=path.size();i++)f[i]=1e18;
		f[0]=val[path.front()];
		for(int i=0,now;i<path.size();i++){
			for(int j=1;j<=K&&i+j<path.size();j++){
				f[i+j]=min(f[i+j],f[i]+val[path[i+j]]);
				for(int l=0;l<=K&&i+l<path.size();l++){
					for(int k=0;k+l+1<=K;k++){
						for(int np:pnt[k][path[i+l]])
							f[i+j]=min(f[i+j],f[i]+val[np]+val[path[i+j]]);
					}
				}
			}
		}
		printf("%lld\n",f[path.size()-1]);
	}
	return 0;
}

