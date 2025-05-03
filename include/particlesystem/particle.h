#pragma once  
#include <glm/glm.hpp>  

// Represents a single particle in the particle system  
class Particle {  
public:  
   // Constructor to initialize a particle with position, velocity, radius, and color  
   Particle(glm::vec2 _position, glm::vec2 _velocity, float _radius, glm::vec4 _color)  
       : position(_position), velocity(_velocity), color(_color), radius(_radius) {}  

   // Updates the particle's position and lifetime based on the elapsed time (dt)  
   void update(float dt) {  
       lifetime += dt; // Increment the lifetime of the particle  
       position += velocity * dt; // Update the position based on velocity and time  
   }  

   // Checks if the particle is still alive  
   bool alive() {  
       // If the lifetime exceeds 5 seconds, the particle is no longer alive  
       if (lifetime >= 5) {  
           return false;  
       }  
       // If the particle moves outside the screen bounds (-1 to 1), it is no longer alive  
       else if (position.x > 1 || position.x < -1 || position.y > 1 || position.y < -1)  
           return false;  

       // Otherwise, the particle is still alive  
       return true;  
   }  

   // Position of the particle in 2D space  
   glm::vec2 position;  
   // Velocity of the particle in 2D space  
   glm::vec2 velocity;  
   // Color of the particle (RGBA)  
   glm::vec4 color;  

   // Lifetime of the particle in seconds  
   float lifetime = 0;  
   // Radius of the particle  
   float radius;  
};
