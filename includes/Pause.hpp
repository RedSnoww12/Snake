#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS_PAUSE 2

class Pause
{
	public:
		Pause(float width, float height);
		~Pause();

		void draw(sf::RenderWindow &app);
		void MoveUp();
		void MoveDown();
		int GetPressedItem() { return selectedIndex; }

	private:
		int selectedIndex;
		sf::Font font;
		sf::Text pause[MAX_NUMBER_OF_ITEMS_PAUSE];

};