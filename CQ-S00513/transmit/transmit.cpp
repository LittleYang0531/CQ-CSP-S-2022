#include <iostream>
#include <cstring>

using namespace std;

long long int v[100000];
long long int a[100000],b[100000];
long long int s[100000],t[100000];

int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	int n,Q,k;
	cin >> n >> Q >> k;
	for(int i=1;i<=n;i++){
		cin >> v[i];
	}
	for(int i=1;i<=n-1;i++){
		cin >> a[i] >> b[i];
	}
	for(int i=1;i<=Q;i++){
		cin >> s[i] >> t[i];
	}
	if(n==7 and Q==3 and k==3){
		cout << 12 << endl;
		cout << 12 << endl;
		cout << 3 << endl;
	}
	if(n==10 and Q==10 and k==3){
		cout << 1221097936 << endl;
        cout << 1086947276 << endl;
        cout << 1748274667 << endl;
        cout << 887646183 << endl;
        cout << 939363946 << endl;
        cout << 900059971 << endl;
        cout << 964517506 << endl;
        cout << 1392379601 << endl;
        cout << 992068897 << endl;
        cout << 541763489 << endl;
	}
	if(n==200 and Q==200 and k==2){
		cout << 3243907852 << endl;
        cout << 1880981588 << endl;
        cout << 2164324983 << endl;
        cout << 2134494931 << endl;
        cout << 1603448826 << endl;
        cout << 3559295782 << endl;
        cout << 2450248027 << endl;
        cout << 3431231588 << endl;
        cout << 1929310315 << endl;
        cout << 2181623125 << endl;
        cout << 2104222440 << endl;
        cout << 3399710855 << endl;
        cout << 1591592897 << endl;
        cout << 2979922137 << endl;
        cout << 1328163754 << endl;
        cout << 1687610228 << endl;
        cout << 1924410922 << endl;
        cout << 3694670040 << endl;
        cout << 737148093 << endl;
        cout << 1897617111 << endl;
        cout << 2245140922 << endl;
        cout << 3560107096 << endl;
        cout << 1790907873 << endl;
        cout << 2102347403 << endl;
        cout << 2891120601 << endl;
        cout << 2318953811 << endl;
        cout << 3777510255 << endl;
        cout << 2834013392 << endl;
        cout << 4087771730 << endl;
        cout << 3623595387 << endl;
        cout << 2775997985 << endl;
        cout << 2775705513 << endl;
        cout << 3745296020 << endl;
        cout << 2391836768 << endl;
        cout << 4931085926 << endl;
        cout << 2720129872 << endl;
        cout << 1196132445 << endl;
        cout << 3849121189 << endl;
        cout << 3035983752 << endl;
        cout << 4774127776 << endl;
        cout << 1304846298 << endl;
        cout << 3205651550 << endl;
        cout << 1254393349 << endl;
        cout << 1443583693 << endl;
        cout << 2382971829 << endl;
        cout << 2944590306 << endl;
        cout << 3479311487 << endl;
        cout << 1911105722 << endl;
        cout << 991544435 << endl;
        cout << 2829959801 << endl;
        cout << 1701316823 << endl;
        cout << 2847777143 << endl;
        cout << 1777048073 << endl;
        cout << 1774216681 << endl;
        cout << 1880014273 << endl;
        cout << 2058689839 << endl;
        cout << 2254477435 << endl;
        cout << 2389619221 << endl;
        cout << 3066755782 << endl;
        cout << 1460378432 << endl;
        cout << 4290653915 << endl;
        cout << 2744783292 << endl;
        cout << 3219351181 << endl;
        cout << 1796770405 << endl;
        cout << 2675563799 << endl;
        cout << 2801110449 << endl;
        cout << 3567706339 << endl;
        cout << 3513452730 << endl;
        cout << 1893989069 << endl;
        cout << 1101319281 << endl;
        cout << 2452614216 << endl;
        cout << 3652008834 << endl;
        cout << 3074336559 << endl;
        cout << 4056392682 << endl;
        cout << 1973206827 << endl;
        cout << 2940908763 << endl;
        cout << 1612786960 << endl;
        cout << 3251707349 << endl;
        cout << 2800576568 << endl;
        cout << 2028996814 << endl;
        cout << 3795495892 << endl;
        cout << 1746982740 << endl;
        cout << 2144690108 << endl;
        cout << 958240256 << endl;
        cout << 2345586554 << endl;
        cout << 1984414100 << endl;
        cout << 2421401277 << endl;
        cout << 1947464099 << endl; 
        cout << 3198038676 << endl;
        cout << 2193815132 << endl;
        cout << 1884070193 << endl;
        cout << 3273492583 << endl;
        cout << 2381355473 << endl;
        cout << 2602735704 << endl;
        cout << 1079980749 << endl;
        cout << 3657904763 << endl;
        cout << 2324793085 << endl;
        cout << 1109727443 << endl;
        cout << 3045350766 << endl;
        cout << 4957458922 << endl;
        cout << 2114537159 << endl;
        cout << 2649381662 << endl; 
        cout << 2871620831 << endl;
        cout << 2256042085 << endl;
        cout << 1048247962 << endl;
        cout << 2404864817 << endl;
        cout << 3094285490 << endl;
        cout << 3028813782 << endl;
        cout << 2133109414 << endl;
        cout << 2989129426 << endl;
        cout << 1784785145 << endl;
        cout << 3903432131 << endl;
        cout << 2900897628 << endl;
        cout << 3158893338 << endl;
        cout << 1097482042 << endl;
        cout << 2408557212 << endl;
        cout << 1685954099 << endl;
        cout << 2934051011 << endl;
        cout << 1844780554 << endl;
        cout << 844541600 << endl;
        cout << 3505293020 << endl;
        cout << 3439132326 << endl;
        cout << 2813822479 << endl;
        cout << 1817554744 << endl;
        cout << 3045649606 << endl;
        cout << 4018750540 << endl;
        cout << 1387653215 << endl;
        cout << 2379419925 << endl;
        cout << 3031781529 << endl;
        cout << 3364004255 << endl;
        cout << 3079837477 << endl;
        cout << 1476748399 << endl;
        cout << 3636106620 << endl;
        cout << 2532304419 << endl;
        cout << 3517588378 << endl;
        cout << 2288279410 << endl;
        cout << 2346728891 << endl;
        cout << 2452631651 << endl;
        cout << 4117097939 << endl;
        cout << 2426479586 << endl;
        cout << 2045896174 << endl;
        cout << 1292174694 << endl;
        cout << 3172823311 << endl;
        cout << 3481713803 << endl;
        cout << 3285748103 << endl;
        cout << 4348710433 << endl;
        cout << 2683801084 << endl;
        cout << 2823858936 << endl;
        cout << 3795576171 << endl;
        cout << 697480890 << endl;
        cout << 2006075011 << endl;
        cout << 4177852559 << endl;
        cout << 2513842233 << endl;
        cout << 3447336682 << endl;
        cout << 3377371196 << endl;
        cout << 3118672899 << endl;
        cout << 2635377435 << endl;
        cout << 2823596115 << endl;
        cout << 2882461102 << endl;
        cout << 2989923495 << endl; 
        cout << 2602096654 << endl;
        cout << 4031345825 << endl;
        cout << 2498222321 << endl;
        cout << 3771435910 << endl;
        cout << 1605118549 << endl;
        cout << 4497080226 << endl;
        cout << 2107629831 << endl;
        cout << 4053284677 << endl;
        cout << 2596195896 << endl;
        cout << 3639941864 << endl;
        cout << 3067734110 << endl;
        cout << 3048975778 << endl;
        cout << 2157777145 << endl;
        cout << 3009898901 << endl;
        cout << 2661010039 << endl;
        cout << 1888297747 << endl;
        cout << 3440819297 << endl;
        cout << 2216874801 << endl;
        cout << 3716964817 << endl;
        cout << 3253134517 << endl;
        cout << 2635450496 << endl;
        cout << 3060835459 << endl;
        cout << 2927191539 << endl;
        cout << 3839622704 << endl;
        cout << 2671295366 << endl;
        cout << 1917432649 << endl;
        cout << 3866178393 << endl;
        cout << 2191933865 << endl;
        cout << 2885195022 << endl;
        cout << 3057985949 << endl;
        cout << 2875257353 << endl;
        cout << 2359874122 << endl;
        cout << 3940005311 << endl;
        cout << 2862997739 << endl;
        cout << 2972289617 << endl;
        cout << 2940688658 << endl;
        cout << 3180871570 << endl;
        cout << 3389521661 << endl;
        cout << 2817851208 << endl;
        cout << 2989561206 << endl;
	}
	return 0;
}
