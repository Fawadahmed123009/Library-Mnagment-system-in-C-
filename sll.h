#pragma once
#include <vector> // #include directive
#include <string>
class sll {
	snode* head, * tail;
class snode {
public:
	string data;
	snode* next;
	snode(string val)
	{
		data = val;
		next = NULL;
	}
};
public:
	sll()
	{
		head = tail = NULL;
	}
	void insert_sll()
	{
		string val;
		cout << "Enter Author : ";
		cin >> val;
		snode* temp = new snode(val);
		temp->next = head;
		head = temp;
	}
	void deleteList()
	{
		snode* current = head;
		snode* next = NULL;

		while (current != NULL)
		{
			next = current->next;
			free(current);
			current = next;
		}
	}
	void print()
	{
		snode* temp = head;
		if (head == NULL)
		{
			cout << "No Author";
		}
		else
		{
			while (temp != NULL)
			{
				cout << temp->data << " , ";
				temp = temp->next;
			}
		}
	}
};
