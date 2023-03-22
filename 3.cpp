#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

#include<iostream>
#include<string.h>
using namespace std;
typedef int ElemType;//定义链表
typedef struct node {
	ElemType data;
	struct node* next;
}node, * Pnode;

typedef struct LNode {
	ElemType data;
	struct LNode* next;
} LNode, * LinkedList;


int GetElem(LinkedList L, int i, ElemType &e) {//获得数据长度
	LinkedList p = L->next;
	int j = 1;
	while (p != NULL && j < i) {
		p = p->next;
		j++;
	}
	if (!p || i < 1) {
		return ERROR;
	}
		e = p->data;
		return OK;
}

LinkedList IntiList(const int n) {//创建链表
	int i;
	LinkedList head;
	LNode* p;
	head = NULL;
	for (i = 0; i < n; i++) {
		p = (LNode*)malloc(sizeof(node));
		if (NULL == p)return ERROR;
		cin >> p->data;
		p->next = head;
		head = p;
	}
}
Status ListDestroy(LNode* L) {//链表销毁
	LNode* cur = L;
	LNode* next = NULL;
	while (cur) {
		next = cur->next;//覆盖
		free(cur);//释放内存
		cur = next;
	}
}
int listLength(LinkedList L) {
	LinkedList first = L;
	int length = 0;
	while (L->next != NULL) {
		length++;
		L = L->next;
	}
	L = first;
	return length;
}
int ListInsert(LinkedList &L, int i, ElemType e) {//插入元素
	LinkedList p = L, q;
	int j = 0;
	while (p && j < i - 1) {//寻找第i个节点
		p = p->next;
		j++;
	}
	if (!p || i < 1)return ERROR;
	q = new LNode;
	q->data = e;
	q->next = p->next;
	p->next = q;
	return OK;
}

Status ListDelete(LinkedList& L, int i, ElemType& e) {
	LinkedList p = L, q;
	int j = 0;
	while (p->next && j < i - 1) {//寻找第i个节点，并令p指向前驱
		p = p->next;
		j++;
	}
	if (!(p->next) || i < 1)return ERROR;
	q = p->next;
	p->next = q->next;
	e = q->data;
	delete q;
	return OK;
}
Status TraverseList(LNode* L) {//链表遍历
	int i = 1;
	Pnode head = (Pnode)malloc(sizeof(Pnode));
	Pnode p = head;//头节点
	while (p->next != NULL) {
		p = p->next;  
		cout << "the NO." << i << "=" << p->data << endl;
		i++;
	}
}
LinkedList SearchList(LinkedList L, ElemType e) {
	while (L != NULL) {
		if(L->data == e){
			return L;
		}
		else {
			L = L->next;
		}
	}
	return L;
}
struct LNode* reverseList(LNode* L, struct LNode* head) {
	struct LNode* newhead = NULL;//新链表头指针
	struct LNode* cur = head;//头节点
	while (cur) {
		struct LNode* next = cur->next;//保持需要的头插节点的下一节点
		cur->next = newhead;//将cur插入新的链表 
		newhead = cur;
		cur = next;
	}
	return newhead;
}
Status IsLoopList(LinkedList L, struct LNode* head) {
	if (head == NULL) {
		return false;
	}
	struct LNode* pre = head->next;
	struct LNode* lag = head;
	while (pre) {
		if (lag == pre) { return true; }
		lag = lag->next;
		pre = pre->next;
		if (pre) {
			pre = pre->next;
		}
	}
	return false;
}


LNode* ReverseEvenList(LinkedList* L,struct LNode *head) {
	LNode* p1, *p2,*p;//p1为第一个节点，p和p2是第二个节点
	p = head->next;
	p = p2 = p1->next;

	while (p1->next != NULL && p1->next->next != NULL) {
		p1->next = p1->next->next;
		p1 = p1->next;

		if (p2->next != NULL && p2->next->next != NULL) {
			p2->next = p2->next->next;
			p2 = p2->next;
		}
	}
	p2->next = NULL;
	p1->next=p;
}

int FindMidNode(LNode* L) {//统计节点个数
	int len = 0;
	LNode* node = L->next;
	while (node != NULL) {
		len++;
		node = node->next;
	}
	int num;//计算中间节点的序号，分奇偶讨论
	if (len % 2 == 0) {
		num = len / 2;
	}
	else {
		num = len / 2 + 1;
	}
	int count = 0;//扫描链表，查找中间节点
	node = L->next;
	while (node != NULL) {
		count++;
		if (count == num) {
			break;
		}
		node = node->next;
	}
	return node->data;
}
int main() {
	ElemType item;
		LinkedList A = NULL;
		IntiList(6);
		ListInsert(A, 1, 'A');
		ListInsert(A, 2, 'B');
		ListInsert(A, 3, 'C');
		ListInsert(A, 4, 'D');
		ListInsert(A, 5, 'F');
		cout << "List A = < ";
		TraverseList(A);
		cout << ">" << endl;
		ElemType  a_next;
		GetElem(A, 3,item);
		cout << a_next << "在A中的位序是" << SearchList(A, a_next) << endl;
		cout << "List A = < ";
		TraverseList(A);
		cout << ">" << endl;
		ListDestroy(A);

		system("pause");
		return 0;
}