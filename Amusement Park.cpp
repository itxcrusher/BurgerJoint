#include "../../../Production/Crusher.h"
#include "./LinkedList.h"
#include "./LinkedList.cpp"
#include "./stack.h"
#include "./stack.cpp"
#include "./Queue.h"
#include "./Queue.cpp"
#include "./luckyDraw.h"
#include "./BurgerJoint.h"

int main() {
	welcome("Amusement Park");
	
	luckyDraw draw(10);
	int ids[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	BurgerJoint shop;

	heading("Reverse Queue");
	draw.populateQueue(ids);
	cout << "\nOriginal Lane: ";
	draw.lane_1.display();
	draw.reverseQueue();
	cout << "\nReversed Lane: ";
	draw.lane_1.display();

	heading("Shift Stack");
	draw.populateTable(ids);
	cout << "\nOriginal Stack: ";
	draw.table_1.display();
	draw.transferStack();
	cout << "\nShifted Stack: ";
	draw.table_2.display();
	
	heading("Sort Stack");
	shop.takeawayCounter();

	farewell();
	return 0;
}