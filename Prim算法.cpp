//图
#include<stdio.h>
#define Maxsize 100
#define INF 999
typedef char VertexType[10];//定义VertexType为字符串类型 
typedef struct 
{
	int adjvex;//顶点编号
	VertexType data;//顶点信息--用char类型 
}VType;//顶点类型--类似char 
typedef struct graph
{
	int n,e;//定义实际顶点数n，实际边数e
	VType vexs[Maxsize];//顶点集合
	int edges[Maxsize][Maxsize];//边的集合 
}MatGraph;
void Create(MatGraph &g,int a[][Maxsize],int n,int e)
{
	int i=0,j=0;
	g.e=e;
	g.n=n;
	for(i=0;i<g.n;i++)
	{
		for(j=0;j<g.n;j++)
			g.edges[i][j]=a[i][j];
	}
}
void Print(MatGraph g)
{
	int i,j;
	for(i=0;i<g.n;i++)
	{
		for(j=0;j<g.n;j++)
		{
			if(g.edges[i][j]<INF)
			printf("%4d",g.edges[i][j]);
			else 
			printf("%4s","∞");
		}
		printf("\n");
	}
}
//prim算法
void prim(MatGraph g,int v)
{
	int lowcost[Maxsize];
	int clostset[Maxsize];
	int i,j;
	int k;
	int mincost;
	for(i=0;i<g.n;i++)
	{
		lowcost[i]=g.edges[v][i];
		clostset[i]=v;
	}
	for(i=1;i<g.n;i++)
	{
		mincost=INF;
		k=-1;
		//在V-U中找出离U最近的顶点K 
		for(j=0;j<g.n;j++)
		{
			if(clostset[j]!=0&&lowcost[j]<INF)
		{
			mincost=lowcost[j];
			k=j;//k为最近顶点的编号 
		}
		}
		printf("边(%d,%d),权值为%d\n",clostset[k],k,mincost);
		lowcost[k]=0;//标记k加入U
		for(j=0;j<g.n;j++)//修正数组 
		{
			if(lowcost[j]!=0&&g.edges[k][j]<lowcost[j])
			{
				lowcost[j]=g.edges[k][j];
				clostset[j]=k;
			}
		 } 
		
	}
	
	
		
		
	
	
 } 
int main()
{
	MatGraph g;
	int a[][Maxsize]={{0,1,2,6,INF},{INF,0,INF,4,5},{INF,INF,0,INF,3},{INF,INF,INF,0,INF},{INF,INF,INF,7,0}};
	int n=5,e=7;
	Create(g,a,n,e); 
	Print(g);
	prim(g,0);
	return 0;
 } 
