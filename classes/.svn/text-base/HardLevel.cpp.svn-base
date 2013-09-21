#include			"HardLevel.hh"

HardLevel::HardLevel(int width, int height) : _width(width), _height(height), _food(true), _speedup(160), _star(200), _random(100), _speedBonus(0), _score(0) {

}

HardLevel::~HardLevel() {

}

void				HardLevel::createMapWalls(std::list<IItem *> &items, Snake *snake)
{
	int				x, y;
	int				i(0);

	while (i < 30) {
		while (snake->find(x = (rand() % (this->_width - 2) + 1), y = (rand() % (this->_height - 2) + 1))); 
		{
			IItem *tmp = new Item(x, y, -1, WALL);
			items.push_back(tmp);
		}
		i++;
	}
}

int					HardLevel::getSleepTime() {
	if (this->_speedBonus > 0) {
		this->_speedBonus--;
		return (45000 / 2);
	}
	return (45000);
}

void				HardLevel::setPopFood() {
	this->_score += 10;
	this->_food = false;
}

void				HardLevel::popOneObject(itemType type, int &value, int cycle, int life, std::list<IItem *> &items, Snake *snake) {
	int				x, y;

	if (value == 0)
	{
		while (snake->find(x = (rand() % (this->_width - 2) + 1), y = (rand() % (this->_height - 2) + 1)));
		items.push_back(new Item(x, y, life, type));
		value = cycle;
	}
	else
		value--;
}

void  				HardLevel::activeSpeedBonus() {
	this->_speedBonus = 50;
}

void  				HardLevel::activeStarBonus() {
	this->_score += 50;
}

void  				HardLevel::activeRandom(std::list<IItem *> &items, Snake *snake) {
	int				type = rand() % 3;
	int				i(0);
	int				tmp;

	if (type == 0) {
		while (i < 15) {
			tmp = 0;
			this->popOneObject(WALL, tmp, 0, -1, items, snake);
			i++;
		}
	} else if (type == 1) {
		while (i < 10) {
			tmp = 0;
			this->popOneObject(STAR, tmp, 0, 200 / 3, items, snake);
			i++;
		}
	} else if (type == 2) {
		this->_speedBonus = 50 * 4;
	}
}

int					HardLevel::getScore() const {
	return (this->_score);
}

void				HardLevel::popObjects(std::list<IItem *> &items, Snake *snake) {
	int		x;
	int		y;
	IItem		*tmp;

	if (this->_food == false)
	{
		while (snake->find(x = (rand() % (this->_width - 2) + 1), y = (rand() % (this->_height - 2) + 1)));
		{
			tmp = new Item(x, y, -1, FOOD);
			items.push_back(tmp);
		}
		this->_food = true;
	}
	this->popOneObject(SPEEDUP, this->_speedup, 160, 15, items, snake);
	this->popOneObject(STAR, this->_star, 200, 25, items, snake);
	this->popOneObject(RANDOM, this->_random, 100, 40, items, snake);
}

void				HardLevel::destroyOutdatedObjects(std::list<IItem *> &items) {
	for (std::list<IItem *>::iterator it = items.begin(); it != items.end(); ++it)
	{
		if ((*it)->getLife() == 0)
		{
			items.erase(it);
			destroyOutdatedObjects(items);
			break;
		}
		else
			(*it)->subLife();
	}
}
