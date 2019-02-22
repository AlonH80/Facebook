#pragma warning (disable:4290)
// Disable "exception specification" error.
#ifndef _FACEBOOK_H
#define _FACEBOOK_H
#include "Person.h"
#include "FanPage.h"
#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>
using namespace std;

enum USERTYPE {PERSON,FANPAGE,USER};

class Facebook
{
private:
    vector<User*> users;
    vector<Status*> allStatuses;
		
public:
	Facebook();
	~Facebook();
	Facebook(const Facebook& fBook) = delete;
	void addPerson(Person& newPers);
	void addFanPage(FanPage& fpage);
    void addStatus(Status& newStatus);
    void addStatusToUser(const string& userName, const string& statusContent, STATUSTYPE statusType,USERTYPE userType) throw (const char*);
    User* findUser(const string& userName,USERTYPE userType) const;
	void linkFriends(Person& p1,Person& p2) throw (const char*);
	void addFanToFanPage(Person& pers, FanPage& fPage) throw (const char*);
	void showAllPersons() const;
	void showAllFanPages() const;
	void showAll() const;
    void showPersonsFriendsStatuses(const string& personName,int numOfStatuses=10) const;
    bool isUserExist(const string& name,USERTYPE userType);
    friend USERTYPE getUserType(User& user);
    friend void checkUserType(int userTypeNum) throw (const char*);
    friend void checkStatusType(int statusType) throw (const char*);
};

USERTYPE getUserType(User& user);
void checkUserType(int userTypeNum) throw (const char*);
void checkStatusType(int statusType) throw (const char*);

#endif
