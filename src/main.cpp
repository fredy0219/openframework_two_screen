#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
//    ofSetupOpenGL(1024,768,OF_WINDOW);            // <-------- setup the GL context
//
//    // this kicks off the running of my app
//    // can be OF_WINDOW or OF_FULLSCREEN
//    // pass in width and height too:
//    ofRunApp(new ofApp());
    
        ofGLFWWindowSettings settings;
        settings.setSize(1920, 1080);
        settings.monitor = 0;
        settings.setPosition(glm::vec2(0,0));
        settings.windowMode = OF_FULLSCREEN;
    
        settings.resizable = false;
        settings.decorated = true;
        shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
    
        settings.setSize(1920, 1080);
    
    
        settings.monitor = 1;
        settings.setPosition(glm::vec2(0,0));
    
    
        settings.setPosition(glm::vec2(-1920,0));
        settings.resizable = false;
        shared_ptr<ofAppBaseWindow> diagramWindow = ofCreateWindow(settings);
        diagramWindow->setVerticalSync(false);
    
        shared_ptr<ofApp> mainApp(new ofApp);
        //mainApp->setupSecondScreen();
        ofAddListener(diagramWindow->events().draw, mainApp.get(), &ofApp::drawSecondScreen);
    
        ofRunApp(mainWindow, mainApp);
        ofRunMainLoop();

}
