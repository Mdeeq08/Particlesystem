#include "../../include/particlesystem/pulseemitter.h"  
#include <cmath>  
#include <iostream>  

// Updates the state of the PulseEmitter based on the elapsed time (dt).  
// Returns true if the emitter is ready to emit particles.  
bool PulseEmitter::update(float dt) {  
   // Accumulate the elapsed time.  
   accumulatedTime += dt;  

   // Check if the accumulated time exceeds the delay threshold.  
   if (accumulatedTime >= delay) {  
       // Reset the accumulated time by subtracting the delay.  
       accumulatedTime -= delay;  
       // Mark the emitter as ready to emit particles.  
       readyToEmit = true;  
       // Note: emittedThisCycle is not reset here, as it may be handled elsewhere.  
   }  

   // Return whether the emitter is ready to emit particles.  
   return readyToEmit;  
}  

// Creates new particles and adds them to the provided particle vector.  
// Only emits particles if the emitter is ready and hasn't emitted in this cycle.  
void PulseEmitter::createNewParticle(std::vector<Particle>& particles) {  
   // Exit early if the emitter is not ready or has already emitted in this cycle.  
   if (!readyToEmit || emittedThisCycle) return;  

   // Emit the specified number of particles.  
   for (int i = 0; i < amount; ++i) {  
       // Generate a random angle for the particle's direction.  
       float angle = static_cast<float>(rand()) / RAND_MAX * 2.0f * 3.14159f;  
       // Generate a random speed for the particle's velocity.  
       float speed = 0.5f + static_cast<float>(rand()) / RAND_MAX * 2.0f;  

       // Calculate the particle's velocity based on the angle and speed.  
       glm::vec2 velocity = {cos(angle) * speed, sin(angle) * speed};  

       // Generate a random radius variation for the particle.  
       float radiusVar = 5.0f + static_cast<float>(rand()) / RAND_MAX * 10.0f;  
       // Generate a random color variation for the particle (fiery orange).  
       glm::vec4 color = {1.0f, 0.5f + static_cast<float>(rand()) / RAND_MAX * 0.5f, 0.0f, 1.0f};  

       // Add the new particle to the particle vector.  
       particles.push_back(Particle(position, velocity, radiusVar, color));  
   }  

   // Mark the emitter as having emitted in this cycle.  
   emittedThisCycle = true;  
   // Reset the readyToEmit flag until the next update.  
   readyToEmit = false;  
}
