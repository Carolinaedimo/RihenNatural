#pragma once
#include "Core/Application.h"

namespace nkentseu {
   class Count : public Application 
   {

    public :
       Count (const ApplicationProperties& props);

       math::Vector2 position;
       float gravity = 9.81 ;
       float r = 100;
       float friction = 50;

    protected :
       void Setup() override;
       void Update(float deltaTime) override;
       void Draw() override;

    };
}
