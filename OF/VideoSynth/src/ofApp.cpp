#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle( "Video synth" );
    ofSetWindowShape( 1280, 720 );
    ofSetFrameRate( 60 );
    ofBackground( ofColor::white );
    
    gui.setup( "Parameters", "settings.xml" );
    gui.add( countX.setup( "countX", 50, 0, 200 ) );
    gui.add( stepX.setup( "stepX", 20, 0, 200 ) );
    gui.add( twistX.setup( "twistX", 5, -45, 45 ) );

    globalGroup.setup( "Global" );
    globalGroup.add( Scale.setup( "Scale", 1, 0.0, 1 ) );
    globalGroup.add( Rotate.setup( "Rotate", 0, -180, 180 ) );
    globalGroup.add( Background.setup("Background",255,0, 255));
    gui.add( &globalGroup );

    
    primGroup.setup( "Primitive" );
    primGroup.add( shiftY.setup("shiftY",0.0,-1000.0,1000.0 ) );
    primGroup.add( rotate.setup("rotate",0.0,-180.0,180.0 ) );
    primGroup.add( size.setup( "size",
    ofVec2f(6,6), ofVec2f(0,0), ofVec2f(20,20) ) );
    primGroup.add( color.setup( "color", ofColor::black, ofColor(0,0,0,0), ofColor::white ) );
    primGroup.add( filled.setup( "filled", false ) );
    primGroup.add( type.setup( "type", false ) );
    gui.add( &primGroup );

    //load the saved gui state
    gui.loadFromFile( "settings.xml" );
    
    showGui = true;

}

//--------------------------------------------------------------
void ofApp::update(){

}

void ofApp::stripePattern() {
   
    ofSetColor( color );
    ofSetLineWidth( 1 );
    if ( filled ) ofFill(); else ofNoFill(); for (int i=-countX; i<=countX; i++) {
        ofPushMatrix();
        ofTranslate( i * stepX, 0 );
        ofRotate( i * twistX );
        ofTranslate( 0, shiftY );
        ofRotate( rotate );
        ofScale( size->x, size->y );
        if ( type ) ofRect( -50, -50, 100, 100 );
        else ofTriangle( 0, 0, -50, 100, 50, 100 );
        ofPopMatrix();
    }
    ofScale( 6, 6 );
    ofTriangle( 0, 0, -50, 100, 50, 100 );
}
//this function saves the state of the gui elements to the settings.xml file,
//which is located in the bin/data folder of the project.
void ofApp::exit() {
    gui.saveToFile( "settings.xml" );
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground( Background );
    ofPushMatrix();
    ofTranslate( ofGetWidth() / 2, ofGetHeight() / 2 );
    float Scl = pow( Scale, 4.0f );
    ofScale( Scl, Scl );
    ofRotate( Rotate );
    
    stripePattern();
    ofPopMatrix();

    if ( showGui ) gui.draw();
}

//--------------------------------------------------------------
//This line checks whether Z is pressed and then inverts the showGui value
//using the negotiation operator !
void ofApp::keyPressed(int key){
    if ( key == 'z' ) showGui = !showGui;
    if ( key == 's' ) {
        ofFileDialogResult res;
        res = ofSystemSaveDialog( "preset.xml", "Saving Preset" ); if ( res.bSuccess ) gui.saveToFile( res.filePath );
    }
    if ( key == 'l' ) {
        ofFileDialogResult res;
        res = ofSystemLoadDialog( "Loading Preset" );
        if ( res.bSuccess ) gui.loadFromFile( res.filePath );
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
   if ( key == OF_KEY_RETURN ) ofSaveScreen( "screenshot.png" );
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
