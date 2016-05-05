#include "ofApp.h"
#include "ofxChoreograph.h"
using namespace ofxChoreograph;
Sequence<ofVec2f> seq( ofVec2f::zero() );
//--------------------------------------------------------------
void ofApp::setup(){
    ofVec2f corner(ofGetWidth(),ofGetHeight());
    seq.then<RampTo>(corner, 1.0f, EaseNone())
    .then<RampTo>(ofVec2f::zero(), 1.0f, EaseNone())
    //basic ramp
    .then<RampTo>(corner, 1.0f, EaseOutQuad())
    .then<RampTo>(ofVec2f::zero(), 1.0f, EaseNone())
    /// RampTo2 is a phrase with 2 separately-interpolated components.
    .then<RampTo2>(corner, 1.0f, EaseOutQuad(), EaseInQuad())
    .then<RampTo>(ofVec2f::zero(), 1.0f, EaseNone());
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    Time t = fmod( ofGetElapsedTimef(), seq.getDuration() );
    auto a = seq.getValue(t);
    ofDrawCircle(a, 10);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
