#ifndef SK_ENGINE_H
#define SK_ENGINE_H

#include <pthread.h>
#include "api/sk_sched.h"
#include "api/sk_entity_mgr.h"
#include "api/sk_mon.h"

typedef struct sk_engine_t {
    pthread_t        io_thread;
    void*            evlp;
    sk_sched_t*      sched;
    sk_entity_mgr_t* entity_mgr;
    sk_mon_t*        mon;
} sk_engine_t;

sk_engine_t* sk_engine_create();
void sk_engine_destroy(sk_engine_t*);

void sk_engine_start(sk_engine_t*, void* env);
void sk_engine_stop(sk_engine_t*);
void sk_engine_wait(sk_engine_t*);

void sk_engine_link(sk_engine_t* src, sk_engine_t* dst);

#endif
