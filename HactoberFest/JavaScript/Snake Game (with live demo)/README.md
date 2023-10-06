# Snake Game

[Demo link](https://sanjeevani-25.github.io/snake-game/)

## Introduction
This repository contains the classic Snake Game built using vanilla JavaScript. Players control a snake with the goal of eating food items, growing longer with each consumed item. The game ends when the snake runs into the wall or itself.

## Features

- **Play Area**: A grid-based board for the snake's movement and food placement.
  
- **Scoring System**:
  - **Current Score**: Increases by one for every food item the snake consumes.
  - **High Score**: Tracks the highest score achieved and displays it to the player. Stored in local storage for persistence across sessions.
  
- **Controls**:
  - **Arrow Keys**: Use the arrow keys to control the direction of the snake.

- **Dynamic Snake Growth**: The snake grows longer with every food item consumed.

- **Random Food Placement**: Food items are randomly placed within the play area.

- **Game Over Logic**:
  - Wall Collision: The game ends if the snake collides with the wall.
  - Self Collision: The game ends if the snake runs into its own body.

- **Game Speed**: Set at a constant speed for consistent gameplay. Can be adjusted for a more challenging or relaxed experience.

## How to Play

1. Use the arrow keys or on-screen buttons to navigate.
2. Eat the food items to grow longer and increase your score.
3. Avoid colliding with the wall and yourself.
4. Aim to achieve a new high score!
