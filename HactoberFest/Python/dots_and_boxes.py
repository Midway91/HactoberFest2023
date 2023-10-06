#5x5 grid
import pygame
pygame.init()
win = pygame.display.set_mode([700,700])
paths = []
paths_2 = []
total_paths = []
boxes = []
boxes_2 = []
curturn = 1 #players 1 and 2
def isbox(paths, x, y):
    return [(x,y),(x+1,y)] in paths and [(x,y),(x,y+1)] in paths and [(x,y+1),(x+1,y+1)] in paths and [(x+1,y),(x+1,y+1)] in paths

run = True
while run:
    for e in pygame.event.get():
        if e.type == pygame.QUIT:
            run = False
    madebox = False
    start, end = sorted([eval(x) for x in input("Player {}: Connect two points (eg. '(1,2) (1,3)')".format(curturn)).split()])
    if not [start, end] in total_paths and abs(abs(start[0]-end[0])+abs(start[1]-end[1])) == 1 and 0 <= start[0] <= 4 and 0 <= start[1] <= 4 and 0 <= end[0] <= 4 and 0 <= end[1] <= 4:
        if curturn == 1:
            paths.append([start, end])
        else:
            paths_2.append([start, end])
        total_paths.append([start, end])
        x, y = start
        for z in range(-1,2):
            for zz in range(-1,2):
                if isbox(total_paths, x+z, y+zz):
                    madebox = True
                    if curturn == 1:
                        boxes.append((x+z, y+zz))
                    else:
                        boxes_2.append((x+z, y+zz))

    else:
        print("Invaild Move")
        madebox = True
    
    if not madebox:
        curturn = 3-curturn
    
    win.fill((255,255,255))
    for idx1 in range(5):
        for idx2 in range(5):
            pygame.draw.circle(win, (0,0,0), (100+idx1*100, 100+idx2*100), 10)
    for stuff in paths:
        pygame.draw.line(win, (255,0,0), (stuff[0][0]*100+100, stuff[0][1]*100+100), (stuff[1][0]*100+100, stuff[1][1]*100+100))
    for stuff in paths_2:
        pygame.draw.line(win, (0,0,255), (stuff[0][0]*100+100, stuff[0][1]*100+100), (stuff[1][0]*100+100, stuff[1][1]*100+100))
    for stuff in boxes:
        pygame.draw.rect(win, (200,0,0), pygame.Rect(100+100*stuff[0], 100+100*stuff[1], 100, 100))
    for stuff in boxes_2:
        pygame.draw.rect(win, (0,0,200), pygame.Rect(100+100*stuff[0], 100+100*stuff[1], 100, 100))
    
    pygame.display.flip()
