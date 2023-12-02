#include "abstractpiece.h"
#include <memory>
using namespace std;

AbstractPiece::AbstractPiece(string colour, string position): colour{colour}, position{position} {}

AbstractPiece::~AbstractPiece() {}

string AbstractPiece::getColour() { return colour; }

string AbstractPiece::getPosition() { return position; };

void AbstractPiece::addAvailableMove(string move) { availableMoves.emplace_back(move); }

void AbstractPiece::addTarget(string target) { targets.emplace_back(target); }

void AbstractPiece::addThreat(string threat) { threats.emplace_back(threat); }

std::vector<Vec> King::getPotentialMoves() const {
  return {{1,0}, {1,1}, {0,1}, {-1, 1}, {-1,0}, {-1,-1}, {0,-1}, {1,-1}};
}
std::vector<Vec> Queen::getPotentialMoves() const {
  return {{ 1, 0}, { 2, 0}, { 3, 0}, { 4, 0}, { 5, 0}, { 6, 0}, { 7, 0},
          {-1, 0}, {-2, 0}, {-3, 0}, {-4, 0}, {-5, 0}, {-6, 0}, {-7, 0},
          { 0, 1}, { 0, 2}, { 0, 3}, { 0, 4}, { 0, 5}, { 0, 6}, { 0, 7},
          { 0,-1}, { 0,-2}, { 0,-3}, { 0,-4}, { 0,-5}, { 0,-6}, { 0,-7},
          { 1, 1}, { 2, 2}, { 3, 3}, { 4, 4}, { 5, 5}, { 6, 6}, { 7, 7},
          {-1,-1}, {-2,-2}, {-3,-3}, {-4,-4}, {-5,-5}, {-6,-6}, {-7,-7},
          { 1,-1}, { 2,-2}, { 3,-3}, { 4,-4}, { 5,-5}, { 6,-6}, { 7,-7},
          {-1, 1}, {-2, 2}, {-3, 3}, {-4, 4}, {-5, 5}, {-6, 6}, {-7, 7}};
}
std::vector<Vec> Rook::getPotentialMoves() const {
  return {{ 1, 0}, { 2, 0}, { 3, 0}, { 4, 0}, { 5, 0}, { 6, 0}, { 7, 0},
          {-1, 0}, {-2, 0}, {-3, 0}, {-4, 0}, {-5, 0}, {-6, 0}, {-7, 0},
          { 0, 1}, { 0, 2}, { 0, 3}, { 0, 4}, { 0, 5}, { 0, 6}, { 0, 7},
          { 0,-1}, { 0,-2}, { 0,-3}, { 0,-4}, { 0,-5}, { 0,-6}, { 0,-7}};
}
std::vector<Vec> Knight::getPotentialMoves() const {
  return {{2,1}, {2,-1}, {1,2}, {-1,2}, {-2,1}, {-2,-1}, {1,-2}, {-1,-2}};
}
std::vector<Vec> Bishop::getPotentialMoves() const {
  return {{ 1, 1}, { 2, 2}, { 3, 3}, { 4, 4}, { 5, 5}, { 6, 6}, { 7, 7},
          {-1,-1}, {-2,-2}, {-3,-3}, {-4,-4}, {-5,-5}, {-6,-6}, {-7,-7},
          { 1,-1}, { 2,-2}, { 3,-3}, { 4,-4}, { 5,-5}, { 6,-6}, { 7,-7},
          {-1, 1}, {-2, 2}, {-3, 3}, {-4, 4}, {-5, 5}, {-6, 6}, {-7, 7}};
}
std::vector<Vec> WhitePawn::getPotentialMoves() const {
  return {{0,1}, {0,2}, {1,1}, {-1,1}};
}
std::vector<Vec> BlackPawn::getPotentialMoves() const {
  return {{0,-1}, {0,-2}, {1,-1}, {-1,-1}};
}
string King::getName() const {
  return "king";
}
string Queen::getName() const {
  return "queen";
}
string Rook::getName() const {
  return "rook";
}
string Knight::getName() const {
  return "knight";
}
string Bishop::getName() const {
  return "bishop";
}
string WhitePawn::getName() const {
  return "whitepawn";
}
string BlackPawn::getName() const {
  return "blackpawn";
}

King::King(string colour, string position): AbstractPiece{colour, position} {}
Queen::Queen(string colour, string position): AbstractPiece{colour, position} {}
Rook::Rook(string colour, string position): AbstractPiece{colour, position} {}
Knight::Knight(string colour, string position): AbstractPiece{colour, position} {}
Bishop::Bishop(string colour, string position): AbstractPiece{colour, position} {}
BlackPawn::BlackPawn(string colour, string position): AbstractPiece{colour, position} {}
WhitePawn::WhitePawn(string colour, string position): AbstractPiece{colour, position} {}

unique_ptr<AbstractPiece> King::clone() const {
  return std::make_unique<King>(*this);
}
unique_ptr<AbstractPiece> Queen::clone() const {
  return std::make_unique<Queen>(*this);
}
unique_ptr<AbstractPiece> Rook::clone() const {
  return std::make_unique<Rook>(*this);
}
unique_ptr<AbstractPiece> Knight::clone() const {
  return std::make_unique<Knight>(*this);
}
unique_ptr<AbstractPiece> Bishop::clone() const {
  return std::make_unique<Bishop>(*this);
}
unique_ptr<AbstractPiece> BlackPawn::clone() const {
  return std::make_unique<BlackPawn>(*this);
}
unique_ptr<AbstractPiece> WhitePawn::clone() const {
  return std::make_unique<WhitePawn>(*this);
}