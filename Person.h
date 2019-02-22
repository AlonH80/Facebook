
#ifndef PERSON_H_
#define PERSON_H_

#include"Status.h"
#include"User.h"

class FanPage;

class Person : public User
{
			
		private:

			int numOfFanPages;

			Date birthDate;

			vector<FanPage*> likedFanPages;





		public:
			Person(const string& pName, const Date& bDay);
			~Person();
			Person(const Person& person);

			const vector<FanPage*>& getFanPages() const;
			Date getBirthDate() const;
			void show() const override;

			void showFanPages(int num) const;

			void addFanPage(FanPage& fanPageToAdd);

			int getNumOfFanPages() const;
			bool isSubToFP(const FanPage& fp);

			friend int compare(const Person& p1, const Person& p2);
			friend bool areEquals(const Person& p1, const Person& p2);
};

#endif /* PERSON_H_ */
