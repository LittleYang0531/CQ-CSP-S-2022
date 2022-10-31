#include<bits/stdc++.h>
#define MAXN 5005
using namespace std;
const int inf=0x7fffffff;
int a[MAXN][MAXN],b[MAXN][MAXN],flag1,n,m,q,x,y,type,vst[MAXN];
int flag=0;
void floyed(){
	for (int k=1;k<=n;k++){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				if (a[i][k]!=inf&&a[k][j]!=inf&&a[i][j]>a[i][k]+a[k][j])a[i][j]=a[i][k]+a[k][j];
			}
		}
	}
}
int check1(int s){
	int flag4=1;
	for (int i=1;i<=n;i++)if (a[s][i]==inf||a[i][s]==inf)flag4=0;
	return flag4;
}
int check2(int s){
	int flag5=1;
	for (int i=1;i<=n;i++){
		if (a[i][s]>n&&i!=s||a[s][i]>n&&i!=s){
			flag5=0;
		}
	}
	return flag5;
}

int check(){
	flag=1;
	for (int i=1;i<=n;i++){
		memset(vst,0,sizeof(vst));
		if (check1(i)==0||check2(i)==0){
			flag=0;
			break;
		}
	}
	return flag;
}
signed main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)for (int j=1;j<=n;j++)a[i][j]=inf;
	for (int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		a[x][y]=1;
	}
	scanf("%d",&q);
	while(q--){
		
		scanf("%d",&type);
		if (type==1){
			scanf("%d%d",&x,&y);
			a[x][y]=inf;
			floyed();
			if (check()==1)cout <<"YES"<<endl;
			else cout <<"NO"<<endl;
		}
		else if (type==2){
			scanf("%d",&x);
			for (int i=1;i<=n;i++)if (a[i][x]==1)a[i][x]=inf,b[i][x]=-1;
			floyed();
			if (check()==1)cout <<"YES"<<endl;
			else cout <<"NO"<<endl;
		}
		else if (type==3){
			scanf("%d%d",&x,&y);
			a[x][y]=1;	
			floyed();
			if (check()==1)cout <<"YES"<<endl;
			else cout <<"NO"<<endl;
		}
		else if (type==4){
			scanf("%d",&x);
			for (int i=1;i<=n;i++)if (a[i][x]==inf&&b[i][x]==-1)a[i][x]=1,b[i][x]=0;
			floyed();
			if (check()==1)cout <<"YES"<<endl;
			else cout <<"NO"<<endl;
		}
	}
	return 0;
}
/*
3 6
2 3
2 1
1 2
1 3
3 1
3 2
11
1 3 2
1 2 3
1 1 3
1 1 2
3 1 3
3 3 2
2 3
1 3 1
3 1 3
4 2
1 3 2
*/
