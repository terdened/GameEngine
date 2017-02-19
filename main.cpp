#include <iostream>
#include <SFML/Graphics.hpp>
#include "Views/FieldView.h"
#include "Scenes/MainScene.h"
#include "ResourceManagers/MainSceneResourceManager.h"
#include "Core/ResourceManager/ResourceManager.h"
#include "Core/ResourceManager/FontResource.h"

using namespace sf;
using namespace std;
using namespace Match2048;

int W = 1200;
int H = 800;

static ResourceManager<FontResource> resourceManager();

int main() {
    srand(time(0));

    RenderWindow app(VideoMode(W, H), "Match 2048");
    app.setFramerateLimit(60);

    MainScene scene(app);
    resourceManager().Add("arial.ttf");

    scene.Init();

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
