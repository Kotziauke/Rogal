#include "Exceptions.h"

char exceptionbadfile[] = "Cannot access the file \"%s\".\n";
char exceptionbadheader[] = "Unknown file type.\n";
char exceptionendoffile[] = "Unexpected end of file \"%s\".\n";
char exceptionunknowncharacter[] = "Unknown character \"%c\" while parsing file \"%s\".\n";
char exceptionnostartpoint[] = "Start point was not set in file \"%s\".\n";
char exceptionduplicatestartpoint[] = "Start point was already set.\n";
char exceptionstartpointinvoid[] = "Start point in file \"%s\" is outside a walkable area.\n";
char exceptionwrongcoordinates[] = "Given coordinates %dx%d are outside the map.\n";
char exceptionwrongdimensions[] = "Area of dimensions %dx%d cannot be created.\n";
char exceptionnocoins[] = "File \"%s\" does not include any coins.\n";
char exceptioninaccessiblecoin[] = "Cannot place a coin at position %dx%d.\n";
char exceptionduplicatecoin[] = "Coin at position %dx%d already exists on the map.\n";
char exceptioncoindoesnotexists[] = "Coin does not exists at position %dx%d.\n";
