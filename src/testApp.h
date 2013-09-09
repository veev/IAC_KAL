#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "ofxFX.h"
#include "mpeClientTCP.h"
#include "ofxNetwork.h"

class testApp : public ofBaseApp, public mpeClientListener {
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofVideoGrabber video;
    ofxKaleidoscope kal;
    ofxKaleidoscope kal2;
    ofxKaleidoscope kal3;

    ofxUDPManager udpConnection1;
    ofxUDPManager udpConnection2;
    ofxUDPManager udpConnection3;

    ofImage img1;
    ofImage img2;
    ofImage img3;
    
    ofImage test1;
    ofImage test2;
    ofImage test3;
    
    ofBuffer tempBuff;
    
    void frameEvent();
    
private:
    mpeClientTCP  client;
    
};

#endif



