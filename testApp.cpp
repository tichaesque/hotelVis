#include "testApp.h"
#include <stdio.h>
#include <stdlib.h>


//--------------------------------------------------------------
void testApp::setup(){
    
    int height = ofGetHeight();
    int width = ofGetWidth();

	// Load a CSV File.
	csv.loadFile(ofToDataPath("hotelsbase.csv"), "~");
    
    ofSetVerticalSync(true);
    ofSetFrameRate(50);
    //ofEnableAlphaBlending();
    ofBackground(0,0,0);
    
    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);
    //glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_POINT_SMOOTH);
    
    //points.assign(csv.numRows,ofPoint());
    
    mesh.setMode(OF_PRIMITIVE_POINTS);
    
    for (int i=1; i<csv.numRows; i++) {
        /*ofPoint &p = points[i];
        
        p.x = 3*ofToFloat(csv.data[i][13]);
        p.y = -3*ofToFloat(csv.data[i][12]);
        //p.z = csv.data[i][1].length(); //length of name
        p.z = ofToFloat(csv.data[i][3]); //price
        //p.z = ofToFloat(csv.data[i][17]); //rooms
        //p.z = ofToFloat(csv.data[i][18]); //facilities*/
        
        mesh.addVertex(ofPoint(3*ofToFloat(csv.data[i][13]),3*ofToFloat(csv.data[i][12]), csv.data[i][1].length()));
        //mesh.addColor(ofFloatColor(100, 300*sin(ofToFloat(csv.data[i][3])),200));
        mesh.addColor(ofFloatColor(0.2, 0.005*ofToFloat(csv.data[i][3]), 0.7));
    }

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    /*ofPushMatrix();
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2, 0);
    
    for (int i=0; i<points.size(); i++) {
        ofPoint &p = points[i];
        ofPushMatrix();
        ofSetColor(80,300*sin(p.z),200);
        ofFill(); 
        
        ofCircle(p.x, p.y, 0.5);
        ofPopMatrix();
    }
    
    ofPopMatrix();*/
    cam.begin();
    //ofTranslate(ofGetWidth()/2, ofGetHeight()/2, 0);
    mesh.draw();
    cam.end();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == 's') {
        ofSaveFrame();
        printf("frame saved");
    }
    
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
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	
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
