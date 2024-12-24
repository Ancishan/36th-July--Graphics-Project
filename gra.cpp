#include <GL/glut.h>
#include <math.h>
#include <string.h>

// Function to draw an ellipse (to make the head slimmer along the X-axis)
void drawEllipse(float x, float y, float radiusX, float radiusY) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float angle = i * 3.14159 / 180;
        glVertex2f(x + radiusX * cos(angle), y + radiusY * sin(angle));
    }
    glEnd();
}

void drawHair() {
    glColor3f(0.0, 0.0, 0.0); // Black color for the hair

    // Draw small black ellipses on top of the head to simulate hair
    drawEllipse(0.0, 0.85, 0.1, 0.1);  // Top-center hair (main part)
    drawEllipse(-0.12, 0.83, 0.08, 0.04); // Left hair strand (slightly adjusted for top placement)
    drawEllipse(0.12, 0.83, 0.08, 0.04);  // Right hair strand (slightly adjusted for top placement)
    drawEllipse(-0.14, 0.80, 0.06, 0.03); // Left side hair (adjusted for better curvature)
    drawEllipse(0.14, 0.80, 0.06, 0.03);  // Right side hair (adjusted for better curvature)
}


// Function to draw a rectangle
void drawRectangle(float x, float y, float width, float height) {
    glBegin(GL_QUADS);
    glVertex2f(x - width / 2, y - height / 2); // Bottom-left corner
    glVertex2f(x + width / 2, y - height / 2); // Bottom-right corner
    glVertex2f(x + width / 2, y + height / 2); // Top-right corner
    glVertex2f(x - width / 2, y + height / 2); // Top-left corner
    glEnd();
}

// Function to draw a triangle (used for the nose)
void drawTriangle(float x, float y, float size) {
    glBegin(GL_TRIANGLES);
    glVertex2f(x, y); // Tip of the nose
    glVertex2f(x - size / 2, y - size); // Bottom-left corner
    glVertex2f(x + size / 2, y - size); // Bottom-right corner
    glEnd();
}

// Function to draw a mouth (arc)
void drawMouth(float x, float y, float radius, float startAngle, float endAngle) {
    glBegin(GL_LINE_STRIP);
    for (int i = startAngle; i <= endAngle; i++) {
        float angle = i * 3.14159 / 180;
        glVertex2f(x + radius * cos(angle), y + radius * sin(angle));
    }
    glEnd();
}

// Function to draw greater than and less than signs (hands)
void drawHands() {
    glLineWidth(12); // Increase line width to make the hands bold
    glColor3f(0.0, 0.8, 0.0); // Green color for the hands

    // Left hand (greater than sign)
    glBegin(GL_LINES);
        glVertex2f(-0.2, 0.2); // Starting point for left hand
        glVertex2f(-0.1, 0.4); // Ending point for left hand
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(-0.2, 0.2); // Starting point for left hand
        glVertex2f(-0.1, 0.03); // Ending point for left hand
    glEnd();

    // Right hand (less than sign)
    glBegin(GL_LINES);
        glVertex2f(0.2, 0.2); // Starting point for right hand
        glVertex2f(0.1, 0.4); // Ending point for right hand
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(0.2, 0.2); // Starting point for right hand
        glVertex2f(0.1, 0.0); // Ending point for right hand
    glEnd();
}

// Function to render text
void renderText(const char *text, float x, float y) {
    glRasterPos2f(x, y);
    for (int i = 0; text[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }
}



// Function to draw Bangladesh Flag
void drawBangladeshFlag() {
    // Draw green rectangle for the flag
    glColor3f(0.0, 0.5, 0.0); // Green color for the flag
    drawRectangle(0.5, 0.7, 0.6, 0.4); // Flag rectangle (green background)

    // Draw red circle in the center
    glColor3f(1.0, 0.0, 0.0); // Red color
    drawEllipse(0.5, 0.7, 0.18, 0.18); // Red circle

    // Render 'BANGLADESH' text on the flag
    glColor3f(1.0, 1.0, 1.0); // White color for text
    renderText("THIS IS NEW", 0.35, 0.75); // Positioning the text
     renderText("BANGLADESH ", 0.35, 0.6);
}

// Function to render the other side with "36th JULY" and "GEN-Z"
void renderOtherSide() {
    // Render "36th JULY"

    glColor3f(1.0, 0.0, 0.0); // Red color for text
    renderText("36th JULY", -0.8, 0.4); // Positioning the text

    // Render "GEN-Z"
    renderText("GEN-Z", -0.9, 0.49); // Positioning the text
}

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the head (ellipse to make it slimmer along the X-axis)
    glColor3f(0.8, 0.5, 0.2); // White color for the circle
    drawEllipse(0.0, 0.65, 0.15, 0.18); // Smaller and slimmer head (ellipse with different X and Y radii)

    drawHair();

    // Draw the neck (rectangle below the head to represent the neck)
    glColor3f(0.8, 0.5, 0.2); // Skin tone color for the neck
    drawRectangle(0.0, 0.43, 0.05, 0.08); // Neck rectangle placed below the head

    // Draw the red rectangle with rounded ends (red cloth covering the eyes)
    glColor3f(1.0, 0.0, 0.0); // Red color
    float redRectY = 0.70; // Adjusted y-position for the red band
    drawRectangle(0.0, redRectY, 0.25, 0.06); // Smaller rectangle for the red cloth
    drawEllipse(-0.125, redRectY, 0.04, 0.04); // Left rounded end
    drawEllipse(0.125, redRectY, 0.04, 0.04);  // Right rounded end

    // Draw the nose (triangle)
    glColor3f(0.0, 0.0, 0.0); // Brown color for the nose
    drawTriangle(0.0, 0.63, 0.05); // Nose adjusted slightly lower to match cloth position

    // Draw the mouth (a simple line)
    glColor3f(0.0, 0.0, 0.0); // Black color for the mouth
    glLineWidth(5.0); // Set line width for the mouth
    glBegin(GL_LINES);
        glVertex2f(-0.05, 0.53); // Starting point of the line (adjusted)
        glVertex2f(0.05, 0.53);  // Ending point of the line (adjusted)
    glEnd();

    // Draw the body (adjusted green tone for the torso)
    glColor3f(0.0, 0.8, 0.0); // Slightly different green tone for the body
    drawRectangle(0.0, 0.2, 0.27, 0.4); // Torso rectangle at (0.0, 0.2)

    // Draw the red circle on the body
    glColor3f(1.0, 0.0, 0.0); // Red color for the circle
    drawEllipse(0.0, 0.2, 0.1, 0.1); // Circle at (0.0, 0.0) with radius 0.1

    // Draw the legs (blue rectangles remain unchanged)
    glColor3f(0.0, 0.0, 1.0); // Blue color for the legs
    drawRectangle(-0.08, -0.3, 0.05, 0.6); // Left leg
    drawRectangle(0.08, -0.3, 0.05, 0.6);  // Right leg

    // Draw the hands (greater than and less than)
    drawHands();

    // Draw the Bangladesh flag
    drawBangladeshFlag();

    // Draw the other side with text
    renderOtherSide();

    glFlush();
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Character with Bangladesh Flag");
    glutDisplayFunc(display);
    glClearColor(0.0, 0.0, 0.0, 1.0);  // Set background color to black

    glutMainLoop();
    return 0;
}
