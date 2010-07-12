#pragma once

#include "MSAFluid.h"
#include "MSATimer.h"
#include "ParticleSystem.h"

#include "ofMain.h"

// comment this line out if you don't wanna use TUIO
// you will need ofxTUIO & ofxOsc
//#define USE_TUIO		

// comment this line out if you don't wanna use the GUI
// you will need ofxSimpleGuiToo, ofxMSAInteractiveObject & ofxXmlSettings
// if you don't use the GUI, you won't be able to see the fluid parameters
#define USE_GUI		



#ifdef USE_TUIO
#include "ofxTuio.h"
#define tuioCursorSpeedMult				0.5	// the iphone screen is so small, easy to rack up huge velocities! need to scale down 
#define tuioStationaryForce				0.001f	// force exerted when cursor is stationary
#endif


#ifdef USE_GUI 
#include "ofxSimpleGuiToo.h"
#endif


class testApp : public ofSimpleApp{
public:
	void setup();
	void update();
	void draw();
	
	void keyPressed  (int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);

	void windowResized(int w, int h);

	void addToFluid(ofxVec2f pos, ofxVec2f vel, bool addColor, bool addForce);

	int					fluidCellsX;
	bool				resizeFluid;
	bool				drawFluid;
	bool				drawParticles;
	bool				renderUsingVA;
	bool				testPerformance;
	
	MSA::FluidSolver	fluidSolver;
	MSA::FluidDrawerGl	fluidDrawer;	
	
	ParticleSystem		particleSystem;
	
	int					pmouseX, pmouseY;
	
	// cache these for slightly better performance
	struct {
		int				width;
		int				height;
		float			invWidth;
		float			invHeight;
		float			aspectRatio;
		float			aspectRatio2;
	} window;
	
	
#ifdef USE_TUIO
	myTuioClient tuioClient;
#endif	
	
#ifdef USE_GUI 
	ofxSimpleGuiToo	gui;
#endif
	
	
};

extern testApp *myApp;


