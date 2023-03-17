#include "ofApp.h"

//  ADD BEATS TO MUSIC!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


void ofApp::setup(){
	
	// I load the sounds, including music, drum, piano, finger snap, punch, rain and bass!!
	// Load my music:
	bgm.load("sounds/FireWater.mp3");
	snap.load("sounds/snap.mp3");
	cymbal.load("sounds/cymbal.mp3");
	rain.load("sounds/rain.mp3");
	punch.load("sounds/punch.mp3");
	piano.load("sounds/piano.mp3");
	bass.load("sounds/bass.mp3");

	// Volume:
	bgm.setVolume(1.00f);
	snap.setVolume(0.75f);
	cymbal.setVolume(0.35f);
	rain.setVolume(0.10f);
	punch.setVolume(0.65f);
	piano.setVolume(0.65f);
	bass.setVolume(1.00f);

	// Load the font:
	font.load("shamery.ttf", 20);

	//  Multipaby:
	rain.setMultiPlay(false);
	cymbal.setMultiPlay(false);
	snap.setMultiPlay(false);
	punch.setMultiPlay(true);
	piano.setMultiPlay(true);
	bass.setMultiPlay(true);

	// Load my pictures
	ofSetVerticalSync(true);
	img.load("01.jpg");
	ofSetLineWidth(2);

}

//--------------------------------------------------------------

void ofApp::update() {

	// Update the sound playing system:
	ofSoundUpdate();

}

//--------------------------------------------------------------

void ofApp::draw(){
	
	//  My background color
	ofBackground(ofColor::black);
    
	// Draw the original image
	ofSetColor(ofColor::white);
	img.draw(0, 0);

	//  Give my mouse a circle 
	ofSetColor(ofColor::black);
	ofDrawCircle(mouseX, mouseY, 10);
	
	//  Divide the screen into seven parts
	float widthDiv = ofGetWidth() / 7.0f;

	//  Add text to the bottom.
	//  Show the speed and progress of the music.
	//  If music is playing, the text with font will change from black to red.

	//BGM:
	if (bgm.isPlaying()) ofSetHexColor(0xFF0000);
	else ofSetHexColor(0x000000);
	font.drawString("MUSIC", 50, ofGetHeight() - 70);

	ofSetHexColor(0x000000);
	string tempStr ="swipe to change speed\nclick to play\npct done: "+ofToString(bgm.getPosition())+"\nspeed: " + ofToString(bgm.getSpeed()) ;
	ofDrawBitmapString(tempStr, 50,ofGetHeight()-50);

    //RAIN:
	if (rain.isPlaying()) ofSetHexColor(0xFF0000);
	else ofSetHexColor(0x000000);
	font.drawString("RAIN", widthDiv+50, ofGetHeight() - 70);

	ofSetHexColor(0x000000);
	tempStr = "click and play\npct done: "+ofToString(rain.getPosition())+"\nspeed: " +ofToString(rain.getSpeed());
	ofDrawBitmapString(tempStr, widthDiv+50,ofGetHeight()-50);

	//CYMBAL:
	if (cymbal.isPlaying()) ofSetHexColor(0xFF0000);
	else ofSetHexColor(0x000000);
	font.drawString("DRUM", widthDiv*2+50, ofGetHeight() - 70);

	ofSetHexColor(0x000000);
	tempStr = "click to play \npct done: "+ofToString(cymbal.getPosition())+"\nspeed: " + ofToString(cymbal.getSpeed());	
	ofDrawBitmapString(tempStr, widthDiv*2+50,ofGetHeight()-50);

	//SNAP:
	if (snap.isPlaying()) ofSetHexColor(0xFF0000);
	else ofSetHexColor(0x000000);
	font.drawString("SNAP", widthDiv * 3 + 50, ofGetHeight() - 70);

	ofSetHexColor(0x000000);
	tempStr = "click to play \npct done: " + ofToString(snap.getPosition()) + "\nspeed: " + ofToString(snap.getSpeed());
	ofDrawBitmapString(tempStr, widthDiv *3 + 50, ofGetHeight() - 50);

    //PUNCH
	if (punch.isPlaying()) ofSetHexColor(0xFF0000);
	else ofSetHexColor(0x000000);
	font.drawString("PUNCH", widthDiv *4 + 50, ofGetHeight() - 70);

	ofSetHexColor(0x000000);
	tempStr = "click to play \npct done: " + ofToString(punch.getPosition()) + "\nspeed: " + ofToString(punch.getSpeed());
	ofDrawBitmapString(tempStr, widthDiv *4 + 50, ofGetHeight() - 50);

	//PIANO
	if (piano.isPlaying()) ofSetHexColor(0xFF0000);
	else ofSetHexColor(0x000000);
	font.drawString("PIANO", widthDiv *5 + 50, ofGetHeight() - 70);

	ofSetHexColor(0x000000);
	tempStr = "click to play \npct done: " + ofToString(piano.getPosition()) + "\nspeed: " + ofToString(piano.getSpeed());
	ofDrawBitmapString(tempStr, widthDiv * 5+ 50, ofGetHeight() - 50);
	
	//BASS
	if (bass.isPlaying()) ofSetHexColor(0xFF0000);
	else ofSetHexColor(0x000000);
	font.drawString("BASS", widthDiv * 6+ 50, ofGetHeight() - 70);

	ofSetHexColor(0x000000);
	tempStr = "click to play \npct done: " + ofToString(bass.getPosition()) + "\nspeed: " + ofToString(bass.getSpeed());
	ofDrawBitmapString(tempStr, widthDiv * 6 + 50, ofGetHeight() - 50);

}


//--------------------------------------------------------------
void ofApp::keyPressed  (int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
	
	// Drag the mouse to control the speed of the music, drag up to speed up, drag down to slow down!!

	float widthStep = ofGetWidth() / 7.0f;
	if (x < widthStep) {
		bgm.setSpeed(0.5f + ((float)(ofGetHeight() - y) / (float)ofGetHeight()) * 1.0f);
	}

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	
	// Divide the screen into seven parts!!!
	// When I presse the mouse button!! It can play music!!
	
	float widthStep = ofGetWidth() / 7.0f;
	if (x < widthStep){
		
		bgm.play();
	
	} else if (x >= widthStep && x < widthStep*2) {
		
		rain.play();	
	
	} else if (x >= widthStep*2 && x < widthStep * 3) {
		
		// The speed increases with the height of the mouse click.
		
		cymbal.play();
		cymbal.setSpeed( 0.1f + ((float)(ofGetHeight() - y) / (float)ofGetHeight())*4);
		cymbal.setPan( ofMap(x, widthStep*2, widthStep*3, -1, 1, true) );
	
	} else if (x >= widthStep * 3 && x < widthStep * 4) {
		
		snap.play();
		snap.setSpeed(0.1f + ((float)(ofGetHeight() - y) / (float)ofGetHeight()) * 3);
		snap.setPan(ofMap(x, widthStep * 3, widthStep * 4, -1, 1, true));
	
	} else if (x >= widthStep * 4 && x < widthStep * 5) {
		
		punch.play();
		punch.setSpeed(0.1f + ((float)(ofGetHeight() - y) / (float)ofGetHeight()) * 5);
		punch.setPan(ofMap(x, widthStep * 4, widthStep * 5, -1, 1, true));
	
	} else if (x >= widthStep * 5 && x < widthStep * 6) {
		
		piano.play();
		piano.setSpeed(0.1f + ((float)(ofGetHeight() - y) / (float)ofGetHeight()) * 5);
		piano.setPan(ofMap(x, widthStep * 5, widthStep * 6, -1, 1, true));
	
	}  else {
		
		bass.play();
		bass.setSpeed(0.1f + ((float)(ofGetHeight() - y) / (float)ofGetHeight()) * 5);
	    bass.setPan(ofMap(x, widthStep * 6, widthStep *7, -1, 1, true));
	}
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