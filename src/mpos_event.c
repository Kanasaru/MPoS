/*
    MPOS_Event: A module of the mpos library to provide event handling.
    License:    zlib license
*/
#include <SDL2/SDL.h>

#include "../include/mpos_event.h"


MPOS_EventQueue * MPOS_EventQueueCreate(void)
{
    size_t gms = sizeof(MPOS_EventQueue);
    MPOS_EventQueue *eq = (MPOS_EventQueue*) malloc(gms);

    if (eq != NULL)
    {
        eq->ev_c = 0;
        eq->ev_qc = 0;
    }

    return eq;
}

u_int32_t MPOSEventPoll(MPOS_EventQueue *eq, MPOS_Event *event, u_int8_t flag)
{
    if (eq->ev_c == 0)
    {
        return 0;
    }

    if (eq->ev_qc >= eq->ev_c)
    {
        eq->ev_qc = 0;
        return 0;
    }

    (*event) = eq->events[eq->ev_qc];

    if (flag == MPOS_EV_QUEUE_DELETE)
    {
        MPOS_EventRemoveFromQueue(eq, eq->ev_qc);
    }

    eq->ev_qc++;

    return 1;
}

u_int32_t MPOS_EventPollType(MPOS_EventQueue *eq, MPOS_Event *event, 
                             uint16_t type, u_int8_t flag)
{
    if (eq->ev_c == 0)
    {
        return 0;
    }

    if (eq->ev_qc >= eq->ev_c)
    {
        eq->ev_qc = 0;
        return 0;
    }

    while (eq->ev_qc < eq->ev_c)
    {
        if (eq->events[eq->ev_qc].type == type)
        {
            (*event) = eq->events[eq->ev_qc];
            if (flag == MPOS_EV_QUEUE_DELETE)
            {
                MPOS_EventRemoveFromQueue(eq, eq->ev_qc);
            }
            eq->ev_qc++;
            return 1;
        }
        eq->ev_qc++;
    }

    return 0;
}

void MPOS_EventPush(MPOS_EventQueue *eq, MPOS_Event event)
{
    size_t gms = sizeof(MPOS_EventQueue);
    gms += (eq->ev_c + 1) * sizeof(MPOS_Event);
    eq = (MPOS_EventQueue*) realloc(eq, gms);

    if (eq != NULL)
    {
        eq->events[eq->ev_c] = event;

        eq->ev_c++;
    }
}

void MPOS_EventRemoveFromQueue(MPOS_EventQueue *eq, u_int32_t e_k)
{
    for (size_t j = e_k; j < eq->ev_c - 1; j++)
    {
        eq->events[j] = eq->events[j + 1];
    }
    eq->ev_c--;

    size_t gms = sizeof(MPOS_EventQueue);
    gms += eq->ev_c * sizeof(MPOS_Event);
    eq = (MPOS_EventQueue*) realloc(eq, gms);
}

void MPOS_EventRemoveTypeFromQueue(MPOS_EventQueue *eq, uint16_t type)
{
    for (size_t i = 0; i < eq->ev_c; i++)
    {
        if (eq->events[i].type == type)
        {
            MPOS_EventRemoveFromQueue(eq, i);
        }
    }
}

void MPOS_EventQueueDelete(MPOS_EventQueue *eq)
{
    free(eq);
}

void MPOS_EventQueueReset(MPOS_EventQueue *eq)
{
    if (eq != NULL)
    {
        MPOS_EventQueueDelete(eq);
    }

    size_t gms = sizeof(MPOS_EventQueue);
    eq = (MPOS_EventQueue*) malloc(gms);

    if (eq != NULL)
    {
        eq->ev_c = 0;
        eq->ev_qc = 0;
    }
}
