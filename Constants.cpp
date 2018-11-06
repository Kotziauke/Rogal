#include "Constants.h"

char tilewall = '#';
char tilefloor = '.';
char tilehallway = '+';
char tilecoin = 'o';
char tileplayer = '@';

char statusbar[] = "Map \"%s\":\n%d coin(s) left, %d collected so far.";

char menulogo[] = "    ____                    __\n   / __ \\____  ____ _____ _/ /\n  / /_/ / __ \\/ __ `/ __ `/ /\n / _, _/ /_/ / /_/ / /_/ / /\n/_/ |_|\\____/\\__, /\\__,_/_/\n            /____/    Ver. 1.0\n";
char menutext[] = "The objective of this game is\nto collect all coins from the\nmap.\n\nUse WASD keys to walk. You can\npress E to exit anytime.\n\nPress P to play or Q to quit.\n";
char menuwin[] = "Congratulations, you've\ncompleted the game!\n\nPress any key to continue.\n";

char messagebadlist[] = "Error while parsing list:\n%s\nPress any key to continue.\n";
char messagebadmap[] = "Error while parsing map \"%s\":\n%s\nPress any key to continue.\n";

char exceptionbadfile[] = "Cannot access the file \"%s\"!\n";
char exceptionbadmaplist[] = "Map list cannot be accessed!\n";
char exceptionemptymaplist[] = "Map list is empty!\n";
char exceptionbadheader[] = "Unknown file type!\n";
char exceptionunknownidentifier[] = "Unknown map element identifier!\n";
char exceptionnostartpoint[] = "Start point was not set!\n";
char exceptionduplicatestartpoint[] = "Start point was already set!\n";
char exceptionstartpointinvoid[] = "Start point is outside a walkable area!\n";
char exceptionwrongcoordinates[] = "Given coordinates %dx%d are outside the map!\n";
char exceptionwrongdimensions[] = "Area of dimensions %dx%d cannot be created!\n";
char exceptionnocoins[] = "Map does not have any coins!\n";
char exceptioninaccessiblecoin[] = "Cannot place a coin at position %dx%d!\n";
char exceptionduplicatecoin[] = "Coin at position %dx%d already exists on the map!\n";
char exceptioncoindoesnotexists[] = "Coin does not exists at position %dx%d!\n";
