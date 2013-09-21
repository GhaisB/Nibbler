#ifndef		__SNAKE_HH__
#define		__SNAKE_HH__

#include	"ISnake.hh"

class		Snake : public ISnake
{
  std::list<IParts *>	_snake;
public:
  Snake(int &, int &);
  virtual ~Snake();
  virtual void move(int);
  virtual void	initSnake(int &, int &);
  virtual void	changeStatus(partType , IParts *);
  virtual void	addQueue(IParts *);
  virtual bool	find(int, int);
  virtual std::list<IParts*> getParts() const;
};

#endif
