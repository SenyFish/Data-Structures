#include<iostream>
using namespace std;
int main(){
	int i=0,j=9,target;
	int a[10]={1,3,6,8,12,15,23,26,31,35};
	int mid = (j-i)/2+i;
	cin>>target;
	for(i;i<=j;){
		if(target>a[mid]){//如果目标值大于中位数，说明要找的数在[mid+1,j]区间内
			i = mid+1;	
			mid = (j-i)/2+i;
		}
		else if(target<a[mid]){
			j = mid-1;
			mid = (j-i)/2+i;
		}
		else if(target==a[mid]){
			cout<<"索引为:"<<mid<<endl;
			break;
		}
	}
	if(i>j)	
		cout<<"没找到";
}