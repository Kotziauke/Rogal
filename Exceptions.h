#pragma once
#include <string>
#include <exception>

class Exception :
	public std::exception
{
protected:
	std::string err_msg;
public:
	const char* what();
};

class ExceptionBadFile :
	public Exception
{
public:
	ExceptionBadFile();
};

class ExceptionEndOfFile :
	public Exception
{
public:
	ExceptionEndOfFile();
};

class ExceptionUnknownCharacter :
	public Exception
{
public:
	ExceptionUnknownCharacter();
};

class ExceptionNoStartPoint :
	public Exception
{
public:
	ExceptionNoStartPoint();
};

class ExceptionDuplicateStartPoint :
	public Exception
{
public:
	ExceptionDuplicateStartPoint();
};

class ExceptionStartPointInVoid :
	public Exception
{
public:
	ExceptionStartPointInVoid();
};

class ExceptionWrongDimensions :
	public Exception
{
public:
	ExceptionWrongDimensions(unsigned int w, unsigned int h);
};

class ExceptionNoCoins :
	public Exception
{
public:
	ExceptionNoCoins();
};

class ExceptionInaccessibleCoin :
	public Exception
{
public:
	ExceptionInaccessibleCoin(unsigned int x, unsigned int y);
};

class ExceptionDuplicateCoin :
	public Exception
{
public:
	ExceptionDuplicateCoin(unsigned int x, unsigned int y);
};

