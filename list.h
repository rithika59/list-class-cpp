#include<iostream>

typedef int Item;

class List
{
	private:

		static int MAX = 0;
		int index;
		Item item[MAX];

	public:

		bool add(Item &item) const;
		bool isEmpty() const;
		bool isFull() const;

};
