#ifndef LOG_H
#define LOG_H

#include <iostream>

class Log
{
public:
	Log();
	~Log();

	static void l(std::string _tag, std::string _message);

	/* data */
};

#endif // LOG_H