#include "ofApp.h"
#include "ofApp.h"
#include "ofxChoreograph.h"
using namespace ofxChoreograph;

// Custom Object
struct CustomObj{
    ofVec2f pos;
    ofColor color;
};

using LerpFn = std::function<CustomObj (const CustomObj&, const CustomObj&, float)>;
LerpFn lerp_function;
Sequence<CustomObj>seq({ofVec2f(0,0), ofColor::black});
//--------------------------------------------------------------
void ofApp::setup(){
    lerp_function = [] (const CustomObj &lhs, const CustomObj &rhs, float mix){
        return CustomObj{
            ch::lerpT( lhs.pos, rhs.pos, mix ),
            ch::lerpT( lhs.color, rhs.color, mix ),
        };
    };
    ofVec2f corner(ofGetWidth(),ofGetHeight());
    
    seq.then<RampTo>({corner, ofColor::red}, 1, EaseNone(), lerp_function)
    .then<RampTo>({ofVec2f::zero(), ofColor::black}, 1, EaseOutAtan(), lerp_function)
    .then<RampTo>({corner, ofColor::green}, 1, EaseOutSine() , lerp_function)
    .then<RampTo>({ofVec2f::zero(), ofColor::black}, 1, EaseOutSine() , lerp_function)
    .then<RampTo>({corner, ofColor::blue}, 1, EaseOutSine() , lerp_function)
    .then<RampTo>({ofVec2f::zero(), ofColor::black}, 1, EaseOutCubic() , lerp_function);    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    Time t = fmod( ofGetElapsedTimef(), seq.getDuration() );
    auto a = seq.getValue(t);
    ofSetColor(a.color);
    ofDrawCircle(a.pos, 10);
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
