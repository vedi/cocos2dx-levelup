/*
 Copyright (C) 2012-2014 Soomla Inc.

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */
 
#ifndef __TestingLevelUpEventHandler_H
#define __TestingLevelUpEventHandler_H

#include "cocos2d.h"
#include "Cocos2dxLevelUp.h"
#include "BaseTestingEventHandler.h"

class TestingLevelUpEventHandler : public BaseTestingEventHandler {
    
public:
    TestingLevelUpEventHandler();
    ~TestingLevelUpEventHandler();
    void onLevelUpInitialized(cocos2d::EventCustom *event);
    
    void onScoreRecordReached(cocos2d::EventCustom *event);
    void onScoreRecordChanged(cocos2d::EventCustom *event);
    
    void onGateOpened(cocos2d::EventCustom *event);
    
    void onMissionCompleted(cocos2d::EventCustom *event);
    void onMissionCompletionRevoked(cocos2d::EventCustom *event);
    
    void onWorldCompleted(cocos2d::EventCustom *event);
    void onWorldRewardAssigned(cocos2d::EventCustom *event);
    
    void onLevelStarted(cocos2d::EventCustom *event);
    void onLevelEnded(cocos2d::EventCustom *event);
};

#endif // __TestingLevelUpEventHandler_H
