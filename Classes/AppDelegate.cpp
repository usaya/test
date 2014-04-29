#include "AppDelegate.h"
#include "HelloWorldScene.h"

#include "BuilderTest.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();

    pDirector->setOpenGLView(pEGLView);
	
    // turn on display FPS
    pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    // CCScene *pScene = HelloWorld::scene();
    
    CCNodeLoaderLibrary *ccNodeLoaderLibrary = CCNodeLoaderLibrary::sharedCCNodeLoaderLibrary();
    ccNodeLoaderLibrary->registerCCNodeLoader("BuilderTest", BuilderTestLoader::loader());
    
    CCBReader * ccbReader = new CCBReader(ccNodeLoaderLibrary);
    CCScene *scene = ccbReader->createSceneWithNodeGraphFromFile("ccbi_files/RETop.ccbi");
    pDirector->getTouchDispatcher();
    pDirector->runWithScene(scene);
    
    
    // run
    // pDirector->runWithScene(pScene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    CCDirector::sharedDirector()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    CCDirector::sharedDirector()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
