#ifndef		__IPARTS_HH__
#define		__IPARTS_HH__

#include	<list>

enum	       partType
  {
    head,
    body,
    queue,
    tmp
  };

class		IParts
{
public:
  virtual	 ~IParts(){};

  virtual int		getX()	const = 0;
  virtual int		getY()	const = 0;
  virtual partType	getType() const = 0;

  virtual void		setX(int &x) = 0;
  virtual void		setY(int &y) = 0;
  virtual void		setType(partType &type) = 0;
};

#endif
