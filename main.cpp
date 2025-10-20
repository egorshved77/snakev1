#include "GameController.h"
#include "GameModel.h"
#include "GameView.h"
#include "MenuView.h"

int main() {
    GameModel model(60, 40, GameModel::EASY);
    sf::RenderWindow window(sf::VideoMode(model.getWidth()*20, model.getHeight()*20), "Snake",sf::Style::Close | sf::Style::Titlebar);
    GameView gameView(model);
    MenuView menuView(window);
    GameController controller(model, gameView, menuView,window);
    controller.run();
    return 0;
}
