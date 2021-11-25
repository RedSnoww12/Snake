#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include "../includes/Menu.hpp"
#include "../includes/Structure.hpp"
#include "../includes/Action.hpp"
#include <stdio.h>



int main () {

  int size = 30;
  int width = size*size, height = size*size;
  int num = 3;
  int dir = 1;
  int score = 0;
  int TIME_SNAKE = 100;

  Snake s[100];

  appleSprite f;

  sf::Texture texture_Head_Snake;
  texture_Head_Snake.loadFromFile("./img/imgSnake/snakeTete.png");

  sf::Texture texture_Body_Snake;
  texture_Body_Snake.loadFromFile("./img/imgSnake/SnakeCorps.png");

  sf::Texture texture_TailR_Snake;
  texture_TailR_Snake.loadFromFile("./img/imgSnake/SnakeQueueDroite.png");

  sf::Texture texture_TailL_Snake;
  texture_TailL_Snake.loadFromFile("./img/imgSnake/SnakeQueueGauche.png");
  
  sf::Texture textureApple;
  textureApple.loadFromFile("./img/fruit.png");

  sf::Sprite appleSprite;
  appleSprite.setTexture(textureApple);
  appleSprite.scale(sf::Vector2f(0.06,0.06));


  int check_key = 0;

  sf::SoundBuffer buffer_sabre;
  buffer_sabre.loadFromFile("./son/sabre.wav");

  sf::Sound sound_sabre;
  sound_sabre.setBuffer(buffer_sabre);

  sf::SoundBuffer buffer;
  sf::SoundBuffer buffer1;
  sf::SoundBuffer buffer2;
  sf::SoundBuffer bufferF;
  buffer.loadFromFile("./son/son_menu.wav");
  buffer1.loadFromFile("./son/son_phase1.wav");
  buffer2.loadFromFile("./son/son_phase2.wav");
  bufferF.loadFromFile("./son/son_phaseFinal.wav");


  sf::Sound sound_menu;
  sf::Sound sound_phase1;
  sf::Sound sound_phase2;
  sf::Sound sound_phaseF;
  sound_menu.setBuffer(buffer);
  sound_menu.setVolume(60.f);
  sound_menu.play();

  sound_phase1.setBuffer(buffer1);
  sound_phase1.setVolume(40.f);
  
  sound_phase2.setBuffer(buffer2);
  sound_phase2.setVolume(40.f);

  sound_phaseF.setBuffer(bufferF);
  sound_phaseF.setVolume(40.f);
  
  
  sf::RenderWindow app(sf::VideoMode(width,height),"Snake");
  app.setFramerateLimit(60);



  sf::Texture fond;
  fond.loadFromFile("./img/gif.gif");
  sf::Sprite sprite;
  sprite.setTexture(fond);

  sf::Texture map;
  map.loadFromFile("./img/map.jpg");
  sf::Sprite sprite_map;
  sprite_map.setTexture(map);
  
  sf::RectangleShape snake(sf::Vector2f(size,size));
  //snake.setFillColor(sf::Color::Green);

  sf::RectangleShape snake_Body(sf::Vector2f(size,size));
  //snake_body.setFillColor(sf::Color::Green);

  sf::RectangleShape snake_TailR(sf::Vector2f(size,size));
  //snake_tail.setFillColor(sf::Color::Green);

  sf::RectangleShape snake_TailL(sf::Vector2f(size,size));
  
  //sf::RectangleShape appleSprite(sf::Vector2f(size,size));
  //appleSprite.setFillColor(sf::Color::Red);

  sprite.setScale(0.5, 0.8);
  sprite_map.setScale(1,1.25);
  
  sf::Clock timer;
  
  f.x = rand()%size;
  f.y = rand()%size;

  Menu menu(900,900);

  int musiqueIsPlaying = 0;
  int choixUser=0;

  snake.setTexture(&texture_Head_Snake);
  snake_Body.setTexture(&texture_Body_Snake);
  snake_TailR.setTexture(&texture_TailR_Snake);
  snake_TailL.setTexture(&texture_TailL_Snake);
  int check_move = 0;
  int k = 0;
  while(app.isOpen()) {

    if(choixUser == 0)
    {
      app.clear();
      app.draw(sprite);
      menu.draw(app);
      app.display();

    }

    sf::Event event;
    while(app.pollEvent(event))
    {
      if(choixUser == 0)
      {
        if(event.type == sf::Event::KeyPressed)
        {
          if(event.key.code == sf::Keyboard::Up)
          {
            menu.MoveUp();
          }
          else if(event.key.code == sf::Keyboard::Down)
          {
            menu.MoveDown();
          }
          if(event.key.code == sf::Keyboard::Enter)
          {
            if(menu.GetPressedItem() == 0) choixUser = 1;
            else if(menu.GetPressedItem() == 1) choixUser = 2;
            else if(menu.GetPressedItem() == 2) choixUser = 3;
          }
        }
      }

      switch(event.type)
      {


        case sf::Event::Closed:
          app.close();
          break;

        case sf::Event::KeyReleased:
          if(event.key.code == sf::Keyboard::Escape)
            app.close();
          break;
      }
    }

    if(choixUser==1){
      
      if(check_key == 0)
      {
        sound_menu.stop();
        sound_phase1.play();
        check_key = 1;
      }
      

      if (timer.getElapsedTime().asMilliseconds()>TIME_SNAKE)
        {
          if(Action(&sound_sabre, s, &f, &num, &dir, size, &score) == 1) app.close();
          timer.restart();
        }
      
      if(dir != 2)
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) dir = 0;
      if(dir != 3)
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) dir = 1;
      if(dir != 0)
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) dir = 2;
      if(dir != 1)
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) dir = 3;
      
      app.clear();
      app.draw(sprite_map);
      
      for (int i = 0; i < 1; i++) 
      {
        snake.setPosition(s[i].x*size, s[i].y*size);
	app.draw(snake);
      }

      for (int i = 1; i < num; i++) 
      {
	snake_Body.setPosition(s[i].x*size, s[i].y*size);
	app.draw(snake_Body);
      }

      k = num;
      if (dir == 3)
	snake_TailR.setTexture(&texture_TailL_Snake);
      if (dir == 1)
	snake_TailR.setTexture(&texture_TailR_Snake);
      while (k <= num)
      {
	snake_TailR.setPosition(s[k].x*size, s[k].y*size);
	
	app.draw(snake_TailR);
	k++;
	}
      
      appleSprite.setPosition(f.x*size, f.y*size);
      app.draw(appleSprite);
      
      app.display();
    }
    
    if (score==130 && check_key == 1)
      {
	sound_phase1.stop();
	sound_phase2.play();
	
	map.loadFromFile("./img/maxresdefault.jpg");
	sprite_map.setTexture(map);
	app.clear();
	app.draw(sprite_map);
	app.display();
	
	TIME_SNAKE = TIME_SNAKE - 40;
	check_key = 2;
      }

    if (score==260 && check_key == 2)
    {
      sound_phase2.stop();
      sound_phaseF.play();

      map.loadFromFile("./img/final.jpg");
      sprite_map.setTexture(map);
      app.clear();
      app.draw(sprite_map);
      app.display();

      TIME_SNAKE = TIME_SNAKE - 30;
      check_key = 3;
    }

    else if(choixUser==3){
      app.clear();
      app.close();
    }

  }
  return 0;
}
