#include	"Nibbler.hh"

Nibbler::Nibbler(int ac, char **av) : _ac(ac), _av(av)
{

}

Nibbler::~Nibbler()
{

}

void		Nibbler::init() {
	if (this->_ac != 4)
		throw new NibblerException("Usage: ./nibbler [width] [height] [display_library.so]");
	this->_width  = atoi(this->_av[1]);
	this->_height = atoi(this->_av[2]);
	this->_libraryPath = this->_av[3];

	if (this->_width < MIN_SIZE || this->_width > MAX_SIZE)
		throw new NibblerException("Width must be an integer between 30 and 100.");

	if (this->_height < MIN_SIZE || this->_height > MAX_SIZE)
		throw new NibblerException("Height must be an integer between 30 and 100.");
}

int			Nibbler::run()
{
	try	{
		this->init();
		this->game = new Game(this->_width, this->_height, this->_libraryPath);
		return (game->run());
	} catch (std::exception *e) {
		std::cerr << e->what() << std::endl;
		return (1);
	}
}
