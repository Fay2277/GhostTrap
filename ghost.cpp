// ============================================================
// GHOST.CPP : Ghost drawing
// Draws the ghost body, head and face using simple SFML shapes.
// Comments explain what the code does without changing gameplay.
// ============================================================

#include "ghost.hpp"
#include <memory>
Ghost::Ghost() : Entity(std::unique_ptr<sf::Shape>(new sf::CircleShape(24.f))), _cell{1,3} {
 _shape->setFillColor(sf::Color(219,49,64));
 _shape->setOrigin(24.f,24.f);
}

// Move this character to the specified grid cell.
void Ghost::set_cell(Cell c,const Grid& grid) { _cell=c;set_position(grid.center(c)); }

// Return the current grid cell of this object.
Cell Ghost::cell() const { return _cell; }

// Draw the object or scene onto the SFML window.
void Ghost::render(sf::RenderWindow& window) const {
 Entity::render(window);
 sf::RectangleShape body(sf::Vector2f(48.f,22.f));
 body.setFillColor(sf::Color(219,49,64));
 body.setPosition(get_position().x-24.f,get_position().y);
 window.draw(body);
 for(int i=0;i<3;i++) {
  sf::ConvexShape tip(3);
  tip.setPoint(0,sf::Vector2f(0,0));
  tip.setPoint(1,sf::Vector2f(16,0));
  tip.setPoint(2,sf::Vector2f(8,10));
  tip.setFillColor(sf::Color(219,49,64));
  tip.setPosition(get_position().x-24.f+i*16.f,get_position().y+21.f);
  window.draw(tip);
 }
 for(int i=0;i<2;i++) {
  sf::CircleShape eye(5.f);
  eye.setFillColor(sf::Color::White);
  eye.setPosition(get_position().x+(i==0?-13.f:6.f),get_position().y-11.f);
  window.draw(eye);
 }
}
