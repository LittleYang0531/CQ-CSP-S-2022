#include<iostream>
using namespace std;
const int N=2510;
int n,m,k;
int x,y,ans=-1;
int v[2510],p[N][N]={-1};
bool h[N],h2[N];
int po[N][N];
bool possible(int a,int b,int g){
	bool flag=false;
	if(g<k){
		if(p[a][b]) flag=true;
		else{
			for(int i=1;i<=n;i++){
				if(p[a][i]>0&&!h2[i]){
					h2[i]=true;
					flag=flag||possible(i,b,g+1);
					h2[i]=false;
				}
			}
		}
	}
	return flag;
}
void dfs(int value,int cnt,int d){
	if(cnt==4){
//		cout<<value<<' ';
//		cout<<p[d][1]<<' ';
		if(p[d][1]==0) return;
		else{
			ans=ans>value?ans:value;
//			cout<<value<<' ';
		}
	}
	else{
		for(int i=1;i<=n;i++){
//			h2[d]=true;
//			if(!h[i]){
//				if(po[d][i]==1){
//					h[i]=true;
//					dfs(value+p[d][i],cnt+1,i);
//					h[i]=false;
//				}
//				else if(po[d][i]==0){
//					if(possible(d,i,-1)){
//						po[d][i]=1;
//						po[i][d]=1;
//						h[i]=true;
//						dfs(value+p[d][i],cnt+1,i);
//						h[i]=false;
//					}
//					else{
//						po[i][d]=2;
//						po[d][i]=2;
//					}
//				}
//			}
//			h2[d]=false;
			if(!h[i]&&p[d][i]>0){
				h[i]=true;
				dfs(value+p[d][i],cnt+1,i);
				h[i]=false;
			}
		}
	}
}

int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=2;i<=n;i++){
		cin>>v[i];
	}
	v[1]=-1;
	for(int i=0;i<m;i++){
		cin>>x>>y;
		p[x][y]=v[y];
		p[y][x]=v[x];
		po[x][y]=1;
		po[x][y]=1;
	}
	h[1]=true;
	dfs(0,0,1);
	cout<<ans;
	return 0;
}
