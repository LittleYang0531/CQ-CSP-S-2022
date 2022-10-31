#include <bits/stdc++.h>

using namespace std;

struct aaa
{
	int numb;
	int fh;
};

int main(int argc, char** argv)
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,m,q;
	cin >> n >> m >> q;
	int a[n],b[m];
	for(int i=0;i<n;i++)
	{
		cin >>a[i];
	}
	for(int i=0;i<m;i++)
	{
		cin >>b[i];
	}
	int l1[q],r1[q],l2[q],r2[q];
	for(int i=0;i<q;i++)
	{
		cin>>l1[i]>>r1[i]>>l2[i]>>r2[i];
	}
	int times=0;
	while(times<q)
	{
		if(times!=0) cout << endl;
		aaa L[n],Q[m];
		int Q1[n],QQ=0,L1[m],LL=0;
		int cheL=1,cheQ=1;
		for(int i=0;i<=r1[times]-l1[times];i++)
		{
			L[i].numb=a[l1[times]+i-1];
			if(L[i].numb<0) 
			{
				L[i].fh=0;
			}
			else if(L[i].numb==0) cheL=2;
			else 
			{
				L[i].fh=1;
				L1[LL++]=L[i].numb;
			}
		}
		for(int i=0;i<=r2[times]-l2[times];i++)
		{
			Q[i].numb=b[l2[times]+i-1];
			if(Q[i].numb<0)
			{
				Q[i].fh=0;
				cheQ=0;
			}
			else
			{
				Q[i].fh=1;
				Q1[QQ++]=Q[i].numb;
			} 
		}
		if(cheL==2 && cheQ==0)
		{
			cout << 0;
			times++;
			continue; 
		}
		sort(L1,L1+LL);
		sort(Q1,Q1+QQ);
		int x,y;
		x=L1[LL/2];
		y=Q1[QQ/2];
		cout << x*y;
		times++;
		continue;
	}
	return 0;
}
