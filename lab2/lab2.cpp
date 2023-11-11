/**
 *
 * Author:
 * Date:
 * Course: Problem Solving Methods
 *
 * Summary of File:
 *	This file contains code which implements an index-based search engine
 *for a registration list.
 *
 */

#include <stdio.h>
#include <string.h>
#define MAX 4

/**
 * Summary of struct :
 *	This REGISTRATION struct contains registration's information of name,
 *age and job
 *
 */

struct REGISTRATION {
  // write down your solution
  char name[51];
  int age;
  char job[51];
};

/**
 * Summary of struct :
 *	This INDEX struct contain job, index value. Using in search_engine
 *(index-based search)
 *
 */

struct INDEX {
  // write down your solution
  char job[51];
  int idx;
};

/**
* void create_index(struct REGISTRATION* reg_arr, struct INDEX* index_arr)
*
* Summary of the Sort function :
*
*	The create_index fuction, fills values in the struct INDEX array based
on struct REGISTRATION array
*
* Parameters	: array: containing struct REGISTRATION, struct INDEX
* Return Value	: Nothing -- Note: Modifies the index_arr "in place"
*
* Description:
*
*   This function fills in the values of the index_arr based on the reg_arr
*	Note: Modifies the struct INDEX array "in place".
* You can use strcpy function
*
*/
void create_index(struct REGISTRATION *reg_arr, struct INDEX *index_arr) {
  // write down your solution
  int i, k;
  int temp = 0, skip = 0;
  for (i = 0; i < MAX; i++) {
    skip = 0;
    for (k = 0; k < temp; k++) {
      if (strcmp(index_arr[k].job, reg_arr[i].job) == 0) {
        skip = 1;
      }
      if (skip == 1)
        break;
    }

    if (skip == 0) {
      strcpy(index_arr[temp].job, reg_arr[i].job);
      index_arr[temp].idx = temp;
      temp++;
    }
  }
}

/**
 * int search_job(struct INDEX* index_arr, char* search_key)
 *
 * Summary of the Sort function :
 *
 *	The search function, searches the index in struct INDEX array
 *	and returns the array index number
 *
 * Parameters	: array: containing struct INDEX, char
 * Return Value	: integer value, which is search_key's value in
 *index_arr return -1 if search_key is not found
 *
 * Description:
 *
 *   This function fills in the values of the index_arr based on the reg_arr
 * Note: Modifies the struct INDEX array "in place".
 * You can use strcmp function
 *
 */
int search_job(struct INDEX *index_arr, char *search_key) {
  // write down your solution
  int i;
  for (i = 0; i < MAX; i++) {
    if (strcmp(index_arr[i].job, search_key) == 0)
      return index_arr[i].idx;
  }
  return -1;
}

// Please do not modify the main function
int main() {
  struct REGISTRATION registration[MAX] = {{"park", 25, "student"},
                                           {"jung", 35, "engineer"},
                                           {"kim", 40, "professor"},
                                           {"lee", 33, "staff"}};
  struct INDEX index[MAX];
  char search_key[51];
  int idx = -1;

  create_index(registration, index);

  printf("Enter the job you want to find: ");
  scanf("%s", search_key);

  printf("\n");
  idx = search_job(index, search_key);
  if (idx == -1)
    printf("NOT Found.\n"); // Note: Defensive coding
  else
    printf("(%s, %d, %s)\n", registration[idx].name, registration[idx].age,
           registration[idx].job);

  return 0;
}