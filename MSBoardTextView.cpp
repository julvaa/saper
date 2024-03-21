#include <iostream>
#include "MSBoardTextView.h"
#include "MinesweeperBoard.h"
using namespace std;
MSBoardTextView::MSBoardTextView(MinesweeperBoard &board) :board(board) {}

void MSBoardTextView::display() const
{
    for(int row=0; row < board.get_width(); row++)
    {

        for(int col=0; col < board.get_height(); col++)
        {
            cout << "[" ;
            cout << board.getFieldInfo(row, col);
            cout << "]";
        }
        cout << endl;
    }
}
