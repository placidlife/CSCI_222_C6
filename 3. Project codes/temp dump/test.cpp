#include "StockItem.h"
#include <iostream>

using namespace std;

int main() {
	StockItem test("0123", "AppleCore", "Food", "Fruit");
	StockItem test2("0124", "Aibot", "Robotics", "Boyfriend V.2.3");

	string testPrint = test.toString();
	string testPrint2 = test2.toString();
	cout << testPrint;
	cout << testPrint2;
}
