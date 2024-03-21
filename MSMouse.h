
#ifndef CPP_MSMOUSE_H
#define CPP_MSMOUSE_H

namespace sf{
    class Event;
}

class MinesweeperBoard;
class MSSFMLView;

class MSMouse {
    MinesweeperBoard &board;
    MSSFMLView &view;

public:
    MSMouse(MinesweeperBoard &board, MSSFMLView &view);
    void Events(sf::Event &event);
};




#endif //CPP_MSMOUSE_H

