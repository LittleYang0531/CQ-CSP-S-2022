#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2500+5;
const ll M=10000;
ll n,m,k,a[N],b[M][M],ans,ans_ging;
bool cmp(int a,int b){
	return a>b;
}
bool chenk(){
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++){
			if(b[j][1]==1) return true;
			else if(b[1][j]==1) return true;
			else if(b[j+i][1]==1) return true;
			else if(b[1][j+i]==1) return true;
			else if(b[j][1+i]==1) return true;
			else if(b[1+i][j]==1) return true;
			else if(b[j-i][1]==1) return true;
			else if(b[1][j-i]==1) return true;
			else if(b[1+i][j+i]==1) return true;
			else if(b[j+i][1+i]==1) return true;
		}
	return false; 
}
void dfs(int x){
	if(ans_ging==4&&(x=1||chenk()==false))
		return ;
	ll cnt[N];
	ll l=1;
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++){
			if(b[j][x]==1) cnt[l++]=a[i];
			else if(b[x][j]==1) cnt[l++]=a[i];
			else if(b[j+i][x]==1) cnt[l++]=a[i];
			else if(b[x][j+i]==1) cnt[l++]=a[i];
			else if(b[j][x+i]==1) cnt[l++]=a[i];
			else if(b[x+i][j]==1) cnt[l++]=a[i];
			else if(b[j-i][x]==1) cnt[l++]=a[i];
			else if(b[x][j-i]==1) cnt[l++]=a[i];
			else if(b[j][x-i]==1) cnt[l++]=a[i];
			else if(b[x-i][j]==1) cnt[l++]=a[i];
			else if(b[x+i][j+i]==1) cnt[l++]=a[i];
			else if(b[j+i][x+i]==1) cnt[l++]=a[i];
			else if(b[x-i][j-i]==1) cnt[l++]=a[i];
			else if(b[j-i][x-i]==1) cnt[l++]=a[i];
		}
	sort(cnt,cnt+l,cmp);
	for(int i=1;i<=l;i++){
		ll Max=INT_MIN,id;
		ans_ging++;
		ans+=cnt[i];
		for(int i=1;i<=n;i++)
			if(a[i]==cnt[i]){
				id=i;
				break;
			}
		dfs(id);
		ans_ging--;
		cout<<ans<<endl;
		ans-=Max;
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=2;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		b[x][y]=1;
	}
	dfs(1);
	cout<<ans;
	return 0;
}

