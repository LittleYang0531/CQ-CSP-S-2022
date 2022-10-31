#include<bits/stdc++.h>
using namespace std;
vector<int>a[100005];
int u,v,f[2505][2505],ans,n,m,k;
struct az {
	int val,id;
} s[100005];
void dfs(int x,int sum,int y) {
	if(sum>k) {
		return;
	}
	for(int i=0; i<a[x].size(); i++) {
		f[y][a[x][i]]=1;
		f[a[x][i]][y]=1;
		dfs(a[x][i],sum+1,y);
	}
}
bool cmp(az a,az b) {
	if(a.val==b.val)return a.id<b.id;
	return a.val>b.val;
}
bool check(int a1,int a2,int a3,int a4) {
	int w[5];
	w[1]=a1;
	w[2]=a2;
	w[3]=a3;
	w[4]=a4;
	for(int i=1; i<=4; i++) {
		for(int j=1; j<=4; j++) {
			for(int k=1; k<=4; k++) {
				for(int l=1; l<=4; l++) {
					if(i!=j&&j!=k&&k!=i&&l!=i&&l!=j&&l!=k&&f[1][w[i]]==1&&f[w[i]][w[j]]==1&&f[w[j]][w[k]]==1&&f[w[k]][w[l]]==1&&f[w[l]][1]==1) {
						return true;
					}
				}

			}
		}
	}
	return false;
}
int main() {
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin>>n>>m>>k;
	s[1].val=0;
	s[1].id=1;
	for(int i=2; i<=n; i++) {
		cin>>s[i].val;
		s[i].id=i;
	}
	for(int i=1; i<=m; i++) {
		cin>>u>>v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for(int i=1; i<=n; i++) {
		dfs(i,0,i);
	}
	sort(s+1,s+n+1,cmp);
	for(int a1=1; a1<=n; a1++) {
		for(int a2=a1+1; a2<=n; a2++) {
			for(int a3=a2+1; a3<=n; a3++) {
				for(int a4=a3+1; a4<=n; a4++) {
					int b1=s[a1].id,b2=s[a2].id,b3=s[a3].id,b4=s[a4].id;
					if(check(b1,b2,b3,b4)) {
						cout<<s[a1].val+s[a2].val+s[a3].val+s[a4].val;
						return 0;
					}
				}
			}
		}
	}
}
/*
8 8 1
9 7 1 8 2 3 6
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 1
*/

