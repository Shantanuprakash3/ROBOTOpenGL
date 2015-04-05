#include <Gl/glut.h>
#define speed 0.2 //controls forward and backward motion speed
static GLfloat theta[] = { 0.0, 0.0 }; //rotation of limbs
static GLboolean toggle = false; //solid or wire?
GLfloat xpos = 0.0;
GLfloat ypos = 0.0;
GLfloat zpos = 0.0;

float width = 500;
float height = 500;

void torso(void);
void head(void);
void upper_rarm(void);
void upper_larm(void);
void left_hand(void);
void lower_rarm(void);
void lower_larm(void);
void right_hand(void);
void init(void);
void display(void);
void reshape(int width, int height);
void leye(void);
void reye(void);
void nose(void);
void mouth(void);
void drawCube(void);
void keyboard(unsigned char key, int x, int y);


/*THIGHS,LEGS AND FEET*/
void left_foot(){
	glPushMatrix();
	glColor3f(0.5, 0.0, 1.0);
	glTranslatef(-0.0, -0.5, 0.0);
	glScalef(1.2, 0.3, 0.5);

	drawCube();
	glPopMatrix();
}

void left_leg(){
	glPushMatrix();
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(-0.015, -0.85, 0.0);
	glScalef(0.5, 0.7, 0.0);

	drawCube();
	left_foot();
	glPopMatrix();
}

void left_thigh(){
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(-0.33, -1.33, 0.0);
	glScalef(0.33, 1.0, 0.0);
	glRotatef(-theta[1], 1.0, 0.0, 0.0);
	drawCube();
	left_leg();
	glPopMatrix();
}

void right_foot(){
	glPushMatrix();
	glColor3f(0.5, 0.0, 1.0);
	glTranslatef(0.0, -0.5, 0.0);
	glScalef(1.2, 0.3, 0.5);

	drawCube();
	glPopMatrix();
}


void right_leg(){
	glPushMatrix();
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(0.015, -0.85, 0.0);
	glScalef(0.5, 0.7, 0.0);
	drawCube();
	right_foot();
	glPopMatrix();
}

void right_thigh(){
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(0.33, -1.33, 0.0);
	glScalef(0.33, 1.0, 0.0);
	glRotatef(theta[0], 1.0, 0.0, 0.0);
	drawCube();
	right_leg();
	glPopMatrix();
}

void lower_body(){
	glColor3f(1.0f, 1.0f, 0.0f);
	drawCube();
	left_thigh();
	right_thigh();
}


/*-----------------------------------------------------------------------------------------------------------------------------------*/

/*HEAD*/

void head(void) {
	glColor3f(1.0f, 0.0f, 0.0f); //color the face red
	glTranslatef(0.0, 5.5, -7.5); //position the face, from the torso coordinate frame
	glScalef(2.0, 2.0, 2.0);
	drawCube();
	//draw face cube and then every feature from this coordinate frame
	//all facial features are yellow
	glPushMatrix();
		leye(); //draw left eye
	glPopMatrix();

	glPushMatrix();
		reye(); //draw right eye
	glPopMatrix();
	
	glPushMatrix();
		nose(); //draw nose
	glPopMatrix();

	glPushMatrix();
		mouth(); //draw mouth
	glPopMatrix();
}

void leye(void){
	glColor3f(1.0f, 1.0f, 0.0f);
	glTranslatef(-0.25, 0.15, 0.0);
	glScalef(0.3, 0.2, 0.0);
	drawCube();
}

void reye(void){
	glColor3f(1.0f, 1.0f, 0.0f);
	glTranslatef(0.25, 0.15, 0.0);
	glScalef(0.3, 0.2, 0.0);
	drawCube();
}

void nose(void){
	glColor3f(1.0f, 1.0f, 0.0f);
	glTranslatef(0.0, -0.15, 0.0);
	glScalef(0.1, 0.25, 0.1);
	drawCube();
	glutSolidCube(1.0);
}

void mouth(void){
	glColor3f(1.0f, 1.0f, 0.0f);
	glTranslatef(0.0, -0.380, 0.0);
	glScalef(0.5, 0.05, 0.0);
	drawCube();
	glutSolidCube(1.0);
}

/*-----------------------------------------------------------------------------------------------------------------------------------*/

/*TORSO*/
//TORSO has all the draw calls, which in turn call other draw functions as per the given scene graph

void torso(void) {
	glColor3f(1.0f, 0.0f, 0.0f);
	glPushMatrix();
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glScalef(3.0, 3.0, 3.0);
	lower_body();
	glTranslatef(0.0, 1.0, 0.0);
	drawCube();
	glPopMatrix();
	glPushMatrix();
	head();
	glPopMatrix();
	glPushMatrix();
	upper_larm();
	glPopMatrix();
	glPushMatrix();
	upper_rarm();
	glPopMatrix();
}


/*-----------------------------------------------------------------------------------------------------------------------------------*/

/*ARMS*/

void upper_larm(void) {
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(-1.8, 1.775, -5.4);
	glScalef(0.75, 2.5, 0.75);
	glRotatef(theta[0], 1.0, 0.0, 0.0);
	drawCube();
	lower_larm();
}

void lower_larm(void) {
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(0.0, -0.880, 0.0);
	glScalef(0.8, 0.75, 1.0);
	drawCube();
	left_hand();
}

void left_hand(void){
	glColor3f(0.0, 0.0, 1.0);
	glTranslatef(0.0, -0.75, 0.0);
	glScalef(0.65, 0.3, 1.0);
	drawCube();
}

void upper_rarm(void) {
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(1.8, 1.775, -5.4);
	glScalef(0.75, 2.5, 0.75);
	glRotatef(-theta[1], 1.0, 0.0, 0.0);
	drawCube();
	lower_rarm();
}

void lower_rarm(void) {
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(0.0, -0.880, 0.0);
	glScalef(0.8, 0.75, 1.0);
	drawCube();
	right_hand();
}

void right_hand(void){
	glColor3f(0.0, 0.0, 1.0);
	glTranslatef(0.0, -0.75, 0.0);
	glScalef(0.65, 0.3, 1.0);
	drawCube();
}



/*-----------------------------------------------------------------------------------------------------------------------------------*/

/*DRAWCUBE AND KEYBOARD*/

void drawCube(void){
	if (toggle){
		glutSolidCube(1.0);
	}
	else {
		glutWireCube(1.0);
	}
}
void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'w':
	case 'W':
		if (toggle == true){
			toggle = false;
		}
		else if (toggle == false){
			toggle = true;
		}
		break;
	case 'f':
	case 'F':
		zpos = zpos + speed;
		if (zpos > 5)
			zpos = (int)(zpos + 1) % 10;
		theta[0] += 5;
		theta[1] -= 7;

		if (theta[0] > 5)
			theta[0] = (int)(theta[0]) % 120;
		if (theta[1] < -5)
			theta[1] = (int)(theta[1]) % 120;
		break;
	case 'b':
	case 'B':
		zpos = zpos - speed;
		if (zpos < -5){
			zpos = ((int)(-zpos)) % 10;
		}
		theta[0] -= 5;
		theta[1] += 7;
		if (theta[1] > 5)
			theta[1] = (int)(theta[1]) % 120;
		if (theta[0] < -5)
			theta[0] = (int)(theta[0]) % 120;
		break;
	case 'q':
	case 'Q':
		exit(0);
		break;
	}
	init();
	glutPostRedisplay();
}
/*-----------------------------------------------------------------------------------------------------------------------------------*/

/*DISPLAY, RESHAPE AND INIT*/

void display(void) {
	glLoadIdentity();
	gluLookAt(0.3, 5.3, 12.0, 0.0, 1.25, 0.0, 0.0, 1.0, 0.0);
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex3f(10.0, 0.0, 10.0);
	glVertex3f(10.0, 0.0, -10.0);
	glVertex3f(-10.0, 0.0, -10.0);
	glVertex3f(-10.0, 0.0, 10.0);
	glVertex3f(10.0, 0.0, 10.0);
	glEnd();
	glTranslatef(xpos, ypos, zpos);
	torso();
	glutSwapBuffers();
}

void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(100.0, (GLfloat)w / (GLfloat)h, 0.5, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void init(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
}

/*-----------------------------------------------------------------------------------------------------------------------------------*/

/*MAIN*/


int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutCreateWindow("Robot");
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}