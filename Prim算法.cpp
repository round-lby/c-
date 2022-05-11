//ͼ
#include<stdio.h>
#define Maxsize 100
#define INF 999
typedef char VertexType[10];//����VertexTypeΪ�ַ������� 
typedef struct 
{
	int adjvex;//������
	VertexType data;//������Ϣ--��char���� 
}VType;//��������--����char 
typedef struct graph
{
	int n,e;//����ʵ�ʶ�����n��ʵ�ʱ���e
	VType vexs[Maxsize];//���㼯��
	int edges[Maxsize][Maxsize];//�ߵļ��� 
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
			printf("%4s","��");
		}
		printf("\n");
	}
}
//prim�㷨
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
		//��V-U���ҳ���U����Ķ���K 
		for(j=0;j<g.n;j++)
		{
			if(clostset[j]!=0&&lowcost[j]<INF)
		{
			mincost=lowcost[j];
			k=j;//kΪ�������ı�� 
		}
		}
		printf("��(%d,%d),ȨֵΪ%d\n",clostset[k],k,mincost);
		lowcost[k]=0;//���k����U
		for(j=0;j<g.n;j++)//�������� 
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
