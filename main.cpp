#include <iostream>
#include <SFML/Graphics.hpp>
#include "Scenes/MainScene.h"
#include "Core/ResourceManager/ResourceManager.h"
#include "Core/ResourceManager/FontResource.h"

using namespace sf;
using namespace std;

int W = 1200;
int H = 800;

static ResourceManager* resourceManager;

int main() {
    srand(time(0));

    RenderWindow app(VideoMode(W, H), "Match 2048");
    app.setFramerateLimit(60);

    MainScene scene(app);
    resourceManager = new ResourceManager(nullptr);
    resourceManager->Add<FontResource>("arial.ttf", "./", "font");

    scene.Init(resourceManager);

    while (app.isOpen()) {
        Event event;
        while (app.pollEvent(event)) {
            if (event.type == Event::Closed)
                app.close();
        }
        app.clear();

        scene.Update();
        scene.Draw();

        app.display();
        sleep(sf::milliseconds(10));
    }

    return 0;
}
