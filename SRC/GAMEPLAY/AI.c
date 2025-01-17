#include "SRC/GENERAL/Common.h"
#include "SRC/GENERAL/Vectors.h"
#include "SRC/SYS/Def_inp.h"
#include "SRC/SYS/Str_sys.h"

#include "Action.h"
#include "Movecoll.h"
#include "Def_ai.h"
#include "Str_wpn.h"

/* AI functions */

extern System_t System;
extern GameData_t Game;
extern Weapon_t Weapons[];

int testLineOfSight(Vec2 p, Vec2 target)
{
    Vec2 v = getVec2(p, target);
    float distance = normalizeAndGetLength(&v);
    float los = 0;
    
    for (los = 0.0; los < distance; los += LOS_STEP)
    {        
        //SET_PIXEL((int)p.x - (CAMERA_OFFSET * SQUARE_SIZE), (int)p.y, COLOUR_WHITE);
        
        if (getTileAt(getGridLocation(p))->obstacle == TRUE)
            return OUT_OF_SIGHT;
        
        p.x += (v.x * LOS_STEP);
        p.y += (v.y * LOS_STEP);
    }
    return IN_SIGHT;
}

int testFieldOfView(Vec2 origin, Vec2 direction, Vec2 target)
{
    Vec2 origin_to_target = getVec2(origin, target);
    float distance_sq = getVec2LengthSquared(origin_to_target);
    float angle;
    
    if (distance_sq < CHASE_DISTANCE_SQ)
    {
        angle = getVec2Angle2(origin_to_target, direction);
        
        if (angle > VIEW_ANGLE_COS && testLineOfSight(origin, target) == IN_SIGHT)
        {
             return IN_SIGHT;
        }
    }

    return OUT_OF_SIGHT;
}

void chaseTarget(Actor_t* chaser)
{
    Vec2 actor_to_target;
    float distance_sq;
    float cross_product;

    #if DEBUG == 1
    char* d;
    #endif

    actor_to_target = getVec2(chaser->position, chaser->move_target);
    distance_sq      = getVec2LengthSquared(actor_to_target);
    cross_product    = crossVec2(actor_to_target, chaser->direction);
    
    if (distance_sq <= MIN_CHASE_DISTANCE_SQ)
        (chaser->control) &= ~CONTROL_UP;
    else
        (chaser->control) |= CONTROL_UP;

    // set direction based on cross product

    if (cross_product > TURN_THRESHOLD)
    {
        (chaser->control) |= CONTROL_LEFT;
        (chaser->control) &= ~CONTROL_RIGHT;
    }
    else if (cross_product < -TURN_THRESHOLD)
    {
        (chaser->control) |= CONTROL_RIGHT;
        (chaser->control) &= ~CONTROL_LEFT;
    }
    else
    {
        (chaser->control) &= ~CONTROL_LEFT;
        (chaser->control) &= ~CONTROL_RIGHT;
    }

    #if DEBUG == 1
    if (System.debug_mode == TRUE)
    {
        d = debug[DEBUG_AICHASE];
        d += sprintf(d, "DISTANCE: %.2f\n", sqrt(distance_sq));
        d += sprintf(d, "ANGLE: %.2lf\n", chaser->angle);
        d += sprintf(d, "CP: %.2f\n", cross_product);
        d += sprintf(d, "DIR-X: %.2f\n", chaser->direction.x);
        d += sprintf(d, "DIR-Y: %.2f", chaser->direction.y);
    }
    #endif
}

void think(Actor_t* actor)
{
    if (Game.ActorsById[actor->target_id_primary] != UINT16_MAX)
    {
        actor->move_target = Game.Actors[Game.ActorsById[actor->target_id_primary]].position;
        // check to see if target in sight; set mode to chase if yes, and timer to 100 ticks
        if (testFieldOfView(actor->position, actor->direction, actor->move_target) == IN_SIGHT)
        {
            actor->ai_mode = AI_CHASE;
            actor->ai_timer = CHASE_TIMEOUT;
        }
    }
    else
    {
        Game.ActorsById[actor->target_id_primary] = UINT16_MAX;
        actor->ai_mode = AI_IDLE;
        actor->control = 0; // same as clearing all bits
    }
}

void act(Actor_t* actor)
{
    if (actor->ai_mode == AI_IDLE)
    {
        if (actor->ai_timer == 0)
        {
            if (!(actor->control & (CONTROL_LEFT|CONTROL_RIGHT)))
            {
                actor->ai_timer = 5 + rand() % 30;
                if (rand() % 2)
                    (actor->control) |= CONTROL_LEFT;
                else
                    (actor->control) |= CONTROL_RIGHT;
            }
            else
            {
                actor->ai_timer = 10 + rand() % 200;
                actor->control = 0;
            }
        }
        else
            actor->ai_timer--;
    }
    else if (actor->ai_mode == AI_CHASE)
    {
        if (testFieldOfView(actor->position, actor->direction, actor->move_target) != IN_SIGHT) // if facing the other way, face target first
        {
            turnTowards(actor, Game.Actors[Game.ActorsById[actor->target_id_primary]].position);
        }

        if (actor->ai_timer > 0)
        {
            chaseTarget(actor);
            if (actor->last_shot + Weapons[actor->primary_weapon_id].shot_delay < System.ticks && testFieldOfView(actor->position, actor->direction, actor->move_target) == IN_SIGHT)
            {
                shootWeapon(actor->primary_weapon_id, actor);
            }

            if (Game.ActorsById[actor->target_id_primary] == UINT16_MAX && actor->target_id_secondary != UINT16_MAX) // if primary target is dead and a secondary target is available
            {
                actor->target_id_primary = actor->target_id_secondary;
                actor->target_id_secondary = UINT16_MAX;
                actor->ai_timer += 50;
            }
            else if (Game.ActorsById[actor->target_id_primary] == UINT16_MAX && actor->target_id_secondary == UINT16_MAX) // if primary target is dead and no secondary target available
            {
                actor->target_id_primary = UINT16_MAX; // remove chase target
                actor->ai_mode = AI_IDLE;
                actor->control = 0; // same as clearing all bits
            }
            actor->ai_timer--;
        }
        else
        {
            actor->ai_mode = AI_IDLE;
            actor->control = 0; // same as clearing all bits
        }
    }
}

void AILoop()
{
    int i;
    if (!(System.ticks % 10)) // only think every 10 tics
    {
        for (i = 1; i < Game.actor_count; i++)
        {
            if (Game.Actors[i].ai_mode != AI_NONE)
            {
                think(&Game.Actors[i]);
                act(&Game.Actors[i]);
            }
        }
    }
    else
    {
        for (i = 1; i < Game.actor_count; i++)
            if (Game.Actors[i].ai_mode != AI_NONE)
                act(&Game.Actors[i]);
    }
}
