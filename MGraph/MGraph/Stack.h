//�ļ���Stack.h
#ifndef QUEUE_H//�����ظ�����Stack.hͷ�ļ�
#define QUEUE_H
#include<iostream>
using namespace std;
const int StackSize=10;//ջ�����10��Ԫ��
template<class T>
class Stack
{
private:
	T data[StackSize];
	int top;
public:
	Stack();//���캯����ջ�ĳ�ʼ��
	~Stack(){}//��������
	void Push(T x);//��Ԫ��X��ջ
	T Pop();//��ջ��Ԫ�ص���
	T GetTop();//ȡջ��Ԫ�أ�����ɾ����
	int Empty();//�ж�ջ�Ƿ�Ϊ��
};
template<class T>
Stack<T>::Stack()
{
	top=-1;
}
template<class T>
void Stack<T>::Push(T x)
{
	if(top==StackSize-1)
		throw "����";
	top++;
	data[top]=x;
}
template<class T>
T Stack<T>::Pop()
{
	T x;
	if(top==-1)
		throw "����";
	x=data[top--];
	return x;
}
template<class T>
T Stack<T>::GetTop()
{
	if(top!=-1)
		return data[top];
}
template<class T>
int Stack<T>::Empty()
{
	if(top==-1) return 1;
	else return 0;
}
#endif;