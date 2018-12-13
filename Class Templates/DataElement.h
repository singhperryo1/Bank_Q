//Header File for the class DataElement
#ifndef _DataElement
#define _DataElement
#include <iostream> 
using namespace std; 
class DataElement
{
  private:
    int arrivalTime;
    int transectionTime;
  public:
    DataElement();
    DataElement(int arTime, int traTime);
    void setArrivalTime(int arTime);
    int getArrivalTime();
    void setTransectionTime(int traTime);
    int getTransectionTime();
	friend ostream &operator<<(ostream &stream, DataElement &Dael);

};
  DataElement::DataElement()
{
	arrivalTime = 0; 
	transectionTime = 0; 
}
  DataElement::DataElement(int arTime, int traTime)
{
	  arrivalTime = arTime; 
	  transectionTime = traTime; 
}
  void DataElement::setArrivalTime(int arTime)
  {
	  arrivalTime = arTime; 
  }
  int DataElement::getArrivalTime()
  {
	  return arrivalTime; 
  }
  void DataElement::setTransectionTime(int traTime)
  {

	  transectionTime = traTime; 
  }
  int DataElement::getTransectionTime()
  {
	  return transectionTime; 
  }
  ostream &operator<<(ostream &out, DataElement &Dael)
  {
	  out << Dael.arrivalTime <<"		"; 
	  out << Dael.transectionTime << endl; 
	  return out; 
  }

#endif
