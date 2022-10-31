#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
bool fl[2505][2505];
ll a[2505];
int mx[2505][3];
int n,m,k;
struct node{
	int p,step;
	node(int p_,int step_){
		p=p_,step=step_;
	}
};
vector<int>vec[2505];
queue<node>q;
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++)scanf("%lld",&a[i]);
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		q.push(node(i,0));
		while(!q.empty()){
			node tp=q.front();
			q.pop();
			fl[i][tp.p]=1;
			if(tp.step==k+1)continue;
			for(auto to:vec[tp.p]){
				if(!fl[i][to])q.push(node(to,tp.step+1));
			}
		}
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=n;j++){
			if(j==i)continue;
			if(fl[i][j]&&fl[1][j]){
				if(a[j]>=a[mx[i][2]]){
					mx[i][2]=j;
					if(a[mx[i][2]]>a[mx[i][1]]){
						swap(mx[i][1],mx[i][2]);
						if(a[mx[i][1]]>a[mx[i][0]])swap(mx[i][1],mx[i][0]);
					}
				}
			}
		}
	}
	ll ans=0;
	for(int i=2;i<=n;i++){
		for(int j=2;j<=n;j++){
			if(!fl[i][j])continue;
			if(i==j)continue;
			for(int k=0;k<3;k++){
				for(int l=0;l<3;l++){
					if(mx[i][k]!=mx[j][l]&&j!=mx[i][k]&&i!=mx[j][l]&&mx[j][l]&&mx[i][k])
					ans=max(ans,a[i]+a[j]+a[mx[i][k]]+a[mx[j][l]]); 
				}
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
