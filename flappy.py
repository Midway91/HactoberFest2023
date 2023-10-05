import pygame
import sys

# Initialize Pygame
pygame.init()

# Constants
SCREEN_WIDTH = 400
SCREEN_HEIGHT = 600
GRAVITY = 0.25
BIRD_JUMP = -4.5
PIPE_WIDTH = 50
PIPE_SPACING = 150
PIPE_VELOCITY = -4

# Colors
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)

# Set up the screen
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pygame.display.set_caption('Flappy Bird')

# Load assets
bird_image = pygame.image.load('bird.png')
background_image = pygame.image.load('background.png')
pipe_image = pygame.image.load('pipe.png')

bird_rect = bird_image.get_rect()
bird_rect.center = (50, SCREEN_HEIGHT // 2)

pipes = []

# Game loop
while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_SPACE:
                bird_velocity = BIRD_JUMP

    # Update bird position
    bird_velocity += GRAVITY
    bird_rect.y += bird_velocity

    # Update pipe positions
    for pipe in pipes:
        pipe['x'] += PIPE_VELOCITY

    # Generate new pipes
    if len(pipes) == 0 or pipes[-1]['x'] <= SCREEN_WIDTH - PIPE_SPACING:
        new_pipe = {'x': SCREEN_WIDTH, 'y': PIPE_HEIGHT}
        pipes.append(new_pipe)

    # Remove off-screen pipes
    pipes = [pipe for pipe in pipes if pipe['x'] > -PIPE_WIDTH]

    # Draw everything
    screen.blit(background_image, (0, 0))
    screen.blit(bird_image, bird_rect)

    for pipe in pipes:
        screen.blit(pipe_image, (pipe['x'], pipe['y']))
        screen.blit(pipe_image, (pipe['x'], pipe['y'] - PIPE_SPACING - pipe_image.get_height()))

    pygame.display.update()
