#include "SFML.hh"

SFML::SFML() : _app(sf::VideoMode(L, H, 64), "nibbler")
{

}

sf::Sprite		*SFML::createSprite(const std::string path, int r, int g, int b)
{
    sf::Sprite		*born = new sf::Sprite();
    sf::Image		*pic;

    pic = new sf::Image();
    if (pic->LoadFromFile(path))
      {
	born->SetImage(*pic);
	born->Resize(this->_case_size, this->_case_size);
      }
    else
      {
	born->SetColor(sf::Color(0, r, g, b));
	born->Resize(this->_case_size, this->_case_size);
      }
    return (born);
  }


void	SFML::initImage(int &width, int &WidthSize, int &height, int &HeightSize)
{
  int	a;

  a = rand() % 3;

  if (a == 0)
    this->_pic = createSprite("ressources/fille1.png", 0, 0, 0);
  else if (a == 1)
    this->_pic = createSprite("ressources/fille.png", 0, 0, 0);
  else if (a == 2)
    this->_pic = createSprite("ressources/fille2.png", 0, 0, 0);
  this->_pic->Resize(width * WidthSize,  height * HeightSize);
}

void	SFML::initMusic()
{
  int	a;
  std::string	path;
  a = rand() % 2;
  this->_background= new sf::Music();
  if (a == 0)
    path = "ressources/background.ogg";
  else if (a == 1)
    path = "ressources/background1.ogg";
  if (!this->_background->OpenFromFile(path))
    delete(this->_background);
  else
    {
      this->_background->Play();
      this->_background->SetVolume(20.0);
    }
}

bool	SFML::initDisplay(int width, int length)
{
  int		a;

  a = rand() % 2;
  initMusic();
  this->_sound = new sf::Sound();
  int WidthSize  = (int) (L / width);
  int HeightSize = (int) (H / length);
  this->_case_size = ( HeightSize < WidthSize ) ? HeightSize : WidthSize;
  initImage(width, WidthSize, length, HeightSize);
  this->_wall = createSprite("ressources/wall.png", 145, 145, 145);
  this->_star = createSprite("ressources/star.png", 255, 255, 115);
  this->_food = createSprite("ressources/apple.png", 58, 199, 69);
  this->_speed = createSprite("ressources/speedup.png", 89, 239, 247);
  this->_rand = createSprite("ressources/random.png", 145, 0, 161);
  if (a == 0)
    this->_snake = createSprite("ressources/david.jpg",  123, 123, 255);
  else if (a == 1)
    this->_snake = createSprite("ressources/snake.png", 123, 123, 255);
  return (true);
}

void	SFML::getEvent(std::queue<Key> &event)
{
  sf::Event		_event;

  event.push(NOTHING);
  while (this->_app.GetEvent(_event))
    {
      if (_event.Type == sf::Event::KeyPressed)
	{
	  if (_event.Type == sf::Event::Closed || _event.Key.Code == sf::Key::Escape)
	    event.push(ESCAPE);
	  else if (_event.Key.Code == sf::Key::Up && event.back() != UP)
	    event.push(UP);
	  else if  (_event.Key.Code == sf::Key::Down && event.back() != DOWN)
	    event.push(DOWN);
	  else if (_event.Key.Code == sf::Key::Left && event.back() != LEFT)
	    event.push(LEFT);
	  else if (_event.Key.Code == sf::Key::Right && event.back() != RIGHT)
	    event.push(RIGHT);
	}
    }
  event.pop();
}

void		SFML::drawSprite(sf::Sprite *display, int x, int y)
{
  display->SetPosition(x, y);
  this->_app.Draw(*display);
}

void		SFML::display(Snake *corps, std::list<IItem *> object, int score)
  {
    std::list<IParts *>	tmp;
    std::list<IItem  *> tmp1;

    (void) score;
    tmp1 = object;
    tmp = corps->getParts();

    this->_app.Clear();
    drawSprite(this->_pic, 0, 0);
    for (std::list<IParts *>::const_iterator it = tmp.begin(); it != tmp.end(); ++it)
      drawSprite(this->_snake, (*it)->getX() * this->_case_size, (*it)->getY() * this->_case_size);
    for (std::list<IItem *>::const_iterator it = tmp1.begin(); it != tmp1.end(); ++it)
      {
	if ((*it)->getType() == WALL)
	  drawSprite(this->_wall, (*it)->getX() * this->_case_size, (*it)->getY() * this->_case_size);
	else if ((*it)->getType() == FOOD)
	  drawSprite(this->_food, (*it)->getX() * this->_case_size, (*it)->getY() * this->_case_size);
	else if ((*it)->getType() == RANDOM)
	  drawSprite(this->_rand, (*it)->getX() * this->_case_size, (*it)->getY() * this->_case_size);
	else if ((*it)->getType() == SPEEDUP)
	  drawSprite(this->_speed, (*it)->getX() * this->_case_size, (*it)->getY() * this->_case_size);
	else if ((*it)->getType() == STAR)
	  drawSprite(this->_star, (*it)->getX() * this->_case_size, (*it)->getY() * this->_case_size);
      }
    this->_app.Display();
  }

void		SFML::playSound()
{
  this->_background->SetVolume(10.0);
  int		a;
  std::string	path;
  sf::SoundBuffer	*_coll;
  _coll = new sf::SoundBuffer();
  a = rand() % 4;

  if (a == 0)
    path = "ressources/bankai.ogg";
  else if (a == 1)
    path = "ressources/pute.ogg";
  else if (a == 2)
    path = "ressources/gateau.ogg";
  else if (a == 3)
    path = "ressources/ghais.ogg";
  if (!_coll->LoadFromFile(path))
    delete(_coll);
  else
    {
      this->_sound->Stop();
      this->_sound->SetBuffer(*_coll);
      this->_sound->Play();
      this->_sound->SetVolume(100.0);
    }
  this->_background->SetVolume(20.0);
}

void	SFML::wait(int time)
{
  usleep(time);
}

void	SFML::closeDisplay()
{
  this->_background->Stop();
  delete( this->_background);
  delete(this->_sound);
}

  extern "C"
  {
    IDisplay *make_display()
    {
      return (new SFML);
    }
  }

