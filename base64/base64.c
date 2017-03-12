/*
 * Copyright (C) 2017 francis_hao <francis_hao@126.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE, GOOD TITLE or
 * NON INFRINGEMENT.  See the GNU General Public License for more
 * details.
 *
 */
#include <stdio.h>

static const unsigned char map_table[64]={"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"};

/*
 ********************************************
 *
 *
 *
 *
 ********************************************
 */
char *base64_encoding(char *dest, char const *src)
{
	unsigned char index;
	if (*dest !='\0' || src == NULL || dest == NULL){
		return NULL;
	}

	while (*src != '\0' ){
		index = *src++ >> 2;
		*dest++ = map_table[index];
		index = (*(src-1)&0x03) << 4 | *src >> 4;  
		*dest++ = map_table[index];
		if (*src == '\0'){
			*dest++ = '=';
			*dest   = '=';
			break;
		}
		index = (*src & 0x0f) << 2 | (*(src+1)) >> 6;
		*dest++ = map_table[index];
		if (*++src == '\0'){
			*dest  = '=';
			break;
		}
		index = *src++ & 0x3f;
		*dest++ = map_table[index];
	}
	//printf("%s\n",dest);
	return dest;
}
/*
 ********************************************
 *
 *
 *
 *
 ********************************************
 */
char *base64_decoding(char const *src)
{
	return NULL;
}


int main(void)
{
	char a[]="A";
	char aa[]="AB";
	char aaa[]="WWW.BAIDU.COM";
	base64_encoding(a);
	base64_encoding(aa);
	printf("%s\n",base64_encoding(aaa));
}
