#include<iostream>
using namespace std;

int sum[301] = {0};
int main(){
	int n;
	int s1,s2,s3;
	cin>>n;
	//将所有满足条件的结果枚举出来,保存到sum数组中
	for(int a1=0;a1<=n;a1++){
		for(int a2=0;a2<=n;a2++){
			for(int a3=0;a3<=n;a3++){
				s1 = a1+a2;
				s2 = a2+a3;
				s3 = a1+a2+a3;
				if((s1%2==0) && (s2%3==0) && (s3%5==0)){
					sum[s3]++;
				}
			}
		}
	}
	//输出最大的值
	for(int i=301;i>=0;i--){
		if(sum[i] != 0){
			cout << i;
			break;
		}
	}
	
	return 0;
}
