#include "../../include/particlesystem/pulseemitter.h"
#include <cmath>
#include <iostream>

bool PulseEmitter::update(float dt) {
    accumulatedTime += dt;

    if (accumulatedTime >= delay) {
        accumulatedTime -= delay;
        emittedThisCycle = false;  // allow next emission
        return true;
    }

    return false;
}

void PulseEmitter::createNewParticle(std::vector<Particle>& particles) {
    if (emittedThisCycle || accumulatedTime > 0.0f) return;

    for (int i = 0; i < amount; ++i) {
        float angle = i * 2.0f * 3.14159f / amount;
        glm::vec2 velocity = {cos(angle), sin(angle)};
        particles.push_back(Particle(position, velocity, radius, color));
    }

    emittedThisCycle = true;
}
