#include "DemoRandomWalk.h" 
#include "Core/Events/Mouse.h"
 
namespace nkentseu { 
    DemoRandomWalk::DemoRandomWalk(const ApplicationProperties& props)  
        : Application(props) {} 
     
    void DemoRandomWalk::Setup() { 
        position = math::Vector2(GetWindowWidth() / 2.0f, GetWindowHeight() / 2.0f); 
        Background(graphics::Color::Black); 
    } 
     
    void DemoRandomWalk::Update(float deltaTime) { 
        // La logique de mise à jour sera dans Draw pour cet exemple simple 

    } 
     
    void DemoRandomWalk::Draw() { 
        // Dessiner le marcheur 
        Fill(graphics::Color::Magenta); 
        NoStroke(); 
        Circle(position, 4.0f); 

        
         //Exercice 1 : déplacements diagonaux
        // Prendre un pas aléatoire 
    //     int choice = math::Random::Range(0, 7); 
         
    //     if (choice == 0) { 
    //         position.x++; 
    //     } else if (choice == 1) { 
    //         position.x--; 
    //     } else if (choice == 2) { 
    //         position.y++; 
    //    } else if (choice == 3) { 
    //         position.y--; 
    //     } else if (choice == 4) { 
    //         position.x++; position.y--; 
    //     } else if (choice == 5) { 
    //         position.x--; position.y--; 
    //     } else if (choice == 6) { 
    //         position.x++; position.y++; 
    //     } else { 
    //         position.x++;  position.y++; 
    //     } 

         //Exercice 2 : marcheur qui a tendance à se déplacer vers la position de la souris
        float r = math::Random::Value(); 

        if (r < 0.5f ) {
            
           float x, y;
           math::Vector2 pos = events::Mouse::GetPosition();
           if (pos.x < x) {
             position.x++;
           } else if (pos.x > x) {
               position.x--;
           } else if (pos.y < y) {
              position.y++;
           } else if (pos.y> y) {
              position.y--;
           }

        } else {
     
        int choix = math::Random::Range(0, 7); 
         
        if (choix == 0) { 
            position.x++; 
        } else if (choix == 1) { 
            position.x--; 
        } else if (choix == 2) { 
            position.y++; 
        } else if (choix == 3) { 
            position.y--; 
        } else if (choix == 4) { 
            position.x++; 
            position.y--; 
        } else if (choix == 5) { 
            position.x--; 
            position.y--; 
        } else if (choix == 6) { 
            position.x++; 
            position.y++; 
        } else { 
            position.x++;  
            position.y++; 
        } 

    }
         
        // Garder dans les limites de l'écran 
        position.x = std::max(0.0f, std::min(position.x, (float)GetWindowWidth())); 
        position.y = std::max(0.0f, std::min(position.y, (float)GetWindowHeight())); 
    } 
} 
 
// Fonction de création 
nkentseu::Application* CreateRandomWalkDemo(const nkentseu::ApplicationProperties& props) { 
    return new nkentseu::DemoRandomWalk(props); 

} 
