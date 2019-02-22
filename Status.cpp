
#include"Status.h"

Status::Status(STATUSTYPE type,const string& content,const string& writer) :  dTime(Time()), contType(type) , writer(writer), content(content)
{
	//this->content = new char[strlen(content)+ 1 ];
	//this->content = strcpy(this->content,content);
	//this->content[strlen(content)] = '\0';
	//this->writer = writer;

}

Status::Status(const Status& copy) : dTime(copy.dTime) , contType(copy.contType) ,writer(copy.writer), content(copy.content)
{
	//this->content = new char[strlen(copy.content)+ 1 ];
	//this->content = strcpy(this->content,copy.content);
	//this->content[strlen(copy.content)] = '\0';
	//this->writer = copy.writer;
}

void Status::show()
{

	const char* types[] = {"video","text","image", "text and image","text and video"};
	cout << "Status type: " << types[contType] << endl <<
			"content:" << content << endl << "Writer: " << writer << endl << endl;
}

Status::~Status()
{

}

int Status::compareContent(const Status& other)
{
	return(content.compare(other.content));
}


string Status::getContent()
{
	return content;
}

Time Status::getDatetime()
{
	return dTime;
}

STATUSTYPE Status::getType()
{
	return contType;
}

string Status::getWriter() const
{
    return this->writer;
}

bool Status::operator==(const Status& other) const
{
	return(content.compare(other.content) == 0);
}

bool Status::operator!=(const Status& other) const
{
	return !(*this==other);
}
