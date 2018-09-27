# base64 encoder and decoder in c

## **NAME**
base64_encode, base64_decode - convert strings between ascii and base64

## **SYNOPSIS**
```c
#indlude "base64.h"

char *base64_encode(char *dest, char const *src);

char *base64_decode(char *dest, char const *src);
```

## **DESCRIPTION**
The **base64_encode()** function convert the string pointed to by `src`,
to the buffer pointed to by `dest`, from ascii to base64.
The strings may not overslap, and the destination string `dest` must be 
initialize as zero, and must be large enough to receive the transition.

The **base64_decode()** function is similar, but convert from base64 to ascii.

## **RETURN VALUE**

The **base64_encode()** and **base64_decode()** functions return a pointer to the  destination string `dest`. If `src` or `dest` is `NULL`, and if `dest` was not initialized as zero, `NULL` will be returned.

## **COPYRIGHT**
Copyright (C) 2017 francis_hao \<francis_hao@126.com>

This program is free software; you can redistribute it and/or modify 
it under the terms of the GNU General Public License as published by 
the Free Software Foundation; either version 2 of the License, 
or (at your option) any later version.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE, GOOD TITLE or
NON INFRINGEMENT.  See [LICENSE] for more details.




[LICENSE]:LICENSE


