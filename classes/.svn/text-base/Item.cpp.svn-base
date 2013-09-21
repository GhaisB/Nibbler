#include	"Item.hh"

Item::Item(int x, int y, int life, itemType type)
  : _x(x), _y(y), _life(life), _type(type)
{

}

Item::~Item()
{

}

void	Item::subLife()
{
  if (this->_life > 0)
    this->_life--;
}

itemType	Item::getType() const
{
  return (this->_type);
}

int		Item::getLife() const
{
  return (this->_life);
}

int		Item::getX() const
{
  return (this->_x);
}

int		Item::getY() const
{
  return (this->_y);
}
