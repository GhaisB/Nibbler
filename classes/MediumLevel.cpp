#include			"MediumLevel.hh"

MediumLevel::MediumLevel(int width, int height) : _width(width), _height(height), _food(true), _speedup(100), _star(120), _random(90), _speedBonus(0), _score(0) {

}

MediumLevel::~MediumLevel() {

}

void				MediumLevel::createMapWalls(std::list<IItem *> &items, Snake *snake)
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

int					MediumLevel::getSleepTime() {
	if (this->_speedBonus > 0) {
		this->_speedBonus--;
		return (66667 / 2);
	}
	return (66667);
}

void				MediumLevel::setPopFood() {
	this->_score += 10;
	this->_food = false;
}

void				MediumLevel::popOneObject(itemType type, int &value, int cycle, int life, std::list<IItem *> &items, Snake *snake) {
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

void  				MediumLevel::activeSpeedBonus() {
	this->_speedBonus = 40;
}

void  				MediumLevel::activeStarBonus() {
	this->_score += 50;
}

void  				MediumLevel::activeRandom(std::list<IItem *> &items, Snake *snake) {
	int				type = rand() % 3;
	int				i(0);
	int				tmp;

	if (type == 0) {
		while (i < 20) {
			tmp = 0;
			this->popOneObject(WALL, tmp, 0, -1, items, snake);
			i++;
		}
	} else if (type == 1) {
		while (i < 15) {
			tmp = 0;
			this->popOneObject(STAR, tmp, 0, 120 / 2, items, snake);
			i++;
		}
	} else if (type == 2) {
		this->_speedBonus = 40 * 4;
	}
}

int					MediumLevel::getScore() const {
	return (this->_score);
}

void				MediumLevel::popObjects(std::list<IItem *> &items, Snake *snake) {
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
	this->popOneObject(SPEEDUP, this->_speedup, 100, 60, items, snake);
	this->popOneObject(STAR, this->_star, 120, 30, items, snake);
	this->popOneObject(RANDOM, this->_random, 90, 50, items, snake);
}

void				MediumLevel::destroyOutdatedObjects(std::list<IItem *> &items) {
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
