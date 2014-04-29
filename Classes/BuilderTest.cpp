//
//  BuilderTest.cpp
//  MyGame20140426
//
//  Created by Suto Atsushi on 2014/04/29.
//
//

#include "BuilderTest.h"

BuilderTest::BuilderTest()
:pLabelTotalPosition(NULL)
,pLabelHighScore(NULL)
,pLabelTotalScore(NULL)
,pSpriteJobHunterLeft(NULL)
,pSpriteJobHunterRight(NULL)
{
 
}

BuilderTest::~BuilderTest(){

}

SEL_MenuHandler BuilderTest::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName){
    return NULL;
}

SEL_CCControlHandler BuilderTest::onResolveCCBCCControlSelector(CCObject *pTarget, const char * pSelectorName) {
    return NULL;
}

bool BuilderTest::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode){
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "totalPosition",  CCLabelTTF *, this->pLabelTotalPosition);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "highScore",      CCLabelTTF *, this->pLabelHighScore);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "totalScore",     CCLabelTTF *, this->pLabelTotalScore);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "jobHunterLeft",  CCSprite *, this->pSpriteJobHunterLeft);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "jobHunterRight", CCSprite *, this->pSpriteJobHunterRight);
    return false;
}

void BuilderTest::onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader){
}

bool BuilderTest::init(){
    return true;
}

void BuilderTest::onEnter(){
    CCLayer::onEnter();
}

void BuilderTest::onExit() {
	CCLayer::onExit();
}
