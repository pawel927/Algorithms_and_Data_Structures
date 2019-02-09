#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

struct Product
{
	string name;
	int num;
	Product *next;

	Product()
	{
		cout << "Give a name: ";
		cin >> name;
		cout << "Give a number: ";
		cin >> num;
		next = NULL;
	}

	void print()
	{
		cout << "Name: " << name << "\tNumber: " << num << endl;
	}
};

void addProduct(Product **p)
{
	Product *newProduct = new Product;
	Product *helpProduct = (*p), *helpProduct1 = NULL;

	while (helpProduct != NULL && (helpProduct->name).compare(newProduct->name) == -1)
	{
		helpProduct1 = helpProduct;
		helpProduct = helpProduct->next;
	}

	if (helpProduct != NULL && (helpProduct->name).compare(newProduct->name) == 0)
	{
		cout << "This product already exists!" << endl;
		delete newProduct;
	}

	else if ((*p) == NULL || ((helpProduct) == (*p) && (helpProduct->name).compare(newProduct->name) == 1))
	{
		newProduct->next = (*p);
		(*p) = newProduct;
	}

	else
	{
		helpProduct1->next = newProduct;
		newProduct->next = helpProduct;
	}
}

void search(Product *p, string s)
{
	while (p != NULL && (p->name).compare(s) != 0)
	{
		p = p->next;
	}

	if (p == NULL)
	{
		cout << "This product does not exist!" << endl;
	}

	else
	{
		p->print();
	}
}

void allProducts(Product *p)
{
	cout << "Products: " << endl;

	while (p != NULL)
	{
		p->print();
		p = p->next;
	}
}

bool deleteProduct(Product **p, string s)
{
	if (*p == NULL)
	{
		return false;
	}

	Product *helpProduct = (*p), *helpProduct1 = NULL;

	while (helpProduct != NULL && (helpProduct->name).compare(s) != 0)
	{
		helpProduct1 = helpProduct;
		helpProduct = helpProduct->next;
	}

	if (helpProduct == NULL)
	{
		return false;
	}

	else if (helpProduct == (*p))
	{
		(*p) = (*p)->next;
		delete helpProduct;
	}

	else
	{
		helpProduct1->next = helpProduct->next;
		delete helpProduct;
	}

	return true;
}

int main()
{
	char command;
	Product *p = NULL;
	string name;

	while (cin >> command)
	{
		switch (command)
		{
		case 'a':
			addProduct(&p);
			break;

		case 's':
			cout << "Give name: ";
			cin >> name;
			search(p, name);
			break;

		case 'p':
			allProducts(p);
			break;

		case 'd':
			cout << "Give name: ";
			cin >> name;
			deleteProduct(&p, name);
			break;
		}
	}

	return 0;
}