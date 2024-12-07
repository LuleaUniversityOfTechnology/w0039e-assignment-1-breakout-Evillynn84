#include "Asteroids.h"

Asteroid::Asteroid() {
    // Initialize random values for position, velocity, etc.
    x = rand() % 800;
    y = rand() % 600;
    vx = rand() % 10 - 5;
    vy = rand() % 10 - 5;
    ax = 0;
    ay = 0;
    rotation = rand() % 360;
    radius = 30.0f;
    scale = 1.0f + rand() % 3;  // Scale between 1 and 3
    rotationalSpeed = (rand() % 5 + 1) * 0.01f;  // Random rotational speed
    spriteID = 1;  // Assuming 1 is asteroid sprite
}

void Asteroid::simulate(float elapsedTime) {
    // Rotate asteroid slightly
    rotation += rotationalSpeed * elapsedTime;
    if (rotation >= 2 * M_PI) rotation -= 2 * M_PI;

    // Apply simple physics (position update, acceleration, etc.)
    x += vx * elapsedTime;
    y += vy * elapsedTime;
}

void Asteroid::draw() {
    // Draw the asteroid at its current position, rotated
    DrawSpriteRotated(spriteID, x, y, rotation);
}

void Asteroid::collide(Rigidbody* other) {
    // Reset the asteroid to random position when collided with a ship
    if (typeid(*other) == typeid(Ship)) {
        x = rand() % 800;
        y = rand() % 600;
        vx = rand() % 10 - 5;
        vy = rand() % 10 - 5;
    }
}