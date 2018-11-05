#pragma once
#include <exception>
#include <stdio.h>
#include "Constants.h"

class Exception :
	public std::exception
{
protected:
	char err_msg[80];
public:
	inline const char* what() noexcept
	{
		return err_msg;
	}
};

class ExceptionBadFile :
	public Exception
{
public:
	ExceptionBadFile() noexcept
	{
		sprintf(err_msg, exceptionbadfile);
	}
};

class ExceptionBadLevelList :
	public Exception
{
public:
	ExceptionBadLevelList() noexcept
	{
		sprintf(err_msg, exceptionbadlevellist);
	}
};

class ExceptionEmptyLevelList :
	public Exception
{
public:
	ExceptionEmptyLevelList() noexcept
	{
		sprintf(err_msg, exceptionemptylevellist);
	}
};

class ExceptionBadHeader :
	public Exception
{
public:
	ExceptionBadHeader() noexcept
	{
		sprintf(err_msg, exceptionbadheader);
	}
};

class ExceptionUnknownIdentifier :
	public Exception
{
public:
	ExceptionUnknownIdentifier() noexcept
	{
		sprintf(err_msg, exceptionunknownidentifier);
	}
};

class ExceptionNoStartPoint :
	public Exception
{
public:
	ExceptionNoStartPoint() noexcept
	{
		sprintf(err_msg, exceptionnostartpoint);
	}
};

class ExceptionDuplicateStartPoint :
	public Exception
{
public:
	ExceptionDuplicateStartPoint() noexcept
	{
		sprintf(err_msg, exceptionduplicatestartpoint);
	}
};

class ExceptionStartPointInVoid :
	public Exception
{
public:
	ExceptionStartPointInVoid() noexcept
	{
		sprintf(err_msg, exceptionstartpointinvoid);
	}
};

class ExceptionWrongCoordinates :
	public Exception
{
public:
	ExceptionWrongCoordinates(int x, int y) noexcept
	{
		sprintf(err_msg, exceptionwrongcoordinates, x, y);
	}
};

class ExceptionWrongDimensions :
	public Exception
{
public:
	ExceptionWrongDimensions(int w, int h) noexcept
	{
		sprintf(err_msg, exceptionwrongdimensions, w, h);
	}
};

class ExceptionNoCoins :
	public Exception
{
public:
	ExceptionNoCoins() noexcept
	{
		sprintf(err_msg, exceptionnocoins);
	}
};

class ExceptionInaccessibleCoin :
	public Exception
{
public:
	ExceptionInaccessibleCoin(int x, int y) noexcept
	{
		sprintf(err_msg, exceptioninaccessiblecoin, x, y);
	}
};

class ExceptionDuplicateCoin :
	public Exception
{
public:
	ExceptionDuplicateCoin(int x, int y) noexcept
	{
		sprintf(err_msg, exceptionduplicatecoin, x, y);
	}
};

class ExceptionCoinDoesNotExists :
	public Exception
{
public:
	ExceptionCoinDoesNotExists(int x, int y) noexcept
	{
		sprintf(err_msg, exceptioncoindoesnotexists, x, y);
	}
};
