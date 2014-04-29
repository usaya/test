//
//  BuilderTest.h
//  MyGame20140426
//
//  Created by Suto Atsushi on 2014/04/29.
//
//

#ifndef __MyGame20140426__BuilderTest__
#define __MyGame20140426__BuilderTest__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class BuilderTest
: public CCLayer
, public CCBSelectorResolver
, public CCBMemberVariableAssigner
, public CCNodeLoaderListener
{

public:
    BuilderTest(); // コンストラクタ
    virtual ~BuilderTest(); // でコンストラクタ
    
    // さんではonNodeLoadedまでマクロにしてましたね。
    CREATE_FUNC(BuilderTest);
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName);
    virtual SEL_CCControlHandler onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName);
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    virtual void onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader);
    void menuCloseCallback(CCObject* pSender);
    
    bool init();
    void onEnter();
    void onExit();
protected:
    CCLabelTTF *pLabelTotalPosition;
    CCLabelTTF *pLabelHighScore;
    CCLabelTTF *pLabelTotalScore;
    CCSprite *pSpriteJobHunterLeft;
    CCSprite *pSpriteJobHunterRight;
    
};

class BuilderTestLoader : public CCLayerLoader {
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(BuilderTestLoader, loader);
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(BuilderTest);
};

#endif /* defined(__MyGame20140426__BuilderTest__) */
