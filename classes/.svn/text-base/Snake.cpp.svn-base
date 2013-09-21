#include		"Snake.hh"

#include		<iostream>

Snake::Snake(int &width, int &length)
{
  initSnake(width, length);
}

Snake::~Snake()
{

}

void	Snake::changeStatus(partType type, IParts *tmp)
{
  tmp->setType(type);
}

void	Snake::move(int key)
{
  int	x = 0;
  int	y = 0;
  IParts	*born;

   born = this->_snake.back();
  this->_snake.pop_back();
  changeStatus(queue, this->_snake.back());
  switch(key)
    {
    case 0:
      x = _snake.front()->getX();
      y = _snake.front()->getY() - 1;
      break;
    case 1:
      x = _snake.front()->getX();
      y = _snake.front()->getY() + 1;
      break;
    case 2:
      x = _snake.front()->getX() - 1;
      y = _snake.front()->getY();
      break;
    case 3:
      x = _snake.front()->getX() + 1;
      y = _snake.front()->getY();
      break;
    }
  born->setX(x);
  born->setY(y);
  changeStatus(body, this->_snake.front());
  changeStatus(head, born);
  _snake.push_front(born);
}

void	Snake::addQueue(IParts *tmp)
{
  int	x, y;
  partType type = body;

  x = tmp->getX();
  y = tmp->getY();
  tmp = new Parts(x, y, queue);
  this->_snake.back()->setType(type);
  _snake.push_back(tmp);
}

std::list<IParts*>	Snake::getParts() const
{
  return (this->_snake);
}

void	Snake::initSnake(int &width, int &length)
{
  IParts	*head1, *body1, *body2, *queue1;

  head1 = new Parts(5, 5, head);
  body1 = new Parts(6, 5, body);
  body2 = new Parts(7, 5, body);
  queue1 = new Parts(8, 5, queue);
  this->_snake.push_back(head1);
  this->_snake.push_back(body1);
  this->_snake.push_back(body2);
  this->_snake.push_back(queue1);
  width = length;
}

bool	Snake::find(int x, int y)
{
  for (std::list<IParts *>::iterator it = this->_snake.begin(); it != this->_snake.end(); it++)
    {
      if ((*it)->getX() == x && (*it)->getY() == y)
	return (true);
    }
  return (false);
}
