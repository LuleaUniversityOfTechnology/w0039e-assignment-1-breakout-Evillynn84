#include "constants.h"

Rigidbody** rigidbody;
int numRigidbodies = 10;


void StepFrame(float elapsedTime)
{

}




void GameEntry()
{
    rigidbody = new Rigidbody * [numRigidbodies];
    rigidbody[0] = new Ship();  // The ship is the first object
    for (int i = 1; i < numRigidbodies; i++) {
        rigidbody[i] = new Asteroid();  // Create asteroids
    }
}

void GameUpdate()
{
    // Simulate and draw each rigidbody
    for (int i = 0; i < numRigidbodies; i++) {
        // Handle collisions
        for (int j = 0; j < numRigidbodies; j++) {
            if (i != j) {
                rigidbody[i]->collide(rigidbody[j]);
            }
        }
        // Simulate and draw the object
        rigidbody[i]->simulate(elapsedTime);
        rigidbody[i]->draw();
    }
}

void GameExit()
{
    for (int i = 0; i < numRigidbodies; i++) {
        delete rigidbody[i];  // Clean up
    }
    delete[] rigidbody;
}

