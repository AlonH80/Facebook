#ifndef _INTERFACE_H
#define _INTERFACE_H
#include <iostream>
#include "Facebook.h"
#include "Date.h"
using namespace std;

static constexpr int NOT_NUMBER = -1;

class Facebook;

class Interface
{
private:
	vector<string> options;
	Facebook* fBook;

public:
	Interface();
	Interface(const Interface&)=delete;
	~Interface();
    void setMenu();
    //void addOptionToMenu(const char*);
	void showMenu() const;
	int userSelect();
    bool execute(int select);
	void runInterface();
    // Execution functions
    void createPerson();
    void createFanPage();
    void createStatus();
    void showAllUserStatuses();
    void link2Friends();
    void addPersonToFanPage();
    void showUserFriends();
    void showPersonsFriendsStatuses();
    // User input
    STATUSTYPE statusTypeSelect();
    USERTYPE userTypeSelect();
    Date enterDate();
    friend string getName();
    void testSetup();
};

int convertToNum(const string& str);
int convertLineToInt(const string& line);
string getUserInput();
int findSpace(const string& str);

#endif
