#include "Facebook.h"

Facebook::Facebook()
{
}

Facebook::~Facebook()
{
    for (vector<User*>::iterator currUser=this->users.begin();currUser<this->users.end();currUser++)
        delete *currUser;
}

void Facebook::addPerson(Person& newPers)
{
    this->users.push_back(&newPers);
}

void Facebook::addFanPage(FanPage &fpage)
{
    this->users.push_back(&fpage);
}

void Facebook::addStatus(Status& newStatus)
{
    // This function adding new status.
    this->allStatuses.push_back(&newStatus);
}

void Facebook::addStatusToUser(const string& userName, const string& statusContent, STATUSTYPE statusType,USERTYPE userType) throw (const char*)
{
    User* user=findUser(userName,userType);
    if (user!=nullptr)
    {
        user->addStatus(statusType, statusContent);
        this->addStatus(*user->getPastStatus()[user->getNumOfStatuses()-1]);
    }
    else
        throw "User not exist.";
    
}

User* Facebook::findUser(const string& userName,USERTYPE userType) const
{
    vector<User*>::const_iterator currUser=this->users.begin();
    while (currUser<this->users.end() && (userName.compare((*currUser)->getName())!=0 || getUserType(*(*currUser))!=userType))
        currUser++;
    if (currUser<this->users.end())
        return *currUser;
    else
    {
        return nullptr;
    }
}

void Facebook::linkFriends(Person &p1, Person &p2) throw (const char*)
{
    // This function link 2 persons.
    if (areEquals(p1,p2))
        throw "Person can't be friend with himself";
    if (!p1.isPersonFriend(p2))
    {
        p1+=p2;
        p2+=p1;
    }
    else
        throw "Already linked.";
}

void Facebook::addFanToFanPage(Person &pers, FanPage &fPage) throw (const char*)
{
    // This function add person to fan page,
    // and add fan page to person.
    if (pers.isSubToFP(fPage))
        throw "Already subscriped.";
    pers.addFanPage(fPage);
    fPage+=pers;
}

void Facebook::showAllPersons() const
{
    // This function show all persons.
    for(vector<User*>::const_iterator currUser=this->users.begin();currUser<this->users.end();currUser++)
    {
        if (getUserType(**currUser)==PERSON)
            (*currUser)->show();
    }
}

void Facebook::showAllFanPages() const
{
    // This function show all fan pages.
    for(vector<User*>::const_iterator currUser=this->users.begin();currUser<this->users.end();currUser++)
    {
        if (getUserType(**currUser)==FANPAGE)
            (*currUser)->show();
    }
}

void Facebook::showAll() const
{
    // This function show all users.
    this->showAllPersons();
    this->showAllFanPages();
}

void Facebook::showPersonsFriendsStatuses(const string& personName,int numOfStatuses) const
{   // This function show numOfStatuses (parameter) statuses of person's friends.
    int statusesShowed=0;
    vector<Status*>::const_iterator currStatus=this->allStatuses.begin();
    Person* pers=dynamic_cast<Person*>(findUser(personName,PERSON));
    Person* currWriter;
    while (currStatus<this->allStatuses.end() && statusesShowed<numOfStatuses)
    {
        currWriter=dynamic_cast<Person*>(this->findUser((*currStatus)->getWriter(),PERSON));
        if (currWriter!=nullptr)
        {
            if (pers->isPersonFriend(*currWriter))
            {
                (*currStatus)->show();
                statusesShowed++;
            }
        }
        currStatus++;
    }
}

bool Facebook::isUserExist(const string& name,USERTYPE userType)
{
    // Check if the user exist.
    return findUser(name,userType)!=nullptr;
}

USERTYPE getUserType(User& user)
{
    if (strcmp(typeid(user).name()+1,"Person")==0)
        return PERSON;
    else if (strcmp(typeid(user).name()+1,"FanPage")==0)
        return FANPAGE;
    return USER;
}

void checkUserType(int userTypeNum) throw (const char*)
{
    if(userTypeNum>FANPAGE || userTypeNum<PERSON)
        throw "Invalid user type.";
}

void checkStatusType(int statusType) throw (const char*)
{
    if(statusType>TEXT_AND_VIDEO || statusType<VIDEO)
        throw "Invalid status type.";
}
