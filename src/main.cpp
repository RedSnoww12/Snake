#include <SFML/Graphics.hpp>


#define WIDTH 800
#define HEIGHT 800

int main()
{
  sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT), "Snake !");
  sf::CircleShape shape(10.f);
  shape.setFillColor(sf::Color::Blue);
  shape.setPosition(10.f,10.f);

  // window.setFramerateLimit(60);

  int x = 10, y = 10;
  
  while (window.isOpen())
    {
      sf::Event event;
      while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
    }
      if (x == 10) {
    while (x != 780) {
      shape.setPosition(x,10.f);
      window.clear();
      window.draw(shape);
      window.display();
      x = x + 1;
    }
      }
      if (y == 10) {
    while (y != 780) {
      shape.setPosition(x,y);
      window.clear();
      window.draw(shape);
      window.display();
      y = y + 1;
    }
      }
      if (x == 780) {
    while (x != 10) {
      shape.setPosition(x,y);
      window.clear();
      window.draw(shape);
      window.display();
      x = x - 1;
    }
      }
      if (y == 780) {
    while (y != 10) {
      shape.setPosition(x,y);
      window.clear();
      window.draw(shape);
      window.display();
      y = y - 1;
    }
      }
    window.clear();
    }

  return 0;
}