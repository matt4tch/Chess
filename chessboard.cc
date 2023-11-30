#include <cctype>
#include <iostream>
#include <algorithm>
#include "chessboard.h"

using namespace std;

template<typename T> bool in(const std::vector<T>& vec, const T& element) {

}

bool ChessBoard::inrange(int r, int c) {
    if (r < 0 || r > 7) return false;
    if (c < 0 || c > 7) return false;
    return true;
}

string ChessBoard::intPairToRankFile(int row, int col) {
    col += 65;
    char ch = col;
    string c = to_string(ch);
    c += to_string(row);
    return c;
}

pair<int,int> ChessBoard::rankFileToIntPair(string rf) {
    ;
}

void ChessBoard::calculateAvailableMoves() {
    int r = 0;
    for (auto &row: board) {
        int c = 0;
        for (auto &col: row) {
            if (col != nullptr) {
                std::vector<Vec> potentialmoves = col->getPotentialMoves();
                for (auto m: potentialmoves) {
                    if (inrange(r + m.y, c + m.x)) {
                        if (board[r + m.y][c + m.x] == nullptr) {
                            if (m.x == 0 || m.y == 0 || m.x == m.y) {
                                // do something --> loop through the positions
                                if (m.x == m.y) {
                                    
                                }
                            } else {
                                board[r][c]->availableMoves.emplace_back(intPairToRankFile(r + m.y, c + m.x));
                            }
                        } else if (board[r][c]->colour != board[r + m.y][c + m.x]->colour) {
                            // code
                        }
                    }
                }
            }
            ++c;
        }
        ++r;
    }
}

ChessBoard::ChessBoard(string config) {
  board.resize(8); // makes 8 rows
  for (auto &i: board) i.resize(8); // makes 8 columns, each entry is nullptr
  if (config == "empty") return;
  if (config == "default") { // official board setup
    board[0][0] = make_unique<Rook>("white");
    board[0][1] = make_unique<Knight>("white");
    board[0][2] = make_unique<Bishop>("white");
    board[0][3] = make_unique<Queen>("white");
    board[0][4] = make_unique<King>("white");
    board[0][5] = make_unique<Bishop>("white");
    board[0][6] = make_unique<Knight>("white");
    board[0][7] = make_unique<Rook>("white");
    for (int i = 0; i < 8; ++i) board[1][i] = make_unique<WhitePawn>("white");
    board[7][0] = make_unique<Rook>("black");
    board[7][1] = make_unique<Knight>("black");
    board[7][2] = make_unique<Bishop>("black");
    board[7][3] = make_unique<Queen>("black");
    board[7][4] = make_unique<King>("black");
    board[7][5] = make_unique<Bishop>("black");
    board[7][6] = make_unique<Knight>("black");
    board[7][7] = make_unique<Rook>("black");
    for (int i = 0; i < 8; ++i) board[6][i] = make_unique<BlackPawn>("black");
  }
  updatePieceLists();
}
ChessBoard::ChessBoard(const ChessBoard &other): ChessBoard{"empty"} {
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      if (other.board[i][j]) {
        board[i][j] = other.board[i][j]->clone();
      }
    }
  }
  updatePieceLists();
}
void ChessBoard::updatePieceLists() {
  blackPieces.resize(0);
  whitePieces.resize(0);
  for (const auto &i: board) {
    for (const auto &j: i) {
      if (j) {
        if (j->getColour() == "white") whitePieces.emplace_back(j.get());
        else if (j->getColour() == "black") blackPieces.emplace_back(j.get());
      }
    }
  }
}
bool ChessBoard::isCheck(string colour) {
  for (const auto &i: board) {
    for (const auto &j : i) {
      if (j->getName() == "king" && j->getColour() == colour) {
        if (j->threats.empty()) return false;
        else return true;
      }
    }
  }
}
void ChessBoard::move(string start, string end) {
  auto startCoords = rankFileToIntPair(start);
  auto endCoords = rankFileToIntPair(end);
  if (board[startCoords.first][startCoords.second]->availableMoves)
}
void ChessBoard::dontCheckYourself() {
  ;
}
std::ostream &operator<<(std::ostream &out, const ChessBoard &chessboard) { // viewing the board
  char sym;
  for (const auto &i: chessboard.board) {
    for (const auto &j: i) {
      if (!j) {
        out << '_';
        continue;
      }
      if (j->getName() == "rook") sym = 'r';
      else if (j->getName() == "knight") sym = 'n';
      else if (j->getName() == "bishop") sym = 'b';
      else if (j->getName() == "king") sym = 'k';
      else if (j->getName() == "queen") sym = 'q';
      else if (j->getName() == "blackpawn" || j->getName() == "whitepawn") sym = 'p';
      if (j->getColour() == "white") out << static_cast<char>(toupper(sym)); // White pieces are uppercase
      else out << sym;
    }
    cout << endl;
  }
  return out;
}