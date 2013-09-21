#ifndef		__IITEM_HH__
#define		__IITEM_HH__

enum		itemType
  {
    WALL,
    FOOD,
    SPEEDUP,
    STAR,
    RANDOM
  };

class		IItem
{
public:
  virtual	 ~IItem(){};
  virtual	itemType getType() const = 0;
  virtual	int	getLife() const = 0;
  virtual	void	subLife() = 0;
  virtual	int	getX() const = 0;
  virtual	int	getY() const = 0;
};

#endif
