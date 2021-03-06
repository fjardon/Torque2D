//-----------------------------------------------------------------------------
// Copyright (c) 2013 GarageGames, LLC
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
//-----------------------------------------------------------------------------

#include "platform/platform.h"
#include "sim/simBase.h"
#include "console/consoleTypes.h"
#include "sim/scriptObject.h"
#include "sim/simBase.h"

//-----------------------------------------------------------------------------

IMPLEMENT_CONOBJECT(ScriptObject);

//-----------------------------------------------------------------------------

ScriptObject::ScriptObject()
{
   mNSLinkMask = LinkSuperClassName | LinkClassName;
}

//-----------------------------------------------------------------------------

bool ScriptObject::onAdd()
{
   if (!Parent::onAdd())
      return false;

   // Call onAdd in script!
   Con::executef(this, 2, "onAdd", Con::getIntArg(getId()));
   return true;
}

//-----------------------------------------------------------------------------

void ScriptObject::onRemove()
{
   // Call onRemove in script!
   Con::executef(this, 2, "onRemove", Con::getIntArg(getId()));

   // Call parent.
   Parent::onRemove();
}
