all:
	g++ *.cpp -I. -lncurses -std=c++17 -Wimplicit-fallthrough=0 -Wall -Wextra -pedantic -o Rogal

