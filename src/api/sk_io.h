// sk_io is a message queue which controlled by scheduler

#ifndef SK_IO_H
#define SK_IO_H

#include "sk_types.h"
#include "sk_event.h"

typedef struct sk_io_t sk_io_t;

sk_io_t* sk_io_create(int size);
void sk_io_destroy(sk_io_t* io);

#define SK_IO_INPUT  0
#define SK_IO_OUTPUT 1

// push N events into sk_io input or output queue
// return - 0: success
//        - 1: failed
int sk_io_push(sk_io_t* io, int type, sk_event_t* events, int nevents);

// try to pull N events from sk_io (input or output) queue
// return the actual event count
int sk_io_pull(sk_io_t* io, int type, sk_event_t* events, int nevents);

int sk_io_used(sk_io_t* io, int type);
int sk_io_free(sk_io_t* io, int type);

#endif

