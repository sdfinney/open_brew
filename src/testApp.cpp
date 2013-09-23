#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    string host = Spacebrew::SPACEBREW_CLOUD; // "localhost";
    string name = "openbrew";
    string description = "drink up";
    
    spacebrew.addPublish("openbrew", Spacebrew::TYPE_BOOLEAN);
    spacebrew.addSubscribe("redfilter", Spacebrew::TYPE_BOOLEAN); //"boolean" ); // just typing "boolean" also works
    spacebrew.connect( host, name, description );
    
    // listen to spacebrew events
    Spacebrew::addListener(this, spacebrew);
    
	ofBackground(0,0,0);
    openbrew.loadMovie("movies/drinking.mov");
	openbrew.play();

    redfilter=false;
}

//--------------------------------------------------------------
void testApp::update(){
    openbrew.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    openbrew.draw(0,25);
    if (!redfilter) {
        ofSetColor(255, 255, 255);
    } else {
        ofSetColor(150, 20, 20);
    }


    
}

//--------------------------------------------------------------
void testApp::onMessage( Spacebrew::Message & m ){
    if ( m.name == "redfilter" ){
        redfilter = m.valueBoolean();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    redfilter=true;
    spacebrew.sendBoolean("openbrew", true);

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    redfilter=false;
    spacebrew.sendBoolean("openbrew", false);
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
