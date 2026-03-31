#include <iostream>
#include <vector>
#include <fstream> //文件输入输出库，用来提供测试数据
using namespace std;
class GraphAdjMat{
private:
	vector<int> v1; //v1的size为图中顶点的个数，存的是顶点值
	vector<vector<int>> v2; //v2容器用来存储邻接矩阵
public:
	void Init(){
		int x,i=0;
		do{
			cout<<"请输入索引"<<i<<"对应的值";
			cin>>x;
			v1.push_back(x);
			i++;
		}
		while(x!=-1);
		v1.pop_back();
		v2.assign(v1.size(),vector<int>(v1.size())); //将n个elem拷贝赋值给本身。
		for(x=0;x<v1.size();x++)
			cout<<"索引"<<x<<"："<<v1[x]<<endl;	
	
		for(x=0;x<v1.size();x++)//将每个数的邻接关系存入到矩阵中
			for(i=x+1;i<v1.size();i++){//i=x意味着每轮循环可以选择将自己与自己邻接
				cout<<"请输入"<<v1[x]<<"与"<<v1[i]<<"的邻接关系";
				cin>>v2[x][i];
				v2[i][x]=v2[x][i];
			}
    }
    
	void Print(){
		for(int i=0;i<v1.size();i++){
			for(int j=0;j<v1.size();j++)
				cout<<v2[i][j]<<" ";
			cout<<endl;
		}		
	}
	
	void addEdgeByIndex(int e1_index,int e2_index){
		if(e1_index==e2_index){
			cout<<"简单图不允许自环";
			return;
		}
		v2[e1_index][e2_index]=1;
		v2[e2_index][e1_index]=1;
	}
	
	void delEdgeByIndex(int e1_index,int e2_index){
		if(e1_index==e2_index){
			cout<<"简单图不允许自环";
			return;
		}
		v2[e1_index][e2_index]=0;
		v2[e2_index][e1_index]=0;
	}
	void addVertex(int vertex_val){ //添加顶点
		v1.push_back(vertex_val); //
		cout<<"==================="<<"增加顶点："<<vertex_val<<endl;
		int index = v1.size()-1;
		v2.resize(v1.size(),vector<int>(v1.size()-1));//预留空间 新增一行
		for(int i=0;i<v1.size();i++)
			v2[i].push_back(0);
		for(int i=0;i<v1.size()-1;i++){
				cout<<"请输入"<<v1.back()<<"与"<<v1[i]<<"的邻接关系";
				cin>>v2[i][index];
				v2[index][i]=v2[i][index];
			}
	}
	void delVertex(int vertex_val){
		int index;
		for(index=0;index<v1.size();index++){
			if(v1[index]==vertex_val)
				break;
		}

		for(int i=0;i<v1.size();i++)
			v2[i].erase(v2[i].begin()+index);
		v2.erase(v2.begin()+index);
		v1.erase(v1.begin()+index);
	}
	void test(){ //测试函数
    v1 = {1,3,2,5,4};
    v2 = {
            {0,1,0,1,0},
            {1,0,1,0,0},
            {0,1,0,1,1},
            {1,0,1,0,1},
            {0,0,1,1,0}
            
         };
	}
};

int main(){
    //提供测试数据，模拟手动输入
	GraphAdjMat G1;
	G1.test();
	G1.addEdgeByIndex(0,2);
	G1.delEdgeByIndex(0,1);
	G1.delVertex(3);
	G1.addVertex(6);
	G1.Print();
}
