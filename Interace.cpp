#include "Interface.h"

Interface::Interface()
{
    this->fBook=new Facebook;
    this->setMenu();
    this->testSetup();
}

Interface::~Interface()
{
    delete fBook;
}

string getName()
{
    // Get name from user
    string personName;
    cout << "Enter name: ";
    getline(cin,personName);
    return personName;
}

void Interface::setMenu()
{
    this->options.push_back("Add new person.");
    this->options.push_back("Add new fan page.");
    this->options.push_back("Add status.");
    this->options.push_back("Show all user's statuses.");
    this->options.push_back("Link 2 persons.");
    this->options.push_back("Add person to fan page.");
    this->options.push_back("Show all users.");
    this->options.push_back("Show all user's friends.");
    //this->options.push_back("Show last 10 statuses of person's friends.");
    this->options.push_back("Exit");
}

void Interface::showMenu() const
{
    cout << "Select one of the following:" << endl;
    for (int i=0;i<this->options.size();i++){
        cout << "\t" << i+1 << ". " << this->options[i] << endl;
    }
}

int Interface::userSelect()
{
    // This function return the number of the action (from the main menu)
    // that the user selected.
    int choice;
    cout << "Your choice: ";
    try
    {
		string userChoiceLine = getUserInput();
		choice = convertLineToInt(userChoiceLine);
        if (choice >= 1 && choice<=this->options.size())
            return choice;
        else
            throw choice;
    }
    catch (int choice)
    {
        cout << "Invalid option entered.";
        cout << "Choose between 1 and " << this->options.size() << "." << endl;
        return this->userSelect();
    }
}

STATUSTYPE Interface::statusTypeSelect()
{
    // This function let the user select the type of the status (video/text/image).
    // Return value: status type (video/text/image).
    int statusType;
    cout << "Select status type:" << endl;
    cout <<"  1.Video\n  2.Text\n  3.Image\n  4.Text and image\n  5.Text and video" << endl;
    try
    {
		string userChoiceLine = getUserInput();
		statusType = convertLineToInt(userChoiceLine);
        checkStatusType(statusType-1);
    }
    catch(const char* msg)
    {
        cout << msg << endl;
        return this->statusTypeSelect();
    }
    return (STATUSTYPE)(statusType-1);
}

USERTYPE Interface::userTypeSelect()
{
    // This function let the user select the type of the user (person/fan page).
    // Return value: user type (person/fan page).
	int userType;
    cout << "Select user type: " << endl;
    cout <<"  1.Person\n  2.Fan page" << endl;
    try
    {
		string userChoiceLine = getUserInput();
		userType = convertLineToInt(userChoiceLine);
        checkUserType(userType-1);
    }
    catch(const char* msg)
    {
        cout << msg << endl;
        return this->userTypeSelect();
    }
    return (USERTYPE)(userType-1);
}

Date Interface::enterDate()
{
    // This function return date format that entered by the user.
    int day,month,year;
    cout << "Enter date (seperate by space. example 13 12 1990): ";
    cin >> day >> month >> year;
    cin.get();                  
    Date newDate(day,month,year);
    if (!newDate.isValidDate())
    {
        while (!newDate.isValidYear())
        {
            cout << "Invalid year (must be over 1000). Enter year: ";
            cin >> year;
            cin.get();
            newDate.setYear(year);
        }
        while (!newDate.isValidMonth())
        {
            cout << "Invalid month (must be between 1 and 12). Enter month: ";
            cin >> month;
            cin.get();
            newDate.setMonth(month);
        }
        while (!newDate.isValidDay())
        {
            cout << "Invalid day (must be between 1 and " << calculateDaysInMonth(month, year) << "). Enter day: ";
            cin >> day;
            cin.get();
            newDate.setDay(day);
        }
    }
    return newDate;
}

bool Interface::execute(int choice)
{
    // This function execute the action according to the user selection.
    bool toExit=false;
    switch(choice)
    {
        case 1: // Create new person
        {
            this->createPerson();
            break;
        }
        case 2: // Create new fan page
        {
            this->createFanPage();
            break;
        }
        case 3: // Add status to user
        {
            this->createStatus();
            break;
        }
        case 4: // Show all user's statuses
        {
            this->showAllUserStatuses();
            break;
        }
        case 5: // Link 2 friends
        {
            this->link2Friends();
            break;
        }
        case 6: // add person to fan page
        {
            this->addPersonToFanPage();
            break;
        }
        case 7: // Show all users
        {
            this->fBook->showAll();
            break;
        }
        case 8: // Show all user's friends
        {
            this->showUserFriends();
            break;
        }
        /*case 9:
            this->showPersonsFriendsStatuses();
            break;*/
        case 9:
        {
            toExit=true;
            break;
        }
    }
    return toExit;
}

void Interface::runInterface()
{
    // This function running the menu until the user select to exit.
    bool toExit=false;
    int choice;
    while (!toExit)
    {
        this->showMenu();
        choice=this->userSelect();
        cout << endl;
        toExit=this->execute(choice);
        cout << endl;
    }
}
// case 1
void Interface::createPerson()
{
    // This function creating new person.
    string name=getName();
    if (!this->fBook->isUserExist(name,PERSON))
    {
        Date newDate=enterDate();
        Person* newPerson=new Person(name,newDate);
        this->fBook->addPerson(*newPerson);
    }
    else
    {
        cout << "Person already exist. Choose a different name." << endl;
    }
}
// case 2
void Interface::createFanPage()
{
    // This function creating new fan page.
    string name=getName();
    if (!this->fBook->isUserExist(name,FANPAGE))
    {
        FanPage* newFPage=new FanPage(name);
        this->fBook->addFanPage(*newFPage);
    }
    else
    {
        cout << "Fan page already exist. Choose a different name." << endl;
    }
}
// case 3
void Interface::createStatus()
{
    // This function creating new status.
    USERTYPE userType=userTypeSelect();
    string name=getName();
    if (this->fBook->isUserExist(name,userType)) // Check if the user exist.
    {
        STATUSTYPE statusType=statusTypeSelect();
        string statusContent;
        switch (statusType)
        {
            case TEXT:
                cout << "Write status: ";
                break;
            case VIDEO:
                cout << "Enter video file name: ";
                break;
            case IMAGE:
                cout << "Enter image file name: ";
                break;
            case TEXT_AND_IMAGE:
                cout << "Enter text and image file name: ";
                break;
            case TEXT_AND_VIDEO:
				cout << "Enter text and video file name: ";
                break;
        }
        getline(cin,statusContent);
        this->fBook->addStatusToUser(name,statusContent, statusType,userType);
    }
    else
        cout << "User doesn't exists." << endl;
}
// case 4
void Interface::showAllUserStatuses()
{
    // This function show all given user statuses.
    USERTYPE userType=userTypeSelect();
    string userName=getName();
    User* user=this->fBook->findUser(userName,userType);
    if (user!=nullptr)
    {
        user->printLastStatuses(user->getNumOfStatuses());
    }
    else
        cout << "User doesn't exists." << endl;
}
// case 5
void Interface::link2Friends()
{
    // This function link 2 friends.
    string persName1=getName();
    string persName2=getName();
    Person* pers1=dynamic_cast<Person*>(this->fBook->findUser(persName1,PERSON));
    Person* pers2=dynamic_cast<Person*>(this->fBook->findUser(persName2,PERSON));
    if (pers1 && pers2)
    {
        try
        {
            this->fBook->linkFriends(*pers1, *pers2);
            cout << persName1 << " and " << persName2 << " successfully linked." << endl;
            
        }
        catch (const char* msg)
        {
            cout << msg << endl;
        }
        
    }
    else
    {
        if (!pers1)
            cout << persName1 << " wasn't found." << endl;
        if(!pers2)
            cout << persName2 << " wasn't found." << endl;
    }
}
// case 6
void Interface::addPersonToFanPage()
{
    // This function add person to a fan page (and vice versa).
    cout << "Person: ";
    string persName=getName();
    cout << "Fan page: ";
    string fPageName=getName();
    Person* person=dynamic_cast<Person*>(this->fBook->findUser(persName,PERSON));
    FanPage* fPage=dynamic_cast<FanPage*>(this->fBook->findUser(fPageName,FANPAGE));
    if (person && fPage)
    {
        try
        {
            this->fBook->addFanToFanPage(*person, *fPage);
            cout << persName << " successfully subscriped to " << fPageName << endl;
        }
        catch (const char* msg)
        {
            cout << msg << endl;
        }
    }
    else
    {
        if (!person)
            cout << persName << " wasn't found." << endl;
        if(!fPage)
            cout << fPageName << " wasn't found." << endl;
    }
}
// case 7
// Implemented in Facebook class
// case 8
void Interface::showUserFriends()
{
    // This function show all user's friends.
    USERTYPE userType=userTypeSelect();
    string userName=getName();
    User* user=this->fBook->findUser(userName,userType);
    if (user)
        user->showFriends(user->getNumOfFriends());
    else
        cout << userName << " wasn't found." << endl;
}

// case 9
void Interface::showPersonsFriendsStatuses()
{
    string userName=getName();
    if (this->fBook->isUserExist(userName, PERSON))
        this->fBook->showPersonsFriendsStatuses(userName);
}

void Interface::testSetup()
{
    // Test function to test the setup.
    Person* pers1=new Person("Alon H",Date(13,12,1990));
    Person* pers2=new Person("Jake Jones",Date(11,10,1989));
    Person* pers3=new Person("Luca luk",Date(9,8,1992));
    FanPage* fPage1=new FanPage("Maccabi");
    FanPage* fPage2=new FanPage("Hapoel");
    FanPage* fPage3=new FanPage("Beitar");
    fBook->addPerson(*pers1);
    fBook->addPerson(*pers2);
    fBook->addPerson(*pers3);
    fBook->addFanPage(*fPage1);
    fBook->addFanPage(*fPage2);
    fBook->addFanPage(*fPage3);
    fBook->addStatusToUser("Alon H","Hi im alon",TEXT,PERSON);
    fBook->addStatusToUser("Alon H","I was born in 1990",TEXT,PERSON);
    fBook->addStatusToUser("Luca luk","Hi im luca",TEXT,PERSON);
    fBook->addStatusToUser("Luca luk","I was born in 1992",TEXT,PERSON);
    fBook->addStatusToUser("Jake Jones","Hi im jake",TEXT,PERSON);
    fBook->addStatusToUser("Jake Jones","I was born in 1989",TEXT,PERSON);
    fBook->addStatusToUser("Maccabi","Maccabi 4ever",TEXT,FANPAGE);
    fBook->addStatusToUser("Maccabi","My city: Tel Aviv",TEXT,FANPAGE);
    fBook->addStatusToUser("Hapoel","Hapoel 4ever",TEXT,FANPAGE);
    fBook->addStatusToUser("Hapoel","My city: Haifa",TEXT,FANPAGE);
    fBook->addStatusToUser("Beitar","Beitar 4ever",TEXT,FANPAGE);
    fBook->addStatusToUser("Beitar","My city: Jerusalem",TEXT,FANPAGE);
    fBook->addFanToFanPage(*pers1, *fPage1);
    fBook->addFanToFanPage(*pers1, *fPage2);
    fBook->addFanToFanPage(*pers2, *fPage2);
    fBook->addFanToFanPage(*pers2, *fPage3);
    fBook->addFanToFanPage(*pers3, *fPage1);
    fBook->addFanToFanPage(*pers3, *fPage3);
    fBook->linkFriends(*pers1, *pers2);
    fBook->linkFriends(*pers2, *pers3);
}

int convertLineToInt(const string& line)
{
    string numChar;
	int i = 0;
	while (line[i] >= '0' && line[i] <= '9')
	{
		numChar.push_back(line[i]);
		i++;
	}
    numChar.push_back(0);
	int numToReturn = convertToNum(numChar);
	return numToReturn;
}

int convertToNum(const string& str)
{
	if (str.size() == 0)
		return NOT_NUMBER;
	int numToReturn = 0;
	int i = 0;
	while (str[i])
	{
		numToReturn *= 10;
		numToReturn += (int)(str[i] - '0');
		i++;
	}
	return numToReturn;
}

string getUserInput()
{
	string userInput;
	getline(cin,userInput);
	cin.clear();
	return userInput;
}

int findSpace(const string& str)
{
	int i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	return i;
}
