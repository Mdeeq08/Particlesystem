#include "../../include/particlesystem/pulseemitter.h"
#include <cmath>
#include <iostream>


bool PulseEmitter::update(float dt) {
    accumulatedTime += dt;

    if (accumulatedTime >= delay) {
        accumulatedTime -= delay;
        readyToEmit = true;
        //emittedThisCycle = false;
    }

    //std::cout << "[DEBUG] PulseEmitter time = " << accumulatedTime << std::endl;
    return readyToEmit;
}

void PulseEmitter::createNewParticle(std::vector<Particle>& particles) {
    if (!readyToEmit || emittedThisCycle) return;

    for (int i = 0; i < amount; ++i) {
        float angle = static_cast<float>(rand()) / RAND_MAX * 2.0f * 3.14159f;
        float speed = 0.5f + static_cast<float>(rand()) / RAND_MAX * 2.0f;  // random burst velocity

        glm::vec2 velocity = {cos(angle) * speed, sin(angle) * speed};

        float radiusVar = 5.0f + static_cast<float>(rand()) / RAND_MAX * 10.0f;  // size variation
        glm::vec4 color = {1.0f, 0.5f + static_cast<float>(rand()) / RAND_MAX * 0.5f, 0.0f,
                           1.0f};  // fiery orange with variation

        particles.push_back(Particle(position, velocity, radiusVar, color));
    }

    emittedThisCycle = true;
    readyToEmit = false;

    //std::cout << "[DEBUG] BOOM! " << amount << " particles released." << std::endl;
}
