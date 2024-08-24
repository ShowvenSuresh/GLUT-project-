#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <string>
#include <ctime>
#include <iostream>
#define pi 3.142
double a=0,b=0,c=0,d=0;
int sceneTracker=0;// to track the scene

double moveX=0,moveY=0;
double startX=0,startY=0,endX=0,endY=0;
double locationX = 0,locationY = 0,animationTime;
double distanceX,distanceY;
int scene = 1,roundCount=0;
using namespace std;

double angle = 187.0,speed = 0.00007;
void drawCircle(double x,double y, double radius)//draws circle for the clouds
{
    glBegin(GL_POLYGON);
        for(int i=0;i<360;i++)
        {
            double rad=i*pi/180;
            glVertex2d(x+radius*cos(rad),y+radius*sin(rad));
        }
    glEnd();
}

void Clock(float x, float y, const char* timeText) {
    // Draw clock circle
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i++) {
        float rad = i * 3.14159 / 180.0;
        glVertex2f(x + 10 * cos(rad), y + 10 * sin(rad));
    }
    glEnd();

    // Fill clock inside with cyan color
    glColor3f(0.0, 1.0, 1.0); // Cyan color for the filled circle
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float rad = i * 3.14159 / 180.0;
        glVertex2f(x + 9.5 * cos(rad), y + 9.5 * sin(rad)); // Decrease the radius to fit inside the clock circle
    }
    glEnd();

    // Draw clock hands
    glColor3f(0.0, 0.0, 0.0); // Black color for the clock hands
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2f(x, y);
    glVertex2f(x + 8 * cos(3.14159 / 2 - 3.14159 / 6), y + 8 * sin(3.14159 / 2 - 3.14159 / 6)); // Hour hand
    glVertex2f(x, y);
    glVertex2f(x + 8 * cos(3.14159 / 2 + 3.14159 / 6), y + 8 * sin(3.14159 / 2 + 3.14159 / 6)); // Minute hand
    glEnd();

    // Draw time text
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2f(x - 10, y + 5);
    for (int i = 0; i < strlen(timeText); i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, timeText[i]);
    }
}

void Window(double x, double y)
{
    // Set window color
    glColor3f(0.0, 1.0, 1.0); // Light gray color for the window

    // Draw window frame
    glBegin(GL_QUADS);
    glVertex2d(x, y);          // Bottom-left corner
    glVertex2d(x + 10, y);     // Bottom-right corner
    glVertex2d(x + 10, y + 60);// Top-right corner
    glVertex2d(x, y + 60);     // Top-left corner
    glEnd();

    // Draw window panes
    glColor3f(0.0, 0.0, 0.0); // Blue color for the window panes

    glBegin(GL_LINES);
    glVertex2d(x + 5, y);          // Vertical line for window pane
    glVertex2d(x + 5, y + 60);

    glVertex2d(x, y + 30);          // Horizontal line for window pane
    glVertex2d(x + 10, y + 30);
    glEnd();
}

void personA3(double x, double y)
{
    glColor3f(0.0, 0.0, 0.0);

     // Broken objects
    glColor3f(0.3, 0.3, 0.3); // Dark gray for broken objects

    // Draw broken object 1
    glBegin(GL_LINES);
    glVertex2d(x + 10, y + 380); // Start point
    glVertex2d(x + 15, y + 390); // End point
    glEnd();

    // Draw broken object 2
    glBegin(GL_LINES);
    glVertex2d(x + 15, y + 380); // Start point
    glVertex2d(x + 10, y + 390); // End point
    glEnd();
    //feets with shoes
    glBegin(GL_QUADS);
    glVertex2d(x + 0, y + 350);
    glVertex2d(x + 5, y + 350);
    glVertex2d(x + 5, y + 355);
    glVertex2d(x + 0, y + 355);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2d(x + 15, y + 350);
    glVertex2d(x + 20, y + 350);
    glVertex2d(x + 20, y + 355);
    glVertex2d(x + 15, y + 355);
    glEnd();

    //leges with shoes
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2d(x + 0, y + 355);
    glVertex2d(x + 20, y + 355);
    glVertex2d(x + 20, y + 375);
    glVertex2d(x + 0, y + 375);
    glEnd();

    glColor3f(0.2, 0.3, 0.6);
    glBegin(GL_POLYGON);
    glVertex2d(x + 5, y + 355);
    glVertex2d(x + 10, y + 365);
    glVertex2d(x + 15, y + 355);
    glEnd();

    //shirt
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2d(x + 0, y + 375);
    glVertex2d(x + 20, y + 375);
    glVertex2d(x + 25, y + 395);
    glVertex2d(x + 10, y + 400);
    glVertex2d(x + 5, y + 395);
    glEnd();

    //Sleaves
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2d(x + 25, y + 395);
    glVertex2d(x + 22, y + 385);
    glVertex2d(x + 25, y + 375);
    glVertex2d(x + 28, y + 385);
    glEnd();

    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2d(x + 15, y + 395);
    glVertex2d(x + 12, y + 385);
    glVertex2d(x + 15, y + 375);
    glVertex2d(x + 18, y + 385);
    glEnd();
    //arms
    glColor3f(0.9, 0.7, 0.5);
    glBegin(GL_POLYGON);
    glVertex2d(x + 28, y + 385);
    glVertex2d(x + 26, y + 380);
    glVertex2d(x + 28, y + 375);
    glVertex2d(x + 30, y + 380);
    glEnd();

    glColor3f(0.9, 0.7, 0.5);
    glBegin(GL_POLYGON);
    glVertex2d(x + 12, y + 385);
    glVertex2d(x + 10, y + 380);
    glVertex2d(x + 12, y + 375);
    glVertex2d(x + 14, y + 380);
    glEnd();

    //face
    glColor3f(0.9, 0.7, 0.5);
    drawCircle(x + 10, y + 409, 15);
    glColor3f(0.0, 0.0, 0.0);

    glPointSize(5.0);
    glBegin(GL_POINTS); //eyes
    glVertex2d(x + 3, y + 414);
    glVertex2d(x + 17, y + 414);
    glEnd();

    glBegin(GL_LINE_STRIP); //mouth
    for (int i = 0; i < 180; i++)
    {
        double theta = double(i) * pi / 180.0;
        glVertex2d(x + 10 + 5 * cos(theta), y + 400 + 5 * sin(theta)); // Adjusted for position and size
    }
    glEnd();

    //hair
    glLineWidth(7.0);
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < 180; i++)
    {
        double theta = double(i) * pi / 180.0;
        glVertex2d(x + 10 + 15 * cos(theta), y + 409 + 15 * sin(theta)); // Adjusted for position and size
    }
    glEnd();

    if(x==100)
    {
        // Draw the window on the left side
        Window(x - 30, y + 375); // Adjust the position as needed
    }

    // Draw acne on the middle boy's face
    if (x == 250)
    {
        glColor3f(1.0, 0.0, 0.0); // Set color to red for acne
        drawCircle(x + 10, y + 409, 1);
        drawCircle(x + 15, y + 405, 1);
        drawCircle(x + 20, y + 412, 1);
        drawCircle(x + 01, y + 404, 1);
        drawCircle(x + 05, y + 402, 1);

        double blushX = x + 3;
        double blushY = y + 410;

        glColor3f(1.0, 0.5, 0.5);
        glBegin(GL_LINES);
        for (int i = 0; i < 5; i++) {
            glVertex2d(blushX, blushY);
            glVertex2d(blushX + 1, blushY - 5);
            blushX += 3;
        }
    }
    if (x == 400)
    {
        glColor3f(0.9, 0.7, 0.5);
        drawCircle(x + 25, y + 409, 5);

        glColor3f(1.0, 0.0, 0.0);
        drawCircle(x + 10, y + 409, 1);
        drawCircle(x + 15, y + 405, 1);
        drawCircle(x + 20, y + 412, 1);
        drawCircle(x + 01, y + 404, 1);
        drawCircle(x + 05, y + 402, 1);

        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_POLYGON);
        glVertex2d(x + 30, y + 415);
        glVertex2d(x + 32, y + 420);
        glVertex2d(x + 32, y + 430);
        glVertex2d(x + 30, y + 435);
        glEnd();

        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_POLYGON);
        glVertex2d(x + 30, y + 415);
        glVertex2d(x + 28, y + 420);
        glVertex2d(x + 28, y + 430);
        glVertex2d(x + 30, y + 435);
        glEnd();

        glColor3f(0.0, 0.0, 0.0);
        glRasterPos2d(x + 27, y + 424);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'M');
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'e');
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'd');
    }
}

void Table(double x, double y)
{
    // Draw table legs
    glColor3f(0.6, 0.3, 0.0); // Set color to brown
    glBegin(GL_QUADS);
    glVertex2f(x , y);
    glVertex2f(x + 20, y);
    glVertex2f(x + 20, y - 40);
    glVertex2f(x , y - 40);

    glVertex2f(x + 20, y);
    glVertex2f(x + 40, y);
    glVertex2f(x + 40, y - 40);
    glVertex2f(x + 20, y - 40);
    glEnd();

    // Draw table surface
    glColor3f(0.6, 0.3, 0.0); // Set color to brown
    glBegin(GL_QUADS);
    glVertex2f(x - 5, y);
    glVertex2f(x + 45, y);
    glVertex2f(x + 45, y - 5);
    glVertex2f(x - 5, y - 5);
    glEnd();
}

void TestPaper(double x, double y)
{
    // Set white color for the test paper
    glColor3f(1.0, 1.0, 1.0);

    // Draw test paper
    glBegin(GL_QUADS);
    glVertex2f(x + 25, y + 15);
    glVertex2f(x + 35, y + 15);
    glVertex2f(x + 35, y + 35);
    glVertex2f(x + 25, y + 35);
    glEnd();

    // Set black color for the text
    glColor3f(0.0, 0.0, 0.0);

    // Draw "39%" on the test paper
    glRasterPos2f(x + 27, y + 27); // Set position for the text
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '3');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '9');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '%');
}

void Strings()
{
    // Draw the strings
    glColor3f(0.0, 0.0, 0.0); // Set color to black
    glBegin(GL_LINES);
    glVertex2f(200, 0); // Position of the first string start
    glVertex2f(200, 500); // Position of the first string end
    glVertex2f(350, 0); // Position of the second string start
    glVertex2f(350, 500); // Position of the second string end
    glEnd();
}

void TextUnderTableLeg(const char* text, float x, float y, int lineLength)
{
    // Set the color for the text
    glColor3f(0.0, 0.0, 0.0); // Black color

    // Set the initial position for the text, shifting it to the left
    x -= 40; // Adjust the horizontal position to move the text to the left
    glRasterPos2f(x, y);

    int lineCount = 0; // Track the number of lines rendered
    while (*text)
    {
        if (*text == '\n') // If newline character, move to next line
        {
            // Move to the next line
            y -= 30; // Adjust the vertical spacing between lines
            glRasterPos2f(x, y);

            // Reset line length counter
            lineCount = 0;
        }
        else
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *text); // Render the character
            lineCount++;

            if (lineCount >= lineLength) // If reached maximum line length, move to next line
            {
                // Move to the next line
                y -= 30; // Adjust the vertical spacing between lines
                glRasterPos2f(x, y);

                // Reset line length counter
                lineCount = 0;
            }
        }
        text++;
    }
}

void IndoorEnvironment()
{
    // Set background color to cyan for indoor environment
    glColor3f(0.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glVertex2f(500, 0); // Extend to cover the entire width of the window
    glVertex2f(500, 500); // Extend to cover the entire height of the window
    glVertex2f(0, 500);
    glEnd();

    // Draw floor
    glColor3f(0.5, 0.5, 0.5); // Gray color for the floor
    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glVertex2f(500, 0); // Extend to cover the entire width of the window
    glVertex2f(400, 100); // Adjusted vertices for perspective effect
    glVertex2f(100, 100); // Adjusted vertices for perspective effect
    glEnd();

    // Draw ceiling
    glColor3f(0.5, 0.5, 0.5); // Gray color for the ceiling
    glBegin(GL_QUADS);
    glVertex2f(0, 500);
    glVertex2f(500, 500); // Extend to cover the entire width of the window
    glVertex2f(400, 400); // Adjusted vertices for perspective effect
    glVertex2f(100, 400); // Adjusted vertices for perspective effect
    glEnd();

    // Draw walls
    glColor3f(0.8, 0.8, 0.8); // Light gray color for the walls
    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glVertex2f(100, 100); // Adjusted vertices for perspective effect
    glVertex2f(100, 400); // Adjusted vertices for perspective effect
    glVertex2f(0, 500);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(500, 0);
    glVertex2f(400, 100); // Adjusted vertices for perspective effect
    glVertex2f(400, 400); // Adjusted vertices for perspective effect
    glVertex2f(500, 500);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(100, 100); // Adjusted vertices for perspective effect
    glVertex2f(400, 100); // Adjusted vertices for perspective effect
    glVertex2f(400, 400); // Adjusted vertices for perspective effect
    glVertex2f(100, 400); // Adjusted vertices for perspective effect
    glEnd();
}

void tree(double x,double y,double size){
    //tree
    glColor3f(0.4,0.1,0.1);//stub
    glBegin(GL_POLYGON);
        glVertex2d(x,y);
        glVertex2d(x+5*size,y);
        glVertex2d(x+5*size,y+10*size);
        glVertex2d(x,y+10*size);
    glEnd();
    //leaves
    glColor3f(0.1,0.5,0.2);
    glBegin(GL_POLYGON);
        glVertex2d(x-5*size,y+10*size);
        glVertex2d(x+2.5*size,y+15*size);
        glVertex2d(x+10*size,y+10*size);
    glEnd();

    glColor3f(0.1,0.5,0.2);
    glBegin(GL_POLYGON);
        glVertex2d(x-5*size,y+13*size);
        glVertex2d(x+2.5*size,y+20*size);
        glVertex2d(x+10*size,y+13*size);
    glEnd();
}

void cloud(double x,double y,double size,double red,double green,double blue){
    glColor3f(red,green,blue);
    drawCircle(x,y,size);
    drawCircle(x+15,y+25,size);
    drawCircle(x+15,y,size);
    drawCircle(x+25,y+25,size);
}

void dirtRoad6(){
    glColor3f(0.7,0.3,0);
    glBegin(GL_POLYGON);
        glVertex2d(0,0);
        glVertex2d(500,0);
        glVertex2d(500,25);
        glVertex2d(0,25);
    glEnd();

    glColor3f(0.2,0.4,0.2);
    glLineWidth(7.0);
    glBegin(GL_LINE_STRIP);
        glVertex2d(0,25);
        glVertex2d(500,25);
    glEnd();

    glColor3f(0.7,0.3,0);
    glBegin(GL_POLYGON);
        glVertex2d(235,25);
        glVertex2d(265,25);
        glVertex2d(265,40);
        glVertex2d(235,40);
    glEnd();

    glColor3f(0.2,0.4,0.2);
    glLineWidth(7.0);
    glBegin(GL_LINE_STRIP);
        glVertex2d(265,25);
        glVertex2d(265,40);
        glVertex2d(235,40);
        glVertex2d(235,25);
    glEnd();
}

void hills6(){

     glBegin(GL_POLYGON);
        glColor3f(0.5,0,0.3);
        glVertex2d(-50,150);
        glColor3f(1.0,1.0,1.0);
        glVertex2d(80,350);
        glColor3f(0.5,0,0.3);
        glVertex2d(175,150);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.5,0,0.3);
        glVertex2d(150,150);
        glColor3f(1.0,1.0,1.0);
        glVertex2d(320,350);
        glColor3f(0.5,0,0.3);
        glVertex2d(500,150);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.5,0,0.3);
        glVertex2d(0,150);
        glColor3f(1.0,1.0,1.0);
        glVertex2d(220,400);
        glColor3f(0.5,0,0.3);
        glVertex2d(350,150);
    glEnd();

}

void ground6(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(0, 255, 0);
    glBegin(GL_POLYGON);
        glVertex2d(0, 0);
        glVertex2d(500, 0);
        glVertex2d(500, 150);
        glVertex2d(0, 150);
    glEnd();
    dirtRoad6();
}

void sun(double x, double y, double radius, int numRays) {
    // sun cycle
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; ++i) {
        double angle = i * 3.14159 / 180;
        double sunX = x + radius * cos(angle);
        double sunY = y + radius * sin(angle);
        glVertex2f(sunX, sunY);
    }
    glEnd();

    // ray
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_LINES);
    for (int i = 0; i < numRays; ++i) {
        double angle = i * 360.0 / numRays;
        double rayX = x + radius * cos(angle * 3.14159 / 180);
        double rayY = y + radius * sin(angle * 3.14159 / 180);
        double endX = rayX + radius * 2 * cos(angle * 3.14159 / 180);
        double endY = rayY + radius * 2 * sin(angle * 3.14159 / 180);
        glVertex2f(rayX, rayY);
        glVertex2f(endX, endY);
    }
    glEnd();
}

void drawTrack(double centerX, double centerY, double radiusX, double radiusY) {
    glBegin(GL_LINE_LOOP);
    for (int a = 0;a<10;a++){
        radiusX+=1;
        radiusY+=1;
        for (int i = 0; i < 300; i++) {
        double theta = (2.0 * 3.1415926 * double(i)/300);
        double x = radiusX * cos(theta);
        double y = radiusY * sin(theta);
        glVertex2d(centerX + x, centerY + y);
        }
    }
    glEnd();
}

void personA6(int face){
    glColor3f(0.0,0.0,0.0);
    //feets with shoes
    glBegin(GL_QUADS);
        glVertex2d(locationX,locationY);
        glVertex2d(locationX+5,locationY);
        glVertex2d(locationX+5,locationY+5);
        glVertex2d(locationX,locationY+5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2d(locationX+15,locationY);
        glVertex2d(locationX+20,locationY);
        glVertex2d(locationX+20,locationY+5);
        glVertex2d(locationX+15,locationY+5);
    glEnd();

    //leges with shoes
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2d(locationX,locationY+5);
        glVertex2d(locationX+20,locationY+5);
        glVertex2d(locationX+20,locationY+25);
        glVertex2d(locationX,locationY+25);
    glEnd();
    glColor3f(0.2,0.3,0.6);
    glBegin(GL_POLYGON);
        glVertex2d(locationX+5,locationY+5);
        glVertex2d(locationX+10,locationY+15);
        glVertex2d(locationX+15,locationY+5);
    glEnd();
    //shirt
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
        glVertex2d(locationX,locationY+25);
        glVertex2d(locationX+20,locationY+25);
        glVertex2d(locationX+25,locationY+45);
        glVertex2d(locationX+10,locationY+50);
        glVertex2d(locationX-5,locationY+45);
    glEnd();

    //Sleaves
    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
        glVertex2d(locationX+25,locationY+45);
        glVertex2d(locationX+22,locationY+35);
        glVertex2d(locationX+25,locationY+25);
        glVertex2d(locationX+28,locationY+35);
    glEnd();

    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
        glVertex2d(locationX-5,locationY+45);
        glVertex2d(locationX-8,locationY+35);
        glVertex2d(locationX-5,locationY+25);
        glVertex2d(locationX-2,locationY+35);
    glEnd();
    //arms
    glColor3f(0.9,0.7,0.5);
    glBegin(GL_POLYGON);
        glVertex2d(locationX+28,locationY+35);
        glVertex2d(locationX+26,locationY+30);
        glVertex2d(locationX+28,locationY+25);
        glVertex2d(locationX+30,locationY+30);
    glEnd();

    glColor3f(0.9,0.7,0.5);
    glBegin(GL_POLYGON);
        glVertex2d(locationX-8,locationY+35);
        glVertex2d(locationX-10,locationY+30);
        glVertex2d(locationX-8,locationY+25);
        glVertex2d(locationX-6,locationY+30);
    glEnd();

    //face
    glColor3f(0.9,0.7,0.5);
    drawCircle(locationX+10,locationY+59,15);
    glColor3f(0.0,0.0,0.0);
    glPointSize(5.0);
    glBegin(GL_POINTS);//eyes
        glVertex2d(locationX+3,locationY+64);
        glVertex2d(locationX+17,locationY+64);
    glEnd();

    if(face==-1){
    glBegin(GL_LINE_STRIP);//mouth cry
        for (int i =0; i<180;i++)
        {
            double theta= double(i)*pi/180.0;
            glVertex2d((locationX+10)+5 * cos(theta), (locationY+50) + 5 * sin(theta)); // Adjusted for position and size
        }
    glEnd();
    } else if(face==0){
    glBegin(GL_LINE_STRIP);//mouth normal
        glVertex2d(locationX+3,locationY+50);
        glVertex2d(locationX+17,locationY+50);
    glEnd();
    }else{
    glBegin(GL_LINE_STRIP);//mouth smile
        for (int i =180; i<360;i++)
        {
            double theta= double(i)*pi/180.0;
            glVertex2d((locationX+10)+5 * cos(theta), (locationY+50) + 5 * sin(theta)); // Adjusted for position and size
        }
    glEnd();
    }
    //hair
    glLineWidth(7.0);
    glBegin(GL_LINE_STRIP);
        for (int i =0; i<180;i++)
        {
            double theta= double(i)*pi/180.0;
            glVertex2d((locationX+10)+15 * cos(theta), (locationY+59) + 15 * sin(theta)); // Adjusted for position and size
        }
    glEnd();
}

void personAEnd()
{
    glColor3f(0.0,0.0,0.0);
    //feets with shoes
    glBegin(GL_QUADS);
        glVertex2d(200,50);
        glVertex2d(205,50);
        glVertex2d(205,55);
        glVertex2d(200,55);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2d(215,50);
        glVertex2d(220,50);
        glVertex2d(220,55);
        glVertex2d(215,55);
    glEnd();

    //leges with shoes
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2d(200,55);
        glVertex2d(220,55);
        glVertex2d(220,75);
        glVertex2d(200,75);
    glEnd();
    glColor3f(0.2,0.3,0.6);
    glBegin(GL_POLYGON);
        glVertex2d(205,55);
        glVertex2d(210,65);
        glVertex2d(215,55);
    glEnd();
    //shirt
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
        glVertex2d(200,75);
        glVertex2d(220,75);
        glVertex2d(225,95);
        glVertex2d(210,100);
        glVertex2d(195,95);
    glEnd();

    //Sleaves
    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
        glVertex2d(225,95);
        glVertex2d(222,85);
        glVertex2d(225,75);
        glVertex2d(228,85);
    glEnd();

    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
        glVertex2d(195,95);
        glVertex2d(192,85);
        glVertex2d(195,75);
        glVertex2d(198,85);
    glEnd();
    //arms
    glColor3f(0.9,0.7,0.5);
    glBegin(GL_POLYGON);
        glVertex2d(228,85);
        glVertex2d(226,80);
        glVertex2d(228,75);
        glVertex2d(230,80);
    glEnd();

    glColor3f(0.9,0.7,0.5);
    glBegin(GL_POLYGON);
        glVertex2d(192,85);
        glVertex2d(190,80);
        glVertex2d(192,75);
        glVertex2d(194,80);
    glEnd();

    //face
    glColor3f(0.9,0.7,0.5);
    drawCircle(210,109,15);
    glColor3f(0.0,0.0,0.0);
    glPointSize(5.0);
    glBegin(GL_POINTS);//eyes
        glVertex2d(203,114);
        glVertex2d(217,114);
    glEnd();

    glBegin(GL_LINE_STRIP);//mouth
        for (int i =180; i<360;i++)
        {
            double theta= double(i)*pi/180.0;
            glVertex2d(210+5 * cos(theta), 100 + 5 * sin(theta)); // Adjusted for position and size
        }
    glEnd();

    //hair
    glLineWidth(7.0);
    glBegin(GL_LINE_STRIP);
        for (int i =0; i<180;i++)
        {
            double theta= double(i)*pi/180.0;
            glVertex2d(210+15 * cos(theta), 109 + 15 * sin(theta)); // Adjusted for position and size
        }
    glEnd();

}

void personAEndMove()
{
    glPushMatrix();
    glTranslated(-60,0,0);
    personAEnd();
    glPopMatrix();
}

void background(int color,double x,double y){
    double r,g,b;
    switch (color){
    case -1:
        r = 0.3;
        g = 0.3;
        b = 0.3;
        break;
    case 0:
        r = 0.7;
        g = 0.7;
        b = 0.7;
        break;
    case 1:
        r = 0.9;
        g = 0.9;
        b = 0.9;
        break;
    }
    ground6();
    sun(x,y,30,7);
    hills6();
    dirtRoad6();
    drawTrack(250,90,200,40);
    //trees
    tree(10,150,1);
    tree(100,150,1);
    tree(300,150,1);
    tree(200,80,2);
    tree(225,70,2);
    tree(275,70,2);
    tree(250,74,2);
    tree(350,70,2);
    //cloud
    cloud(20,400,20,r,g,b);
    cloud(100,400,20,r,g,b);
    cloud(180,400,20,r,g,b);
    cloud(285,400,20,r,g,b);
    cloud(420,400,20,r,g,b);
    cloud(232,480,10,r,g,b);
    cloud(337,475,10,r,g,b);
    cloud(432,480,10,r,g,b);
}

void setAPosition(double x,double y){
    //position from left down is 0,0 max 1280,720 pixel
    locationX = x;
    locationY = y;
}

void setMove(double fromX,double fromY,double toX,double toY,double time){
    startX = fromX;
    startY = fromY;
    endX = toX;
    endY = toY;
    animationTime = time;
    distanceX = toX-fromX;//positive means go to left else right
    distanceY = toY-fromY;
}

void movePersonA6(int face) {
    //cout<<"moving";
    glPushMatrix();
    glTranslated(moveX, moveY, 0);
    personA6(face);
    glPopMatrix();
}

void timerEllipsMove(int value) {
    angle += speed;
   // cout<<"\t\t"<<angle;
    if (angle >= 360.0) {
        angle -=360;
        roundCount++;
      //  cout<<"\t\t"<<roundCount;
    }
    glutPostRedisplay();
    glutTimerFunc(16, timerEllipsMove, 0);
}

void movePersonAInEllips(int face,double radiusX,double radiusY) {
   // cout<<"movingElips";
    glutTimerFunc(0, timerEllipsMove, 0);
    glPushMatrix();
    glTranslated(startX+radiusX * cos(angle), startY+radiusY * sin(angle), 0.0);
    personA6(face);
    glPopMatrix();
}

void timer(int value) {
    double objectSpeedX,objectSpeedY;
    objectSpeedX = abs(distanceX)/animationTime;
    objectSpeedY = abs(distanceY)/animationTime;

    if (distanceX>0){
        moveX += objectSpeedX;
    }else{
        moveX -= objectSpeedX;
    }
    if (distanceY>0){
        moveY += objectSpeedY;
    }else{
        moveY -= objectSpeedY;
    }

    if (abs(moveX)>=abs(distanceX)&&abs(moveY)>=abs(distanceY)){
        moveX = distanceX;
        moveY = distanceY;
        return;
    }
    glutPostRedisplay();
    glutTimerFunc(0, timer, 0);
}

void moveInit(){
    moveX = 0;
    moveY = 0;
    startX=0;
    startY=0;
    endX=0;
    endY=0;
    animationTime = 0;
    locationX = 0;
    locationY = 0;
    distanceX;
    distanceY;
}

void scene6A(double r,double g,double b,int face){
    glClearColor(r, g, b, 1.0f);
   // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    background(-1,500,500);
    setAPosition(0,20);
    setMove(0,20,250,20,5000);
    movePersonA6(face);
    glutTimerFunc(16,timer,0);
    glFlush();
    //glutSwapBuffers();
    if (abs(moveX)>=abs(startX-endX)&&abs(moveY)>=abs(startY-endY)){
        moveInit();
        scene = 2;
    }
}

void scene6B(double r,double g,double b,int face){
    glClearColor(r, g, b, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    background(-1,500,500);
    setAPosition(250,20);
    setMove(250,20,250,30,100);
    movePersonA6(face);
    glutTimerFunc(16,timer,0);
    glFlush();
    //glutSwapBuffers();
    if (abs(moveX)>=abs(startX-endX)&&abs(moveY)>=abs(startY-endY)){
        moveInit();
        scene = 3;
    }
}

void scene6C(double r,double g,double b,int face){
    int cloud=-1;
    if (angle>210){
        face = 1;
        r = 0.7;
        g = 0.7;
        b = 1.0;
        cloud = 1;
    } else if (angle>200){
        face = 0;
        r = 0.6;
        g = 0.6;
        b = 0.9;
        cloud = 0;
    }
    glClearColor(r, g, b, 1.0f);
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    background(cloud,500,500);
    setAPosition(100,30);
    setMove(145,53,0,0,0);
    movePersonAInEllips(face,200,40);
    glutTimerFunc(16,timer,0);
    glFlush();
  //  glutSwapBuffers();
    if (angle>280){
        moveInit();
        scene = 4;
     }

}

void scene6()
{
   // glClearColor(1.0f,1.0f,1.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    //cout<<scene<<endl;
    if(scene == 1){
        scene6A(0.2,0.3,0.6,-1);
    }
    if(scene == 2){
        scene6B(0.2,0.3,0.6,-1);
    }
    if(scene == 3){
        scene6C(0.2,0.3,0.6,-1);
    }

}

void personB()
{
    glColor3f(0.0,0.0,0.0);
    //feets with shoes
    glBegin(GL_QUADS);
        glVertex2d(430,50);
        glVertex2d(435,50);
        glVertex2d(435,55);
        glVertex2d(430,55);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2d(445,50);
        glVertex2d(450,50);
        glVertex2d(450,55);
        glVertex2d(445,55);
    glEnd();

    //leges with shoes
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2d(430,55);
        glVertex2d(450,55);
        glVertex2d(450,75);
        glVertex2d(430,75);
    glEnd();
    glColor3f(0.2,0.3,0.6);
    glBegin(GL_POLYGON);
        glVertex2d(435,55);
        glVertex2d(440,65);
        glVertex2d(445,55);
    glEnd();
    //shirt
    glColor3f(1.0,0.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2d(430,75);
        glVertex2d(450,75);
        glVertex2d(455,95);
        glVertex2d(440,100);
        glVertex2d(425,95);
    glEnd();

    //Sleaves
    glColor3f(1,0,1);
    glBegin(GL_POLYGON);
        glVertex2d(455,95);
        glVertex2d(452,85);
        glVertex2d(455,75);
        glVertex2d(458,85);
    glEnd();

    glColor3f(1,0,1);
    glBegin(GL_POLYGON);
        glVertex2d(425,95);
        glVertex2d(422,85);
        glVertex2d(425,75);
        glVertex2d(428,85);
    glEnd();
    //arms
    glColor3f(0.9,0.7,0.5);
    glBegin(GL_POLYGON);
        glVertex2d(458,85);
        glVertex2d(456,80);
        glVertex2d(458,75);
        glVertex2d(460,80);
    glEnd();

    glColor3f(0.9,0.7,0.5);
    glBegin(GL_POLYGON);
        glVertex2d(422,85);
        glVertex2d(420,80);
        glVertex2d(422,75);
        glVertex2d(424,80);
    glEnd();

    //face
    glColor3f(0.9,0.7,0.5);
    drawCircle(440,109,15);
    glColor3f(0.0,0.0,0.0);
    glPointSize(5.0);
    glBegin(GL_POINTS);//eyes
        glVertex2d(433,114);
        glVertex2d(447,114);
    glEnd();

    glBegin(GL_LINE_STRIP);//mouth
        for (int i =180; i<360;i++)
        {
            double theta= double(i)*pi/180.0;
            glVertex2d(440+5 * cos(theta), 100 + 5 * sin(theta)); // Adjusted for position and size
        }
    glEnd();

    //hair
    glLineWidth(7.0);
    glBegin(GL_LINE_STRIP);
        for (int i =0; i<180;i++)
        {
            double theta= double(i)*pi/180.0;
            glVertex2d(440+15 * cos(theta), 109 + 15 * sin(theta)); // Adjusted for position and size
        }
    glEnd();

}

void movePersonB()
{
    glPushMatrix();
    glTranslated(c,d,0);
    personB();
    glPopMatrix();
}

void timerB1(int value)
{
    a=0;
    b=0;
    if(c>=-60)
    {
        c-=0.01;

    }
    else if (c<-60&&d<=60)
    {
        d+=0.01;

    }
    else
        return;
    glutPostRedisplay();
    glutTimerFunc(0,timerB1,0);
}

void adviceText()//the text present at scene 5
{
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
        glVertex2d(100,200);
        glVertex2d(300,200);
        glVertex2d(370,160);
        glVertex2d(350,250);
        glVertex2d(350,350);
        glVertex2d(100,350);
    glEnd();

    glColor3f(0,1,0);
    const char *messageL1="SUICIDE IS NOT THE ANSWER";
    int textWidth1 = glutBitmapLength(GLUT_BITMAP_HELVETICA_12, (unsigned char *)messageL1);
    int x1=250-textWidth1/2;
    int y1= 300;
    glRasterPos2d(x1,y1);
    for (const char *c = messageL1; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }

    const char *messageL2="CONSIDER THE CHANGE THAT CAN HAPPEN IN THE FUTURE";
    int textWidth2 = glutBitmapLength(GLUT_BITMAP_HELVETICA_12, (unsigned char *)messageL2);
    int x2=220-textWidth1/2;
    int y2= 280;
    glRasterPos2d(x2,y2);
    for (const char *c = messageL2; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}

void lighterClouds()//lighter cloud at scenen five to  signal hope
{
    //cloud1
   glColor3f(0.5,0.5,0.5);
   drawCircle(20,400,20);
   drawCircle(35,425,20);
   drawCircle(35,400,20);
   drawCircle(45,425,20);
//cloud2
   glColor3f(0.5,0.5,0.5);
   drawCircle(100,425,20);
   drawCircle(115,450,20);
   drawCircle(115,425,20);
   drawCircle(125,450,20);
//cloud3
   glColor3f(0.5,0.5,0.5);
   drawCircle(180,375,20);
   drawCircle(195,400,20);
   drawCircle(195,375,20);
   drawCircle(205,400,20);
//cloud4
   glColor3f(0.5,0.5,0.5);
   drawCircle(285,375,20);
   drawCircle(300,400,20);
   drawCircle(300,375,20);
   drawCircle(310,400,20);
//cloud5
   glColor3f(0.5,0.5,0.5);
   drawCircle(420,400,20);
   drawCircle(435,425,20);
   drawCircle(435,400,20);
   drawCircle(445,425,20);
//cloud6
    glColor3f(0.5,0.5,0.5);
   drawCircle(420,400,10);
   drawCircle(435,425,10);
   drawCircle(435,400,10);
   drawCircle(445,425,10);
//cloud7
   glColor3f(0.5,0.5,0.5);
   drawCircle(232,480,10);
   drawCircle(237,465,10);
   drawCircle(237,475,10);
   drawCircle(242,480,10);
   //cloud 8
   glColor3f(0.5,0.5,0.5);
   drawCircle(337,475,10);
   drawCircle(342,460,10);
   drawCircle(342,470,10);
   drawCircle(347,475,10);
   //cloud 9
   glColor3f(0.5,0.5,0.5);
   drawCircle(432,480,10);
   drawCircle(437,465,10);
   drawCircle(437,475,10);
   drawCircle(442,480,10);
}

void whiteClouds()//lighter cloud at scenen five to  signal hope
{
    //cloud1
   glColor3f(1.0,1.0,1.0);
   drawCircle(20,400,20);
   drawCircle(35,425,20);
   drawCircle(35,400,20);
   drawCircle(45,425,20);
//cloud2
   glColor3f(1.0,1.0,1.0);
   drawCircle(100,425,20);
   drawCircle(115,450,20);
   drawCircle(115,425,20);
   drawCircle(125,450,20);
//cloud3
   glColor3f(1.0,1.0,1.0);
   drawCircle(180,375,20);
   drawCircle(195,400,20);
   drawCircle(195,375,20);
   drawCircle(205,400,20);
//cloud4
   glColor3f(1.0,1.0,1.0);
   drawCircle(285,375,20);
   drawCircle(300,400,20);
   drawCircle(300,375,20);
   drawCircle(310,400,20);
//cloud5
   glColor3f(1.0,1.0,1.0);
   drawCircle(420,400,20);
   drawCircle(435,425,20);
   drawCircle(435,400,20);
   drawCircle(445,425,20);
//cloud6
   glColor3f(1.0,1.0,1.0);
   drawCircle(420,400,10);
   drawCircle(435,425,10);
   drawCircle(435,400,10);
   drawCircle(445,425,10);
//cloud7
   glColor3f(1.0,1.0,1.0);
   drawCircle(232,480,10);
   drawCircle(237,465,10);
   drawCircle(237,475,10);
   drawCircle(242,480,10);
   //cloud 8
  glColor3f(1.0,1.0,1.0);
   drawCircle(337,475,10);
   drawCircle(342,460,10);
   drawCircle(342,470,10);
   drawCircle(347,475,10);
   //cloud 9
  glColor3f(1.0,1.0,1.0);
   drawCircle(432,480,10);
   drawCircle(437,465,10);
   drawCircle(437,475,10);
   drawCircle(442,480,10);
}

void mouse(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        sceneTracker++;
        a=0;
        b=0;
        c=0;
        d=0;
        //printf("Mouse clicked! Scene Tracker: %d\n", sceneTracker); // Print scene tracker value
        glutPostRedisplay();
    }
    else if (button==GLUT_RIGHT_BUTTON&& state==GLUT_DOWN)
    {
        sceneTracker--;
        a=0;
        b=0;
        c=0;
        d=0;
        glutPostRedisplay();
    }

    else;
}

void sceneCut1()
{
    glClearColor(0.0,0.0,0.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    glRasterPos2d(200,250);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'W');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'H');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'Y');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,' ');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'D');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'I');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'D');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,' ');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'H');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'E');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,' ');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'J');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'U');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'M');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'P');

}

void hills()
{

     glBegin(GL_POLYGON);
        glColor3f(0.5,0,0.3);
        glVertex2d(-50,150);
        glColor3f(1.0,1.0,1.0);
        glVertex2d(80,350);
        glColor3f(0.5,0,0.3);
        glVertex2d(175,150);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.5,0,0.3);
        glVertex2d(150,150);
        glColor3f(1.0,1.0,1.0);
        glVertex2d(320,350);
        glColor3f(0.5,0,0.3);
        glVertex2d(500,150);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.5,0,0.3);
        glVertex2d(0,150);
        glColor3f(1.0,1.0,1.0);
        glVertex2d(220,400);
        glColor3f(0.5,0,0.3);
        glVertex2d(350,150);
    glEnd();

}

void personA()
{
    glColor3f(0.0,0.0,0.0);
    //feets with shoes
    glBegin(GL_QUADS);
        glVertex2d(400,350);
        glVertex2d(405,350);
        glVertex2d(405,355);
        glVertex2d(400,355);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2d(415,350);
        glVertex2d(420,350);
        glVertex2d(420,355);
        glVertex2d(415,355);
    glEnd();

    //leges with shoes
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2d(400,355);
        glVertex2d(420,355);
        glVertex2d(420,375);
        glVertex2d(400,375);
    glEnd();
    glColor3f(0.2,0.3,0.6);
    glBegin(GL_POLYGON);
        glVertex2d(405,355);
        glVertex2d(410,365);
        glVertex2d(415,355);
    glEnd();
    //shirt
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
        glVertex2d(400,375);
        glVertex2d(420,375);
        glVertex2d(425,395);
        glVertex2d(410,400);
        glVertex2d(395,395);
    glEnd();

    //Sleaves
    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
        glVertex2d(425,395);
        glVertex2d(422,385);
        glVertex2d(425,375);
        glVertex2d(428,385);
    glEnd();

    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
        glVertex2d(395,395);
        glVertex2d(392,385);
        glVertex2d(395,375);
        glVertex2d(398,385);
    glEnd();
    //arms
    glColor3f(0.9,0.7,0.5);
    glBegin(GL_POLYGON);
        glVertex2d(428,385);
        glVertex2d(426,380);
        glVertex2d(428,375);
        glVertex2d(430,380);
    glEnd();

    glColor3f(0.9,0.7,0.5);
    glBegin(GL_POLYGON);
        glVertex2d(392,385);
        glVertex2d(390,380);
        glVertex2d(392,375);
        glVertex2d(394,380);
    glEnd();

    //face
    glColor3f(0.9,0.7,0.5);
    drawCircle(410,409,15);
    glColor3f(0.0,0.0,0.0);
    glPointSize(5.0);
    glBegin(GL_POINTS);//eyes
        glVertex2d(403,414);
        glVertex2d(417,414);
    glEnd();

    glBegin(GL_LINE_STRIP);//mouth
        for (int i =0; i<180;i++)
        {
            double theta= double(i)*pi/180.0;
            glVertex2d(410+5 * cos(theta), 400 + 5 * sin(theta)); // Adjusted for position and size
        }
    glEnd();

    //hair
    glLineWidth(7.0);
    glBegin(GL_LINE_STRIP);
        for (int i =0; i<180;i++)
        {
            double theta= double(i)*pi/180.0;
            glVertex2d(410+15 * cos(theta), 409 + 15 * sin(theta)); // Adjusted for position and size
        }
    glEnd();


}

void personA5()//the main carachter in scene5
{
    glPushMatrix();
    glTranslated(-30,-175,0);
    personA();
    glPopMatrix();
}

void movePersonA1()//person a is jumping of the building
{
    glPushMatrix();
    glTranslated(a,b,0);
    personA();
    glPopMatrix();

}

void timerA1(int value)//straight movement
{
    if(a<=-30)
        a=-30;
    else
        a-=0.01;
    if(b<=-175)
        return;
    else
        b-=0.01;

    glutPostRedisplay();
    glutTimerFunc(0,timerA1,0);


}

void movePersonA5()
{
    glPushMatrix();
    glTranslated(a,b,0);
    personA5();
    glPopMatrix();
}

void timerA5(int value)
{
    if (b <= 175)
    {
        b += 0.01;
    }
    else if (a <= 30 && b >= 175)
    {
        a += 0.01;
    }
    else
        return;

    glutPostRedisplay();
    glutTimerFunc(0,timerA5,0);


}

void trees()
{
    //tree1
    glColor3f(0.4,0.1,0.1);//stub
    glBegin(GL_POLYGON);
        glVertex2d(10,150);
        glVertex2d(15,150);
        glVertex2d(15,160);
        glVertex2d(10,160);
    glEnd();
    //leaves
    glColor3f(0.1,0.5,0.2);
    glBegin(GL_POLYGON);
        glVertex2d(5,160);
        glVertex2d(12.5,165);
        glVertex2d(20,160);
    glEnd();

    glColor3f(0.1,0.5,0.2);
    glBegin(GL_POLYGON);
        glVertex2d(5,163);
        glVertex2d(12.5,170);
        glVertex2d(20,163);
    glEnd();

    //tree2
    glColor3f(0.4,0.1,0.1);//stub
    glBegin(GL_POLYGON);
        glVertex2d(100,150);
        glVertex2d(105,150);
        glVertex2d(105,160);
        glVertex2d(100,160);
    glEnd();
    //leaves
    glColor3f(0.1,0.5,0.2);
    glBegin(GL_POLYGON);
        glVertex2d(95,160);
        glVertex2d(102.5,165);
        glVertex2d(110,160);
    glEnd();

    glColor3f(0.1,0.5,0.2);
    glBegin(GL_POLYGON);
        glVertex2d(95,163);
        glVertex2d(102.5,170);
        glVertex2d(110,163);
    glEnd();

    //trees3
    glColor3f(0.4,0.1,0.1);//stub
    glBegin(GL_POLYGON);
        glVertex2d(300,150);
        glVertex2d(305,150);
        glVertex2d(305,160);
        glVertex2d(300,160);
    glEnd();
    //leaves
    glColor3f(0.1,0.5,0.2);
    glBegin(GL_POLYGON);
        glVertex2d(295,160);
        glVertex2d(302.5,165);
        glVertex2d(310,160);
    glEnd();

    glColor3f(0.1,0.5,0.2);
    glBegin(GL_POLYGON);
        glVertex2d(295,163);
        glVertex2d(302.5,170);
        glVertex2d(310,163);
    glEnd();

    glColor3f(0.4,0.1,0.1);//stub
    glBegin(GL_POLYGON);
        glVertex2d(350,150);
        glVertex2d(355,150);
        glVertex2d(355,160);
        glVertex2d(350,160);
    glEnd();
    //leaves
    glColor3f(0.1,0.5,0.2);
    glBegin(GL_POLYGON);
        glVertex2d(345,160);
        glVertex2d(352.5,165);
        glVertex2d(360,160);
    glEnd();

    glColor3f(0.1,0.5,0.2);
    glBegin(GL_POLYGON);
        glVertex2d(345,163);
        glVertex2d(352.5,170);
        glVertex2d(360,163);
    glEnd();

    glColor3f(0.4,0.1,0.1);//stub
    glBegin(GL_POLYGON);
        glVertex2d(40,85);
        glVertex2d(50,85);
        glVertex2d(50,105);
        glVertex2d(40,105);
    glEnd();
    //leaves
    glColor3f(0.1,0.5,0.2);
    glBegin(GL_POLYGON);
        glVertex2d(30,105);
        glVertex2d(45,120);
        glVertex2d(60,105);
    glEnd();
//trees5
    glColor3f(0.1,0.5,0.2);
    glBegin(GL_POLYGON);
        glVertex2d(30,112);
        glVertex2d(45.5,140);
        glVertex2d(60,112);
    glEnd();

    glColor3f(0.4,0.1,0.1);//stub
    glBegin(GL_POLYGON);
        glVertex2d(200,85);
        glVertex2d(215,85);
        glVertex2d(215,105);
        glVertex2d(200,105);
    glEnd();
    //leaves
    glColor3f(0.1,0.5,0.2);
    glBegin(GL_POLYGON);
        glVertex2d(185,105);
        glVertex2d(207.5,120);
        glVertex2d(230,105);
    glEnd();

    glColor3f(0.1,0.5,0.2);
    glBegin(GL_POLYGON);
        glVertex2d(185,112);
        glVertex2d(207.5,140);
        glVertex2d(230,112);
    glEnd();

}

void darkClouds()// dark clouds when the character is depressed
{
   //cloud1
   glColor3f(0.2,0.2,0.2);
   drawCircle(20,400,20);
   drawCircle(35,425,20);
   drawCircle(35,400,20);
   drawCircle(45,425,20);
//cloud2
   glColor3f(0.2,0.2,0.2);
   drawCircle(100,425,20);
   drawCircle(115,450,20);
   drawCircle(115,425,20);
   drawCircle(125,450,20);
//cloud3
   glColor3f(0.2,0.2,0.2);
   drawCircle(180,375,20);
   drawCircle(195,400,20);
   drawCircle(195,375,20);
   drawCircle(205,400,20);
//cloud4
   glColor3f(0.2,0.2,0.2);
   drawCircle(285,375,20);
   drawCircle(300,400,20);
   drawCircle(300,375,20);
   drawCircle(310,400,20);
//cloud5
   glColor3f(0.2,0.2,0.2);
   drawCircle(420,400,20);
   drawCircle(435,425,20);
   drawCircle(435,400,20);
   drawCircle(445,425,20);
//cloud6
    glColor3f(0.2,0.2,0.2);
   drawCircle(420,400,10);
   drawCircle(435,425,10);
   drawCircle(435,400,10);
   drawCircle(445,425,10);
//cloud7
   glColor3f(0.2,0.2,0.2);
   drawCircle(232,480,10);
   drawCircle(237,465,10);
   drawCircle(237,475,10);
   drawCircle(242,480,10);
   //cloud 8
   glColor3f(0.2,0.2,0.2);
   drawCircle(337,475,10);
   drawCircle(342,460,10);
   drawCircle(342,470,10);
   drawCircle(347,475,10);
   //cloud 9
   glColor3f(0.2,0.2,0.2);
   drawCircle(432,480,10);
   drawCircle(437,465,10);
   drawCircle(437,475,10);
   drawCircle(442,480,10);

}

void dirtRoad()
{
    glColor3f(0.7,0.3,0);
    glBegin(GL_POLYGON);
        glVertex2d(0,0);
        glVertex2d(500,0);
        glVertex2d(500,25);
        glVertex2d(0,25);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2d(430,25);
        glVertex2d(460,25);
        glVertex2d(460,50);
        glVertex2d(430,50);
    glEnd();
//border
    glColor3f(0.2,0.4,0.2);
    glLineWidth(7.0);
    glBegin(GL_LINE_STRIP);
        glVertex2d(0,25);
        glVertex2d(430,25);
        glVertex2d(430,50);
    glEnd();

    glColor3f(0.2,0.4,0.2);
    glLineWidth(7.0);
    glBegin(GL_LINE_STRIP);
        glVertex2d(460,50);
        glVertex2d(460,25);
        glVertex2d(500,25);
    glEnd();

}

void ground()//for the grass ground in all scenes
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(0, 255, 0);
    glBegin(GL_POLYGON);
        glVertex2d(0, 0);
        glVertex2d(500, 0);
        glVertex2d(500, 150);
        glVertex2d(0, 150);
    glEnd();
    dirtRoad();
}

void building()//the building where the person jumps of
{
    glBegin(GL_POLYGON);// main building frame
        glColor3ub(179,102,26);
        glVertex2d(400,50);
        glColor3ub(179,102,26);
        glVertex2d(490,50);
        glColor3ub(179,77,179);
        glVertex2d(490,350);
        glColor3ub(179,77,179);
        glVertex2d(400,350);
    glEnd();
    //door
    glColor3f(0.7,0,0.2);
    glBegin(GL_POLYGON);
        glVertex2d(430,50);
        glVertex2d(460,50);
        glVertex2d(460,100);
        glVertex2d(430,100);
    glEnd();

    glLineWidth(5.0);
    glColor3f(0.7,0.7,0.7);
    glBegin(GL_LINE_STRIP);
        glVertex2d(430,50);
        glVertex2d(430,100);
        glVertex2d(460,100);
        glVertex2d(460,50);
    glEnd();

    //window2
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
        glVertex2d(430,140);
        glVertex2d(445,140);
        glVertex2d(445,170);
        glVertex2d(430,170);
    glEnd();

    glLineWidth(5.0);
    glColor3f(0.7,0.7,0.7);
    glBegin(GL_LINE_LOOP);
        glVertex2d(430,140);
        glVertex2d(445,140);
        glVertex2d(445,170);
        glVertex2d(430,170);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
        glVertex2d(445,140);
        glVertex2d(460,140);
        glVertex2d(460,170);
        glVertex2d(445,170);
    glEnd();

    glLineWidth(5.0);
    glColor3f(0.7,0.7,0.7);
    glBegin(GL_LINE_LOOP);
        glVertex2d(445,140);
        glVertex2d(460,140);
        glVertex2d(460,170);
        glVertex2d(445,170);
    glEnd();

    //window3
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
        glVertex2d(430,200);
        glVertex2d(445,200);
        glVertex2d(445,230);
        glVertex2d(430,230);
    glEnd();

    glLineWidth(5.0);
    glColor3f(0.7,0.7,0.7);
    glBegin(GL_LINE_LOOP);
        glVertex2d(430,200);
        glVertex2d(445,200);
        glVertex2d(445,230);
        glVertex2d(430,230);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
        glVertex2d(445,200);
        glVertex2d(460,200);
        glVertex2d(460,230);
        glVertex2d(445,230);
    glEnd();

    glLineWidth(5.0);
    glColor3f(0.7,0.7,0.7);
    glBegin(GL_LINE_LOOP);
        glVertex2d(445,200);
        glVertex2d(460,200);
        glVertex2d(460,230);
        glVertex2d(445,230);
    glEnd();
    //window4
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
        glVertex2d(430,260);
        glVertex2d(445,260);
        glVertex2d(445,290);
        glVertex2d(430,290);
    glEnd();

    glLineWidth(5.0);
    glColor3f(0.7,0.7,0.7);
    glBegin(GL_LINE_LOOP);
        glVertex2d(430,260);
        glVertex2d(445,260);
        glVertex2d(445,290);
        glVertex2d(430,290);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
        glVertex2d(445,260);
        glVertex2d(460,260);
        glVertex2d(460,290);
        glVertex2d(445,290);
    glEnd();

    glLineWidth(5.0);
    glColor3f(0.7,0.7,0.7);
    glBegin(GL_LINE_LOOP);
        glVertex2d(445,260);
        glVertex2d(460,260);
        glVertex2d(460,290);
        glVertex2d(445,290);
    glEnd();
    //inti name
    glColor3f(1.0,0.0,0.0);
    glRasterPos2d(435,315);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'I');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'N');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'I');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'T');

}

void rainScene1()
{
    for(int i = 0; i < 1000; i++)
   {
        int x = rand() % 500;
        int y = rand() % 500;
        if(x > 500 || y > 500)
            break;
        glLineWidth(1.0);
        glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2d(x, y);
        glVertex2d(x + 2, y + 5);
        glEnd();
    }
    //glFlush();
}

void rainScene5()
{
    for(int i = 0; i < 300; i++)
   {
        int x = rand() % 500;
        int y = rand() % 500;
        if(x > 500 || y > 500)
            break;
        glLineWidth(1.0);
        glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2d(x, y);
        glVertex2d(x + 2, y + 5);
        glEnd();
    }
}

void scene1()//the first scene
{
    glClearColor(0.2f, 0.3f, 0.6f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    ground();
    hills();
    trees();
    building();
    darkClouds();
    rainScene1();
    movePersonA1();
    glutTimerFunc(36,timerA1,0);
    glFlush();
}

void scene5()//scene to Kick the main character back up
{
    glClearColor(0.1f, 0.2f, 0.6f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    ground();
    hills();
    trees();
    lighterClouds();
    building();
    rainScene5();
    movePersonB();
    movePersonA5();
    if(c>=-60&&d<=60)
        glutTimerFunc(16,timerB1,0);
    else
        glutTimerFunc(16,timerA5,0);
    if(a>=30&&b>=175&&c<=-60&&d>=60)
    adviceText();
    glFlush();

}

void endScene()
{
    glClearColor(0.0,0.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    ground();
    sun(450,450,30,7);
    hills();
    trees();
    building();
    whiteClouds();
    personB();
    personAEndMove();

    glColor3f(1.0,0.0,0.0);
    const char *endingMessage="A HEALTHY BODY HAS A HEALTHY MIND";
    int textWidth1 = glutBitmapLength(GLUT_BITMAP_HELVETICA_18, (unsigned char *)endingMessage);
    int x1=350-textWidth1/2;
    int y1= 280;
    glRasterPos2d(x1,y1);
    for (const char *c = endingMessage; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }

    glColor3f(1.0,0.0,0.0);
    const char *endingMessage1="WHICH WILL LEAD TO  A HAPPY LIFE";
    int textWidth2 = glutBitmapLength(GLUT_BITMAP_HELVETICA_18, (unsigned char *)endingMessage1);
    int x2=350-textWidth1/2;
    int y2= 260;
    glRasterPos2d(x2,y2);
    for (const char *c = endingMessage1; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }

    glColor3f(1.0,0.0,0.0);
    const char *endingMessage2="THE END";
    int textWidth3 = glutBitmapLength(GLUT_BITMAP_HELVETICA_18, (unsigned char *)endingMessage2);
    int x3=400-textWidth1/2;
    int y3= 230;
    glRasterPos2d(x3,y3);
    for (const char *c = endingMessage2; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }

}

void drug(double centerX, double centerY, double size)
{
    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_LINES);
    glVertex2d(centerX, centerY - size);
    glVertex2d(centerX, centerY + size);
    glEnd();

    double rectWidth = size / 2.0;
    double rectHeight = size / 2.5;
    double rectSpacing = size / 2.0;

    glColor3f(0.7f, 0.7f, 0.7f);

    glBegin(GL_QUADS);
    for (int i = 0; i < 3; ++i)
    {
        double rectX = centerX + (i - 1) * (rectWidth + rectSpacing); // Center the rectangles horizontally
        double rectY = centerY - size - rectHeight;

        glVertex2d(rectX, rectY);
        glVertex2d(rectX + rectWidth, rectY);
        glVertex2d(rectX + rectWidth, rectY + rectHeight);
        glVertex2d(rectX, rectY + rectHeight);
    }
    glEnd();

    // Render 'Drug' text inside each rectangle in black color
    glColor3f(0.0f, 0.0f, 0.0f);
    const char* drugText = "Drug";
    for (int i = 0; i < 3; ++i)
    {
        double rectX = centerX + (i - 0.8) * (rectWidth + rectSpacing); // Calculate rectangle position
        double rectY = centerY - size - rectHeight;

        // Position 'Drug' text inside the rectangle
        double textX = rectX + (rectWidth - glutBitmapLength(GLUT_BITMAP_HELVETICA_12, (const unsigned char*)drugText)) / 2;
        double textY = rectY + rectHeight / 0.8 - 15; // Center vertically

        // Render 'Drug' text
        glRasterPos2d(textX, textY);
        for (const char* c = drugText; *c != '\0'; ++c)
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
        }
    }
}

void drawRoom()
{
    // walls (rectangle)
    glColor3f(0.9f, 0.9f, 0.8f);
    glBegin(GL_POLYGON);
    glVertex2d(100, 100);
    glVertex2d(400, 100);
    glVertex2d(400, 400);
    glVertex2d(100, 400);
    glEnd();

    // floor (rectangle)
    glColor3f(1.0f, 0.5f, 0.5f);
    glBegin(GL_POLYGON);
    glVertex2d(100, 100);
    glVertex2d(400, 100);
    glVertex2d(400, 300);
    glVertex2d(100, 300);
    glEnd();

    // window
    glColor3f(0.6f, 0.8f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2d(250, 250);
    glVertex2d(350, 250);
    glVertex2d(350, 350);
    glVertex2d(250, 350);
    glEnd();

    // window panes (cross pattern)
    glColor3f(0.7f, 0.9f, 1.0f);
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glVertex2d(250, 300);
    glVertex2d(350, 300);
    glVertex2d(300, 250);
    glVertex2d(300, 350);
    glEnd();

    // bed (rectangle)
    glColor3f(0.6f, 0.3f, 0.1f);
    glBegin(GL_POLYGON);
    glVertex2d(150, 150);
    glVertex2d(350, 150);
    glVertex2d(350, 250);
    glVertex2d(150, 250);
    glEnd();

    // pillow (rectangle)
    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_POLYGON);
    glVertex2d(300, 250);
    glVertex2d(350, 250);
    glVertex2d(350, 280);
    glVertex2d(300, 280);
    glEnd();

    // nightstand (rectangle)
    glColor3f(0.4f, 0.2f, 0.1f);
    glBegin(GL_POLYGON);
    glVertex2d(130, 150);
    glVertex2d(150, 150);
    glVertex2d(150, 180);
    glVertex2d(130, 180);
    glEnd();

    // lamp on the nightstand
    glColor3f(0.8f, 0.8f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2d(140, 180);
    glVertex2d(140, 200);
    glVertex2d(145, 200);
    glVertex2d(145, 180);
    glEnd();

    // lampshade on the lamp
    glColor3f(0.9f, 0.9f, 0.7f);
    glBegin(GL_POLYGON);
    glVertex2d(135, 200);
    glVertex2d(150, 220);
    glVertex2d(155, 220);
    glVertex2d(140, 200);
    glEnd();
}

void drawMoneyIcon(double centerX, double centerY, double size)
{
    glColor3f(0.0f, 0.5f, 0.0f);

    glVertex2d(centerX, centerY - size);
    glVertex2d(centerX, centerY + size);
    glEnd();

    // Calculate the size and spacing of the rectangles based on the dollar sign size
    double rectWidth = size / 1.5;
    double rectHeight = size / 2.0;
    double rectSpacing = size / 2.0;

    for (int i = 0; i < 3 ; ++i)
    {
    // Calculate random positions for the rectangles
    double rectX = centerX + (rand() % 200 - 90);
    double rectY = centerY + size + (rand() % 200 - 50);

    glColor3f(0.0f, 0.5f, 0.0f);
    glRectd(rectX, rectY, rectX + rectWidth, rectY + rectHeight);

    // Render '$' text inside each rectangle
    glColor3f(1.0f, 1.0f, 1.0f); // White color for the text
    glRasterPos2d(rectX + rectWidth / 2 - 5, rectY + rectHeight / 2 - 5); // Position '$' text inside the rectangle
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '$'); // Render '$' character

    // Define text area dimensions and position inside the rectangle
    double textAreaWidth = rectWidth - 10; // Width of the text area (slightly smaller than the rectangle width)
    double textAreaHeight = rectHeight - 10; // Height of the text area (slightly smaller than the rectangle height)
    double textAreaX = rectX + 5; // X-coordinate of the text area (offset from the left edge of the rectangle)
    double textAreaY = rectY + 5; // Y-coordinate of the text area (offset from the bottom edge of the rectangle)
    }
}

void drawRectangle(double x, double y, double width, double height)
{
    glBegin(GL_QUADS);
    glVertex2d(x, y);
    glVertex2d(x + width, y);
    glVertex2d(x + width, y + height);
    glVertex2d(x, y + height);
    glEnd();
}

void memoriesOfDrugAddiction()
{
    glColor3f(0.0f, 0.0f, 0.0f);
    // Line of text
    const char *text1 = "Drug addiction caused me huge expenses, poor health and losing my financial resources.";
    int text1Width = glutBitmapLength(GLUT_BITMAP_HELVETICA_18, (unsigned char *)text1);
    int text1X = 475 - text1Width / 2;
    int text1Y = 380;
    glRasterPos2d(text1X, text1Y);
    for (const char *c = text1; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }

    personA5();
}

void scene2()
{
    // Render scene 2
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    drawRoom();
    personA5();
    drawMoneyIcon(250,300,40);
    memoriesOfDrugAddiction();
    drug(250,300,40);
    glutTimerFunc(0,timerA1,0);

    glFlush();
}

void scene3()
{
  glClear(GL_COLOR_BUFFER_BIT);

    // Draw indoor environment
    IndoorEnvironment();

    // Draw the boys
     personA3(100, -150);
     personA3(250, -150);
     personA3(400, -150);

    // Draw clocks above each boy's head with specified times
    Clock(100, 455, "10:00 AM");
    Clock(250, 455, "11:00 AM");
    Clock(400, 455, "2:00 PM");

    // Draw the table and test paper for each boy
    Table(100, 230);
    TestPaper(100, 220);

    Table(250, 230);
    TestPaper(250, 220);

    Table(400, 230);
    TestPaper(400, 220);

    // Draw the strings
    Strings();

    // Left boy's table leg

    TextUnderTableLeg("The left side shows the main character \n(MC) failed his final test, \nwhich made him start to feel stressed",100, 130, 300);

    // Middle boy's table leg

    TextUnderTableLeg("The middle shows boy is experiencing \npuberty and starting to have acne, \nwhich makes him feel embarrassed",250, 130, 300);

    // Right boy's table leg

    TextUnderTableLeg("The right side shows the boy hears \nabout a medicine that can address \npuberty problems and \nimprove studying",400, 130, 300);

    glFlush();
}

void titleScene()// Main introduction scene
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,1.0,0.0);
    const char *introText1="SGD3: HEALTH AND WELL BEING";
    int text1Width1 = glutBitmapLength(GLUT_BITMAP_HELVETICA_18, (unsigned char *)introText1);
    int x1=350-text1Width1/2;
    int y1= 325;
    glRasterPos2d(x1,y1);
    for (const char *c = introText1; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }

    const char *introText2="Group 1";
    int text1Width2= glutBitmapLength(GLUT_BITMAP_HELVETICA_18, (unsigned char *)introText2);
    int x2=275-text1Width2/2;
    int y2=300;
    glRasterPos2d(x2,y2);
    for (const char *c = introText2; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }

    const char *introText3="Presented By :";
    int text1Width3 = glutBitmapLength(GLUT_BITMAP_HELVETICA_18, (unsigned char *)introText3);
    int x3=263-text1Width3/2;
    int y3=275;
    glRasterPos2d(x3,y3);
    for (const char *c = introText3; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }

    const char *introText4="Showven Suresh";
    int text1Width4 = glutBitmapLength(GLUT_BITMAP_HELVETICA_18, (unsigned char *)introText4);
    int x4=325-text1Width4/2;
    int y4=250;
    glRasterPos2d(x4,y4);
    for (const char *c = introText4; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }

    const char *introText5="Tay Xuan Ye";
    int text1Width5 = glutBitmapLength(GLUT_BITMAP_HELVETICA_18, (unsigned char *)introText5);
    int x5=308-text1Width5/2;
    int y5=225;
    glRasterPos2d(x5,y5);
    for (const char *c = introText5; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }

    const char *introText6="Voon Jun Hau";
    int text1Width6 = glutBitmapLength(GLUT_BITMAP_HELVETICA_18, (unsigned char *)introText6);
    int x6=313-text1Width6/2;
    int y6=200;
    glRasterPos2d(x6,y6);
    for (const char *c = introText6; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }

    const char *introText7="Lim Zhou Yin";
    int text1Width7 = glutBitmapLength(GLUT_BITMAP_HELVETICA_18, (unsigned char *)introText7);
    int x7=309-text1Width7/2;
    int y7=175;
    glRasterPos2d(x7,y7);
    for (const char *c = introText7; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }

}

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 500, 0.0, 500);
    glColor3f(0,0,0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    //printf("Display function called! Current scene: %d\n", sceneTracker); // Print scene tracker value
    glutMouseFunc(mouse);
    if(sceneTracker==0)
        titleScene();
    else if (sceneTracker==1)
        scene1();
    else if (sceneTracker==2)
        sceneCut1();
    else if (sceneTracker==3)
        scene3();
    else if (sceneTracker==4)
        scene2();
    else if (sceneTracker==5)
        scene5();
    else if (sceneTracker==6)
        scene6();
    else if (sceneTracker==7)
        endScene();

    glutSwapBuffers();


}

int main (int argc, char**argv)
{
    glutInit(&argc,argv);//initializes the glut library
    glutInitWindowPosition(0,0);//sets the window's position
    glutInitWindowSize(1280,720);//sets the size of the windows
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);//to  set the display mode for the window
    glutCreateWindow("Health And Well Being");//creates the window and names it
    init();
    glutDisplayFunc(display);//calls the function to  be displayed on the screen
    glutMouseFunc(mouse);//sets up the mouse click
    glutMainLoop();//keeps the display running

    return 0;

}



