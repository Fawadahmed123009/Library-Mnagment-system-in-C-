#pragma once
#include <vector> // #include directive
#include <string>
class DLL {
private:
class dnode {
public:
	int val;
	dnode* next, * pre;
	string title;
	int no_of_copies;
	int no_of_ref;
	string author;
	void pr()
	{
		cout << "Book Title : " << title << endl;
		cout << "Number of Copies : " << no_of_copies << endl;
		cout << "Number of Refrences : " << no_of_ref << endl;
		cout << "Author : " << author << endl;
	}
	dnode()
	{

	}
};
	dnode* head, * temp;
	int data, choice;
	string title;
	int no_of_copies;
	int no_of_ref;
	string author;
public:
	DLL()
	{
		head = temp = NULL;
		data = 0;
	}
	dnode* get_tail()
	{
		temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		return temp;
	}

	dnode* newnode(string t, int nc, int nr, string a)
	{
		dnode* temp = new dnode;
		temp->title = t;
		temp->no_of_copies = nc;
		temp->no_of_ref = nr;
		temp->author = a;
		return temp;
	}

	dnode* get()
	{
		return get_tail();
	}

	void inserstion_dll()
	{
		cout << "Enter title of book : ";
		cin >> title;
		cout << "Enter number of copies : ";
		cin >> no_of_copies;
		cout << "Enter number of refrences : ";
		cin >> no_of_ref;
		cout << "Enter Author name : ";
		cin >> author;
		if (head == NULL)
		{
			head = newnode(title, no_of_copies, no_of_ref, author);
			return;
		}
		dnode* tail = get_tail();
		temp = newnode(title, no_of_copies, no_of_ref, author);
		temp->next = NULL;
		temp->pre = tail;
		tail->next = temp;
	}
	void print()
	{
		if (head == NULL) {
			cout << "List is empty!!!" << endl;
			return;
		}

		temp = head;
		while (temp != NULL) {
			cout << "Book Title : " << temp->title << endl;
			cout << "Number of Copies : " << temp->no_of_copies << endl;
			cout << "Number of Refrences : " << temp->no_of_ref << endl;
			cout << "Author : " << temp->author << endl;
			temp = temp->next;
		}
	}
	dnode* searching(int data) {
		if (head == NULL) {
			cout << "list is empty :" << endl;
			return NULL;
		}

		temp = head;
		while (temp != NULL) {
			if (temp->val == data) {
				break;
			}
			temp = temp->next;
		}
		return temp;
	}
	void delete_node()
	{
		if (head == NULL) {
			cout << "List is empty : " << endl;
		}

		temp = head;
		cout << "Enter key to delete : ";
		cin >> title;

		dnode* search = searching(no_of_copies);
		dnode* del = NULL;
		if (search == head) {
			del = head;
			if (head->next == NULL) {
				head = NULL;
				cout << endl << "List is Empty Now!!!" << endl;
			}
			else
			{
				head = head->next;
				head->pre = NULL;
			}
		}
		else {
			del = search;
			temp = search;
			temp = temp->pre;
			if (search->next == NULL) {
				temp->next = NULL;
			}
			else {
				temp->next = search->next;
				search->next->pre = temp;
			}
		}

		delete del;
	}


};