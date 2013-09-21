//
// ncurses.cpp for yolo in /home/maitre_c/nibbler/graphics/ncurses
//
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
//
// Started on  Tue Mar 19 11:44:55 2013 antoine maitre
//

#include <sstream>
#include "NCurses.hh"
 
NCurses::NCurses()
  : run(true)
{
  color.insert(std::pair<int,int>(FOOD, COLOR_PAIR(2)));
  color.insert(std::pair<int,int>(SPEEDUP, COLOR_PAIR(3)));
  color.insert(std::pair<int,int>(RANDOM, COLOR_PAIR(5)));
  color.insert(std::pair<int,int>(STAR, COLOR_PAIR(4)));
  color.insert(std::pair<int,int>(WALL, COLOR_PAIR(7)));
}

NCurses::~NCurses()
{

}

void    NCurses::playSound() {
  
}

bool		NCurses::initDisplay(int width, int height)
{
  (void) width;
  (void) height;
  initscr();
  raw();
  noecho();
  curs_set(false);
  start_color();
  keypad(stdscr, TRUE);
  refresh();
  init_pair(1, COLOR_RED, COLOR_RED);
  init_pair(2, COLOR_GREEN, COLOR_GREEN);
  init_pair(3, COLOR_YELLOW, COLOR_YELLOW);
  init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);
  init_pair(7, COLOR_WHITE, COLOR_WHITE);
  win = newwin(0,0,0,0);
  box(win, 0,0);
  wrefresh(win);
  timeout(0);
  wclear(win);
  return (true);
}

void		NCurses::closeDisplay()
{
    endwin();
}

bool		NCurses::isRunning()
{
  return (this->run);
}

void		NCurses::getEvent(std::queue<Key> &keyList)
{
  int		ch;

  while ((ch = getch()))
    {
      if (ch == KEY_LEFT)
	keyList.push(LEFT);
      else if (ch == KEY_RIGHT)
	keyList.push(RIGHT);
      else if (ch == KEY_UP)
	keyList.push(UP);
      else if (ch == KEY_DOWN)
	keyList.push(DOWN);
      else if (ch == 27)
	this->run = false;
      else
	break;
    }
}

void			NCurses::display(Snake *snake, std::list<IItem *> obj, int score)
{
  std::list<IParts *>	tmp;
  std::ostringstream	oss;
  std::string		result;

  result = "score: ";
  oss << score;
  result = result + oss.str();
  mvwprintw(this->win, 0, 2, result.c_str());
  tmp = snake->getParts();
  for (std::list<IItem *>::iterator it = obj.begin(); it != obj.end(); ++it)
    {
      wattron(win, this->color[(*it)->getType()]);
      mvwprintw(this->win, (*it)->getY() + 1, (*it)->getX(), " ");
      wattroff(win, this->color[(*it)->getType()]);
    }
  for (std::list<IParts *>::iterator it = tmp.begin(); it != tmp.end(); it++)
    {
      wattron(win, COLOR_PAIR(1));
      mvwprintw(this->win, (*it)->getY() + 1, (*it)->getX(), " ");
      wattroff(win, COLOR_PAIR(1));
    }
  wrefresh(win);
  wclear(win);
}

void		NCurses::wait(int time)
{
  usleep(time);
}

extern "C"
{
  IDisplay *make_display()
  {
    return (new NCurses);
  }
}
