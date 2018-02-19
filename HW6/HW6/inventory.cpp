#include <stdbool.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

class InventoryItem { //converted struct to class
public:
		string sku;
		double price;
		size_t quantity;
		bool onSale;
};

void printItem(InventoryItem &item)
{
	cout << "Item SKU: " << item.sku << ": $" << item.price << " x " << item.quantity << " (SALE: " << item.onSale << ")" << endl;
}
void sellItem(InventoryItem &item)
{
	item.quantity--;
}
void addInventory(InventoryItem &item, size_t stock)
{
	item.quantity += stock;
}
void toggleSaleStatus(InventoryItem &item)
{
	item.onSale = !(item.onSale);
}

int main()
{
	InventoryItem item0 = { "1523041125", 12.00, 14, false };
	InventoryItem item1 = { "aksdjflajf", 15.99, 8, true };
	InventoryItem item2 = { "12kefe1j38", 1.72, 33, false };
	InventoryItem items[] = { item0, item1, item2 };
	for (int i = 0; i < 3; ++i)
	{
		printItem((items[i]));
	}
	// sell some stuff
	sellItem(items[1]); // all pass-by-pointers are now pass-by-reference. mwahahaha
	sellItem(items[2]);
	sellItem(items[2]);
	sellItem(items[0]);
	sellItem(items[0]);
	sellItem(items[2]);
	sellItem(items[0]);
	// get new inventory
	addInventory(items[0], 5);
	addInventory(items[1], 15);
	addInventory(items[2], 40);
	// have a sale
	for (int i = 0; i < 3; ++i)
	{
		if (items[i].quantity > 20 && !(items[i].onSale))
			toggleSaleStatus(items[i]);
	}
	// print results
	for (int i = 0; i < 3; ++i)
	{
		printItem(items[i]);
	}
}