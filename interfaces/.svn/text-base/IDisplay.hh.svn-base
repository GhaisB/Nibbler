#ifndef 				__IDISPLAY_HH__
#define 				__IDISPLAY_HH__

#include 				"Snake.hh"
#include 				"IItem.hh"
#include				<queue>
#include				<stdlib.h>

enum 					Key {
	UP,
	DOWN,
	LEFT,
	RIGHT,
	ESCAPE,
	NOTHING
};

class 						IDisplay
{

public:
  virtual					    ~IDisplay() {}

  virtual bool				initDisplay(int, int)  					              = 0;
  virtual void				closeDisplay()  						                  = 0;

  virtual bool				isRunning() 							                    = 0;
  virtual void			 	getEvent(std::queue<Key> &)			              = 0;
  virtual void				display(Snake *, std::list<IItem *>, int)     = 0;
  virtual void				wait(int time)							                  = 0;
  virtual void        playSound()                                   = 0;


};

#endif
