/*
    MPOS_Event: A module of the mpos library to provide event handling.
    License:    zlib license
*/
#ifndef __MPOS_EVENT_H__
#define __MPOS_EVENT_H__

#include <SDL2/SDL.h>


typedef enum
{
    MPOS_EV_QUEUE_DELETE,
    MPOS_EV_QUEUE_HOLD,
} MPOS_EventFlag;

typedef struct MPOS_Event
{
    uint16_t type;
    SDL_Rect rect;
} MPOS_Event;

typedef struct MPOS_EventQueue
{
    u_int32_t ev_c;
    u_int32_t ev_qc;
    MPOS_Event events[];
} MPOS_EventQueue;


#ifdef __cplusplus
extern "C" {
#endif

MPOS_EventQueue * MPOS_EventQueueCreate(void);

u_int32_t MPOSEventPoll(MPOS_EventQueue *eq, MPOS_Event *event, u_int8_t flag);

u_int32_t MPOS_EventPollType(MPOS_EventQueue *eq, MPOS_Event *event, 
                             uint16_t type, u_int8_t flag);

void MPOS_EventPush(MPOS_EventQueue *eq, MPOS_Event event);

void MPOS_EventRemoveFromQueue(MPOS_EventQueue *eq, u_int32_t e_k);

void MPOS_EventRemoveTypeFromQueue(MPOS_EventQueue *eq, uint16_t type);

void MPOS_EventQueueDelete(MPOS_EventQueue *eq);

void MPOS_EventQueueReset(MPOS_EventQueue *eq);

#ifdef __cplusplus
}
#endif
#endif /* !__MPOS_EVENT_H__ */
