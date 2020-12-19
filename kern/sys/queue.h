#ifndef _QUEUE_H_
#define _QUEUE_H_

struct list {
	void *data;
	struct queue *next;
};

struct dlist {
	void *data;
	struct queue *next, *last;
};

#endif

