
#include<iostream>
#include<iomanip>
#include"DataElement.h"
#include"List.h"
#include"Event.h"
#include"Queue.h"
using namespace std;

const int SIZE = 6;
void processArrival(int &customer,
	DataElement  iFile[], int  length,
	List<Event>  &eList, Queue<DataElement>  &bQueue);
void processDeparture(List<Event>  &eList, Queue<DataElement>  &bQueue, int &wTime);
int main()
{
	// an array of DataElement with the data the bank provided:
	DataElement bankData[SIZE] = { DataElement(20,5),DataElement(22,4),DataElement(23,2),DataElement(30,3)
		,DataElement(40,3),DataElement(41,4) };
	Queue<DataElement> bankQueue;
	List<Event> eventList;
	int customer = 0;
	int waitingTime;
	int totalWaitingTime = 0;

	cout << endl;
	cout << "Computer Simulation starts......\n";

	
	eventList.insertSorted(Event('A', bankData[customer].getArrivalTime()));
	while (!eventList.isEmpty())
	{
		if (eventList.getEntry(1).getEventStatus()=='A')
		{
			processArrival(customer, bankData[], SIZE, eventList, bankQueue); 
			customer++; 
		}
		else
		{
			processDeparture(eventList, bankQueue, waitingTime);
		}
	}


	system("pause");
	return 0;
}
void processArrival(int &customer,
	DataElement  iFile[], int  length,
	List<Event>  &eList, Queue<DataElement>  &bQueue)
{
	if (bQueue.isEmpty())
	{
		eList.insertSorted(Event('D', (iFile[customer].getArrivalTime() + iFile[customer].getTransectionTime())));
	}
	bQueue.enqueue(iFile[customer]);
	eList.remove(1);
	customer++;
	if (((lenght - 1)>customer))
	{
		eList.insertSorted(Event('A', (iFile[customer].getArrivalTime())));
	}

}
void processDeparture(List<Event>  &eList, Queue<DataElement>  &bQueue, int &wTime)
{
	int dTemp = bQueue.peekFront().getTransectionTime();
	bQueue.dequeue;
	int dTime = dTemp.getArrivalTime() + dTemp.getTransectionTime();
	DataElement curTemp = bQueue.peekFront();
wTime = dTime - curTemp.getArrivalTime();
eList.remove(1);
Event dEvent('D', dTemp);
if (!bQueue.isEmpty())
{
	eList.insertSorted(dEvent);
}
}

