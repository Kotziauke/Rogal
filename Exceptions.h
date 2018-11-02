#pragma once
#include <string>
#include <exception>
#include <stdio.h>

extern char exceptionbadfile[];
extern char exceptionendoffile[];
extern char exceptionunknowncharacter[];
extern char exceptionnostartpoint[];
extern char exceptionduplicatestartpoint[];
extern char exceptionstartpointinvoid[];
extern char exceptionwrongdimensions[];
extern char exceptionnocoins[];
extern char exceptioninaccessiblecoin[];
extern char exceptionduplicatecoin[];

class Exception :
	public std::exception
{
protected:
	char err_msg[80];
public:
	inline const char* what()
	{
		return err_msg;
	}
};

class ExceptionBadFile :
	public Exception
{
public:
	ExceptionBadFile(const char* path)
	{
		sprintf(err_msg, exceptionbadfile, path);
	}
};

class ExceptionEndOfFile :
	public Exception
{
public:
	ExceptionEndOfFile(const char* path)
	{
		sprintf(err_msg, exceptionendoffile, path);
	}
};

class ExceptionUnknownCharacter :
	public Exception
{
public:
	ExceptionUnknownCharacter(const char* path, char ch)
	{
		sprintf(err_msg, exceptionunknowncharacter, ch, path);
	}
};

class ExceptionNoStartPoint :
	public Exception
{
public:
	ExceptionNoStartPoint(const char* path)
	{
		sprintf(err_msg, exceptionnostartpoint, path);
	}
};

class ExceptionDuplicateStartPoint :
	public Exception
{
public:
	ExceptionDuplicateStartPoint(const char* path)
	{
		sprintf(err_msg, exceptionduplicatestartpoint, path);
	}
};

class ExceptionStartPointInVoid :
	public Exception
{
public:
	ExceptionStartPointInVoid(const char* path)
	{
		sprintf(err_msg, exceptionstartpointinvoid, path);
	}
};

class ExceptionWrongDimensions :
	public Exception
{
public:
	ExceptionWrongDimensions(unsigned int w, unsigned int h)
	{
		sprintf(err_msg, exceptionwrongdimensions, w, h);
	}
};

class ExceptionNoCoins :
	public Exception
{
public:
	ExceptionNoCoins(const char* path)
	{
		sprintf(err_msg, exceptionnocoins, path);
	}
};

class ExceptionInaccessibleCoin :
	public Exception
{
public:
	ExceptionInaccessibleCoin(const char* path, unsigned int x, unsigned int y)
	{
		sprintf(err_msg, exceptioninaccessiblecoin, x, y, path);
	}
};

class ExceptionDuplicateCoin :
	public Exception
{
public:
	ExceptionDuplicateCoin(const char* path, unsigned int x, unsigned int y)
	{
		sprintf(err_msg, exceptionduplicatecoin, x, y, path);
	}
};
