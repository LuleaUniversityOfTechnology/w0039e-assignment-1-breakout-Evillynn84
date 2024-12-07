#pragma once
#include "constants.h"
#include "Ship.h"

class Ship : public Rigidbody {
private:
    float thrust;
    int spriteID; // Sprite identifier

public:
    Ship();
    virtual ~Ship() {}

    void simulate(float elapsedTime) override;
    void draw() override;
    void collide(Rigidbody* other) override;
};

#endif
