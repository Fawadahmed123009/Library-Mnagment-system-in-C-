#pragma once
#include <vector> // #include directive
#include <string>
#include "sll.h"
#include "DLL.h"
#include "AVL.h"
class menu {
private:
	AVL obj;
	DLL d;
	Tnode* issn = NULL;

public:
	void create_book_record()
	{
		int n;
		cout << "Enter issn : ";
		cin >> n;
		d.inserstion_dll();
		obj.insertNode(d.get(), n);


	}
	void review()
	{
		obj.inorder(d.get());
	}
	void delete_record()
	{
		int n;
		cout << "Enter issn : ";
		cin >> n;
		obj.deleteNode(d.get(), n);
		cout << "Issn : " << n << " deleted successfully !!";
	}
	void update()
	{
		int n;
		cout << "Enter issn : ";
		cin >> n;
		bool a = obj.searchAvl(d.get(), n);
		if (a == true)
		{
			obj.deleteNode(d.get(), n);
			d.inserstion_dll();
			obj.insertNode(d.get(), n);
		}
	}
	void Menu()
	{
		int choice;
		cout << "\t\t  ------------------------------------------Menu-----------------------------------------\t\n\n";
		cout << "1.Create a book Record" << endl;
		cout << "2.Delete Book Record" << endl;
		cout << "3.Review Book Record" << endl;
		cout << "4.Update Book Record";
		cout << "5.exit" << endl;
		cout << "Enter your choice(1,2,3,4,5) : ";
		cin >> choice;
		do {
			if (choice == 1) {
				cout << "\t\t-------------------------------------Create Book Record-------------------------------------\n\n";
				create_book_record();
				cout << endl;
			}
			else if (choice == 2) {
				cout << "\t\t-------------------------------------Delete Book Record-------------------------------------\n\n";
				delete_record();
				cout << endl;
			}
			else if (choice == 3) {
				cout << "\t\t-------------------------------------Review Book Record-------------------------------------\n\n";
				review();
				cout << endl;
			}
			else if (choice == 4)
			{
				cout << "\t\t-------------------------------------Update Book Record-------------------------------------\n\n";
				update();
			}
			else if (choice == 5)
			{
				cout << "\t---------------------End-----------------------\t\n";
			}
			else {
				cout << "Enter valid choice please!!!" << endl;
			}
			cout << "\t\t  ------------------------------------------Menu-----------------------------------------\t\n\n";
			cout << "1.Create a book Record" << endl;
			cout << "2.Delete Book Record" << endl;
			cout << "3.Review Book Record" << endl;
			cout << "4.Update Book Record";
			cout << "5.exit" << endl;
			cout << "Enter your choice(1,2,3,4,5) : ";
			cin >> choice;

		} while (choice != 5);
	}

};