#ifndef		__ISNAKE_HH__
#define		__ISNAKE_HH__

#include	<list>
#include	"Parts.hh"

class		ISnake
{
public:
  virtual ~ISnake(){};
  virtual void move(int) = 0;
  virtual void	initSnake(int &, int &) = 0;
  virtual void	changeStatus(partType , IParts *) = 0;
  virtual void	addQueue(IParts *) = 0;
  virtual bool	find(int, int) = 0;
  virtual std::list<IParts*> getParts() const = 0;
};

#endif
