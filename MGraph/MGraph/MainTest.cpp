//�ļ���MaunTest.cpp
#include"ALGraph.h"
#include"MGraph.h"
#include<iostream>
using namespace std;
int visited[MaxSize]={0};
int mainMG();//����ͼ�˵���ʾ�����������ܵĵ��ã��������㹻�Ѻã�
int mainALG();//����ͼ�˵���ʾ�����������ܵĵ���
int menu()//ͼ�ı����Ĳ˵�
{
	cout<<"|------------------------------------------------------------|"<<endl;
	cout<<"|--------------------------ͼ�ı���--------------------------|"<<endl;
	cout<<"|------------------------------------------------------------|"<<endl;
	cout<<"|--------------------------0.��  ��--------------------------|"<<endl;
	cout<<"|------------------------------------------------------------|"<<endl;
	cout<<"|--------------------------1.����ͼ--------------------------|"<<endl;
	cout<<"|------------------------------------------------------------|"<<endl;
	cout<<"|--------------------------2.����ͼ--------------------------|"<<endl;
	cout<<"|------------------------------------------------------------|"<<endl;
	cout<<"|--------------------------3.��  ��--------------------------|"<<endl;
	cout<<"|------------------------------------------------------------|"<<endl;
	int n;
	cout<<"���������ѡ��(0-3)��"<<endl;
	cin>>n;
	char ch;
	switch(n)
	{
	case 0:break;
	case 1:
		{
			mainMG();
			cout<<"�Ƿ񷵻�/�˳���(Y/N)"<<endl;
			cin>>ch;
			if(ch=='Y' || ch=='y')
				menu();
			else
				break;
		}break;
	case 2:
		{
			mainALG();
			cout<<"�Ƿ񷵻�/�˳���(Y/N)"<<endl;
			cin>>ch;
			if(ch=='Y' || ch=='y')
				menu();
			else
				break;
		}break;
	case 3:menu();break;
	}
	return 0;
}
int menuM()
{
	cout<<"|------------------------------------------------------------|"<<endl;
	cout<<"|--------------------------*����ͼ*--------------------------|"<<endl;
	cout<<"|------------------------------------------------------------|"<<endl;
	cout<<"|--------------------------0.�ǵݹ�--------------------------|"<<endl;
	cout<<"|------------------------------------------------------------|"<<endl;
	cout<<"|--------------------------1.��  ��--------------------------|"<<endl;
	cout<<"|------------------------------------------------------------|"<<endl;
	cout<<"|--------------------------2.��  ��--------------------------|"<<endl;
	cout<<"|------------------------------------------------------------|"<<endl;
	cout<<"|--------------------------3.��  ��--------------------------|"<<endl;
	cout<<"|------------------------------------------------------------|"<<endl;
	return 0;
}
int menuA()
{
	cout<<"|------------------------------------------------------------|"<<endl;
	cout<<"|--------------------------*����ͼ*--------------------------|"<<endl;
	cout<<"|------------------------------------------------------------|"<<endl;
	cout<<"|--------------------------0.�ǵݹ�--------------------------|"<<endl;
	cout<<"|------------------------------------------------------------|"<<endl;
	cout<<"|--------------------------1.��  ��--------------------------|"<<endl;
	cout<<"|------------------------------------------------------------|"<<endl;
	cout<<"|--------------------------2.��  ��--------------------------|"<<endl;
	cout<<"|------------------------------------------------------------|"<<endl;
	cout<<"|--------------------------3.��  ��--------------------------|"<<endl;
	cout<<"|------------------------------------------------------------|"<<endl;
	return 0;
}
int mainMG()
{
	int m,n,i=0;
	cout<<"����������������ڵ�������ô���10��"<<endl;
	cin>>m;
	cout<<"����������Ϣ�������ֵ,��#��β��"<<endl;
	char a,b[10];
	cin>>a;
	while(a!='#')
	{
		b[i]=a;
		i++;
		cin>>a;
	}
	cout<<"������ߵ�������"<<endl;
	cin>>n;
	MGraph<char> MG(b,m,n);
	menuM();
	int t;
	cout<<"���������ѡ��(0-3)��"<<endl;
	cin>>t;
	switch(t)
	{
	case 0:
		{
			for(int i=0;i<MaxSize;i++)
			visited[i]=0;
			cout<<"�ǵݹ�������ȱ��������ǣ�"<<endl;
			MG.DFSTraverse0(0);
			cout<<endl;
			for(int i=0;i<MaxSize;i++)
			visited[i]=0;
			cout<<"������ȱ��������ǣ�"<<endl;
			MG.BFSTraverse(0);
			cout<<endl;
		}break;
	case 1:
		{
			for(int i=0;i<MaxSize;i++)
				visited[i]=0;
			cout<<"�ݹ�������ȱ��������ǣ�"<<endl;
			MG.DFSTraverse1(0);
			cout<<endl;
			for(int i=0;i<MaxSize;i++)
			visited[i]=0;
			cout<<"������ȱ��������ǣ�"<<endl;
			MG.BFSTraverse(0);
			cout<<endl;
		}break;
	case 2:break;
	case 3:menuM();break;
	}
	return 0;
}
int mainALG()
{
	int m,n,i=0;
	cout<<"����������������ڵ�������ô���10��"<<endl;
	cin>>m;
	cout<<"����������Ϣ�������ֵ,��#��β��"<<endl;
	char a,b[10];
	cin>>a;
	while(a!='#')
	{
		b[i]=a;
		i++;
		cin>>a;
	}
	cout<<"������ߵ�������"<<endl;
	cin>>n;
	ALGraph<char> ALG(b,m,n);
	menuA();
	int t;
	cout<<"���������ѡ��(0-3)��"<<endl;
	cin>>t;
	switch(t)
	{
	case 0:
		{
			for(int i=0;i<MaxSize;i++)
			visited[i]=0;
			cout<<"�ǵݹ�������ȱ��������ǣ�"<<endl;
			ALG.DFSTraverse0(0);
			cout<<endl;
			for(int i=0;i<MaxSize;i++)
			visited[i]=0;
			cout<<"������ȱ��������ǣ�"<<endl;
			ALG.BFSTraverse(0);
			cout<<endl;
			int c;
			cout<<"�������ѯ�������ȵĵ�����У�"<<endl;
			cin>>c;
			cout<<"���Ϊ��"<<ALG.GetVertex(c).InDegree<<endl;
			cout<<"����Ϊ��"<<ALG.GetVertex(c).OutDegree<<endl;
			ALG.TopSort(ALG);
			//ALG.Link(ALG);
		}break;
	case 1:
		{
			for(int i=0;i<MaxSize;i++)
				visited[i]=0;
			cout<<"�ݹ�������ȱ��������ǣ�"<<endl;
			ALG.DFSTraverse1(0);
			cout<<endl;
			for(int i=0;i<MaxSize;i++)
			visited[i]=0;
			cout<<"������ȱ��������ǣ�"<<endl;
			ALG.BFSTraverse(0);
			cout<<endl;
			int c;
			cout<<"�������ѯ�������ȵĵ�����У�"<<endl;
			cin>>c;
			cout<<"���Ϊ��"<<ALG.GetVertex(c).InDegree<<endl;
			cout<<"����Ϊ��"<<ALG.GetVertex(c).OutDegree<<endl;
			ALG.TopSort(ALG);
			//ALG.Link(ALG);
		}break;
	case 2:break;
	case 3:menuA();break;
	}
	return 0;
}
void main()
{
	menu();
}