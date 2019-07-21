#include<bits/stdc++.h>

using namespace std;

class Node
{
public:

	/* data */
	int data;
	Node* next;
	Node(int data){
		this->data = data;
	}
};

void traverseLinkedList(Node* node ){
	Node* temp = node;
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

Node* deleteData(Node* node, int data){
	Node* temp = node;
	if(node== NULL){
		return node;
	}
	if(node->data == data){
		Node* temp = node;
		temp = temp->next;
		delete(node);
		return temp;
	}
	while(temp->next !=NULL && temp->next->data != data){
		temp = temp->next;
	}
	if(temp->next ==NULL){
		return node;
	}
	Node* nodeToBeDeleted = temp->next;
	temp->next = temp->next->next;
	delete(nodeToBeDeleted);
	return node;
}

int lengthOfLinkedList(Node* node){
	int length = 0;
	while(node != NULL){
		length++;
		node = node->next;
	}
	return length;
}

Node* pushFront(Node* node, int data){
	Node* newHead = new Node(data);
	newHead->next = node;
	return newHead;
}

Node* append(Node* node, int data){
	Node* last = node;
	Node* newLast = new Node(data);
	newLast->next = NULL;
	if(last == NULL){
		return newLast;
	}
	while(last->next != NULL){
		last = last->next;
	}	
	last->next = newLast;
	return node;
}

bool search(Node* node, int data){
	if(node == NULL){
		return false;
	}
	Node* temp = node;
	while(temp != NULL){
		if(temp->data == data){
			delete(temp);
			return true;
		}
		temp = temp->next;
	}
	return false;
}

// 0 Indexing
int getNthNode(Node* node, int n){
	if(node ==NULL){
		return -1;
	}
	Node* temp = node;
	while(temp != NULL && n>0){
		temp = temp->next;
		n--;
	}
	if(n==0 && temp != NULL){
		return temp->data;
	}
	return -1;
}

int printNthFromLast(Node* node, int n){
	Node* temp1 = node;
	Node* temp2 = node;
	while(temp1 != NULL && n>0){
		temp1 = temp1->next;
		n--;
	}
	if(temp1 == NULL){
		return -1;
	}
	while(temp1->next != NULL){
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	return temp2->data;
}

int findMiddleElement(Node* node){
	Node* fast = node;
	Node* slow = node;
	if(node == NULL){
		return -1;
	}
	while(fast != NULL && fast->next !=NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow->data;
}

int main(){

	Node* head = new Node(1);
	Node* secondNode = new Node(2); 
	Node* thirdNode = new Node(3);

	head->next = secondNode;
	secondNode->next = thirdNode;
	thirdNode->next = NULL;

	// traverse LL
	traverseLinkedList(head);

	// append 4
	head = append(head, 4);
	traverseLinkedList(head);	

	// pushFront 0
	head = pushFront(head, 0);
	traverseLinkedList(head);	

	// delete 0
	head = deleteData(head, 0);
	traverseLinkedList(head);

	// head = deleteData(head, 3);
	// traverseLinkedList(head);

	// head = deleteData(head, 4);
	// traverseLinkedList(head);	
	cout<<"Length of LL: "<<lengthOfLinkedList(head)<<endl;

	//search 5 in LL
	cout<<"seach 5 in LL: "<<search(head,5)<<endl;

	//search 2 in LL
	cout<<"seach 2 in LL: "<<search(head,2)<<endl;

	// get 4th Node
	cout<<"4th Node in LL: "<<getNthNode(head,3)<<endl;

	// get 5th Node
	cout<<"5th Node in LL: "<<getNthNode(head,4)<<endl;	

	// get 0th Node from last
	cout<<"0th Node from end in LL: "<<printNthFromLast(head,0)<<endl;

	// get middle Node of LL
	cout<<"middle Node of LL: "<<findMiddleElement(head)<<endl;

}