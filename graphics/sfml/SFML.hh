#ifndef __SFML_HH__
#define __SFML_HH__

#include <iostream>
#include <string>
#include "IDisplay.hh"
#include <unistd.h>
#include	<SFML/Audio.hpp>
#include	<SFML/Graphics.hpp>
#include	<SFML/System.hpp>
#include	<queue>

#define		L 1920
#define		H 1080

class SFML : public IDisplay
{
  sf::RenderWindow	_app;
  int		_case_size;

  sf::Sprite	*_wall;
  sf::Sprite	*_star;
  sf::Sprite	*_speed;
  sf::Sprite	*_food;
  sf::Sprite	*_rand;
  sf::Sprite	*_snake;
  sf::Sprite	*_pic;

  sf::Music	*_background;
  sf::Sound	*_sound;
  virtual sf::Sprite		*createSprite(const std::string , int , int , int);
  virtual void				drawSprite(sf::Sprite *display, int x, int y);
  virtual void		initImage(int&, int&, int&, int& );
  virtual void		initMusic();
public:
  SFML();
  virtual ~SFML() {}

virtual bool		initDisplay(int, int);

  virtual void		closeDisplay();

  virtual bool		isRunning() {
  	return (true);
  }
  virtual void		getEvent(std::queue<Key> &event);
  virtual void		display(Snake *, std::list<IItem *>, int score);
  virtual void		wait(int);
  virtual void		playSound();
};

#endif
