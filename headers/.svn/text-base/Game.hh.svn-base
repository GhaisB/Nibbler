#ifndef					        __GAME_HH__
#define					        __GAME_HH__

#include 				        <string>
#include                <iostream>
#include				        <exception>
#include                <queue>
#include 				        <dlfcn.h>
#include				        "IDisplay.hh"
#include				        "IItem.hh"
#include                "IStrategy.hh"
#include                "NibblerException.hpp"
#include                "Snake.hh"
#include					      "Item.hh"
#include                "EasyLevel.hh"
#include                "MediumLevel.hh"
#include                "HardLevel.hh"

class                  IDisplay;
typedef 				       IDisplay*(*t_maker_display)();

class					         Game
{
private:
  int					         _width;
  int					         _height;
  std::string          _libraryPath;
  bool                 _isRunning;
  int                  _hasEat;
  bool                 _food;
  void                 *_hndl;
  Snake                *_snake;
  std::list<IItem *>   _item;
  Key                  _direction;
  std::queue<Key>      _keysQueue;
  IStrategy            *_strategy;


public:
  Game(int, int, std::string);
  ~Game();

  int					         run();
  int					         checkCollision(IDisplay *library);

private:
  IDisplay				     *getDisplayInstance();
  void                 handleKey();
  int                  handleCollision(IItem *, IDisplay *library);
  void		             createMap();
  void                 checkStrategy();
};

#endif
