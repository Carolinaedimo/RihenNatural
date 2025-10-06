#pragma once 
#include "Core/Application.h" 
#include "Core/Math/Random.h" 
#include "Core/Math/Vector2.h" 
 
namespace nkentseu { 
    class DemoAffiche : public Application { 
        
    private: 
    math::Vector2 position;
       
    struct rectangle {
        math::Vector2 position;
        math::Vector2 size;
        graphics::Color color;
        int idx ;
    };

    std::vector<rectangle> tab;
         
    public: 
        DemoAffiche(const ApplicationProperties& props); 
         
    protected: 
        void Setup() override; 
        void Update(float deltaTime) override; 
        void Draw() override; 
    }; 
}
