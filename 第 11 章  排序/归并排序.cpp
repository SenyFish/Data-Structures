#include<iostream>
#include<vector>
using namespace std;
void mergesort(int &a){
	static vector<int> v1;
	static vector<int> v2;
	static int length = sizeof(a)/sizeof(a[0]);
	static int j = length - 1;
	static int i = 0;
	while (i<=j) {
		if(left>=i) //当左数组
			return;
		if(right>=j)
			return;
		left = mid - 1;
		right = mid;
		v1.push_back()
		v2.push_back()
	}

}
int main(){
	int a[10]={1,3,6,8,12,15,23,26,31,35};
} 