#include "BasicAppendTweenApp.h"

//--------------------------------------------------------------
void BasicAppendTweenApp::setup()
{
    mTimeline = make_shared<Timeline>();
    mPos = ofVec2f(ofGetWidth()/2.0, ofGetHeight()/2.0);
    mNumDestinations = 10;
    setDestinations();
    startTweening();
}

//--------------------------------------------------------------
void BasicAppendTweenApp::update(){
    timeline().step(ofGetLastFrameTime());
}

//--------------------------------------------------------------
void BasicAppendTweenApp::draw(){
    ofClear( ofFloatColor( 0.2f, 0.2f, 0.2f ) );
    
    for( int i=0; i<mNumDestinations; i++ ){
        ofSetColor( ofFloatColor( 1, 0, 0 ) );
        ofDrawCircle( mDestinations[i], 3.0f );
        
        if( i > 0 ){
            ofSetColor( ofFloatColor( 1, 0, 0, 0.25f ) );
            ofDrawLine( mDestinations[i], mDestinations[i-1] );
        }
    }
    
    ofSetColor( ofColor::white );
    ofDrawCircle( mPos.value(), 20.0f );
}

void BasicAppendTweenApp::setDestinations(){
    // clear all destinations
    mDestinations.clear();
    // start from current position
    mDestinations.push_back( mPos );
    // add more destinations
    for( int i=0; i<mNumDestinations-1; i++ ){
        ofVec2f v(ofRandomWidth(), ofRandomHeight());
        mDestinations.push_back( v );
    }
}

void BasicAppendTweenApp::startTweening()
{
    timeline().apply( &mPos).then<RampTo>(mDestinations[0], 0.5f, EaseInOutQuad());
    for( int i=1; i<mNumDestinations; i++ ){
        timeline().append( &mPos).then<RampTo>(mDestinations[i], 0.5f, EaseInOutQuad() );
    }
}

//--------------------------------------------------------------
void BasicAppendTweenApp::keyPressed(int key){

}

//--------------------------------------------------------------
void BasicAppendTweenApp::keyReleased(int key){

}

//--------------------------------------------------------------
void BasicAppendTweenApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void BasicAppendTweenApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void BasicAppendTweenApp::mousePressed(int x, int y, int button){
    setDestinations();
    startTweening();
}

//--------------------------------------------------------------
void BasicAppendTweenApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void BasicAppendTweenApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void BasicAppendTweenApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void BasicAppendTweenApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void BasicAppendTweenApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void BasicAppendTweenApp::dragEvent(ofDragInfo dragInfo){ 

}
