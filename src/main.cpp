#include <SFML/Graphics.hpp>

#define WIDTH 800
#define HEIGHT 800
#define VITESSE 0.05

int main()
{
  sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT), "Snake !");
  sf::RectangleShape rectangle(sf::Vector2f(10, 10));
  rectangle.setFillColor(sf::Color::Blue);

  // window.setFramerateLimit(60);

  float x = 20, y = 20;
  rectangle.setPosition(x,y);  
  
  while (window.isOpen())
    {
      sf::Event event;
      while (window.pollEvent(event)) {
	if (event.type == sf::Event::Closed)
	  window.close();
      }

      /*sf::SoundBuffer buffer;
      if (!buffer.loadFromFile("sound.wav"))
        return -1;*/
      
      window.draw(rectangle);
      window.display();

      if (x <= 790) {
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
	  while (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && x <= 790) {
	    rectangle.setPosition(x,y);
	    window.clear();
	    window.draw(rectangle);
	    window.display();
	    x = x + VITESSE;
	  }
	}
      }

      if (y <= 790) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
	  while (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && y <= 790) {
	    rectangle.setPosition(x,y);
	    window.clear();
	    window.draw(rectangle);
	    window.display();
	    y = y + VITESSE;
	  }
	}
      }

      if (x >= 0) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
	  while (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && x >= 0) {
	    rectangle.setPosition(x,y);
	    window.clear();
	    window.draw(rectangle);
	    window.display();
	    x = x - VITESSE;
	  }
	}
      }

      if (y >= 0) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
	  while (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && y >= 0) {
	    rectangle.setPosition(x,y);
	    window.clear();
	    window.draw(rectangle);
	    window.display();
	    y = y - VITESSE;
	  }
	}
      }
    }

  return 0;
}
