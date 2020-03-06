#include <iostream>
using namespace std;

typedef int Item;

class List
{
private:
	static const int MAX = 5;
	Item items[MAX];
	int index;
public:
	List();
	bool add(const Item & item);
	bool isEmpty() const;
	bool isFull() const;
	void show() const;
	void visit(void(*pf)(Item & item));
};
List::List()
{
	index = 0;
}

bool List::add(const Item & item)
{
	if (index < MAX)
	{
		items[index++] = item;
		return true;
	}
	else return false;
}

bool List::isEmpty() const
{
	return index == 0;
}

bool List::isFull() const
{
	return index == MAX;
}

void List::show() const
{
	for (int i = 0; i < MAX; i++)
	{
		cout << "\n" << i + 1 << ": " << items[i];
	}
}

void List::visit(void(*pf)(Item & item))
{
	for (int i = 0; i < MAX; i++)
	{
		(*pf)(items[i]);
	}
}
void cha(Item & num);

int main()
{
	void(*pf)(Item & num);
	pf = &cha;
//   cout << boolalpha;
	Item input;
	List l;
	cout << "empty? " << l.isEmpty();
	cout << "\nfull? " << l.isFull();
	cout << "\nList : ";
	l.show();
	cout << endl;
	cout << "Enter 5 values: ";
	for (int i = 0; i < 5; i++)
	{
		cin >> input;
		l.add(input);
	}
	cout << "empty? " << bool(l.isEmpty());
	cout << "\nfull? " << bool(l.isFull());
	cout << "\nList : ";
	l.show();
	cout << endl;
	cout << "Values of all list items if squared: ";
	l.visit(*pf);
	l.show();
	return 0;
}

void cha(Item & num)
{
	num = num * num;
}
