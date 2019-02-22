
#include "FanPage.h"
#include "Person.h"

FanPage::FanPage(const string& fpName) : User(fpName)
{

}

FanPage::FanPage(const FanPage& copy) : User(copy)
{

}

FanPage::~FanPage()
{

}

void FanPage::show() const
{
	cout << "Fan Page: " << name << endl;
}

int compare(const FanPage& p1,const FanPage& p2)
{
	return(p1.getName().compare(p2.getName()));
}
bool areEquals(const FanPage& p1, const FanPage& p2)
{
	return (compare(p1,p2) == 0);
}
