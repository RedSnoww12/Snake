#include <SFML/Graphics.hpp>

#define WIDTH 800
#define HEIGHT 800
#define VITESSE 5

int main()
{
  sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT), "Snake !");
  window.setFramerateLimit(60);
  
  sf::RectangleShape rectangle(sf::Vector2f(10, 10));
  rectangle.setFillColor(sf::Color::Blue);
  sf::CircleShape shape(5.f);
  shape.setFillColor(sf::Color::Red);

  float x = 20, y = 20;
  rectangle.setPosition(x,y);
  shape.setPosition(400.f,400.f);
  
  window.draw(shape);
  window.display();
  
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
	  while ( x <= 790) {
	    rectangle.setPosition(x,y);
	    window.clear();
	    window.draw(rectangle);
	    window.draw(shape);
	    window.display();
	    x = x + VITESSE;
	    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))) {
	      break;
	    }
	  }
	}
      }

      if (y <= 790) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
	  while ( y <= 790) {
	    rectangle.setPosition(x,y);
	    window.clear();
	    window.draw(rectangle);
	    window.draw(shape);
	    window.display();
	    y = y + VITESSE;
	    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))) {
	      break;
	    }
	  }
	}
      }

      if (x >= 0) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
	  while (x >= 0) {
	    rectangle.setPosition(x,y);
	    window.clear();
	    window.draw(rectangle);
	    window.draw(shape);
	    window.display();
	    x = x - VITESSE;
	    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))) {
	      break;
	  }
	  }
	}
      }

      if (y >= 0) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
	  while (y >= 0) {
	    rectangle.setPosition(x,y);
	    window.clear();
	    window.draw(rectangle);
	    window.draw(shape);
	    window.display();
	    y = y - VITESSE;
	    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))) {
	      break;
	    }
	  }
	}
      }
    }

  return 0;
}
