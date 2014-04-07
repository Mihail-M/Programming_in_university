#include "exception.h"

Exception::Exception(char *msg) : message(msg)
{
}

char* Exception::get() const
{
	return message;
}
