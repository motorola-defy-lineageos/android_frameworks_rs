/*
 * Copyright (C) 2009 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "rsObjectBase.h"
#include <utils/Log.h>

using namespace android;
using namespace android::renderscript;

ObjectBase::ObjectBase()
{
    mRefCount = 0;
}

ObjectBase::~ObjectBase()
{
    rsAssert(!mRefCount);
}

void ObjectBase::incRef() const
{
    mRefCount ++;
    //LOGE("ObjectBase %p inc ref %i", this, mRefCount);
}

void ObjectBase::decRef() const
{
    rsAssert(mRefCount > 0);
    mRefCount --;
    //LOGE("ObjectBase %p dec ref %i", this, mRefCount);
    if (!mRefCount) {
        delete this;
    }
}
