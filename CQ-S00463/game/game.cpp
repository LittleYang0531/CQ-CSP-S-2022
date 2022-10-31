#include<bits/stdc++.h>
using namespace std;
const int N=100000+5;
int n,m,q;
int a[N],b[N];
int za=INT_MIN,zb=INT_MIN,fa=INT_MAX,fb=INT_MAX;
void init(int l1,int r1,int l2,int r2,int &ax,int &am,int &az,int &af,int &tp,int &bx,int &bm)
{
	for(int i=l1;i<=r1;i++)
	{
		if(a[i]==0)tp=1;
		if(a[i]>0&&abs(a[i])<az)az=a[i];
		if(a[i]<0&&abs(a[i])<af)af=a[i];
		ax=max(ax,a[i]);
		am=min(am,a[i]);
	}
	for(int i=l2;i<=r2;i++)
	{
		bx=max(bx,b[i]);
		bm=min(bm,b[i]);
	}
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		zb=max(zb,a[i]);
		fb=min(fb,a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&b[i]);
		za=max(za,b[i]);
		fa=min(fa,b[i]);
	}
	while(q--)
	{
		int l1,r1,l2,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		int la=r1-l1+1,lb=r2-l2+1;		
		if(l1==r1&&l2==r2)
		{
			
			printf("%d\n",a[l1]*b[l2]);
			continue;
		}
		int tp=0;
		int ax=INT_MIN,bx=INT_MIN,am=INT_MAX,bm=INT_MAX;
		int az=INT_MAX,af=INT_MAX;
		init(l1,r1,l2,r2,ax,am,az,af,tp,bx,bm);
		if(l1==r1)
		{
			if(am<0)printf("%d\n",am*bx);
			else printf("%d\n",am*bm);	
		}
		else if(l2==r2)
		{
			if(bm<0)printf("%d",bm*am);
			else printf("%d",bm*ax);	
		}
		else if(am>0&&bm>0)
		{
			printf("%d\n",ax*bm);
		}
		else if(ax<0)
		{
			printf("%d\n",ax*bx);
		}
		else if(bm>0)
		{
			printf("%d\n",ax*bm);
		}
		else
		{
			if(am<0&&ax>0&&bm<0&&bx>0)
			{
				if(tp==1)
				{
					printf("0\n");
				}
				else
				{
					printf("%d\n",max(az*bm,af*bx));
				}
			}
			else if(am<0&&ax>0&&bx<0)
			{
				printf("%d\n",am*bx);
			}
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