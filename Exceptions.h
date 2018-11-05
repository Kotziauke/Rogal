#pragma once
#include <string>
#include <exception>
#include <stdio.h>
#include "Constants.h"

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
	ExceptionBadFile()
	{
		sprintf(err_msg, exceptionbadfile);
	}
};

class ExceptionBadLevelList :
	public Exception
{
public:
	ExceptionBadLevelList()
	{
		sprintf(err_msg, exceptionbadlevellist);
	}
};

class ExceptionEmptyLevelList :
	public Exception
{
public:
	ExceptionEmptyLevelList()
	{
		sprintf(err_msg, exceptionemptylevellist);
	}
};

class ExceptionBadHeader :
	public Exception
{
public:
	ExceptionBadHeader()
	{
		sprintf(err_msg, exceptionbadheader);
	}
};

class ExceptionUnknownCharacter :
	public Exception
{
public:
	ExceptionUnknownCharacter()
	{
		sprintf(err_msg, exceptionunknowncharacter);
	}
};

class ExceptionNoStartPoint :
	public Exception
{
public:
	ExceptionNoStartPoint()
	{
		sprintf(err_msg, exceptionnostartpoint);
	}
};

class ExceptionDuplicateStartPoint :
	public Exception
{
public:
	ExceptionDuplicateStartPoint()
	{
		sprintf(err_msg, exceptionduplicatestartpoint);
	}
};

class ExceptionStartPointInVoid :
	public Exception
{
public:
	ExceptionStartPointInVoid()
	{
		sprintf(err_msg, exceptionstartpointinvoid);
	}
};

class ExceptionWrongCoordinates :
	public Exception
{
public:
	ExceptionWrongCoordinates(int x, int y)
	{
		sprintf(err_msg, exceptionwrongcoordinates, x, y);
	}
};

class ExceptionWrongDimensions :
	public Exception
{
public:
	ExceptionWrongDimensions(int w, int h)
	{
		sprintf(err_msg, exceptionwrongdimensions, w, h);
	}
};

class ExceptionNoCoins :
	public Exception
{
public:
	ExceptionNoCoins()
	{
		sprintf(err_msg, exceptionnocoins);
	}
};

class ExceptionInaccessibleCoin :
	public Exception
{
public:
	ExceptionInaccessibleCoin(int x, int y)
	{
		sprintf(err_msg, exceptioninaccessiblecoin, x, y);
	}
};

class ExceptionDuplicateCoin :
	public Exception
{
public:
	ExceptionDuplicateCoin(int x, int y)
	{
		sprintf(err_msg, exceptionduplicatecoin, x, y);
	}
};

class ExceptionCoinDoesNotExists :
	public Exception
{
public:
	ExceptionCoinDoesNotExists(int x, int y)
	{
		sprintf(err_msg, exceptioncoindoesnotexists, x, y);
	}
};
