#pragma once
/*
Choreograph simple example.
BasicTween via
https://github.com/cinder/Cinder/tree/master/samples/_timeline/BasicTween
and
https://github.com/pizthewiz/ofxCinderTimeline/tree/master/example-BasicTween
*/
#include "ofMain.h"
#include "ofxChoreograph.h"
using namespace ofxChoreograph;

class BasicAppendTweenApp : public ofBaseApp{
        std::shared_ptr<Timeline>	mTimeline;
	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

        void setDestinations();
        void startTweening();
        
        Output<ofVec2f>mPos;
        int				mNumDestinations;
        vector<ofVec2f>	mDestinations;
        Timeline&		timeline() { return *mTimeline; }
};
