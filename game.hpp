#pragma once

#include <utility>
#include <tuple>
#include <memory>
#include <chrono>
#include <thread>

#include "window.hpp"
#include "snake.hpp"
namespace snake_game {

constexpr int GAME_HEIGHT = 24;
constexpr int GAME_WIDTH = 80;


struct game_state {
    int score = 0;
};

struct game {

    curses::window main_win = curses::window(GAME_HEIGHT, GAME_WIDTH,10,10);
    bool is_running = true;
    coords last_direction = direction::WEST;
    snake_game::snake snake = snake_game::snake( {10,10}, {10,11} );
    snake_game::food food = snake_game::food({0,0});
    game_state game_state;

	auto render_snake() -> void;
    auto end_game() -> void;
    auto game_loop() -> void;
};

} //namespace snake