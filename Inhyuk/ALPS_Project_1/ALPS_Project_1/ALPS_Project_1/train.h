
#include <assert.h>
#include <stdlib.h>

#include "train_size.h"
#include "train_color.h"

typedef struct train
{
	char *name;
	train_size_t size;
	const train_color_t *color;
	struct train *prev;
	struct train *next;
} train_t;

train_t *create_train_malloc(const char *const name, const train_size_t size, const train_color_t *color);
train_t *get_train_head(const train_t *trains);
train_t *get_train_tail(const train_t *trains);
void merge_train(const train_t *left_trains, const train_t *right_trains);
void interleave_train(train_t *const target_train, const train_t *const new_trains);
int pop_train(train_t *trains, train_t *const target_train);
void retrieve_train_to_box(train_t *const train);