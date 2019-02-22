
#include "Person.h"
#include "FanPage.h"

Person::Person(const string& pName,const Date& bDate) :User(pName), numOfFanPages(0),
		 birthDate(bDate) , likedFanPages()
{



}


Person::Person(const Person& other) : User(other) , numOfFanPages(other.numOfFanPages),

		 birthDate(other.birthDate) , likedFanPages(other.likedFanPages)
{



}
Person::~Person()
{


}




/*void Person::doubleFanPagesArr()
{
	FanPage** tempArr = new FanPage*[friendsLogicalSize * 2];
	for (int i = 0; i < numOfFanPages; i++)
	{
		tempArr[i] = likedFanPages[i];
	}
	delete []likedFanPages;
	likedFanPages = tempArr;
	FanPagesLogicalSize *= 2;
}*/

/////////////

bool Person::isSubToFP(const FanPage& fp)
{
	bool found = false;
	for (int i = 0; !found && i < numOfFanPages; i++)
		{
			found = (areEquals(fp, *(likedFanPages[i])));

		}

	return found;

}

void Person::addFanPage(FanPage& fanPageToAdd)
{
	if (!isSubToFP(fanPageToAdd))
	{

				likedFanPages.push_back(&fanPageToAdd);
				numOfFanPages++;
	}
}


Date Person::getBirthDate() const
{
	return birthDate;
}


const vector<FanPage*>& Person::getFanPages() const
{
	return likedFanPages;
}


void Person::showFanPages(int num) const
{
	if (num > numOfFriends)
		{
			cout << name << " has only " << numOfFanPages << " fan pages" << endl;
			num = numOfFanPages;
		}
		for (int i = 0; i < num; i++)
		{
			cout << likedFanPages[numOfFanPages - i - 1]->getName() << endl;
		}
}

void Person::show() const
{
	cout << "Person: " << name << endl;
}

int compare(const Person& p1,const Person& p2)
{
	return(p1.getName().compare(p2.getName()));
}

bool areEquals(const Person& p1,const Person& p2)
{
	return(compare(p1,p2) == 0);
}
