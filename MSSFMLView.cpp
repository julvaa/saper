#include "MSSFMLView.h"
#include "MineSweeperBoard.h"

MSSFMLView::MSSFMLView(MinesweeperBoard & b) : board(b)
{

    r = sf::RectangleShape ( sf::Vector2f(25, 25));
    r.setFillColor ( sf::Color(50,50,50));
    bomb = sf::CircleShape(25*0.25);
    bomb.setFillColor(sf::Color(100,15,15));
    flag = sf::CircleShape(25*0.25, 3);
    flag.setFillColor(sf::Color(15,15,100));
    k = sf::RectangleShape ( sf::Vector2f(25, 25) ) ;
    k.setFillColor ( sf::Color(14,110,28));



    font.loadFromFile("../arialmt.ttf");

    t1.setFont(font);t1.setString("1");t1.setCharacterSize(20);
    t1.setFillColor(sf::Color(100,100,100));

    t2.setFont(font);t2.setString("2");t2.setCharacterSize(20);
    t2.setFillColor(sf::Color(100,100,100));

    t3.setFont(font);t3.setString("3");t3.setCharacterSize(20);
    t3.setFillColor(sf::Color(100,100,100));

    t4.setFont(font);t4.setString("4");t4.setCharacterSize(20);
    t4.setFillColor(sf::Color(100,100,100));


    wygrana.setFont(font);
    wygrana.setString("wygrana");
    wygrana.setCharacterSize(50);
    wygrana.setFillColor(sf::Color(255,255,255));
    przegrana.setFont(font);
    przegrana.setString("przegrana");
    przegrana.setCharacterSize(50);
    przegrana.setFillColor(sf::Color(255,255,255));
}
void MSSFMLView::draw (sf::RenderWindow & win)
{

    int X=0;
    int Y=0;
    for(int row=0; row < board.get_width(); ++row)
    {
        for (int col = 0; col < board.get_height(); ++col)
        {
            r.setPosition(X+(25+1)*col,Y+(25+1)*row);
            win.draw(r);
            k.setPosition(X+(25+1)*col ,Y+(25+1)*row);
            if(board.getFieldInfo(row,col)==' '){win.draw(k);}

            bomb.setPosition(X+(25+1)*col,Y+(25+1)*row);
            if(board.getFieldInfo(row,col)=='X'){win.draw(bomb);}

            flag.setPosition(X+(25+1)*col,Y+(25+1)*row);
            if(board.getFieldInfo(row,col)=='F'){win.draw(flag);}

            t1.setPosition(X+(25+1)*col,Y+(25+1)*row);
            if(board.getFieldInfo(row,col)=='1'){win.draw(t1);}

            t2.setPosition(X+(25+1)*col,Y+(25+1)*row);
            if(board.getFieldInfo(row,col)=='2'){win.draw(t2);}

            t3.setPosition(X+(25+1)*col,Y+(25+1)*row);
            if(board.getFieldInfo(row,col)=='3'){win.draw(t3);}

            t4.setPosition(X+(25+1)*col,Y+(25+1)*row);
            if(board.getFieldInfo(row,col)=='4'){win.draw(t4);}



        }
    }

    int px=board.get_width()*25;
    int py=board.get_height()*25;
    wygrana.setPosition(0, py);
    przegrana.setPosition(0, py);


    if(board.getGameState()==RUNNING);
    else if(board.getGameState()==FINISHED_WIN){win.draw(wygrana);}
    else if(board.getGameState()==FINISHED_LOSS){win.draw(przegrana);}
}