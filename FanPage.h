
#ifndef FANPAGE_H_
#define FANPAGE_H_

#include"Status.h"
#include"User.h"
class Person;

class FanPage : public User
{

	public:
		FanPage(const string& fpName);
		~FanPage();
		FanPage(const FanPage& copy);


		void show() const override;

		friend int compare(const FanPage& p1, const FanPage& p2);
		friend bool areEquals(const FanPage& p1, const FanPage& p2);
};
			
#endif /* FANPAGE_H_ */
