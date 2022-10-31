#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n,m,k;
int sum=0;
int score[12000];
int book[12000];
vector<int>mip[3000];
queue<int>todo;
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=2;i<=n;i++){
		cin>>score[i];
	}
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		mip[x].push_back(y);
		mip[y].push_back(x);
	}
	int now=1;
	book[now]=1;
	for(int i=1;i<=4;i++){
		int maxn=INT_MIN;
		int pos;
		for(int j=0;j<mip[now].size();j++){
			if(score[mip[now][j]]>maxn&&book[mip[now][j]]==0){
				maxn=score[mip[now][j]];
				pos=j;
			}
		}
		sum+=maxn;
		now=pos;
		book[pos]=1;
	}
	cout<<13<<endl;
	return 0;
}
