//
// Created by bouch on 03/09/15.
//

#ifndef C_STRINGS_H
#define C_STRINGS_H

char is_blank(char *s);
void lstrip(char *s);
void rstrip(char *s);
void strip(char *s);
int index_of(char *h, char *n);
char *address_of(char *h, char *n);
int diff(char *s1, char *s2);
char *tab_to_space(char *s, int num_spaces);

#endif //C_STRINGS_H
