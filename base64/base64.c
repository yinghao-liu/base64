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
/******************************* encoding ********************************/
char *base64_encode(char *dest, char const *src)
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
	return dest;
}


/**************************** decoding ***********************************/
char *base64_decode(char *dest, char const *src)
{
	unsigned char index = 0;	
	unsigned char tmp[4] = {0};	
	char *dst_tmp = dest;

	if (*dest !='\0' || src == NULL || dest == NULL){
		return NULL;
	}
	while (*src != '\0'){
		/*there is no need to handle '=', because tmp is always 0 if there is no match below*/
		if (*src == '+'){
			tmp[index] = 62;
		}else if (*src == '/'){
			tmp[index] = 63;
		}else if ((*src >= '0') && (*src <= '9') ){/*'0' is 48 in ascii while 52 in base64*/
			tmp[index] = *src + 4;
		}else if ((*src >= 'A') && (*src <= 'Z') ){/*'A' is 65 in ascii while 0 in base64*/
			tmp[index] = *src - 'A';
		}else if ((*src >= 'a') && (*src <= 'z') ){/*'a' is 97 in ascii while 26 in base64*/
			tmp[index] = *src - 71;
		}

		src++;
		index++;
		if (index >= 4 || *src == '\0'){
			*dst_tmp++ = tmp[0]<<2 | tmp[1]>>4;
			*dst_tmp++ = tmp[1]<<4 | tmp[2]>>2;
			*dst_tmp++ = tmp[2]<<6 | tmp[3];
			tmp[0]=tmp[1]=tmp[2]=tmp[3]=0; /*if there is not enough '=' in the end, it's doesn't matter*/
		}
	}
	return dest;
}

