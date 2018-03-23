/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef PINK_LEAD_ACTOR_H
#define PINK_LEAD_ACTOR_H

#include "actor.h"

namespace Pink {

class CursorMgr;
class WalkMgr;
class Sequencer;

class LeadActor : public Actor {
public:
    enum State {
        kReady = 0,
        kMoving,
        kInDialog1, //???
        kInventory,
        kPDA,
        kInDialog2,//???
        kPlayingVideo, // ???
        kUnk_Loading // ????
    };

    virtual void deserialize(Archive &archive);

    virtual void toConsole();

    void setNextExecutors (Common::String &nextModule, Common::String &nextPage);
    virtual void init(bool unk);

    State getState() const;

    void start(bool isHandler);

private:
    State _state;
    CursorMgr *_cursorMgr;
    WalkMgr *_walkMgr;
    Sequencer *_sequencer;
};


class ParlSqPink : public LeadActor {
public:
    void toConsole();
};

class PubPink : public LeadActor {
public:
    void toConsole();
};


} // End of namespace Pink

#endif