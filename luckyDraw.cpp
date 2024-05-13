#ifndef LUCKYDRAW_CPP
#define LUCKYDRAW_CPP
#include "luckyDraw.h"
#include "stack.cpp"
#include "queue.cpp"

luckyDraw::luckyDraw(int count)
{
	totalCount = count;
	specialVariable = 0;
}

//populate lane_1 with the given array of winnersId   
void luckyDraw::populateQueue(int* winnersId)
{
	for (int i = 0; i < totalCount; i++) {
		lane_1.enqueue(winnersId[i]);
	}
}

//populate table_1 with the given array of giftsId   
void luckyDraw::populateTable(int* giftsId)
{
	for (int i = 0; i < totalCount; i++) {
		table_1.push(giftsId[i]);
	}
}

//reverse the queue keeping the conditions in mind
void luckyDraw::reverseQueue()
{

	while (!lane_1.isEmpty()) {
		lane_2.enqueue(lane_1.dequeue());
	}
	for (int i = 0; i < totalCount; i++) {
		for (int j = 0; j < totalCount - (i+1); j++) {
			lane_2.enqueue(lane_2.dequeue());
		}
		lane_1.enqueue(lane_2.dequeue());
	}
}

//transfer the stack keeping the conditions in mind
void luckyDraw::transferStack()
{
	for (int i = 0; i < totalCount; i++) {
		for (int j = 0; j < totalCount - (i + 1); j++) {
			table_2.push(table_1.pop());
		}
		specialVariable = table_1.pop();
		for (int j = 0;j < totalCount - (i + 1); j++) {
			table_1.push(table_2.pop());
		}
		table_2.push(specialVariable);
	}
}

#endif
