//�ļ���MGraph.h
//����ͼʵ�ֵݹ顢�ǵݹ����
//�ж��Ƿ��л�·																
#ifndef MGRAPH_H
#define MGRAPH_H
#include<iostream>
#include"Stack.h"
using namespace std;
const int MaxSize=10;//ͼ����󶥵���
template<class T>
class MGraph
{
private:
	T vertex[MaxSize];
	int arc[MaxSize][MaxSize];
	int vertexNum,arcNum;
public:
	MGraph(T a[],int n,int e);//�ڽӾ���洢����������n������e���ߵ�ͼ
	~MGraph(){}//��������Ϊ��
	void DFSTraverse1(int v);//�ݹ���ȱ���
	void DFSTraverse0(int v);//�ǵݹ�
	void BFSTraverse(int v);
};
template<class T>
MGraph<T>::MGraph(T a[],int n,int e)
{
	int i,j,k;
	vertexNum=n;
	arcNum=e;
	for(i=0;i<vertexNum;i++)//�洢ͼ�Ķ�����Ϣ
		vertex[i]=a[i];
	for(i=0;i<vertexNum;i++)//��ʼ��ͼ���ڽӾ���
		for(j=0;j<vertexNum;j++)
			arc[i][j]=0;
	for(k=0;k<arcNum;k++)//�洢ͼ�ı���Ϣ
	{
		cout<<"������ߵ������������ţ�"<<endl;
		cin>>i>>j;
		arc[i][j]=1;
		arc[j][i]=1;
	}
}
template<class T>
void MGraph<T>::DFSTraverse1(int v)
{
	cout<<vertex[v];
	visited[v]=1;
	for(int j=0;j<vertexNum;j++)
		if(arc[v][j]==1 && visited[j]==0)
			DFSTraverse1(j);
}
template<class T>
void MGraph<T>::DFSTraverse0(int v)
{
	int S[MaxSize];
	int top=-1,j;
	cout<<vertex[v];
	visited[v]=1;
	S[++top]=v;//S.Push(v);
	while(top!=-1)
	{
		v=S[top];
		for(j=0;j<vertexNum;j++)
			if(arc[v][j]==1 && visited[j]==0)
			{
				cout<<vertex[j];
				visited[j]=1;
				S[++top]=j;//S.Push(j);
				break;
			}
		if(j==vertexNum) top--;
	}
}
template<class T>
void MGraph<T>::BFSTraverse(int v)
{
	int Q[MaxSize];//������в���˳��洢�Ҳ��ᷢ�����
	int front=-1,rear=-1;//��ʼ������
	cout<<vertex[v];//�����ʶ������
	visited[v]=1;
	Q[++rear]=v;
	while(front!=rear)//�����зǿ�ʱ
	{
		v=Q[++front];//����ͷԪ�س��Ӳ��͵�v��
		for(int j=0;j<vertexNum;j++)
			if(arc[v][j]==1 && visited[j]==0)
			{
				cout<<vertex[j];
				visited[j]=1;
				Q[++rear]=j;
			}
	}
}
#endif