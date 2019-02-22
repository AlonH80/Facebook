
#ifndef _STATUS_H_
#define _STATUS_H_

#include "Time.h"
#include "DayTime.h"
#include<string.h>
#include<typeinfo>
#include<string>
using namespace std;

enum STATUSTYPE {VIDEO, TEXT, IMAGE, TEXT_AND_IMAGE, TEXT_AND_VIDEO};

class Status
{
private:
		Time dTime;
		STATUSTYPE contType; // (video, text, image)
        string writer;
		string content;


public:
			Status(STATUSTYPE type,const string& content,const string& writer);
			~Status();
			Status(const Status& status);
			void show();
			string getContent();
			int compareContent(const Status& other);
            string getWriter() const;
			Time getDatetime();
			STATUSTYPE getType();
			bool operator==(const Status& other) const;
			bool operator!=(const Status& other) const;
};


#endif /* STATUS_H_ */
