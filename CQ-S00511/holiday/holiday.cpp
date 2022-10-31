#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define int long long
ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,k;
int a[2505][2505];
int val[2505];
vector<int> G[2505];
int f[2505][10];
int c[2505][2505];
int b[2505][2505];
vector<int> ve[2505][10];
void print(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			printf("%d",c[i][j]);
		printf("\n");
	}
}

signed main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=2;i<=n;i++)val[i]=read();
	for(int i=1;i<=m;i++){
		int x=read(),y=read();
		b[x][y]=b[y][x]=a[x][y]=a[y][x]=1;
	}
	if(k!=0)
	for(int kk=1;kk<=k+1;kk++){
		for(int l=1;l<=n;l++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					if(i!=j)b[i][j]|=c[i][l]&a[l][j];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				c[i][j]=b[i][j];
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			c[i][j]=b[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(c[i][j])G[i].push_back(j);
		}
	//print();
	for(int i=1;i<=n;i++)
		for(int j=0;j<=5;j++){
			for(int v:G[i]){
				// if(f[v][j+1]<f[i][j]+val[v]){
				// 	int ok=1;
				// 	for(int t:ve[i][j]){
				// 		if(t==v)ok=0;
				// 	}
				// 	if(ok){
				// 		for(int t:ve[i][j])ve[v][j+1].push_back(t);
				// 		f[v][j+1]=f[i][j]+val[v];
				// 		ve[v][j+1].push_back(i);
				// 	}
				// }
				f[v][j+1]=max(f[v][j+1],f[i][j]+val[v]);
			}
		}
	//printf("%lld",f[1][5]);
	cout<<f[1][5];
	return 0;
}