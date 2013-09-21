##
## Makefile for Makefile in /home/knocka_a/rendu-epitech/git-repositories/nibbler
##
## Made by antoine knockaert
## Login   <knocka_a@epitech.net>
##
## Started on  Mon Mar 18 14:33:29 2013 antoine knockaert
##

NAME=				nibbler

RM=					rm -f

INCLUDES=			-I headers/							\
					-I interfaces/						\
					-I exceptions/						\
					-I /usr/include/					\
					-I /usr/include/allegro5/

LIBRARIES_NIBBLER=	-ldl -export-dynamic

CPPFLAGS=			-Wall -Wextra -Werror $(INCLUDES) $(LIBRARIES_NIBBLER) -g

SRC=				src/main.cpp 						\
					classes/Game.cpp 					\
					classes/Item.cpp 					\
					classes/Nibbler.cpp 				\
					classes/Parts.cpp 					\
					classes/Snake.cpp 					\
					classes/EasyLevel.cpp 				\
					classes/MediumLevel.cpp 			\
					classes/HardLevel.cpp

OBJ=				$(SRC:.cpp=.o)

LIBRARY_SFML=		libraries/lib_nibbler_sfml.so

LIBRARY_ALLEGRO=	libraries/lib_nibbler_allegro.so

LIBRARY_NCURSES=	libraries/lib_nibbler_ncurses.so

SFML_SRC=			graphics/sfml/SFML.cpp

NCURSES_SRC=		graphics/ncurses/NCurses.cpp

ALLEGRO_SRC=		graphics/allegro/Allegro.cpp

all:				$(LIBRARY_SFML) $(LIBRARY_ALLEGRO) $(LIBRARY_NCURSES) $(NAME)

$(LIBRARY_SFML):
					g++ -o $(LIBRARY_SFML) $(SFML_SRC) -shared -fPIC  -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system $(CPPFLAGS)

$(LIBRARY_ALLEGRO):
					g++ -o $(LIBRARY_ALLEGRO) $(ALLEGRO_SRC) -lallegro -lallegro_image -shared -fPIC -Wall -Wextra -Werror $(INCLUDES)

$(LIBRARY_NCURSES):
					g++ -o $(LIBRARY_NCURSES) $(NCURSES_SRC) -shared -fPIC -lncurses -Wall -Wextra -Werror $(INCLUDES)

$(NAME):			$(OBJ)
					g++ -o $(NAME) $(OBJ) $(CPPFLAGS) $(LIBRARIES_NIBBLER)

clean:
					$(RM) $(OBJ) $(SFML_OBJ) $(ALLEGRO_OBJ) $(NCURSES_OBJ)

fclean:				clean
					$(RM) $(NAME) $(LIBRARY_NCURSES) $(LIBRARY_ALLEGRO) $(LIBRARY_SFML)

re:					clean fclean all
