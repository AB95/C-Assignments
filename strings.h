//
// Created by bouch on 03/09/15.
//

#ifndef C_STRINGS_H
#define C_STRINGS_H

int length(char *s);
void lower(char *old, char *new);
char is_blank(char *s);
void lstrip(char *s);
void rstrip(char *s);
void strip(char *s);
int index_of(char *h, char *n);
char *address_of(char *h, char *n);
int diff(char *s1, char *s2);
char *tab_to_space(char *s, int num_spaces);
int strcmp_ign_case(char *s1, char *s2);
char *distinct(char *s);
char *pad(char *s, int d);
int begins_with_ignore_case(char *s, char *pre);
int ends_with_ignore_case(char *s, char *suff);
char *de_tab(char *s, int num_spaces);
char *remove_chars(char *s1, char *s2);
char *repeat(char *s, int x, char sep);
char *intersect(char *s1, char *s2);
char *replace(char *s, char *pat, char *rep);
char **chop(char *s, char c);

#endif //C_STRINGS_H
