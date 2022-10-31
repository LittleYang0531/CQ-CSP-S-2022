#include<bits/stdc++.h>
using namespace std;
long long n,m,q;
int fx[100001][30],fm[100001][30],fam[100001][30];
int fm_up[100001][30],fx_do[100001][30],fbx[100001][30];
int a[100001],b[100001];
void make()
{
	for(int i = 1;i <= n;i++)
	{
		fx[i][0]=a[i];
		fam[i][0]=a[i];
		fm_up[i][0]=(a[i]>=0?a[i]:0x3f3f3f3f);
		fx_do[i][0]=(a[i]<=0?a[i]:-0x3f3f3f3f);
	}
	for(int j = 1;j <= log2(n);j++)
	{
		for(int i = 1;i+(1<<j)-1 <= n;i++)
		{
			fx[i][j]=max(fx[i][j-1],fx[i+(1<<j-1)][j-1]);
			fam[i][j]=min(fam[i][j-1],fam[i+(1<<j-1)][j-1]);
			fx_do[i][j]=max(fx_do[i][j-1],fx_do[i+(1<<j-1)][j-1]);
			fm_up[i][j]=min(fm_up[i][j-1],fm_up[i+(1<<j-1)][j-1]);
		}
	}
	for(int i = 1;i <= m;i++)
	{
		fm[i][0]=b[i];
		fbx[i][0]=b[i];
	}
	for(int j = 1;j <= log2(m);j++)
	{
		for(int i = 1;i+(1<<j)-1 <= m;i++)
		{
			fm[i][j]=min(fm[i][j-1],fm[i+(1<<j-1)][j-1]);
			fbx[i][j]=max(fbx[i][j-1],fbx[i+(1<<j-1)][j-1]);
		}
	}
}
int askmax(int l,int r)
{
	int x = log2(r-l+1);
//	cout << fx[l][x] << " " << fx[r-(1<<x)+1][x] << " " << l << " " << r << " " << x << " " << r-(1<<x)+1 << " " << max(fx[l][x],fx[r-(1<<x)+1][x]) << endl;
	return max(fx[l][x],fx[r-(1<<x)+1][x]);
}
int askmina(int l,int r)
{
	int x = log2(r-l+1);
	return max(fam[l][x],fam[r-(1<<x)+1][x]);
}
int askmin(int l,int r)
{
	int x = log2(r-l+1);
//	cout << min(fm[l][x],fm[r-(1<<x)+1][x])<< endl;
	return min(fm[l][x],fm[r-(1<<x)+1][x]);
}
int askmina_up(int l,int r)
{
	int x = log2(r-l+1);
//	cout << min(fm[l][x],fm[r-(1<<x)+1][x])<< endl;
	return min(fm_up[l][x],fm_up[r-(1<<x)+1][x]);
}
int askmaxa_do(int l,int r)
{
	int x = log2(r-l+1);
//	cout << min(fm[l][x],fm[r-(1<<x)+1][x])<< endl;
	return max(fx_do[l][x],fx_do[r-(1<<x)+1][x]);
}
int askmaxb(int l,int r)
{
	int x = log2(r-l+1);
//	cout << min(fm[l][x],fm[r-(1<<x)+1][x])<< endl;
	return max(fbx[l][x],fbx[r-(1<<x)+1][x]);
}
int suma[500001],sumb[500001],sum1a[500001],sum1b[500001];
signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> q;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		suma[i]+=suma[i-1]+(a[i]<0);
		sum1a[i]+=sum1a[i-1]+(a[i]==0);
//		cout << a[i] << " ";
	}
	for(int i = 1;i <= m;i++)
	{
		cin >> b[i];
		sumb[i]+=sumb[i-1]+(b[i]<0);
		sum1b[i]+=sum1b[i-1]+(b[i]==0);
	}
	make();
	while(q--)
	{
		int l1,r1,l2,r2;
		cin >> l1 >> r1 >> l2 >> r2;
		int minn = askmin(l2,r2);
		int maxx = askmax(l1,r1);
		int mina = askmina(l1,r1);
		if(minn<0)
		{
			if(sumb[r2]-sumb[l2-1]==r2-l2+1)cout << (long long)mina*askmaxb(l2,r2) << "\n";
			else if(sum1a[r1]-sum1a[l1-1]>0)cout << 0 << "\n";
			else cout << max((long long)askmina_up(l1,r1)*minn,(long long)askmaxa_do(l1,r1)*askmaxb(l2,r2)) << "\n";
		}
		else
		{
			cout << (long long)maxx*minn << "\n";
		}
	}
	return 0;
}
/*
3 2 2
0 1 -2
-3 4
1 3 1 2
2 3 2 2

6 4 5
3 -1 -2 1 2 0
1 2 -1 -3
1 6 1 4
1 5 1 4
1 4 1 2
2 6 3 4
2 5 2 3
*/

