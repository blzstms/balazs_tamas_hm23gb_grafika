#include "ball.h"

#include <GL/gl.h>

#include <math.h>


void init_ball(Ball * ball, float x, float y)
{
    ball->x = x;
    ball->y = y;
    ball->radius = 50;
    ball->speed_x = 500;
    ball->speed_y = 500;
    ball->rotation = 0;
    ball-> rotation_speed = 1;
}

void update_ball(Ball * ball, double time)
{
    ball->x += ball->speed_x * time;
    ball->y += ball->speed_y * time;
    ball->rotation = ball->rotation * ball->rotation_speed * time;
    if (ball->rotation > 2*atan(1)*4){
        ball->rotation = 0;
    }
    if(ball ->rotation < 0){
        ball->rotation = 2*atan(1)*4;
    }




}

void render_ball(Ball * ball)
{
    double angle;
    double x;
    double y;
    int i = 0;

    glPushMatrix();
    glTranslatef(ball->x, ball->y, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 0.9, 0.8);
    glVertex2f(0, 0);
    angle = 0;
    while (angle < 2.0 * (atan(1)*4) + 1) {
        x = cos(angle + ball->rotation) * ball->radius;
        y = sin(angle + ball->rotation) * ball->radius;
        glColor3ub(0, 0, 0);
        i+=255*0.2/(2.0 * (atan(1)*4) + 1);
        glVertex2f(x, y);
        angle += 0.2;
    }
    glEnd();
    glPopMatrix();
}

