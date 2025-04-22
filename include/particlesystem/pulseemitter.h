#pragma once  

#include "emitter.h"  // Must inherit from this  
#include <vector>  
#include <glm/glm.hpp>  

class PulseEmitter : public Emitter {  
public:  
   PulseEmitter(glm::vec2 _position, float _radius, float _delay, int _amount)  
       : Emitter(_position, _radius, _delay, {1, 1, 1, 1})  // using white as default color  
       , amount(_amount)  
       , accumulatedTime(0.0f)  
       , emittedThisCycle(false) {}  

   bool update(float dt) override;  
   void createNewParticle(std::vector<Particle>& particles) override;  

private:  
   int amount;  
   float accumulatedTime;  
   bool emittedThisCycle;  
};
