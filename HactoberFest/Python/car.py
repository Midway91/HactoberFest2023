import pygame
import sys

# Initialize Pygame
pygame.init()

# Constants
SCREEN_WIDTH = 800
SCREEN_HEIGHT = 600
CAR_WIDTH = 50
CAR_HEIGHT = 100
CAR_VELOCITY = 5
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)

# Set up the screen
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pygame.display.set_caption('Car Racing Game')

# Load car image
car_image = pygame.image.load('car.png')
car_image = pygame.transform.scale(car_image, (CAR_WIDTH, CAR_HEIGHT))
car_rect = car_image.get_rect()
car_rect.center = (SCREEN_WIDTH // 2, SCREEN_HEIGHT - CAR_HEIGHT)

# Game loop
while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

    keys = pygame.key.get_pressed()
    if keys[pygame.K_LEFT] and car_rect.left > 0:
        car_rect.x -= CAR_VELOCITY
    if keys[pygame.K_RIGHT] and car_rect.right < SCREEN_WIDTH:
        car_rect.x += CAR_VELOCITY

    # Update the screen
    screen.fill(BLACK)
    screen.blit(car_image, car_rect)
    pygame.display.update()
