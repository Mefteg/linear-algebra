#include "log.h"

Log::Log() {}
Log::~Log() {}

////////////
// STATIC //
////////////

void Log::l(std::string _tag, std::string _message)
{
	std::cout << _tag << ": " << _message << std::endl;
}