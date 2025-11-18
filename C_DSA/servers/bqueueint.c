// bounded_buffer.c
// Simple TX/RX demo using a bounded circular buffer with pthreads.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE   8      
#define NUM_MESSAGES  30      

typedef struct {
    int data[BUFFER_SIZE];
    size_t in;        // write idx
    size_t out;       // read idx
    size_t count;

    pthread_mutex_t mutex;
    pthread_cond_t  not_full;
    pthread_cond_t  not_empty;
} buffer_t;

// ---------- buffer functions (SEND / RECEIVE) ----------

void buffer_init(buffer_t *b) {
    b->in = 0;
    b->out = 0;
    b->count = 0;

    if (pthread_mutex_init(&b->mutex, NULL) != 0) {
        perror("pthread_mutex_init");
        exit(EXIT_FAILURE);
    }
    if (pthread_cond_init(&b->not_full, NULL) != 0) {
        perror("pthread_cond_init not_full");
        exit(EXIT_FAILURE);
    }
    if (pthread_cond_init(&b->not_empty, NULL) != 0) {
        perror("pthread_cond_init not_empty");
        exit(EXIT_FAILURE);
    }
}

void buffer_destroy(buffer_t *b) {
    pthread_mutex_destroy(&b->mutex);
    pthread_cond_destroy(&b->not_full);
    pthread_cond_destroy(&b->not_empty);
}

// SEND (TX)
void buffer_send(buffer_t *b, int value) {
    pthread_mutex_lock(&b->mutex);

    while (b->count == BUFFER_SIZE) {
        pthread_cond_wait(&b->not_full, &b->mutex);
    }

    b->data[b->in] = value;
    b->in = (b->in + 1) % BUFFER_SIZE;
    b->count++;

    pthread_cond_signal(&b->not_empty);

    pthread_mutex_unlock(&b->mutex);
}

// RECEIVE (RX)
int buffer_receive(buffer_t *b) {
    pthread_mutex_lock(&b->mutex);

    while (b->count == 0) {
        pthread_cond_wait(&b->not_empty, &b->mutex);
    }

    int value = b->data[b->out];
    b->out = (b->out + 1) % BUFFER_SIZE;
    b->count--;

    pthread_cond_signal(&b->not_full);

    pthread_mutex_unlock(&b->mutex);
    return value;
}

// ---------- demo TX/RX threads ----------

buffer_t g_buffer;

void *producer_thread(void *arg) {
    (void)arg;
    for (int i = 0; i < NUM_MESSAGES; ++i) {
        printf("TX -> %d\n", i);
        buffer_send(&g_buffer, i);
        usleep(100 * 1000); 
    }
    return NULL;
}

void *consumer_thread(void *arg) {
    (void)arg;
    for (int i = 0; i < NUM_MESSAGES; ++i) {
        int v = buffer_receive(&g_buffer);
        printf("RX <- %d\n", v);
        usleep(150 * 1000); // 150 m
    }
    return NULL;
}

int main(void) {
    buffer_init(&g_buffer);

    pthread_t prod, cons;

    if (pthread_create(&prod, NULL, producer_thread, NULL) != 0) {
        perror("pthread_create producer");
        return EXIT_FAILURE;
    }
    if (pthread_create(&cons, NULL, consumer_thread, NULL) != 0) {
        perror("pthread_create consumer");
        return EXIT_FAILURE;
    }

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    buffer_destroy(&g_buffer);
    return 0;
}

