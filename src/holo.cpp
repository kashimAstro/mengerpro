#include "holo.h"
int w,h;

void holo::setup() {
   xholo.load("meneger_jo.vertex","meneger_jo.fragment");
   w=ofGetScreenWidth();
   h=ofGetScreenHeight();
   fbo.allocate(w,h, GL_RGBA);
}


//--------------------------------------------------------------
void holo::update() {
   ofSetWindowTitle(ofToString(ofGetFrameRate()));
   fbo.begin();
   ofClear(255,255,255,0);
   fbo.end();
}

//--------------------------------------------------------------
void holo::draw() {   
     xholo.begin();
     xholo.setUniform3f("resol", w,h,0);
     xholo.setUniform1f("time", -ofGetElapsedTimef());
     xholo.setUniform4f("mouse", ofMap(mouseX,0.0,w,-10.0,10.0),ofMap(mouseY,0.0,h,-10.0,10.0),0,0);
     fbo.draw(0,0);
     xholo.end();
}

//--------------------------------------------------------------
void holo::keyPressed(int key){
	if(key=='s')
		ofSaveFrame();
}

//--------------------------------------------------------------
void holo::keyReleased(int key){
	if(key == 'f')
		ofToggleFullscreen();
}

//--------------------------------------------------------------
void holo::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void holo::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void holo::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void holo::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void holo::windowResized(int w, int h){

}

//--------------------------------------------------------------
void holo::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void holo::dragEvent(ofDragInfo dragInfo){ 

}
