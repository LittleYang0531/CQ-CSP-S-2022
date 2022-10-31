#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;	
}
const int N=2e5+5;
const ll inf=1e18;
int n,q,k;
int a[N],b[N];
struct matrix{
	ll a[3][3];
	ll* operator [](int x){return a[x];}
	void init(){
		for(int i=0;i<k;i++)
			for(int j=0;j<k;j++)
				a[i][j]=inf;	
	}
};
matrix operator * (matrix a,matrix b){
	static matrix c;c.init();
	for(int i=0;i<k;i++)
		for(int l=0;l<k;l++)
			for(int j=0;j<k;j++)
				c[i][j]=min(c[i][j],a[i][l]+b[l][j]);
	return c;
}
vector<int> e[N];
int fa[N][18],dep[N];
matrix up[N][18],down[N][18];
matrix build_matrix(int x){
	matrix m;m.init();
	if(k==1)m[0][0]=a[x];
	if(k==2)m[0][1]=a[x],m[0][0]=a[x],m[1][1]=a[x],m[1][0]=0;
	if(k==3){
		m[0][0]=a[x],m[0][1]=a[x],m[0][2]=a[x];
		m[1][0]=0,m[1][1]=b[x],m[1][2]=a[x];
		m[2][0]=0,m[2][1]=0,m[2][2]=a[x];	
	}
	return m;
}
void dfs(int x){
	dep[x]=dep[fa[x][0]]+1;
	up[x][0]=down[x][0]=build_matrix(x);
	for(int i=1;1<<i<dep[x];i++){
		fa[x][i]=fa[fa[x][i-1]][i-1];
		up[x][i]=up[x][i-1]*up[fa[x][i-1]][i-1];
		down[x][i]=down[fa[x][i-1]][i-1]*down[x][i-1];
	}
	for(int y:e[x]){
		if(y==fa[x][0])continue;	
		fa[y][0]=x,dfs(y);
	}
}
inline int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=17;i>=0;i--)
		if(dep[x]-dep[y]>=1<<i)x=fa[x][i];
	if(x==y)return x;
	for(int i=17;i>=0;i--){
		if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	}
	return fa[x][0];
}
matrix go_up(int x,int y){
	matrix res;res.init();res[0][0]=res[1][1]=res[2][2]=0;
	for(int i=17;i>=0;i--)
		if(dep[x]-dep[y]>=1<<i)res=res*up[x][i],x=fa[x][i];
	return res;
}
matrix go_down(int x,int y){
	matrix res;res.init();res[0][0]=res[1][1]=res[2][2]=0;
	for(int i=17;i>=0;i--)
		if(dep[x]-dep[y]>=1<<i)res=down[x][i]*res,x=fa[x][i];
	return res;
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	n=in(),q=in(),k=in();
	for(int i=1;i<=n;i++)a[i]=in();
	for(int i=1;i<n;i++){
		int x=in(),y=in();
		e[x].push_back(y);
		e[y].push_back(x);	
	}
	for(int i=1;i<=n;i++){
		b[i]=a[i];
		for(int j:e[i])b[i]=min(b[i],a[j]);	
	}
	dfs(1);
	while(q--){
		int x=in(),y=in(),yy=y,z=lca(x,y);
		matrix res;
		res=go_up(x,z)*up[z][0]*go_down(y,z);	
		printf("%lld\n",res[0][k-1]);
	}
	return 0;
}
