#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<queue>
#include<list>
#include<string>
#include<algorithm>
#include<cassert>
#include<memory.h>
#include<cmath>
#include<map>
using namespace std;
template<typename T>
class Node {
public:
	T data;
	Node* link;
	Node(T element) {
		data = element;
		link = NULL;
	}
};
template<typename T>
class LinkedList {
protected:
	Node<T>* root;
	int currentSize;
public:
	LinkedList() {
		root = NULL;
		currentSize = 0;
	}
	~LinkedList() {
		Node<T>* temp;
		while (root != NULL) {
			temp = root;
			root = root->link;
			delete temp;
		}
	}
	T GetSize() { return currentSize; }
	//맨 앞에 element를 삽입한다.
	void Insert(T element) {
		//새 노드를 리스트에 연결시킨 후, root가 새 노드를 가리키도록 한다.
		Node<T>* newNode = new Node<T>(element);
		newNode->link = root;
		root = newNode;
		++currentSize;
	}
	//맨 뒤의 원소를 삭제하고 삭제한 원소를 element에 담는다.
	//삭제가 불가능한 경우 false를 반환한다.
	virtual bool Delete(T& element) {
		//삭제가 불가능한 경우
		if (root == NULL) 
			return false;
		Node<T>* cur = root;
		Node<T>* prev = NULL;
		while (1) {
			//맨 뒤의 노드를 찾은 경우
			if (cur->link == NULL) {
				if (prev != NULL)
					prev->link = NULL;
				//원소가 한개뿐인경우
				else
					root = NULL;
				break;
			}
			prev = cur;
			cur = cur->link;
		}
		//삭제한 노드의 원소를 element에 할당
		element = cur->data;
		delete cur;
		--currentSize;
		return true;
	}
	void Print() {
		Node<T>* cur = root;
		for (int i = 1; i < currentSize; ++i) {
			cout << "[" << i << "|" << cur->data << "]->";
			cur = cur->link;
		}
		if (currentSize > 0)
			cout << "[" << currentSize << "|" << cur->data << "]" << endl;
	}
};
template<typename T>
class Stack :public LinkedList<T> {
public:
	Stack():LinkedList<T>(){}
	~Stack() {
		Node<T>* temp;
		//dependent name
		while (this->root != NULL) {
			temp = this->root;
			this->root = this->root->link;
			delete temp;
		}
	}
	//맨 앞의 원소를 삭제하고 삭제한 원소를 element에 담는다.
	//삭제가 불가능한 경우 false를 반환한다.
	bool Delete(T& element) {
		//삭제가 불가능한 경우
		if (this->root == NULL)
			return false;
		Node<T>* cur = this->root;
		element = cur->data;
		this->root = cur->link;
		delete cur;
		this->currentSize = this->currentSize - 1;
		return true;
	}
};
void prnMenu() {
	cout << "**********************************************" << endl;
	cout << "* 1.삽입      2.삭제      3.출력      4.종료 *" << endl;
	cout << "**********************************************" << endl;
	cout << endl;
	cout << "원하시는 메뉴를 골라주세요: ";
}
int main(void) {
	int mode, selectNumber, tmpItem;
	LinkedList<int>* p;
	bool flag = false;
	cout << "자료구조 선택(1: Stack, Other: LinkedList): ";
	cin >> mode;
	if (mode == 1)
		p = new Stack<int>();
	else
		p = new LinkedList<int>();
	do {
		prnMenu();
		cin >> selectNumber;
		switch (selectNumber) {
		case 1:
			cout << "원하시는 값을 입력해주세요: ";
			cin >> tmpItem;
			p->Insert(tmpItem);
			cout << tmpItem << "가 삽입되었습니다." << endl;
			break;
		case 2:
			if (p->Delete(tmpItem) == true)
				cout << tmpItem << "가 삭제되었습니다." << endl;
			else cout << "비어있습니다. 삭제 실패" << endl;
			break;
		case 3:
			cout << "크기: " << p->GetSize() << endl;
			p->Print();
			break;
		case 4:
			flag = true; break;
		default:
			cout << "잘못 입력하셨습니다." << endl;
			break;
		}
		if (flag) break;
	} while (1);
	delete p;
}
