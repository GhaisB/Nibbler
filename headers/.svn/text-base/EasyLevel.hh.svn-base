#ifndef 			   __EASY_LEVEL_HH__
#define 			   __EASY_LEVEL_HH__

#include			   	<list>
#include          <iostream>
#include			   	<exception>
#include				  <vector>
#include				  "IItem.hh"
#include				  "Item.hh"
#include				  "IStrategy.hh"
#include				  "Item.hh"

class 				  EasyLevel : public IStrategy
{
private:
  int           _width;
  int           _height;
  bool          _food;
  int           _speedup;
  int           _star;
  int           _random;
  int           _speedBonus;
  int           _score;

public:
	EasyLevel(int width, int height);
	virtual ~EasyLevel();

	virtual void	createMapWalls(std::list<IItem *> &, Snake *);
	virtual int 	getSleepTime();
	virtual void 	popObjects(std::list<IItem *> &, Snake *);
	virtual void	destroyOutdatedObjects(std::list<IItem *> &);
  virtual void  setPopFood();
  virtual void  activeSpeedBonus();
  virtual void  activeStarBonus();
  virtual void  activeRandom(std::list<IItem *> &items, Snake *snake);
  virtual int   getScore() const;


private:
  void          popOneObject(itemType type, int &value, int cycle, int life, std::list<IItem *> &items, Snake *snake);
};


#endif
