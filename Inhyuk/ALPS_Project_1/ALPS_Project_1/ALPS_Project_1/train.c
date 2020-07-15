#include "train.h"

train_t* create_train_malloc(const char* const name, const train_size_t size, const train_color_t* color)
{
	train_t* new_train = (train_t*)malloc(sizeof(train_t));
	
	assert(new_train != NULL);

	new_train->name = name;
	new_train->size = size;
	new_train->color = color;
	new_train->prev = NULL;
	new_train->next = NULL;
	new_train->len = 1;

	return new_train;
}

train_t* get_train_head(const train_t* trains)
{
	assert(trains != NULL);
	const train_t* head_train = trains;
	while (head_train->prev != NULL)
		head_train = head_train->prev;
	return head_train;
}

train_t* get_train_tail(const train_t* trains)
{
	assert(trains != NULL);
	const train_t* tail_train = trains;
	while (tail_train->next != NULL)
		tail_train = tail_train->next;
	return tail_train;
}

void merge_train(const train_t* left_trains, const train_t* right_trains) 
{
	assert(left_trains != NULL);
	assert(right_trains != NULL);
	assert(left_trains != right_trains);

	
}

void interleave_train(train_t* const target_train, const train_t* const new_trains)
{
	assert(target_train != NULL);
	assert(new_trains != NULL);
	assert(target_train != new_trains);

	//TODO
}

int pop_train(train_t* trains, train_t* const target_train)
{
	assert(trains != NULL);
	assert(target_train != NULL);

	int targetIdx = 0;
	while (targetIdx < trains->len && target_train != trains + targetIdx) targetIdx++;

	if (targetIdx == trains->len)
		return 0;
	
	if (targetIdx == 0) {
		trains[targetIdx + 1].prev = NULL;
	}
	else if (targetIdx == trains->len - 1) {
		trains[targetIdx - 1].next = NULL;
	}
	else {
		trains[targetIdx - 1].next = target_train->next;
		trains[targetIdx + 1].prev = target_train->prev;
	}
	target_train->prev = NULL;
	target_train->next = NULL;
	retrieve_train_to_box(target_train);

	return 1;
}

void retrieve_train_to_box(train_t* const train)
{
	assert(train != NULL);
	
	free(train->name);
	free(train->color);
	free(train->prev);
	free(train->next);
	free(train);
}