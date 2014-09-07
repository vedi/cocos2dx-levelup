//
// Created by Shubin Fedor on 22/08/14.
// Copyright (c) 2014 SOOMLA. All rights reserved.
//

#include "CCVirtualItemScore.h"
#include "CCError.h"
#include "CCStoreInventory.h"
#include "CCSoomlaUtils.h"

namespace soomla {
#define TAG "SOOMLA VirtualItemScore"


    CCVirtualItemScore *CCVirtualItemScore::create(cocos2d::CCString *id, cocos2d::CCString *associatedItemId) {
        return CCVirtualItemScore::create(id, NULL, NULL, associatedItemId);
    }

    CCVirtualItemScore *CCVirtualItemScore::create(cocos2d::CCString *id, cocos2d::CCString *name, cocos2d::CCBool *higherBetter, cocos2d::CCString *associatedItemId) {
        CCVirtualItemScore *ret = new CCVirtualItemScore();
        if (ret->init(id, name, higherBetter, associatedItemId)) {
            ret->autorelease();
        }
        else {
            CC_SAFE_DELETE(ret);
        }

        return ret;
    }

    bool CCVirtualItemScore::init(cocos2d::CCString *id, cocos2d::CCString *name, cocos2d::CCBool *higherBetter, cocos2d::CCString *associatedItemId) {
        bool result = CCScore::init(id, name, higherBetter);
        if (result) {
            setAssociatedItemId(associatedItemId);
            return true;
        }
        return result;
    }

    bool CCVirtualItemScore::initWithDictionary(cocos2d::CCDictionary *dict) {
        bool result = CCScore::initWithDictionary(dict);
        if (result) {
            cocos2d::CCString *itemIdDict = dynamic_cast<cocos2d::CCString *>(
                    dict->objectForKey(CCLevelUpConsts::JSON_LU_ASSOCITEMID));
            if (itemIdDict) {
                setAssociatedItemId(itemIdDict);
            }
            return true;
        }
        return result;
    }

    cocos2d::CCDictionary *CCVirtualItemScore::toDictionary() {
        cocos2d::CCDictionary *dict = CCScore::toDictionary();

        if (mAssociatedItemId) {
            dict->setObject(mAssociatedItemId, CCLevelUpConsts::JSON_LU_ASSOCITEMID);
        }

        return dict;
    }

    void CCVirtualItemScore::performSaveActions() {
        CCScore::performSaveActions();

        CCError *error = NULL;
        int amount = (int) getTempScore();
        CCStoreInventory::sharedStoreInventory()->giveItem(mAssociatedItemId->getCString(), amount, &error);
        if (error) {
            CCSoomlaUtils::logError(TAG, cocos2d::CCString::createWithFormat(
                    "Couldn't find item associated with a given VirtualItemScore. itemId: %s",
                    mAssociatedItemId->getCString())->getCString());
            CCSoomlaUtils::logError(TAG, error->getInfo());
        }
    }
}