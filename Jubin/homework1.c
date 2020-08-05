#include <assert.h>
#include <stdio.h>
 
#include "train.h"
#include "train_size.h"
 
void print_train_information(const train_t* const train);
 
int main()
{
    train_t* train_jubin = create_train_malloc("jubin", SMALL, create_rgb_color_malloc(255, 0, 0));
    train_t* train_kiwan = create_train_malloc("kiwan", SMALL, create_rgb_color_malloc(0, 255, 0));
    train_t* train_jongbum = create_train_malloc("jongbum", MEDIUM, create_rgb_color_malloc(255, 128, 128));
    train_t* train_younghoon = create_train_malloc("younghoon", MEDIUM, create_rgb_color_malloc(0, 0, 0));
    train_t* train_seungwoo = create_train_malloc("seungwoo", LARGE, create_rgb_color_malloc(255, 255, 255));
 
    print_train_information(train_jubin);
    print_train_information(train_kiwan);
    print_train_information(train_jongbum);
    print_train_information(train_younghoon);
    print_train_information(train_seungwoo);
 
    assert(train_jubin->prev == NULL);
    assert(train_jubin->next == NULL);
    assert(get_train_head(train_jubin) == train_jubin);
    assert(get_train_tail(train_jubin) == train_jubin);
 
    merge_train(train_jubin, train_seungwoo);
    assert(train_jubin->prev == NULL);
    assert(train_jubin->next == train_seungwoo);
    assert(train_seungwoo->prev == train_jubin);
    assert(train_seungwoo->next == NULL);
 
    merge_train(train_younghoon, train_jongbum);
    merge_train(train_kiwan, train_younghoon);
    assert(train_kiwan->prev == NULL);
    assert(train_kiwan->next == train_younghoon);
    assert(train_kiwan->next->next == train_jongbum);
 
    assert(get_train_head(train_younghoon) == train_kiwan);
    assert(get_train_tail(train_younghoon) == train_jongbum);
 
    assert(train_younghoon->prev == train_kiwan);
    assert(train_younghoon->prev->prev == NULL);
    assert(train_younghoon->prev->next == train_younghoon);
    assert(train_younghoon->next->prev == train_younghoon);
    assert(train_younghoon->next == train_jongbum);
    assert(train_younghoon->next->next == NULL);
 
    assert(train_jongbum->next == NULL);
    assert(train_jongbum->prev == train_younghoon);
    assert(train_jongbum->prev->prev == train_kiwan);
 
    merge_train(train_jubin, train_jongbum);
    assert(train_jubin->prev == NULL);
    assert(train_jubin->next == train_seungwoo);
    assert(train_seungwoo->prev = train_jubin);
    assert(train_seungwoo->next = train_kiwan);
    assert(train_kiwan->prev = train_seungwoo);
    assert(train_kiwan->next == train_younghoon);
    assert(train_younghoon->prev == train_kiwan);
    assert(train_younghoon->next == train_jongbum);
    assert(train_jongbum->prev == train_younghoon);
    assert(train_jongbum->next == NULL);
 
    assert(pop_train(train_kiwan, train_kiwan) != 0);
    assert(pop_train(train_kiwan, train_kiwan) != 0);
    assert(train_kiwan->prev == NULL);
    assert(train_kiwan->next == NULL);
 
    assert(train_seungwoo->next == train_younghoon);
    assert(train_younghoon->prev == train_seungwoo);
 
    assert(pop_train(train_kiwan, train_jubin) == 0);
    assert(pop_train(train_jongbum, train_jubin) != 0);
    assert(train_jubin->prev == NULL);
    assert(train_jubin->next == NULL);
    assert(train_seungwoo->prev == NULL);
    assert(train_seungwoo->next == train_younghoon);
 
    assert(pop_train(train_jongbum, train_jongbum) != 0);
    assert(train_jongbum->prev == NULL);
    assert(train_jongbum->next == NULL);
    assert(train_younghoon->next == NULL);
 
    interleave_train(train_jubin, train_kiwan);
    merge_train(train_jongbum, train_kiwan);
    merge_train(train_seungwoo, train_jongbum);
    assert(train_seungwoo->prev == NULL);
    assert(train_seungwoo->next == train_younghoon);
    assert(train_younghoon->prev == train_seungwoo);
    assert(train_younghoon->next == train_jongbum);
    assert(train_jongbum->prev == train_younghoon);
    assert(train_jongbum->next == train_jubin);
    assert(train_jubin->prev == train_jongbum);
    assert(train_jubin->next == train_kiwan);
    assert(train_kiwan->prev == train_jubin);
    assert(train_kiwan->next == NULL);
 
    retrieve_train_to_box(train_jubin);
    retrieve_train_to_box(train_kiwan);
    retrieve_train_to_box(train_jongbum);
    retrieve_train_to_box(train_younghoon);
    retrieve_train_to_box(train_seungwoo);
 
    return 0;
}
 
void print_train_information(const train_t* const train)
{
    const char* SIZE_NAME[] = { "Small", "Medium", "Large" };
    printf("name: %s\tsize = %s\tRGB Color=(%hhu, %hhu, %hhu)", train->name, SIZE_NAME[train->size], train->color->red, train->color->green, train->color->blue);
    putchar('\n');
}
