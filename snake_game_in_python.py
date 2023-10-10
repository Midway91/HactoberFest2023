import turtle
import time
import random

wn=turtle.Screen()
wn.title("SHAKY THE SNAKE")
wn.bgcolor=('white')
wn.setup(width=600,height=600)
#wn.tracer(0)
delay = 0.1
score = 0
high = 0
#head of the snake
head=turtle.Turtle()
head.shape('circle')
head.color('black')
head.goto(0,0)
head.direction="Stop"

#food
food=turtle.Turtle()
food.color("yellow")
food.shape("circle")
food.penup()
food.goto(0,100)


pen=turtle.Turtle()
pen.speed(0)
pen.shape("square")
pen.color("black")
pen.penup()
pen.hideturtle()
pen.goto(0,250)
pen.write("score:0")


#key directions
def up():
    if head.direction !="down":
       head.direction ="up"

def down():
    if head.direction !="up":
       head.direction ="down"       

def right():
    if head.direction !="left":
       head.direction ="right"

def left():
    if head.direction !="right":
       head.direction ="left"   

def move():
    if head.direction =="up" :
        y=head.ycor()
        head.sety(y+20)

    if head.direction =="down" :
        y=head.ycor()
        head.sety(y-20)
  
    if head.direction =="right" :
        x=head.xcor()
        head.setx(x+20)

    if head.direction =="left" :
        x=head.xcor()
        head.setx(x-20)    
#accepting  key presses
wn.listen()
wn.onkeypress(up,"Up")
wn.onkeypress(down,"Down")
wn.onkeypress(right,"Right")
wn.onkeypress(left,"Left")

segments=[]

#game play

while True:
    wn.update()
    if head.xcor()>290 or head.xcor()<-290 or head.ycor()>290 or head.ycor()<-290 :
        time.sleep(1)
        head.goto(0,0)
        head.direction="Stop"
        for segment in segments:
            segment.goto(1000,1000)
        segments.clear()
        score =0
        delay=0.1
        pen.clear()
        pen.write("Score:{} High Score :{}".format(score,high),align="center")


    if head.distance(food)<20:
        x= random.randint(-270,270)
        y= random.randint(-270,270)
        food.goto(x,y)

     #adding segment
        new_segment = turtle.Turtle()
        new_segment.speed(0)
        new_segment.shape("circle")
        new_segment.color("red") # tail colour
        new_segment.penup()
        segments.append(new_segment)
        delay -= 0.001
        score += 10
        if score > high:
            high = score
        pen.clear()
        pen.write("Score:{} High Score :{}".format(score,high),align="center")


        # collisions
    for index in range (len(segments)-1,0,-1):
        x=segments[index-1].xcor()
        y=segments[index-1].ycor()
        segments[index].goto(x,y)
    if len(segments)>0:
        x=head.xcor()
        y=head.ycor()
        segments[0].goto(x,y)
    move()
    for segment in segments:
        if segment.distance(head)<10:
            time.sleep(1)
            head.goto(0,0)
            head.direction="Stop"
            for segment in segments :
                segment.goto(1000,1000)
            segments.clear()


            score=0
            delay=0.1
            pen.clear()
            pen.write("Score:{} High Score :{}".format(score,high),align="center")
    time.sleep(delay)

            
