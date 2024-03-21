#include <iostream>
#include "MSTextController.h"
#include "MSBoardTextView.h"
#include "MinesweeperBoard.h"
using namespace std;
MSTextController::MSTextController(MinesweeperBoard &board, MSBoardTextView &view):board(board), view(view)
{ }
void MSTextController::play()
{
    int row, col = 0, opcja;
    do{
        view.display();
        cout<< "Wybierz 1 zeby postawic flage albo 2 zeby odkryc pole " << endl;
        cin >> opcja;
        cout<< "Podaj pozycje pola \n rzad: " << endl;
        cin >> row;
        cout<< "\n kolumna: " << endl;
        cin >> col;
        if(opcja==1)
        {
            board.toggleFlag(row, col);
        }
        else  if(opcja==2)
        {
            board.revealField(row, col);
        }
        else cout << "Nie ma takiej opcji" << endl;
    }
    while(board.getGameState()== RUNNING);
    board.debug_display();
    if(board.getGameState()== FINISHED_WIN) cout << "Wygrana " << endl;
    else if (board.getGameState()== FINISHED_LOSS) cout << "Przegrana" << endl;
}