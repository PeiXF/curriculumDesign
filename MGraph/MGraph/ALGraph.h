//�ļ���ALGraph.h
#ifndef ALGRAPH_H//����ͼ
#define ALGRAPH_H
#include<iostream>
#include"Queue.h"
using namespace std;
const int A_MaxSize=10;
//���¶���߱���Ͷ������
//���¶���߱���
struct ArcNode
{
	int adjvex;//�ڽӵ���
	ArcNode * next;
};
//���嶥�����
template<class T>
struct VertexNode
{
	T vertex;
	int InDegree,OutDegree;
	ArcNode *firstedge;
};
//����ΪALGraph������
template<class T>
class ALGraph
{
private:
	VertexNode<T> adjlist[A_MaxSize];
	int vertexNum,arcNum;
public:
	ALGraph(T a[],int n,int e);//����ͼ���캯�������ڽӱ�洢
	~ALGraph();//��������
	VertexNode<T> GetVertex(int n){return adjlist[n];}//��ȡ��������Ϣ
	void DFSTraverse1(int v);//�ݹ���ȱ���ͼ
	void DFSTraverse0(int v);//�ǵݹ���ȱ���ͼ
	void BFSTraverse(int v);//��ȱ���ͼ
	void TopSort(ALGraph<T> &G);//���������ж����޻�·
	//void Link(ALGraph<T> &G);
};
template<class T>
ALGraph<T>::ALGraph(T a[],int n,int e)
{
	ArcNode *s;
	int i,j,k;
	vertexNum=n;
	arcNum=e;
	for(i=0;i<vertexNum;i++)//�洢������Ϣ����ʼ�������
	{
		adjlist[i].vertex=a[i];
		adjlist[i].firstedge=NULL;
		adjlist[i].InDegree=0;
		adjlist[i].OutDegree=0;
	}
	for(k=0;k<arcNum;k++)//��������ÿһ����
	{
	cout<<"������ߵ������������ţ�"<<endl;
	cin>>i>>j;//���ձ�����������������ı��
	s=new ArcNode;//����һ���߱���S
	s->adjvex=j;
	s->next=adjlist[i].firstedge;//�����S���뵽��i���߱�ı�ͷ
	adjlist[i].firstedge=s;
	adjlist[i].OutDegree++;
	adjlist[j].InDegree++;
	}
}
template<class T>
ALGraph<T>::~ALGraph()
{
	ArcNode *p=NULL;
	for(int i=0;i<vertexNum;i++)
	{
		p=adjlist[i].firstedge;
		while(p!=NULL)//ɾ����i���߱�
		{
			adjlist[i].firstedge=p->next;
			delete p;//�ͷŽ��ռ�
			p=adjlist[i].firstedge;
		}
	}
}
template<class T>
void ALGraph<T>::DFSTraverse1(int v)//�ݹ�������ȱ���ͼ
{
	ArcNode *p=NULL;
	int j;
	cout<<adjlist[v].vertex;
	visited[v]=1;
	p=adjlist[v].firstedge;//����ָ��pָ�򶥵�v�ı߱�
	while(p!=NULL)//������������v���ڽӵ�j
	{
		j=p->adjvex;
		if(visited[j]==0)
			DFSTraverse1(j);
		p=p->next;
	}
}
template<class T>
void ALGraph<T>::DFSTraverse0(int v)
{
	int Q[MaxSize];
	int front,rear,j;
	front=rear=-1;
	cout<<adjlist[v].vertex;
	visited[v]=1;
	Q[++rear]=v;
	while(front!=rear)
	{
		v=Q[++front];
		ArcNode *p=adjlist[v].firstedge;
		while(p!=NULL)
		{
			j=p->adjvex;
			if(visited[j]==0)
			{
				cout<<adjlist[j].vertex;
				visited[j]=1;
				Q[++rear]=j;
			}
			p=p->next;
		}
	}
}
template<class T>
void ALGraph<T>::BFSTraverse(int v)
{
	int Q[MaxSize];//������в���˳��洢
	int front=-1,rear=-1;//��ʼ������
	ArcNode *p=NULL;
	cout<<adjlist[v].vertex;//�����ʶ������
	visited[v]=1;
	Q[++rear]=v;
	while(front!=rear)//�����зǿ�ʱ 
	{
		v=Q[++front];
		p=adjlist[v].firstedge;//����ָ��pָ�򶥵�v�ı߱�
		while(p!=NULL)
		{
			int j=p->adjvex;//j�Ƕ���v���ڽӵ�
			if(visited[j]==0)
			{
				cout<<adjlist[j].vertex;
				visited[j]=1;
				Q[++rear]=j;
			}
			p=p->next;
		}
	}
}
template<class T>
void ALGraph<T>::TopSort(ALGraph<T> &G)
{
	ArcNode *p;
	int top=-1,count=0,i,j,S[MaxSize],k;
	for(i=0;i<G.vertexNum;i++)
	{
		if(G.adjlist[i].InDegree==0)
			S[++top]=i;
	}
	while(top!=-1)
	{
		j=S[top--];
		cout<<G.adjlist[j].vertex;
		count++;
		p=G.adjlist[j].firstedge;
		while(p!=NULL)
		{
			k=p->adjvex;
			G.adjlist[k].InDegree--;
			if(G.adjlist[k].InDegree==0)
				S[++top]=k;
			p=p->next;
		}
	}
	if(count<G.vertexNum) 
		cout<<"�л�·��"<<endl;
	else
		cout<<"�޻�·��"<<endl;
}
//template<class T>
//void ALGraph<T>::Link(ALGraph<T> &G)
//{
//	int count=0;
//	for(int i=0;i<G.vertexNum;i++)
//	{
//	if(visited>1)cout<<"�л�·"<<endl;
//	else if(visited<1)cout<<"����ͨ"<<endl;
//	else
//	cout<<"�޻�·����ͨ"<<endl;
//
//	}
//}
#endif