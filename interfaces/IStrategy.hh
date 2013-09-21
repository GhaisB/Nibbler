#ifndef 					__I_STRATEGY_HH__
#define 					__I_STRATEGY_HH__

#include					<queue>
#include					<list>
#include					"IDisplay.hh"
#include					"IItem.hh"

class 						IStrategy
{

public:
  virtual					~IStrategy() {}

  /* Crée les murs random dans la map */
  virtual void 				createMapWalls(std::list<IItem *> &, Snake *)			    = 0;

  /* Renvoie le temps du usleep (Gestion du temps) */
  virtual int				  getSleepTime() 									                      = 0;

  /* Permet de poper les bonus/malus/nourriture */
  virtual void				popObjects(std::list<IItem *> &, Snake *)		          = 0;

  /* Permet de détruire les bonus/malus/bouffe qui sont expirés */
  virtual void				destroyOutdatedObjects(std::list<IItem *> &)	        = 0;

  /* Permer d'indiquer a l'IA de popper de la food a la prochaine frame */
  virtual void 				setPopFood() 									                        = 0;

  /* Permet d'activer le bonus de vitesse */
  virtual void        activeSpeedBonus()                                    = 0;

  /* Ajoute au score le bonus de STAR */
  virtual void        activeStarBonus()                                     = 0;

  /* Active un bonus ou malus random */
  virtual void        activeRandom(std::list<IItem *> &items, Snake *snake) = 0;

  virtual int         getScore() const                                      = 0;
};

#endif
