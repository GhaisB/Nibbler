//
// ncurses.hh for azertyu in /home/maitre_c/nibbler/graphics/ncurses
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Mar 19 11:43:19 2013 antoine maitre
// Last update Fri Mar 22 11:07:23 2013 antoine maitre
//

#ifndef __NCURSES_HH__
#define __NCURSES_HH__

#include <iostream>
#include <string>
#include <unistd.h>
#include <ncurses.h>
#include <curses.h>
#include <map>
#include <queue>
#include "IDisplay.hh"

class NCurses : public IDisplay
{
  WINDOW *win;
  bool run;
  std::map<int, int> color;
public:
  NCurses();
  virtual ~NCurses();

  virtual bool		initDisplay(int, int);
  virtual void		closeDisplay();
  virtual bool		isRunning();
  virtual void		getEvent(std::queue<Key>&);
  virtual void		display(Snake *, std::list<IItem *>, int score);
  virtual void		wait(int);
  virtual void    playSound();
};

#endif
