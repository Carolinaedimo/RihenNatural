#include "Count.h"
#include "Core/ApplicationProperties.h"
#include "Core/Application.h"

namespace nkentseu {

     Count::Count(const ApplicationProperties& props)  
     : Application(props) {} 

    void Count::Setup() {
        
        position.x = GetWindowWidth()/2.0f;
        position.y = 100/2.0f;
    } 

    void Count::Update(float deltaTime) {
        float hauteur = GetWindowHeight();
        position.y += gravity * deltaTime;
        if (position.y <= hauteur - r ) {
            position.y += friction * deltaTime;
        }
    } 

    void Count::Draw() {
        Circle(position, 100);

    }
}