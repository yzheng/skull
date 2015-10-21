#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "api/sk_utils.h"
#include "api/sk_env.h"
#include "api/sk_sched.h"
#include "api/sk_entity.h"
#include "api/sk_txn.h"
#include "api/sk_pto.h"
#include "api/sk_timer_service.h"

int _run (sk_sched_t* sched, sk_entity_t* entity, sk_txn_t* txn,
          void* proto_msg)
{
    TimerTriggered* timer_pto = proto_msg;
    sk_timer_t* timer = (sk_timer_t*) timer_pto->timer_obj.data;

    if (!sk_timer_valid(timer)) {
        sk_print("timer is not valid, destroy it\n");

        sk_timersvc_t* timersvc = sk_timer_svc(timer);
        sk_timersvc_timer_destroy(timersvc, timer);
        return 0;
    }

    sk_print("timer triggered\n");

    void* ud = timer_pto->ud.data;
    sk_timer_triggered timer_cb =
        (sk_timer_triggered) (uintptr_t) timer_pto->timer_cb.data;

    timer_cb(ud);
    return 0;
}

sk_proto_t sk_pto_timer_triggered = {
    .priority = SK_PTO_PRI_9,
    .descriptor = &timer_triggered__descriptor,
    .run = _run
};
