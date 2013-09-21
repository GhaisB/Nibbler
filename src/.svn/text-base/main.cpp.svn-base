#include		"main.hh"

static bool 	checkEnv() {
	char		*display;

	if (!getenv("DISPLAY"))
		return (false);
	display = getenv("DISPLAY");
	if (strcmp(display, ":0.0") == 0 || strcmp(display, ":0") == 0)
		return (true);
	else
		return (false);
	return (false);
}

int				main(int ac, char **av)
{
	try {
		if (!checkEnv()) {
			std::cerr << "Cannot find DISPLAY." << std::endl;
			return (1);
		}
		Nibbler		nibbler(ac, av);
		srand(123456789);
		return (nibbler.run());
	} catch (...) {
		std::cerr << "An unknown error occured." << std::endl;
		return (1);
	}
}
