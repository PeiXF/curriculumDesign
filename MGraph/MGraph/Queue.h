//�ļ���Queue.h
#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>
using namespace std;
//���¶��������еĽ��
template<class T>
struct Node
{
	T data;
	Node<T> *next;
};
//��������������Queue������
template<class T>
class Queue
{
private:
	Node<T> *front,*rear;//��ͷ�Ͷ�βָ��
public:
	Queue();//���캯������ʼ��һ���յ�������
	~Queue();//�����������ͷ��������и����Ĵ洢�ռ�
	void EnQueue(T x);//��Ԫ��X���
	T DeQueue();//����ͷԪ�س���
	T GetQueue();//ȡ�����еĶ�ͷԪ��
	int Empty();//�ж��������Ƿ�Ϊ��
};
template<class T>
Queue<T>::Queue()
{
	Node<T> *s=NULL;
	s=new Node<T>;
	s->next=NULL;
	front=rear=s;
}
template<class T> 
Queue<T>::~Queue()
{
	Node<T> *p=NULL:
	while(front!=NULL)
	{
		p=front->next;
		delete front;
		front=p;
	}
}
template<class T>
void Queue<T>::EnQueue(T x)
{
	Node<T> *s=NULL;
	s=new Node<T>;
	s->data=x;//����һ��������ΪX�Ľ��S 
	s->next=NULL;
	rear->next=s;
	rear=s;//�����S���뵽��β
}
template<class T>
T Queue<T>::DeQueue()
{
	Node<T> *p=NULL;
	int x;
	if(rear==front) throw"����";
	p=front->next;
	x=p->data;//�ݴ��ͷԪ��
	front->next=p->next;//����ͷԪ�����ڽ��ժ��
	if(p->next==NULL) rear=front;// �жϳ���ǰ���г����Ƿ�Ϊ1
	delete p;
	return x;
}
template<class T>
T Queue<T>::GetQueue()
{
	if(front!=rear)
		return front->next->data;
}
template<class T>
int Queue<T>::Empty()
{
	if(front==rear)
		return 1;
	else
		return 0;
}
#endif;