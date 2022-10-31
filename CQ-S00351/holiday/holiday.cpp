#include<bits/stdc++.h>
using namespace std;
long long a[5005][5005],n,m,k,l,p,ans=0;
struct node{
	long long b,f;
}s[10005];
bool cmp(node &i,node &j)
{
	if(i.b>=j.b)
	return i.f>j.f;
	else return i.f>=j.f;
}
int xh(int i,int c,int f)
{
	if(c==4 )
	if(a[i][1]==1)
	ans=max(ans,f*1ll);
	else return 0; 
	for(int j=n;j>=2;j--)
	if(a[i][j]==1)
	xh(j,c+1,f+s[j].f);
	return 0;
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);	
	cin>>n>>m>>k;
	for(int i=2;i<=n;i++)
	cin>>s[i].f,s[i].b=i;
	for(int i=1;i<=m;i++)
	cin>>l>>p,a[l][p]=1,a[p][l]=1;
	sort(s+2,s+n+1,cmp);
	xh(1,0,0);
	cout<<ans;
}
