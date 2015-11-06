//
// Created by Raul Villanueva on 11/6/15.
//

#include "Game.h"



Game::Game() {
    cout << "Commencing Checkers Game!" << endl;
}

void Game::run() {
    while (true) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
}

void Game::update() {
}

void Game::render() {
}
