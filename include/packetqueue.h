#ifndef _PACKET_QUEUE_H_
#define _PACKET_QUEUE_H_

#include <pthread.h>
#include <stdint.h>

#define MAX_PACKET_SIZE 18432

typedef struct PacketNode
{
	char *packet;
	int16_t packet_size;
	struct PacketNode *next;
} PacketNode;

typedef struct PacketList
{
	PacketNode *first;
	PacketNode *last;
	int32_t num_packets;
	int32_t total_packets_count;
	pthread_cond_t cond;
	pthread_mutex_t mutex;
} PacketList;

void PacketQueueInit(PacketList *list);
void PacketQueueDestroy(PacketList *list);
void PacketQueuePut(PacketList *list,PacketNode *packet);
PacketNode *PacketQueueGet(PacketList *list);

#endif
