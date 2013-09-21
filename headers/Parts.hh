#ifndef		__PARTS_HH__
#define		__PARTS_HH__

#include	"IParts.hh"

class		Parts : public IParts
{
  int		_x;
  int		_y;
  partType	_type;
public:
  Parts(int , int , partType);
  virtual ~Parts();

  virtual int		getX()	const;
  virtual int		getY()	const;
  virtual partType	getType() const;

  virtual void		setX(int &x);
  virtual void		setY(int &y);
  virtual void		setType(partType &type);
};

#endif
