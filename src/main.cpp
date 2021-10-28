#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>

using namespace std;
using namespace sf;

int size = 30;
int width = size*size, height = size*size;
int num = 3;
int dir = 1;

struct Snake{

  int x = 0, y = 0;
	   
}s[100];

struct Fruit{
  int x,y;
}f;

int Action(){

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
      f.x = rand()%size;
      f.y = rand()%size;
    }

  if (s[0].x < 0) s[0].x = size;
  if (s[0].x > size) s[0].x = 0;
  if (s[0].y < 0) s[0].y = size;
  if (s[0].y > size) s[0].y = 0;

  for(int i = 1; i<num; i++)
    {
      if (s[0].x == s[i].x && s[0].y == s[i].y) return 1;
    }
  
  return 0;
}


int main () {

  int check_key = 0;
  RenderWindow app(VideoMode(width,height),"Snake", Style::Titlebar);
  app.setFramerateLimit(60);

  Texture fond;
  fond.loadFromFile("./img/fond.jpg");
  Sprite sprite;
  sprite.setTexture(fond);

  Texture map;
  map.loadFromFile("./img/map.png");
  Sprite sprite_map;
  sprite_map.setTexture(map);
  
  RectangleShape snake(Vector2f(size,size));
  snake.setFillColor(Color::Green);
  
  RectangleShape fruit(Vector2f(size,size));
  fruit.setFillColor(Color::Red);

  sprite.setScale(0.5, 0.8);
  sprite_map.setScale(4, 4);
  
  Clock timer;
  
  f.x = rand()%size;
  f.y = rand()%size;
  
  while(app.isOpen()) {
    Event event;
    while(app.pollEvent(event)){
      switch(event.type)
      case Event::KeyReleased:
	if(event.key.code == Keyboard::Escape)
	  app.close();
      break;
    }
  
    while(check_key == 0)
      {
	if (Keyboard::isKeyPressed(Keyboard::Space))
	  check_key = 1;
	app.clear();
	app.draw(sprite);
	app.display();
      }
    if (timer.getElapsedTime().asMilliseconds()>125)
      {
	if(Action() == 1) app.close();
	timer.restart();
      }
    
    if(dir != 2)
      if(Keyboard::isKeyPressed(Keyboard::Up)) dir = 0;
    if(dir != 3)
      if(Keyboard::isKeyPressed(Keyboard::Right)) dir = 1;
    if(dir != 0)
      if(Keyboard::isKeyPressed(Keyboard::Down)) dir = 2;
    if(dir != 1)
      if(Keyboard::isKeyPressed(Keyboard::Left)) dir = 3;
    
    app.clear();
    app.draw(sprite_map);
    for (int i = 0; i < num; i++) {
      snake.setPosition(s[i].x*size, s[i].y*size);
      app.draw(snake);
    }
    
    fruit.setPosition(f.x*size, f.y*size);
    app.draw(fruit);
    
    app.display();
  }
  return 0;
}
