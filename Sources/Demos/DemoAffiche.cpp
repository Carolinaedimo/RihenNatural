#include "DemoAffiche.h"

//Exercice 3 :  dessiner un histogramme des positions visitées par le marcheur.
namespace nkentseu { 
    DemoAffiche::DemoAffiche(const ApplicationProperties& props)  
        : Application(props) {} 
     
    void DemoAffiche::Setup() { 
        Background(graphics::Color::Black); 

        for (int i = 0; i < 7; i++){
            rectangle r;
            r.color = graphics::Color::Magenta;
            r.position = math::Vector2( i* float(GetWindowWidth())/7, float(GetWindowHeight()));
            r.size = math::Vector2( float(GetWindowWidth())/7, 0);
            r.idx = i;

            tab.push_back(r);
        }

    } 
     
    void DemoAffiche::Update(float deltaTime) {  
        DemoAffiche::Draw();
    } 
     
    void DemoAffiche::Draw() { 

        for (auto& rectangle : tab ) {

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

            if ( choix == rectangle.idx) {
                rectangle.size.y--;
            }
            Rect (rectangle.position, rectangle.size);
            Fill ( rectangle.color);
        }
        
         
        // Garder dans les limites de l'écran 
        position.x = std::max(0.0f, std::min(position.x, (float)GetWindowWidth())); 
        position.y = std::max(0.0f, std::min(position.y, (float)GetWindowHeight())); 
    } 
} 

 
// Fonction de création 
nkentseu::Application* CreateAfficheDemo(const nkentseu::ApplicationProperties& props) { 
    return new nkentseu::DemoAffiche(props); 

} 
