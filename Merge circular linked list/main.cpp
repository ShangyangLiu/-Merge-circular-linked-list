#include <iostream>
using namespace std;
#include <string>

struct NODE
{
	int data;
	NODE* next;
};

NODE* creat_link(int arr[], int n)
{
	NODE* node, * rear, * head;
	head = new(NODE);
	rear = head;
	for (int i = 0; i < n; i++)
	{
		node = new(NODE);
		node->data = arr[i];
		node->next = head;
		rear->next = node;
		rear = node;
	}
	return rear;

}

NODE* linktwo(NODE* rear1, NODE* rear2)
{
	NODE* p;
	p = rear1->next;
	rear1->next = rear2->next->next;
	delete rear2->next;
	rear2->next = p;
	return rear2;
}

void display_link(NODE* rear)
{
	NODE* p;
	p = rear->next->next;
	while (p != rear->next)
	{
		cout << p->data << endl;
		p = p->next;
	}
}

int main()
{
	int arr1[5] = { 1,2,3,4,5 };
	int arr2[3] = { 0,0,0 };
	NODE* rearlink1 = creat_link(arr1, 5);
	NODE* rearlink2 = creat_link(arr2, 3);
	cout << "链表1" << endl;
	display_link(rearlink1);
	cout << "链表2" << endl;
	display_link(rearlink2);
	cout << "合并链表" << endl;
	NODE* rearlink3 = linktwo(rearlink1, rearlink2);
	display_link(rearlink3);

	system("pause");

	return 0;

}
