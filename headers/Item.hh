#ifndef		__ITEM_HH__
#define		__ITEM_HH__

#include	"IItem.hh"

class		Item : public IItem
{
  int		_x;
  int		_y;
  int		_life;
  itemType	_type;
public:
  Item(int, int, int, itemType);
  virtual ~Item();
  virtual void		subLife();
  virtual itemType	getType() const;
  virtual int		getLife() const;
  virtual int		getX() const;
  virtual int		getY() const;
};

#endif
