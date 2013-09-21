#ifndef					__NIBBLER_HH__
#define					__NIBBLER_HH__

#include 				<exception>
#include				<cstdlib>
#include				<iostream>
#include				"NibblerException.hpp"
#include				"Game.hh"

/* When modified, change the error message in Nibbler.cpp */
#define					MIN_SIZE	30
#define					MAX_SIZE	100

class					Nibbler
{
private:
	int 				_ac;
	char				**_av;
	int 				_width;
	int 				_height;
	std::string 		_libraryPath;
	Game				*game;


public:
  	Nibbler(int ac, char **av);
  	~Nibbler();

  	int					run();

private:
	void				init();
};

#endif
