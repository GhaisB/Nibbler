#ifndef 				__ALLEGRO_HH__
#define 				__ALLEGRO_HH__

#include 				<iostream>
#include 				<string>
#include				<queue>
#include        "NibblerException.hpp"
#include 				"IDisplay.hh"
#include        <allegro.h>
#include 				<allegro_image.h>

const int       SCREEN_W    = 1280.0;
const int       SCREEN_H    = 1024.0;

class 							        Allegro : public IDisplay
{
private:
  ALLEGRO_DISPLAY       		*_display;
  ALLEGRO_EVENT_QUEUE   		*_eventQueue;
  ALLEGRO_EVENT_QUEUE   		*_eventTimerQueue;
  ALLEGRO_TIMER         		*_timer;
  ALLEGRO_BITMAP        		*_bouncer;
  ALLEGRO_BITMAP				    *_wallBouncer;
  ALLEGRO_BITMAP				    *_foodBouncer;
  ALLEGRO_BITMAP				    *_randomBouncer;
  ALLEGRO_BITMAP            *_starBouncer;
  ALLEGRO_BITMAP				    *_speedUpBouncer;
  int 							        _bouncerSize;

public:
	Allegro();
	virtual ~Allegro();
	virtual bool				initDisplay(int, int);
	virtual void				closeDisplay();
	virtual bool				isRunning();
	virtual void				getEvent(std::queue<Key> &);
	virtual void				display(Snake *, std::list<IItem *>, int score);
	virtual void				wait(int);
  virtual void        playSound();
  ALLEGRO_BITMAP      *createSprite(const std::string &path, int r, int g, int b);
};

#endif
