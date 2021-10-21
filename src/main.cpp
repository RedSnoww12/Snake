#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>

using namespace std;
using namespace sf;

int size = 30;
int width = size*size, height = size*size;
int num = 3;
int dir = 1;

struct snake{

  int x,y;
	   
}s[100];

struct fruit{
  int x,y;
}f;

void Action(){

  for(int i = num; i>0 ; i--){

    s[i].x = s[i-1].x;
    s[i].y = s[i-1].y;
      
  }

  if (dir == 0) s[0].y -= 1;
  if (dir == 1) s[0].x += 1;
  if (dir == 2) s[0].y += 1;
  if (dir == 3) s[0].x -= 1;

  if (s[0].x == f.x && s[0].y == f.y)
    {
      num++;
      f.x = rand()*size;
      f.y = rand()*size;
    }
}


int main () {

  RenderWindow app(VideoMode(width,height),"Snake", Style::Titlebar);
  app.setFramerateLimit(60);

  RectangleShape snake(Vector2f(size,size));
  snake.setFillColor(Color::Blue);

  RectangleShape fruit(Vector2f(size,size));
  fruit.setFillColor(Color::Red);

  
  Clock timer;

  f.x = rand()*size;
  f.y = rand()*size;
  
  while(app.isOpen()) {
    Event event;
    while(app.pollEvent(event)){
      switch(event.type)
      case Event::KeyReleased:
	if(event.key.code == Keyboard::Escape)
	  app.close();
      break;
    }
  }

  if (timer.getElapsedTime().asMilliseconds()>200)
    {
      Action();
      timer.restart();
    }
  
  if(Keyboard::isKeyPressed(Keyboard::Up)) dir = 0;
  if(Keyboard::isKeyPressed(Keyboard::Right)) dir = 1;
  if(Keyboard::isKeyPressed(Keyboard::Down)) dir = 2;
  if(Keyboard::isKeyPressed(Keyboard::Left)) dir = 3;
  
  app.clear();

  for (int i = 0; i < num; i++) {
    snake.setPosition(s[i].x*size,s[i].y*size);
    app.draw(snake);
  }

  fruit.setPosition(f.x*size, f.y*size);
  app.draw(fruit);
  
  app.display();
  
  return 0;
}
