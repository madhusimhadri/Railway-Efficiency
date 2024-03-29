#include <pthread.h>

struct station {
  int out_passengers; // passengers waiting in station
  int in_passengers; // passengers in train
  pthread_mutex_t lock;
  pthread_cond_t train_arrived_cond;
  pthread_cond_t passengers_seated_cond;
  pthread_cond_t train_is_full_cond;
};

void station_init(struct station *station);

void station_load_train(struct station *station, int count);

void station_wait_for_train(struct station *station);

void station_on_board(struct station *station);
