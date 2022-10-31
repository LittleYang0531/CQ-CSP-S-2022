#include<bits/stdc++.h>
using namespace std;

int n,m,c[10005][10005],p,a[100005],b[100005];
bool f=true;

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			c[i][j]=a[i]*b[j];
		}
	}
	for(int j=1;j<=p;j++){
		int l1,l2,r1,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		if(l1==r1){
			int minn=INT_MAX;
			for(int i=l2;i<=r2;i++){
				minn=min(minn,c[l1][i]);
			}
			printf("%d\n",minn);
			continue;
		}
		if(l2==r2){
			int maxx=INT_MIN;
			for(int i=l1;i<=r1;i++){
				maxx=max(maxx,c[i][l2]);
			}
			printf("%d\n",maxx);
			continue;
		}
		int id[100000],idx=0;
		for(int i=l1;i<=r1;i++){
			for(int j=l2;j<=r2;j++){
				id[idx]=c[i][j];
				idx++;
			}
		}
		sort(id,id+idx-1);
		int cnt=1,ix[100000],iy=1;
		for(int i=0;i<idx;i++){
			int a=id[i];
			while(a==id[i]) i++;
			cnt++;
			ix[iy]=a;
			iy++;
		}
		cout<<ix[cnt/2]<<"\n";
	}
	return 0;
}
