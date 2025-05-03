#pragma once  

#include "emitter.h"  // Must inherit from this  
#include <vector>  
#include <glm/glm.hpp>  

// PulseEmitter class inherits from the Emitter base class
class PulseEmitter : public Emitter {  
public:  
  // Constructor to initialize the PulseEmitter with position, radius, delay, and amount of particles
  PulseEmitter(glm::vec2 _position, float _radius, float _delay, int _amount)  
      : Emitter(_position, _radius, _delay, {1, 1, 1, 1})  // using white as default color  
      , amount(_amount)  // Number of particles to emit in a pulse
      , accumulatedTime(0.0f)  // Tracks time since the last emission
      , emittedThisCycle(false) {}  // Indicates if particles have been emitted in the current cycle

  // Updates the emitter's state and determines if it is ready to emit particles
  bool update(float dt) override;  

  // Creates new particles and adds them to the provided particle vector
  void createNewParticle(std::vector<Particle>& particles) override;  

  // Flag to indicate if the emitter is ready to emit particles
  bool readyToEmit = false;

private:  
  int amount;  // Number of particles to emit in a single pulse
  float accumulatedTime;  // Accumulated time since the last emission
  bool emittedThisCycle;  // Tracks if particles were emitted in the current cycle
};
