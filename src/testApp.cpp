#include "testApp.h"

#define RECONNECT_TIME 400

//--------------------------------------------------------------
void testApp::setup(){
	// initialize app
    ofSetLogLevel(OF_LOG_VERBOSE);
    ofSetVerticalSync(true);
	ofSetFrameRate(30);
    ofEnableSmoothing();
	ofSetBackgroundAuto(false);
    
	client.setup("settings.xml", this);
    
    //init camera
    //video.initGrabber(640, 480);
    
    //create the socket and bind to port 11999
	udpConnection1.Create();
	udpConnection1.Bind(11999);
	udpConnection1.SetNonBlocking(true);
    
    //create the socket and bind to port 12000
	udpConnection2.Create();
	udpConnection2.Bind(12000);
	udpConnection2.SetNonBlocking(true);

    //create the socket and bind to port 12001
	udpConnection3.Create();
	udpConnection3.Bind(12001);
	udpConnection3.SetNonBlocking(true);
    
    //allocate kaleidoscope
    kal.allocate(640, 480, GL_RGBA);
    kal2.allocate(640, 480, GL_RGBA);
    kal3.allocate(640, 480, GL_RGBA);
    
    //tempBuff.allocate(230400);
    
	// start client
    client.start();
    
    ofBackground(50, 50, 50);

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

}

//--------------------------------------------------------------
void testApp::frameEvent() {
    
    
    
    char udpMessage1[230400];
    
    udpConnection1.Receive(udpMessage1,230400);
	ofBuffer buffer1 = ofBuffer(udpMessage1, 230400);
    
//    client.broadcast(ofToString(buffer1) + ",");
//    client.broadcast(",");
	
    if(test1.loadImage(buffer1)){
        img1.setFromPixels(test1.getPixelsRef());
        //img2.setFromPixels(test1.getPixelsRef());
        cout << "set pixels" << endl;
    }
    
    char udpMessage2[230400];
    
    udpConnection2.Receive(udpMessage2,230400);
	ofBuffer buffer2 = ofBuffer(udpMessage2, 230400);
    
    //    client.broadcast(ofToString(buffer1) + ",");
    //    client.broadcast(",");
	
    if(test2.loadImage(buffer2)){
        img2.setFromPixels(test2.getPixelsRef());
        cout << "set pixels" << endl;
    }

    char udpMessage3[230400];
    
    udpConnection3.Receive(udpMessage3,230400);
	ofBuffer buffer3 = ofBuffer(udpMessage3, 230400);
    
    //    client.broadcast(ofToString(buffer1) + ",");
    //    client.broadcast(",");
	
    if(test3.loadImage(buffer3)){
        img3.setFromPixels(test3.getPixelsRef());
        cout << "set pixels" << endl;
    }
    
    kal.setTexture(img1.getTextureReference(), 0);
    kal.setRotation(client.getFrameCount()*0.004);
    kal.update();

    kal2.setTexture(img2.getTextureReference(), 0);
    kal2.setRotation(client.getFrameCount()*0.004);
    kal2.update();
    
    kal3.setTexture(img3.getTextureReference(), 0);
    kal3.setRotation(client.getFrameCount()*0.004);
    kal3.update();
    
    int xskip = 416;
    int yskip= 720;
    
    //draw kaleidoscope on client0
    for (int y = -360; y < 361; y += yskip)
        for (int x = -324; x < client.getMWidth(); x += xskip) {
            kal.draw(x, y);
            //kal2.draw(x, y);
            //kal3.draw(x, y);
            
            //kal.draw(x + (xskip*7), y);
            //kal.draw(x + (xskip*18), y);
            ofPushStyle();
            ofSetColor(255, 0, 0);
            ofRect(x, y, 10, 10);
            ofPopStyle();
            ofPushStyle();
            ofSetColor(0, 255, 0);
            ofRect(x + (xskip*7), y, 10, 10);
            ofPopStyle();
            ofPushStyle();
            ofSetColor(0, 0, 255);
            ofRect(x + (xskip*18), y, 10, 10);
            ofPopStyle();

        }

    for (int y = 0; y < 361; y += yskip)
        for (int x = -116; x < client.getMWidth(); x += xskip) {
            kal.draw(x, y);
            //kal2.draw(x, y);
            //kal3.draw(x, y);
            //kal2.draw(x + (xskip*7), y);
            //kal3.draw(x + (xskip*18), y);
            ofPushStyle();
            ofSetColor(255, 0, 0);
            ofRect(x, y, 10, 10);
            ofPopStyle();
            ofPushStyle();
            ofSetColor(0, 255, 0);
            ofRect(x + (xskip*7), y, 10, 10);
            ofPopStyle();
            ofPushStyle();
            ofSetColor(0, 0, 255);
            ofRect(x + (xskip*18), y, 10, 10);
            ofPopStyle();
        }
    

    
//    img1.draw(0,720);
//    img1.draw(3640,720);
//    img2.draw(3640,720);
//    img2.draw(7480,720);
//    img3.draw(7480, 720);
//    
//    kal.draw(0,0);
//    kal.draw(3640, 0);
//    //kal.clear();
//    kal2.draw(3640, 0);
//
//    kal2.draw(7480, 0);
//    //kal2.clear();
//    kal3.draw(7480, 0);

    if (client.messageAvailable()) {
        vector<string> msg = client.getDataMessage();
//        vector<string> splitMsg = ofSplitString(msg[0], ",");
//        char tempMsg = ofToChar(splitMsg[0]);
//        tempBuff.set(&tempMsg, msg.size());
        
    
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
void testApp::mousePressed(int x, int y, int button) {
    // never include a ":" when broadcasting your message
    //x += client.getXoffset();
    //y += client.getYoffset();
    //client.broadcast(ofToString(x) + "," + ofToString(y));
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
