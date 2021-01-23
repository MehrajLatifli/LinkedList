#include <iostream>
#include <assert.h>

using namespace std;



template <typename T>
class LinkedList {
public:
	class Node {
	public:
		T data;
		Node* next = nullptr;

	};
	static void printList(Node* n) {
		cout << "\n Printing new list " << endl;
		while (n != NULL) {
			cout << " " << n->data << " ";
			n = n->next;
		}
	}

	void pushlast(Node* head, T new_data) {
		Node* new_node = (Node*)malloc(sizeof(Node));
		new_node->data = new_data;
		new_node->next = NULL;
		Node* last = head;
		while (last->next != NULL) {
			last = last->next;
		}
		last->next = new_node;
	}

	void pushfirst(Node** head, T new_data) {
		Node* new_node = new Node;
		new_node->data = new_data;
		new_node->next = *(head);
		*head = new_node;
	}

	void insertAfter(Node* prev_node, T new_data) {
		if (prev_node == NULL) {
			cout << " Error " << endl;
			return;
		}
		Node* new_node = (Node*)malloc(sizeof(Node));
		new_node->data = new_data;
		new_node->next = prev_node->next;
		prev_node->next = new_node;
	}

	void deleteAfterwithNode(Node* head, Node* temp)
	{

		if (head == temp)
		{
			if (head->next == NULL)
			{
				cout << "There is only one node." <<
					" The list can't be made empty ";
				return;
			}


			head->data = head->next->data;


			temp = head->next;


			head->next = head->next->next;


			free(temp);

			return;
		}

		Node* prev_node = head;
		while (prev_node->next != NULL && prev_node->next != temp) {
			prev_node = prev_node->next;
		}


		if (prev_node->next == NULL)
		{
			cout << "\nGiven node is not present in Linked List";
			return;
		}


		prev_node->next = prev_node->next->next;


		free(temp);

		return;
	}



	void deleteAfterwithKey(Node** head_ref, T key)
	{


		Node* temp = *head_ref;
		Node* prev_node = NULL;


		if (temp != NULL && temp->data == key)
		{
			*head_ref = temp->next;
			delete temp;
			return;
		}


		while (temp != NULL && temp->data != key)
		{
			prev_node = temp;
			temp = temp->next;
		}


		if (temp == NULL)
			return;


		prev_node->next = temp->next;


		delete temp;
	}
};

void main() {
	LinkedList<char>::Node* head = NULL;
	LinkedList<char>::Node* second = NULL;
	LinkedList<char>::Node* third = NULL;

	head = new LinkedList<char>::Node();
	second = new LinkedList<char>::Node();
	third = new LinkedList<char>::Node();

	head->data = 'a';
	head->next = second;

	second->data = 'd';
	second->next = third;

	third->data = 'i';
	third->next = NULL;

	LinkedList<char>::printList(head);
	LinkedList<char>* linked = new LinkedList<char>();

	cout << "\n =========================== \n ";
	linked->pushlast(head, 't');
	LinkedList<char>::printList(head);
	cout << "\n =========================== \n ";
	linked->pushfirst(&head, 'e');
	LinkedList<char>::printList(head);
	cout << "\n =========================== \n ";
	linked->insertAfter(second, 'v');
	LinkedList<char>::printList(head);
	cout << "\n =========================== \n ";
	linked->deleteAfterwithNode(second, third);
	LinkedList<char>::printList(head);
	cout << "\n =========================== \n ";
	linked->deleteAfterwithKey(&head, 't');
	LinkedList<char>::printList(head);
	cout << "\n =========================== \n ";

}