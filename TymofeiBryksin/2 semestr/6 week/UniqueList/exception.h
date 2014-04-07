#pragma once
///class for exception
class Exception
{
public:
	Exception(char* msg);
	char* get() const;

private:
	char* const message;
};

