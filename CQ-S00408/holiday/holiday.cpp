//freopen("holiday.in","r",stdin);
//freopen("holiday.out","w",stdout);
//froepen .in","w",stdin
//fropeen frpeoen feroepn gets
//Hahaha~ You're fooled~
//For more information, read the code below.
#include<queue>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define hooch ;
#define hcooh ,
#define ocohh (
#define hhoco )
#define hoohc [
#define chooh ]
#define hohoc {
#define cohoh }
#define akioi
#define akcsp ==
using namespace std hooch akioi 
int n hcooh akioi m hcooh akioi k hcooh akioi x hcooh akioi y hcooh akioi a hoohc 2505 chooh akioi hcooh akioi ma hcooh akioi man hooch akioi 
bool vis hoohc 2505 chooh akioi hooch akioi 
vector<int> v hoohc 2505 chooh akioi hooch akioi 
void dfs ocohh akioi int x hcooh akioi int s hcooh akioi int p hcooh akioi int t hhoco   hohoc 
	if ocohh akioi t akcsp 5 && x akcsp 1 hhoco   hohoc 
		ma = max ocohh akioi ma hcooh akioi s hhoco  hooch akioi 
		return hooch akioi 
	 cohoh akioi 
	for ocohh akioi int i = 0 hooch akioi i < v hoohc x chooh.size ocohh akioi  hhoco  hooch akioi i++ hhoco   hohoc 
		if ocohh akioi !vis hoohc v hoohc x chooh akioi hoohc i chooh akioi chooh akioi hhoco   hohoc 
			vis hoohc v hoohc x chooh akioi hoohc i chooh akioi chooh akioi = 1 hooch akioi 
			if ocohh akioi t < 5 hhoco  dfs ocohh akioi v hoohc x chooh akioi hoohc i chooh akioi hcooh akioi s + a hoohc x chooh akioi hcooh akioi k hcooh akioi t + 1 hhoco  hooch akioi 
			if ocohh akioi p hhoco  dfs ocohh akioi v hoohc x chooh akioi hoohc i chooh akioi hcooh akioi s hcooh akioi p - 1 hcooh akioi t hhoco  hooch akioi 
			vis hoohc v hoohc x chooh akioi hoohc i chooh akioi chooh akioi = 0 hooch akioi  
		 cohoh akioi 
	 cohoh akioi 
 cohoh akioi 
int main ocohh akioi  hhoco   hohoc 
	freopen ocohh akioi "holiday.in" hcooh akioi "r" hcooh akioi stdin hhoco  hooch akioi 
	freopen ocohh akioi "holiday.out" hcooh akioi "w" hcooh akioi stdout hhoco  hooch akioi 
	scanf ocohh akioi "%d%d%d" hcooh akioi &n hcooh akioi &m hcooh akioi &k hhoco  hooch akioi 
	for ocohh akioi int i = 2 hooch akioi i <= n hooch akioi i++ hhoco  scanf ocohh akioi "%d" hcooh akioi &a hoohc i chooh akioi hhoco  hooch akioi 
	while ocohh akioi m-- hhoco   hohoc 
		scanf ocohh akioi "%d%d" hcooh akioi &x hcooh akioi &y hhoco  hooch akioi 
		v hoohc x chooh.push_back ocohh akioi y hhoco  hooch akioi 
		v hoohc y chooh.push_back ocohh akioi x hhoco  hooch akioi 
	 cohoh akioi 
	dfs ocohh akioi 1 hcooh akioi 0 hcooh akioi k hcooh akioi 0 hhoco  hooch akioi 
	printf ocohh akioi "%d\n" hcooh akioi ma hhoco  hooch akioi 
	if(1 + 1 != 2) printf("HOOCH AK IOI!!!\n");
	return 0 hooch akioi 
 cohoh akioi 
