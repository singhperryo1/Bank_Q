//Header File for the class Event
#ifndef _Event
#define _Event
#include <iostream> 
using namespace std; 
class Event
{
private:
	char eventStatus;
	int occurTime;
public:
	Event();
	Event(char eStatue, int oTime);
	void setEventStatus(char eStatus);
	char getEventStatus();
	void setOccurTime(int oTime);
	int getOccurTime()const ;
	//operatro overloading
	bool operator>(const Event &anEvent) const;
	bool operator==(const Event &anEvent) const;
};
Event::Event()
{
	eventStatus = 'A';
	occurTime = 0;
}
Event::Event(char eStatue, int oTime)
{
	eventStatus = eStatue; 
	occurTime = oTime; 
}
void Event::setEventStatus(char eStatus)
{
	eventStatus = eStatus; 
}
char Event::getEventStatus()
{
	return eventStatus; 
}
void Event::setOccurTime(int oTime)
{
	occurTime = oTime; 
}
int Event::getOccurTime() const
{
	return occurTime; 
}
bool Event::operator>(const Event &anEvent)const
{
	if(this->getOccurTime()> anEvent.getOccurTime())
		return true;
	else
		return false; 
}
bool Event::operator==(const Event &anEvent) const
{
	if (this->getOccurTime() == anEvent.getOccurTime())
		return true;
	else
		return false; 
}
#endif