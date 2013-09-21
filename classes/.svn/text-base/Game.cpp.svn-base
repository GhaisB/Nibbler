#include			"Game.hh"

Game::Game(int width, int height, std::string libraryPath) : _width(width), _height(height), _libraryPath(libraryPath), _isRunning(true), _hasEat(0)
{
  this->_hndl = dlopen(this->_libraryPath.c_str(), RTLD_LAZY);
  if (!this->_hndl)
    throw new NibblerException("An error occured while loading shared library : " + this->_libraryPath + " (" + dlerror() + ")");

  // On instancie le serpent de base (4 cases)
  this->_snake = new Snake(this->_width, this->_height);

  // On initialise la direction a bas
  this->_direction = DOWN;

  // On charge la stratégie initiale (Easy)
  this->_strategy = new EasyLevel(this->_width, this->_height);

  // On crée la map (Murs)
  this->createMap();
}

Game::~Game()
{
	dlclose(this->_hndl);
}

void				Game::createMap()
{
  for (int i = 0; i < this->_width; i++)
    this->_item.push_back(new Item(i, 0, -1, WALL));
  for (int i = 0; i < this->_width; i++)
    this->_item.push_back(new Item(i, this->_height - 1, -1, WALL));
  for (int i = 0; i < this->_height; i++)
    this->_item.push_back(new Item(0, i, -1, WALL));
  for (int i = 0; i < this->_height; i++)
    this->_item.push_back(new Item(this->_width, i, -1, WALL));
}

IDisplay			*Game::getDisplayInstance()
{
	IDisplay 		*library = NULL;
	void 			*mkr = dlsym(this->_hndl, "make_display");
	t_maker_display	displayMaker;

	if (!mkr)
		throw new NibblerException("An error occured while loading shared library : " + this->_libraryPath + " (" + dlerror() + ")");
	displayMaker = (t_maker_display) mkr;
	library = displayMaker();
	if (!library)
		throw new NibblerException("An error occured while loading shared library : " + this->_libraryPath + " (" + dlerror() + ")");
	return (library);
}

void				Game::handleKey()
{
  Key 			key;

  if (!this->_keysQueue.empty()) {
    while (!this->_keysQueue.empty()) {
      key = this->_keysQueue.front();
      if (key == ESCAPE)
	this->_isRunning = false;
      if (!((this->_direction == UP && key == DOWN) || (this->_direction == DOWN && key == UP) ||
	    (this->_direction == LEFT && key == RIGHT) || (this->_direction == RIGHT && key == LEFT)))
		this->_direction = key;
      if (this->_direction == UP || this->_direction == LEFT || this->_direction == DOWN || this->_direction == RIGHT)
	  this->_snake->move(this->_direction);
      this->_keysQueue.pop();
    }
  }
  else if (this->_direction == UP || this->_direction == LEFT || this->_direction == DOWN || this->_direction == RIGHT) {
    this->_snake->move(this->_direction);
  }
}

void				Game::checkStrategy() {
	if (this->_hasEat == 10) {
		this->_hasEat++;
		delete this->_strategy;
		this->_strategy = new MediumLevel(this->_width, this->_height);
	}
	if (this->_hasEat == 30) {
		this->_hasEat++;
		delete this->_strategy;
		this->_strategy = new HardLevel(this->_width, this->_height);
	}
}

int					Game::run()
{
	IDisplay		*library = this->getDisplayInstance();

	if (!library->initDisplay(this->_width, this->_height)) {
		throw new NibblerException("Cannot init shared library display.");
		return (1);
	}
	this->_strategy->createMapWalls(this->_item, this->_snake);
	while (library->isRunning() && this->_isRunning)
	{
	  this->checkStrategy();
	  library->display(this->_snake, this->_item, this->_strategy->getScore());
	  library->getEvent(this->_keysQueue);
	  this->handleKey();
	  library->wait(this->_strategy->getSleepTime());
	  if (this->checkCollision(library) == -1)
	    this->_isRunning = false;
	  this->_strategy->popObjects(this->_item, this->_snake);
	  this->_strategy->destroyOutdatedObjects(this->_item);
	}
	library->closeDisplay();
	return (0);
}

int					Game::checkCollision(IDisplay *library)
{
	int	x, y, b;
	std::list<IParts*>	tmp = this->_snake->getParts();

	x = tmp.front()->getX();
	y = tmp.front()->getY();
	b = 0;
	for (std::list<IParts*>::const_iterator it = tmp.begin(); it != tmp.end(); ++it)
	{
		if (b == 0)
		{
			advance(it, 1);
			b = 1;
		}
		if (x == (*it)->getX() && y == (*it)->getY())
			return (-1);
	}
	for (std::list<IItem*>::const_iterator it = this->_item.begin(); it != this->_item.end(); ++it)
	{
		if (x == (*it)->getX() && y == (*it)->getY())
			return (this->handleCollision(*it, library));
	}
	return (0);
}

int 		Game::handleCollision(IItem *cube, IDisplay *library)
{
	library->playSound();
	if (cube->getType() == WALL)
		return (-1);
	else if (cube->getType() == FOOD) {
		this->_strategy->setPopFood();
		this->_hasEat++;
		this->_snake->addQueue(this->_snake->getParts().back());
	} else if (cube->getType() == SPEEDUP)
		this->_strategy->activeSpeedBonus();
	else if (cube->getType() == STAR)
		this->_strategy->activeStarBonus();
	else if (cube->getType() == RANDOM)
		this->_strategy->activeRandom(this->_item, this->_snake);
	this->_item.remove(cube);
	std::cout << "Votre score : " << this->_strategy->getScore() << "pts !" << std::endl;
	return (0);
}
