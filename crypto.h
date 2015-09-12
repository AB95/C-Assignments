//
// Created by bouch on 10/09/15.
//

#ifndef C_CRYPTO_H
#define C_CRYPTO_H

char *shift(char *s, int n);
int is_word(char *s, char **list, int len);
char **init_dict();
char **init_file(int n);
int find_shift();
void shift_file(int n);

#endif //C_CRYPTO_H
