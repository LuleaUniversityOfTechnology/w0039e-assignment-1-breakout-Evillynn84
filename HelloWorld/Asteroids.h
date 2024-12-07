#pragma once
#include "constants.h"
#include "Asteroids.h"

class Asteroid : public Rigidbody {
private:
    float scale;
    float rotationalSpeed;
    int spriteID; // Sprite identifier

public:
    Asteroid();
    virtual ~Asteroid() {}

    void simulate(float elapsedTime) override;
    void draw() override;
    void collide(Rigidbody* other) override;
};

#endif
