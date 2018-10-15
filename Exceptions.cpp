#include "Exceptions.h"

const char* Exception::what()
{
	return err_msg.c_str();
}

ExceptionBadFile::ExceptionBadFile()
{
	err_msg = "Cannot access the file.\n";
}

ExceptionEndOfFile::ExceptionEndOfFile()
{
	err_msg = "Unexpected end of file.\n";
}

ExceptionUnknownCharacter::ExceptionUnknownCharacter()
{
	err_msg = "Unknown character.\n";
}

ExceptionNoStartPoint::ExceptionNoStartPoint()
{
	err_msg = "Start point was not set.\n";
}

ExceptionStartPointInVoid::ExceptionStartPointInVoid()
{
	err_msg = "Start point is outside a walkable area.\n";
}

ExceptionWrongDimensions::ExceptionWrongDimensions(unsigned int w, unsigned int h)
{
	err_msg = "Area of dimensions ";
	err_msg += std::to_string((int)w);
	err_msg += "x";
	err_msg += std::to_string((int)h);
	err_msg += " cannot be created.\n";
}

ExceptionNoCoins::ExceptionNoCoins()
{
	err_msg = "Map does not include any coins.\n";
}

ExceptionInaccessibleCoin::ExceptionInaccessibleCoin(unsigned int x, unsigned int y)
{
	err_msg = "Cannot place a coin at position ";
	err_msg += std::to_string((int)x);
	err_msg += "x";
	err_msg += std::to_string((int)y);
	err_msg += ".\n";
}

ExceptionDuplicateCoin::ExceptionDuplicateCoin(unsigned int x, unsigned int y)
{
	err_msg = "Coin at position ";
	err_msg += std::to_string((int)x);
	err_msg += "x";
	err_msg += std::to_string((int)y);
	err_msg += " already exists on the map.\n";
}

