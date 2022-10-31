//感谢CCF的送分题
//sto Lisdery orz
//sto Mu_tr orz
//sto ryhuang orz
//sto piggydan orz
//sto MrXBJ orz
//sto PPYYHH orz
//sto LittleYang orz
//sto hualian orz
//sto moyujiang orz
//sto zjy orz
//sto unreachable orz
//sto shuaizui orz
//sto lmgoat orz
//sto my_grandson orz
//sto gyh20 orz
//sto feecle6418 orz
//sto mazihang2022 orz
//sto Prean orz
//sto Leasier orz
//sto OhtoAi orz
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,maxj=17,inf=0x3f3f3f3f;
int n,m,q,a[N],b[N],lg[N],f[18][N][2][4];
long long ans;
//0->非负最大
//1->非负最小
//2->负最大
//3->负最小
int query(int l,int r,bool A,int B)
{
	int k=lg[r-l+1],A1=f[k][l][A][B],A2=f[k][r-(1<<k)+1][A][B];
	return (!B||B==2)?max(A1,A2):min(A1,A2);
}
void pre()
{
	for(int i=2;i<N;i++) lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		if(a[i]>=0)
			f[0][i][0][0]=f[0][i][0][1]=a[i],f[0][i][0][2]=-inf;
		else
			f[0][i][0][0]=-inf,f[0][i][0][1]=inf,
			f[0][i][0][2]=f[0][i][0][3]=a[i];
	}
	for(int i=1;i<=maxj;i++)
		for(int j=1;j+(1<<i)-1<=n;j++)
			f[i][j][0][0]=max(f[i-1][j][0][0],f[i-1][j+(1<<(i-1))][0][0]),
			f[i][j][0][1]=min(f[i-1][j][0][1],f[i-1][j+(1<<(i-1))][0][1]),
			f[i][j][0][2]=max(f[i-1][j][0][2],f[i-1][j+(1<<(i-1))][0][2]),
			f[i][j][0][3]=min(f[i-1][j][0][3],f[i-1][j+(1<<(i-1))][0][3]);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",b+i);
		if(b[i]>=0)
			f[0][i][1][0]=f[0][i][1][1]=b[i],f[0][i][1][2]=-inf;
		else
			f[0][i][1][0]=-inf,f[0][i][1][1]=inf,
			f[0][i][1][2]=f[0][i][1][3]=b[i];
	}
	for(int i=1;i<=maxj;i++)
		for(int j=1;j+(1<<i)-1<=m;j++)
			f[i][j][1][0]=max(f[i-1][j][1][0],f[i-1][j+(1<<(i-1))][1][0]),
			f[i][j][1][1]=min(f[i-1][j][1][1],f[i-1][j+(1<<(i-1))][1][1]),
			f[i][j][1][2]=max(f[i-1][j][1][2],f[i-1][j+(1<<(i-1))][1][2]),
			f[i][j][1][3]=min(f[i-1][j][1][3],f[i-1][j+(1<<(i-1))][1][3]);
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);pre();
	int x,y,l1,r1,l2,r2;
	while(q--)
	{
		ans=-1e18-1;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		x=query(l1,r1,0,0);//a取非负最大,b取负最小/非负最小
		y=query(l2,r2,1,3);
		if(y>=0) y=query(l2,r2,1,1);
		if(x>=0&&x<inf) ans=max(ans,1ll*x*y);
		x=query(l1,r1,0,1);//a取非负最小,b取负最小/非负最小
		if(x>=0&&x<inf) ans=max(ans,1ll*x*y);
		x=query(l1,r1,0,2);//a取负最大,b取非负最大/负最大
		y=query(l2,r2,1,0);
		if(y<0) y=query(l2,r2,1,2);
		if(x<0&&x>-inf) ans=max(ans,1ll*x*y);
		x=query(l1,r1,0,3);//a取负最小,b取非负最大/负最大
		if(x<0&&x>-inf) ans=max(ans,1ll*x*y);
		if(ans==-1e18-1) ans=0;
		cout<<ans<<'\n';
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
