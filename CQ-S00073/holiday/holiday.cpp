#include <bits/stdc++.h>
using namespace std;
struct stu
{
	int	x,y;
}s[20005];
int n,m,k,p,q,cnt,sum,maxx;
int a1[2505],a2[2505],a3[2505],a4[2505],a5[10005];
long long a[2510];
bool flag;
void js(int a,int x,int y,int z,int p,int step)
{
	if(a==1&&flag==1)
	{
		if(step==4*k+5&&x!=0&&y!=0&&z!=0&&p!=0)
		{
			a5[x]++;
			a5[y]++;
			a5[z]++;
			a5[p]++;
			if(a5[x]>1||a5[y]>1||a5[z]>1||a5[p]>1)
			{
				a5[x]=0;
				a5[y]=0;
				a5[z]=0;
				a5[p]=0;
				return;
			}
			a1[++cnt]=x;
			a2[cnt]=y;
			a3[cnt]=z;
			a4[cnt]=p;
		}
		a5[x]=0;
		a5[y]=0;
		a5[z]=0;
		a5[p]=0;
		return;
	}
	else if(a==1)
	{
		flag=1;
	}
	else if(x!=0&&y!=0&&z!=0&&p!=0&&step>=4*k+5)
	{
		return;
	}
	for(int i=1;i<=2*m;i++)
	{
		if(s[i].x==a)
		{
			if(x==0)
			{
				js(s[i].y,s[i].y,y,z,p,step+1);
			}
			else if(x!=0&&y==0)
			{
				js(s[i].y,x,s[i].y,z,p,step+1);
			}
			else if(x!=0&&y!=0&&z==0)
			{
				js(s[i].y,x,y,s[i].y,p,step+1);
			}
			else if(x!=0&&y!=0&&z!=0&&p==0)
			{
				js(s[i].y,x,y,z,s[i].y,step+1);
			}
			else
			{
				js(s[i].y,x,y,z,p,step+1);
			}
			if(s[i+1].x!=a)
			{
				break;
			}
		}
	}
	return;
}
bool cmp(stu a,stu b)
{
	return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
int main() {
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		cnt++;
		scanf("%d%d",&s[cnt].x,&s[cnt].y);
		cnt++;
		s[cnt].x=s[cnt-1].y;
		s[cnt].y=s[cnt-1].x;
	}
	s[cnt+1].x=0;
	sort(s+1,s+1+cnt,cmp);
	cnt=0;
	js(1,0,0,0,0,0);
	for(int i=1;i<=cnt;i++)
	{
		sum=a[a1[i]]+a[a2[i]]+a[a3[i]]+a[a4[i]];
		maxx=max(sum,maxx);
	}
	printf("%d",maxx);
	
	return 0;
}
