#pragma once
#include "constants.h"


struct Rigidbody {
    float x, y;            // Position
    float vx, vy;          // Velocity
    float ax, ay;          // Acceleration
    float rotation;        // Rotation (in radians)
    float radius;          // Radius

    virtual ~Rigidbody(){}

    virtual void simulate(float elapsedTime) = 0; // Simulate physics (pure virtual)
    virtual void draw() = 0;                       // Draw the object (pure virtual)
    virtual void collide(Rigidbody* other) = 0;    // Handle collision (pure virtual)
};


