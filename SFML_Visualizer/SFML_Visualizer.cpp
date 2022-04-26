#include <iostream>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Trie Example", sf::Style::Titlebar | sf::Style::Close);
    sf::Event ev;

    // FIRST LEVEL
    sf::CircleShape circle(50);
    circle.setPosition(550.f, 10.f);
    sf::RectangleShape line(sf::Vector2f(150, 5));
    line.setPosition(500.f, 170.f);
    line.rotate(-45);
    sf::RectangleShape line2(sf::Vector2f(150, 5));
    line2.setPosition(600.f, 70.f);
    line2.rotate(45);

    // SECOND LEVEL

    //left
    sf::CircleShape circle2(50);
    circle2.setPosition(430.f, 150.f);
    sf::RectangleShape line3(sf::Vector2f(150, 5));
    line3.setPosition(345.f, 345.f);
    line3.rotate(-45);
    sf::RectangleShape line5(sf::Vector2f(150, 5));
    line5.setPosition(500.f, 240.f);
    line5.rotate(60);
    //right
    sf::CircleShape circle3(50);
    circle3.setPosition(670.f, 150.f);
    sf::RectangleShape line4(sf::Vector2f(150, 5));
    line4.setPosition(755.f, 235.f);
    line4.rotate(45);
    sf::RectangleShape line6(sf::Vector2f(150, 5));
    line6.setPosition(620.f, 370.f);
    line6.rotate(-60);

    // THIRD LEVEL

    //left
    sf::CircleShape circle4(50);
    circle4.setPosition(270.f, 330.f);
    circle4.setFillColor(sf::Color::Green);
    sf::CircleShape circle5(50);
    circle5.setPosition(490.f, 330.f);
    sf::RectangleShape line7(sf::Vector2f(150, 5));
    line7.setPosition(440.f, 545.f);
    line7.rotate(-60);
    sf::RectangleShape line8(sf::Vector2f(150, 5));
    line8.setPosition(570.f, 415.f);
    line8.rotate(60);
    //right
    sf::CircleShape circle6(50);
    circle6.setPosition(610.f, 330.f);
    circle6.setFillColor(sf::Color::Green);
    sf::CircleShape circle7(50);
    circle7.setPosition(830.f, 330.f);
    sf::RectangleShape line9(sf::Vector2f(150, 5));
    line9.setPosition(890.f, 415.f);
    line9.rotate(60);

    // FOURTH LEVEL

    //left
    sf::CircleShape circle8(50);
    circle8.setPosition(390.f, 530.f);
    circle8.setFillColor(sf::Color::Green);
    sf::CircleShape circle9(50);
    circle9.setPosition(600.f, 530.f);
    circle9.setFillColor(sf::Color::Green);
    //right
    sf::CircleShape circle10(50);
    circle10.setPosition(920.f, 530.f);
    circle10.setFillColor(sf::Color::Green);

    //load font
    sf::Font font;
//    font.loadFromFile("Users/ellieoswald/Documents/CSC212/Projects/HelloSFML/Arial.ttf");
    if (!font.loadFromFile("Arial.ttf"))
    {
        std::cout << "Error" << std::endl;
    }


    // MAP
    // m
    sf::Text text;
    // select the font
    text.setFont(font); // font is a sf::Font
    // set the string to display
    text.setString("m");
    // set the character size
    text.setCharacterSize(48); // in pixels, not points!
    // set the color
    text.setFillColor(sf::Color::Black);
    //set position
    text.setPosition(580.f, 25.f);
    // set the text style
    text.setStyle(sf::Text::Bold);

    // a
    sf::Text text2;
    // select the font
    text2.setFont(font); // font is a sf::Font
    // set the string to display
    text2.setString("a");
    // set the character size
    text2.setCharacterSize(48); // in pixels, not points!
    // set the color
    text2.setFillColor(sf::Color::Black);
    //set position
    text2.setPosition(465.f, 165.f);
    // set the text style
    text2.setStyle(sf::Text::Bold);

    // p
    sf::Text text3;
    // select the font
    text3.setFont(font); // font is a sf::Font
    // set the string to display
    text3.setString("p");
    // set the character size
    text3.setCharacterSize(48); // in pixels, not points!
    // set the color
    text3.setFillColor(sf::Color::Black);
    //set position
    text3.setPosition(305.f, 345.f);
    // set the text style
    text3.setStyle(sf::Text::Bold);

    // MASK
    // s
    sf::Text text4;
    // select the font
    text4.setFont(font); // font is a sf::Font
    // set the string to display
    text4.setString("s");
    // set the character size
    text4.setCharacterSize(48); // in pixels, not points!
    // set the color
    text4.setFillColor(sf::Color::Black);
    //set position
    text4.setPosition(525.f, 345.f);
    // set the text style
    text4.setStyle(sf::Text::Bold);

    // k
    sf::Text text5;
    // select the font
    text5.setFont(font); // font is a sf::Font
    // set the string to display
    text5.setString("k");
    // set the character size
    text5.setCharacterSize(48); // in pixels, not points!
    // set the color
    text5.setFillColor(sf::Color::Black);
    //set position
    text5.setPosition(425.f, 550.f);
    // set the text style
    text5.setStyle(sf::Text::Bold);

    // MASS
    // s
    sf::Text text6;
    // select the font
    text6.setFont(font); // font is a sf::Font
    // set the string to display
    text6.setString("s");
    // set the character size
    text6.setCharacterSize(48); // in pixels, not points!
    // set the color
    text6.setFillColor(sf::Color::Black);
    //set position
    text6.setPosition(635.f, 545.f);
    // set the text style
    text6.setStyle(sf::Text::Bold);

    // MOP
    // o
    sf::Text text7;
    // select the font
    text7.setFont(font); // font is a sf::Font
    // set the string to display
    text7.setString("o");
    // set the character size
    text7.setCharacterSize(48); // in pixels, not points!
    // set the color
    text7.setFillColor(sf::Color::Black);
    //set position
    text7.setPosition(705.f, 165.f);
    // set the text style
    text7.setStyle(sf::Text::Bold);

    // p
    sf::Text text8;
    // select the font
    text8.setFont(font); // font is a sf::Font
    // set the string to display
    text8.setString("p");
    // set the character size
    text8.setCharacterSize(48); // in pixels, not points!
    // set the color
    text8.setFillColor(sf::Color::Black);
    //set position
    text8.setPosition(645.f, 345.f);
    // set the text style
    text8.setStyle(sf::Text::Bold);

    // MOSS
    // s
    sf::Text text9;
    // select the font
    text9.setFont(font); // font is a sf::Font
    // set the string to display
    text9.setString("s");
    // set the character size
    text9.setCharacterSize(48); // in pixels, not points!
    // set the color
    text9.setFillColor(sf::Color::Black);
    //set position
    text9.setPosition(865.f, 345.f);
    // set the text style
    text9.setStyle(sf::Text::Bold);

    // s
    sf::Text text10;
    // select the font
    text10.setFont(font); // font is a sf::Font
    // set the string to display
    text10.setString("s");
    // set the character size
    text10.setCharacterSize(48); // in pixels, not points!
    // set the color
    text10.setFillColor(sf::Color::Black);
    //set position
    text10.setPosition(960.f, 545.f);
    // set the text style
    text10.setStyle(sf::Text::Bold);


    // run the program as long as the window is open
    while (window.isOpen())
    {
        while(window.pollEvent(ev))
        {
            switch(ev.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if(ev.key.code == sf::Keyboard::Escape)
                        window.close();
                    break;
            }
        }

        //Clear window
        window.clear(sf::Color::Black);

        //Draw game
        window.draw(circle);
        window.draw(line);
        window.draw(line2);
        window.draw(circle2);
        window.draw(line3);
        window.draw(circle3);
        window.draw(line4);
        window.draw(line5);
        window.draw(line6);
        window.draw(circle4);
        window.draw(circle5);
        window.draw(circle6);
        window.draw(circle7);
        window.draw(line7);
        window.draw(line8);
        window.draw(line9);
        window.draw(circle8);
        window.draw(circle9);
        window.draw(circle10);
        window.draw(text);
        window.draw(text2);
        window.draw(text3);
        window.draw(text4);
        window.draw(text5);
        window.draw(text6);
        window.draw(text7);
        window.draw(text8);
        window.draw(text9);
        window.draw(text10);

        //Tell window is done drawing
        window.display();

    }

    return 0;

}