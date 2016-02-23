#include "AdvancedTweenApp.h"
#include "ofxChoreograph.h"

using namespace ofxChoreograph;

Timeline timeline;

Output<ofVec3f>pos;
Output<ofQuaternion>rot;
vector<Output<ofVec3f>> outputs;

ofVec3f randv(){
    return ofVec3f(ofRandomWidth(),ofRandomHeight(),ofRandom(-500, 500));
}
//--------------------------------------------------------------
void AdvancedTweenApp::setup(){
    auto m = timeline.apply(&pos);
    m.then<RampTo>(ofVec3f(ofGetWidth()/2.0, ofGetHeight()/2.0,0), 1);
    ofSetFrameRate(60);
    
    while (outputs.size()<10000) {
        outputs.emplace_back();
    }
    int i=0;
    for(auto &v: outputs){
        auto m = Sequence<ofVec3f>(randv());
        m.then<RampTo>(randv(),1);
        m.then<RampTo>(randv(),1);
        m.then<RampTo>(ofVec3f(ofGetWidth()/2.0, ofGetHeight()/2.0, 0),1);
        m.then(makeProcedure<ofVec3f>(1, [&i](Time t, Time duration){
            float px = cos(i/10000.*TWO_PI) * 300 * t/duration + ofGetWidth()/2.0;
            float py = sin(i/10000.*TWO_PI) * 300 * t/duration + ofGetHeight()/2.0;
            i++; // i should be here
            return ofVec3f(px, py, 0);
        }));
        timeline.apply(&v, m);
    }
}

//--------------------------------------------------------------
void AdvancedTweenApp::update(){
    timeline.step(1/60.);
}

//--------------------------------------------------------------
void AdvancedTweenApp::draw(){
    ofBackground(0);
    stringstream stream;
    stream << "fps:"<< ofGetFrameRate() << endl;
    stream << "num of particles" << outputs.size() << endl;
    stream << "a: cancel a phrase and add a new random position phrase" << endl;
    stream << "s: append a new random position phrase" << endl;
    stream << "d: cancel the current rotation phrase and add a new rotation phrase" << endl;
    stream << "f: cancel a phrase add particle and random position phrase" << endl;
    stream << "g: cancel a phrase go to sphere position phrase" << endl;
    
    ofSetColor(255, 255, 255);
    ofDrawBitmapString(stream.str() , 10, 10);
    
    ofMatrix4x4 mat;
    mat.rotate(rot.value());
    mat.translate(pos.value());
    ofPushMatrix();
    ofMultMatrix(mat);
    ofSetColor(255, 0, 0);
    ofNoFill();
    ofDrawBox(40);
    ofPopMatrix();
    
    ofSetColor(5, 125, 255,100);
    ofFill();
    glBegin(GL_POINTS);
    for(auto &v: outputs){
        glVertex3fv(v.value().getPtr());
        glColor3f(0.1, 1., 0.5);
    }
    glEnd();
}

//--------------------------------------------------------------
void AdvancedTweenApp::keyPressed(int key){
    
    // apply new phrase
    if(key == 'a'){
        auto m = timeline.apply(&pos);
        m.then<RampTo>(randv(), 2);
        for( auto &output : outputs ) {
            auto m = timeline.apply(&output);
            m.then<RampTo>(randv(), 2);
        }
    }
    //cancel a current phrase and add a new phrase
    if(key == 's'){
        auto m = timeline.append(&pos);
        m.then<RampTo>(randv(), 2);
        
        for( auto &output : outputs ) {
            auto m = timeline.append(&output);
            m.then<RampTo>(randv(), 2);
        }
    }
    //cancel a current rotation phrase and add a new phrase
    if(key == 'd'){
        auto m= timeline.apply(&rot);
        m.then<RampTo>(ofQuaternion(ofRandom(360), ofVec3f(1, 0, 0),
                                    ofRandom(360), ofVec3f(0, 1, 0),
                                    ofRandom(360), ofVec3f(0, 0, 1)), 2);
    }
    //add particle with animation
    if(key == 'f'){
        for(int i=0;i<100;i++){
            outputs.emplace_back(); //don't use push_back
            
            ofQuaternion q(ofRandom(-180, 180), ofVec3f(1, 0, 0),
                                        ofRandom(-90,90), ofVec3f(0, 1, 0),
                                        0, ofVec3f(0, 0, 1));
            
            
            timeline.apply(&outputs.back()).set(randv())
            .then<RampTo>(randv(), 1)
            .then<RampTo>(randv(), 1)
            .then<RampTo>(q * ofVec3f(0,0,100) + ofVec3f(ofGetWidth()/2.0, ofGetHeight()/2.0,0), 1);
        }
    }
    //cancel a current animation and add a new phrase
    if(key == 'g'){
        for(auto &v:outputs){
            timeline.apply(&v)
            .then<RampTo>(ofVec3f(ofGetWidth()/2.0, ofGetHeight()/2.0,0), 1)
            .then(makeProcedure<ofVec3f>(3.0, [](Time t, Time duration){
                ofQuaternion q(ofRandom(-180, 180), ofVec3f(1, 0, 0),
                               ofRandom(-90,90), ofVec3f(0, 1, 0),
                               0, ofVec3f(0, 0, 1));
                ofVec3f pv = q * ofVec3f(0,0, 400 * t/duration) + ofVec3f(ofGetWidth()/2.0, ofGetHeight()/2.0,0);
                return pv;
            }
            ));
        }
    }
}

//--------------------------------------------------------------
void AdvancedTweenApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void AdvancedTweenApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void AdvancedTweenApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void AdvancedTweenApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void AdvancedTweenApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void AdvancedTweenApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void AdvancedTweenApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void AdvancedTweenApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void AdvancedTweenApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void AdvancedTweenApp::dragEvent(ofDragInfo dragInfo){
    
}
