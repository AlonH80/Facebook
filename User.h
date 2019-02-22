/*
 * User.h
 *
 *  Created on: 27 בדצמ 2018
 *      Author: nave
 */

#ifndef USER_H_
#define USER_H_
#include"Status.h"
#include<string>
#include<vector>
using namespace std;

class Person;
class FanPage;
class User
{
	protected:
		string name;

		vector<Status*> pastStatus;
		int numOfStatuses;

		vector<Person*> friends;
		int numOfFriends;

		void addStatus(Status& statusToAdd);

		User(const string& fpName);
		User(const User& copy);
	public:

		virtual ~User();

		const string& getName() const;
		const vector<Status*>& getPastStatus() const;
		const vector<Person*>& getFriends() const;
		virtual void show() const;
		void showFriends(int num) const;
		void printLastStatuses(int num) const;

		void addStatus(STATUSTYPE sType,const string& sContent);
		void addFriend(Person& fanToAdd);
		bool isPersonFriend(const Person& fanToFind) const;
		int getNumOfStatuses() const;
		int getNumOfFriends() const;
		int compare(const User& other) const;
		friend int compare(const User& p1, const User& p2);
		friend bool areEquals(const User& p1, const User& p2);
		bool operator>(const User& other) const;
		const User& operator+=(Person& personToAdd);
};


#endif /* USER_H_ */
