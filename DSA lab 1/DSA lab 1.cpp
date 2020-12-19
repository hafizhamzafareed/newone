// DSA lab 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<string>
using namespace std;

class list
{
private:
	int*p;
	int curr_ind;
public:
	list()
	{
		p = new int[3]{ 1,2,3 };
		curr_ind = 3;
	}
	int search(int x);
	void insert(int x, int y);
	void remove(int x);

	int front(int x)
	{
		if (x > curr_ind)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	int back(int x)
	{
		if (x < 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	void update(int x, int i);

	void index_at(int x)
	{
		cout << "\nvalue found at idex " << x << endl;
	}
	void display();
	void menu();

	~list()
	{
		delete[]p;
	}
};
int list::search(int x)
{
	for (int i = 0; i < curr_ind; i++)
	{
		if (x == p[i])
		{
			index_at(i);
			return i;
		}
	}
	cout << "value is not found.....";
	return -1;
}
void list::insert(int x, int y)
{
	if (y == 1)
	{
		int*temp = new int[curr_ind + 1];
		temp[0] = x;
		for (int i = 0; i < curr_ind; i++)
		{
			temp[i + 1] = p[i];
		}
		curr_ind++;
		p = new int[curr_ind];
		for (int i = 0; i < curr_ind; i++)
		{
			p[i] = temp[i];
		}
		cout << "\n value added successfully....";
	}
	else
	{
		int*temp = new int[curr_ind + 1];
		for (int i = 0; i < curr_ind; i++)
		{
			temp[i] = p[i];
		}
		temp[curr_ind] = x;
		curr_ind++;
		p = new int[curr_ind];
		for (int i = 0; i < curr_ind; i++)
		{
			p[i] = temp[i];
		}
		cout << "\n value added successfully....";
	}
}
void list::remove(int x)
{
	if (search(x) != -1)
	{
		int*temp = new int[curr_ind];
		for (int i = 0; i < curr_ind; i++)
		{
			temp[i] = p[i];
		}
		p = new int[curr_ind - 1];
		for (int i = 0; i < curr_ind; i++)
		{
			if (x == *temp)
			{
				temp++;
				--curr_ind;
			}
			p[i] = *temp;
			temp++;
		}
		cout << "node removed successfully....";
	}
	else
	{
		cout << "\nNo such node exists......";
	}
}
void list::update(int x, int i)
{
	if (front(i) && back(i))
	{
		p[i] = x;
		cout << "\nNode updated successfully.....";
	}
	else
	{
		cout << "\nNo such node exists......press any key to exit.........";
	}
}
void list::display()
{
	cout << "\nThe values in the list are : ";
	for (int i = 0; i < curr_ind; i++)
	{
		cout << p[i] << "  ";
	}
}
void list::menu()
{
	while (1)
	{
		system("CLS");
		cout << "***************************************************" << endl;
		cout << "********* Welcome user this is a list class *******" << endl;
		cout << "***************************************************" << endl << endl;
		cout << "This list has 1,2,3 values to respective index starting from 0.." << endl;
		cout << "You can perform the following operation on the list...." << endl << "1. insert node at the start." << endl;
		cout << "2. insert node at the end." << endl << "3. serch a specific value." << endl << "4. update a value." << endl;
		cout << "5. remove a node." << endl << "6. Display the list.\n\n";
		cout << "Please select an option through 1,2,3,4,5,6....";
		int x, y;
		cin >> x;
		switch (x)
		{
		case 1:
		{
			system("CLS");
			cout << "Enter the value u want to insert : ";
			cin >> y;
			insert(y, x);
			break;
		}
		case 2:
		{
			system("CLS");
			cout << "Enter the value u want to insert : ";
			cin >> y;
			insert(y, x);
			break;
		}
		case 3:
		{
			system("CLS");
			cout << "Enter the value u want to search : ";
			cin >> y;
			search(y);
			break;
		}
		case 4:
		{
			system("CLS");
			int i;
			cout << "Enter the index : ";
			cin >> i;
			cout << "Enter the value u want to update : ";
			cin >> y;
			update(y, i);
			break;
		}
		case 5:
		{
			system("CLS");
			cout << "Enter the value u want to remove : ";
			cin >> y;
			remove(y);
			break;
		}
		case 6:
		{
			system("CLS");
			display();
			break;
		}
		default:
		{
			cout << "You entered a wrong option....";
		}
		}
		int t;
		cout << "\nEnter 1 to return to the main menu and any other to exit...";
		cin >> t;

		if (t != 1)
		{
			break;
		}

	}

}
void main()
{
	list l1;
	l1.menu();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
