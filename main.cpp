#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <list>
#include "Views/FieldView.h"
#include "Views/BaseView.h"
#include "Models/FieldModel.h"

using namespace sf;
using namespace std;
using namespace Match2048;

int W = 1200;
int H = 800;

int main() {
    srand(time(0));

    RenderWindow app(VideoMode(W, H), "Match 2048");
    app.setFramerateLimit(60);

    FieldModel fieldModel(5,7);
    FieldView fieldView(fieldModel);

    while (app.isOpen()) {
        Event event;
        while (app.pollEvent(event)) {
            if (event.type == Event::Closed)
                app.close();
        }

        fieldView.Draw(app);
        app.display();
    }

    return 0;
}
