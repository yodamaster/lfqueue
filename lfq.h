/*
Copyright (c) 2015, Mike Taghavi (mitghi) <mitghi@me.com>
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

#ifndef LFQ
#define LFQ
#endif

#define MPANIC(x) ;if(x == NULL) { perror("Malloc failed."); printf("[FILE %s] Malloc failed at line %d in function%s.",__FILE__,__LINE__,__FUNCTION__); exit(1);}

#define RETDISCARD /* VALUE IS DISCARDED */
#define CHECK_COND(cond) if (__sync_bool_compare_and_swap(&cond,1,1)) break;

#define PR(a) a;

typedef struct _node_t node_t;
typedef struct _pointer_t pointer_t;
typedef struct _queue_t queue_t;
typedef struct _value_t value_t;

struct _node_t{
	 value_t *value;
	 pointer_t *next;
};

struct _pointer_t{
	 int count;
	 node_t *nptr;
};

struct _queue_t{
	 pointer_t *head;
	 pointer_t *tail;
};

struct _value_t{
        unsigned int type;
        void *data;
};

queue_t *
q_initialize(void);


void
qpush(queue_t *, void *);

value_t *
qpop(queue_t *,int);


