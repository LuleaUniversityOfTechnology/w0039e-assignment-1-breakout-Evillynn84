#include "Ship.h"


Ship::Ship() {
    x = 400.0f;
    y = 300.0f;
    vx = 0;
    vy = 0;
    ax = 0;
    ay = 0;
    rotation = 0.0f;
    radius = 20.0f;
    thrust = 200.0f;
    spriteID = 0;  // Assuming 0 is ship sprite
}

void Ship::simulate(float elapsedTime) {
    // Apply thrust if space key is pressed
    if (GetAsyncKeyState(VK_SPACE)) {
        ax += thrust * sin(rotation) * elapsedTime;
        ay -= thrust * cos(rotation) * elapsedTime;  // Negate y-axis for screen coordinates
    }

    // Rotate the ship based on left/right arrow keys
    if (GetAsyncKeyState(VK_LEFT)) {
        rotation -= 0.05f; // Rotate counterclockwise
    }
    if (GetAsyncKeyState(VK_RIGHT)) {
        rotation += 0.05f; // Rotate clockwise
    }

    // Apply physics to update position and velocity
    vx += ax * elapsedTime;
    vy += ay * elapsedTime;
    x += vx * elapsedTime;
    y += vy * elapsedTime;

    // Reset acceleration
    ax = 0;
    ay = 0;
}

void Ship::draw() {
    // Draw the ship at its current position, rotated
    DrawSpriteRotated(spriteID, x, y, rotation);
}

void Ship::collide(Rigidbody* other) {
    // Reset position and velocity upon collision with an asteroid
    if (typeid(*other) == typeid(Asteroid)) {
        x = 400.0f;
        y = 300.0f;
        vx = 0;
        vy = 0;
        rotation = 0.0f;
    }
}