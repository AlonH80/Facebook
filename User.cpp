/*
 * User.cpp
 *
 *  Created on: 27 בדצמ 2018
 *      Author: nave
 */

#include"User.h"
#include"Person.h"
#include <typeinfo>
User::User(const string& fpName) :name(fpName) , pastStatus() , friends()
{



	numOfFriends = 0;


	numOfStatuses = 0;


}

User::User(const User& copy) :name(copy.name) , pastStatus(copy.pastStatus),numOfStatuses(copy.numOfStatuses), friends(copy.friends) ,numOfFriends(copy.numOfFriends)


{


	for (int i = 0; i < numOfStatuses; i++)
		{
			pastStatus[i] = new Status(*(copy.pastStatus[i]));
			//pastStatus.push_back(new Status(*(copy.pastStatus[i])));
		}

}

User::~User()
{

	for (int i = 0; i < numOfStatuses; i++)
	{
		delete pastStatus[i];
	}

}

const string& User::getName() const
{
	return name;
}

bool User::isPersonFriend(const Person& fanToFind) const
{
	bool isFound = false;
	for (int i = 0;!isFound && i < numOfFriends; i++)
	{
		isFound = areEquals(fanToFind,*(friends[i]));
	}
	return isFound;

}



void User::addFriend(Person& sub)
{
	if (!isPersonFriend(sub))
	{
		friends.push_back(&sub);
		//friends[numOfFriends] = &sub;
		numOfFriends++;
	}
}

void User::addStatus(Status& sub)
{

		pastStatus.push_back(&sub);

		numOfStatuses++;

}

// this function allocates new status
void User::addStatus(STATUSTYPE sType,const string& sContent)
{
	Status* stat = new Status(sType, sContent , name);
	addStatus(*stat);
}


int User::getNumOfStatuses() const
{
	return numOfStatuses;
}

int User::getNumOfFriends() const
{
	return numOfFriends;
}

const vector<Status*>& User::getPastStatus() const
{
	return pastStatus;
}

const vector<Person*>& User::getFriends() const
{
	return friends;
}

void User::printLastStatuses(int num) const
{
	if (num > numOfStatuses)
	{
	cout <<"there are only " << numOfStatuses << " statuses" << endl;
	num = numOfStatuses;
	}

	if (num <= numOfStatuses) {
		for(int i = 0; i < num; i++)
		{
			pastStatus[numOfStatuses - i -1]->show();
		}
	}
}

void User::showFriends(int num) const
{
	if (num > numOfFriends)
	{
		cout <<"there are only " << numOfFriends << " friends" << endl;
		num = numOfFriends;
	}
	for(int i = 0; i < num; i++)
	{
		cout << friends[numOfFriends - i -1]->getName() << endl;
	}
}

void User::show() const
{
	cout << "User: " << name << endl;
}

int User::compare(const User& other) const
{
	return(name.compare(other.getName()));
}

int compare(const User& p1,const User& p2)
{
	return(p1.getName().compare(p2.getName()));
}
bool areEquals(const User& p1, const User& p2)
{
	return (compare(p1,p2) == 0);
}

bool User::operator>(const User& other) const
{
	return (this->getNumOfFriends() > other.getNumOfFriends());
}
const User& User::operator+=(Person& personToAdd)
{
	addFriend(personToAdd);
	return *this;
}
