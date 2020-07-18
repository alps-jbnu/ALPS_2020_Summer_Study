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

	return new_train;
}

train_t* get_train_head(const train_t* trains)
{
	assert(trains != NULL);
	while (trains->prev != NULL)
		trains = trains->prev;
	return trains;
}

train_t* get_train_tail(const train_t* trains)
{
	assert(trains != NULL);
	while (trains->next != NULL)
		trains = trains->next;
	return trains;
}

void merge_train(const train_t* left_trains, const train_t* right_trains) 
{
	assert(left_trains != NULL);
	assert(right_trains != NULL);
	assert(left_trains != right_trains);

	train_t* right_head_train = get_train_head(right_trains);
	train_t* left_tail_train = get_train_tail(left_trains);

	get_train_tail(left_trains)->next = right_head_train;
	get_train_head(right_trains)->prev = left_tail_train;

}

void interleave_train(train_t* const target_train, const train_t* const new_trains)
{
	assert(target_train != NULL);
	assert(new_trains != NULL);
	assert(target_train != new_trains);

	train_t* train_head = get_train_head(new_trains);
	if (target_train->next == NULL) {
		target_train->next = train_head;
		train_head->prev = target_train;
	}
	else {
		train_head->next = target_train->next;
		train_head->prev = target_train;
		target_train->next->prev = train_head;
		target_train->next = train_head;
	}
}

int pop_train(train_t* trains, train_t* const target_train)
{
	assert(trains != NULL);
	assert(target_train != NULL);

	//����Ǿ��ִ��� Ȯ��
	train_t* search_train = get_train_head(trains);
	while (search_train != NULL && search_train != target_train)
		search_train = search_train->next;
	if (search_train == NULL)
		return 0;

	train_t* train = get_train_head(trains);
	
	if(target_train->next != NULL) target_train->next->prev = target_train->prev;
	if(target_train->prev != NULL) target_train->prev->next = target_train->next;
	target_train->prev = NULL;
	target_train->next = NULL;

	return 1;
}

void retrieve_train_to_box(train_t* const train)
{
	assert(train != NULL);

	//free(train->name);
	free(train->color);
	free(train);
}