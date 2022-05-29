// C++ Program to sort a linked list 0s, 1s or 2s
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node
{
	public:
	int data;
	Node* next;
};


void sortList(Node *head)
{
	int count[3] = {0, 0, 0}; 
	Node *ptr = head;

	while (ptr != NULL)
	{
		count[ptr->data] += 1;
		ptr = ptr->next;
	}

	int i = 0;
	ptr = head;
	while (ptr != NULL)
	{
		if (count[i] == 0)
			++i;
		else
		{
			ptr->data = i;
			--count[i];
			ptr = ptr->next;
		}
	}
}

/* Function to push a node */
void push (Node** head_ref, int new_data)
{
	/* allocate node */
	Node* new_node = new Node();

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}


void printList(Node *node)
{
	while (node != NULL)
	{
		cout << node->data << " ";
		node = node->next;
	}
	cout << endl;
}


int main(void)
{
	Node *head = NULL;
	push(&head, 0);
	push(&head, 1);
	push(&head, 0);
	push(&head, 2);
	push(&head, 1);
	push(&head, 1);
	push(&head, 2);
	push(&head, 1);
	push(&head, 2);

	cout << "Linked List Before Sorting\n";
	printList(head);

	sortList(head);

	cout << "Linked List After Sorting\n";
	printList(head);

	return 0;
}


