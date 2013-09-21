#include	"Parts.hh"

Parts::Parts(int x, int y, partType type) : _x(x), _y(y), _type(type)
{

}

Parts::~Parts()
{

}

int	Parts::getX() const
{
  return (this->_x);
}

int	Parts::getY() const
{
  return(this->_y);
}

partType	Parts::getType() const
{
  return (this->_type);
}

void	        Parts::setX(int &x)
{
  this->_x = x;
}

void		Parts::setY(int &y)
{
  this->_y = y;
}

void		Parts::setType(partType &type)
{
  this->_type = type;
}
