// ============================================================
// GHOST.HPP : Ghost declarations
// The ghost occupies a grid cell and is drawn as a red character.
// Comments explain what the code does without changing gameplay.
// ============================================================

#pragma once
#include "entity.hpp"
#include "grid.hpp"
class Ghost : public Entity {
public:
 Ghost();

// Move this character to the specified grid cell.
 void set_cell(Cell cell,const Grid& grid);

// Return the current grid cell of this object.
 Cell cell() const;

// Draw the object or scene onto the SFML window.
 void render(sf::RenderWindow& window) const override;
private:
 Cell _cell;
};
