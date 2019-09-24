#include<iostream>
#include<cstdio>
#include<fstream>
using namespace std;
int CountOnes(int n){
	int count=0;
	int factor=1;
	int high,low,curr;
	while(n/factor){
		high=n/(factor*10);
		low=n%factor;
		curr=(n/factor)%10;
		//cout<<high<<" "<<curr<<" "<<low<<endl;
		switch(curr){
			case 0:count+=high*factor;break;
			case 1:count+=high*factor+low+1;break;
			default:count+=(high+1)*factor;
		}
	//	cout<<count<<endl;
		factor*=10;
	}
	return count;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	#endif
	
	int n;
	scanf("%d",&n);
	printf("%d\n",CountOnes(n));
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	#endif
	return 0;
}