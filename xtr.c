/* COMPILE ME */

/* gcc optimized: gcc -march=native -mtune=generic xtr.c -o xtr */
/* cc plain: cc xtr.c -o xtr */

/* ALL EXTERNAL CODE POINTS */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*

    xtr - character eXTRapolator
    Copyright (C) 2012  Triston J. Taylor

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    Contact: pc.wiz.tt@gmail.com
    https://www.facebook.com/pc.wiz.tt
    https://www.facebook.com/alt.bash
    https://www.facebook.com/alt.c.pro.tech

Here is a rundown of the elected options.

+e | -i - Exclude LIST
-e | +i - Include LIST
-[...] - Exclude RANGE
+[...] - Include RANGE
s/LIST/[replacement text/] - swap char with text
a/LIST/[prefix text[/suffix text][/]] - prefix char optional suffix
-p "prefix" - set global prefix
-s "suffix" - set global suffix
-f hex|octal|char - set output format

use --help option to get online help

Affix Operations Cheat Sheet:

a/LIST/       - clear affixes for for LIST
a/LIST/p[/]   - set p and s to p for LIST
a/LIST/p//    - set p, ignore s for LIST
a/LIST//s[/]  - ignore p, set s for LIST
a/LIST/p/s[/] - set p, set s for LIST
a/LIST///     - NOP

Where LIST may be any combination of ESCAPE, CHAR, and RANGE

For example:
"\n[a-c]123"

is a LIST of character values: (NEWLINE, a, b, c, 1, 2, 3)

In a useful example, we'll convert non-printing ascii values to dots, and pass the rest
through as plain text.

xtr -f char 's/[\0-\31][\127-\255]/.'

Here is a different main function, which is used to test the value scanner.

int main(int argc, char * argv[], char * env[]) {
    char input[1024];
    XTR_VALUE test;
    while ((gets(input)) != NULL) {
        test = xtr_utils_scan_value(input);
        printf("scanned: %s\nvalue: %u\nlength: %u\ntype: %s\n",
            input, test.value, test.length, xtr_utils_value_type_tostring(&test)
        );
    }
    return 0;
}

Here is a link to a picture of xtr in action.
https://sphotos-b.xx.fbcdn.net/hphotos-ash3/c43.0.403.403/p403x403/61340_442444625817650_1768461240_n.png

*/

/* auto-generated binary include: "help.txt" encoded by bin2inc (sh)

resource : file:///home/triston/projects/bash-masters/application/xtr/help.txt
developer: triston
machine  : AOD257
content-length: 1712

*/

unsigned char main_help[] = {

    0x0a, 0x78, 0x74, 0x72, 0x20, 0x2d, 0x20, 0x63, 0x68, 0x61, 0x72, 0x61, 0x63, 0x74,
    0x65, 0x72, 0x20, 0x65, 0x58, 0x54, 0x52, 0x61, 0x70, 0x6f, 0x6c, 0x61, 0x74, 0x6f,
    0x72, 0x20, 0x43, 0x6f, 0x70, 0x79, 0x72, 0x69, 0x67, 0x68, 0x74, 0x20, 0x28, 0x43,
    0x29, 0x20, 0x32, 0x30, 0x31, 0x32, 0x20, 0x20, 0x54, 0x72, 0x69, 0x73, 0x74, 0x6f,
    0x6e, 0x20, 0x4a, 0x2e, 0x20, 0x54, 0x61, 0x79, 0x6c, 0x6f, 0x72, 0x0a, 0x0a, 0x53,
    0x59, 0x4e, 0x4f, 0x50, 0x53, 0x59, 0x53, 0x0a, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x78, 0x74, 0x72, 0x20, 0x5b, 0x6f, 0x70, 0x74, 0x69, 0x6f, 0x6e,
    0x73, 0x5d, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x0a, 0x4f, 0x50,
    0x54, 0x49, 0x4f, 0x4e, 0x53, 0x0a, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x2b, 0x65, 0x20,
    0x7c, 0x20, 0x2d, 0x69, 0x20, 0x2d, 0x20, 0x45, 0x78, 0x63, 0x6c, 0x75, 0x64, 0x65,
    0x20, 0x4c, 0x49, 0x53, 0x54, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x2d, 0x65, 0x20, 0x7c,
    0x20, 0x2b, 0x69, 0x20, 0x2d, 0x20, 0x49, 0x6e, 0x63, 0x6c, 0x75, 0x64, 0x65, 0x20,
    0x4c, 0x49, 0x53, 0x54, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x2d, 0x5b, 0x2e, 0x2e, 0x2e,
    0x5d, 0x20, 0x2d, 0x20, 0x45, 0x78, 0x63, 0x6c, 0x75, 0x64, 0x65, 0x20, 0x52, 0x41,
    0x4e, 0x47, 0x45, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x2b, 0x5b, 0x2e, 0x2e, 0x2e, 0x5d,
    0x20, 0x2d, 0x20, 0x49, 0x6e, 0x63, 0x6c, 0x75, 0x64, 0x65, 0x20, 0x52, 0x41, 0x4e,
    0x47, 0x45, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x73, 0x2f,
    0x4c, 0x49, 0x53, 0x54, 0x2f, 0x5b, 0x72, 0x65, 0x70, 0x6c, 0x61, 0x63, 0x65, 0x6d,
    0x65, 0x6e, 0x74, 0x20, 0x74, 0x65, 0x78, 0x74, 0x2f, 0x5d, 0x20, 0x2d, 0x20, 0x73,
    0x77, 0x61, 0x70, 0x20, 0x63, 0x68, 0x61, 0x72, 0x20, 0x77, 0x69, 0x74, 0x68, 0x20,
    0x74, 0x65, 0x78, 0x74, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x61, 0x2f, 0x4c, 0x49, 0x53,
    0x54, 0x2f, 0x5b, 0x70, 0x72, 0x65, 0x66, 0x69, 0x78, 0x20, 0x74, 0x65, 0x78, 0x74,
    0x5b, 0x2f, 0x73, 0x75, 0x66, 0x66, 0x69, 0x78, 0x20, 0x74, 0x65, 0x78, 0x74, 0x5d,
    0x5b, 0x2f, 0x5d, 0x5d, 0x20, 0x2d, 0x20, 0x70, 0x72, 0x65, 0x66, 0x69, 0x78, 0x20,
    0x63, 0x68, 0x61, 0x72, 0x20, 0x6f, 0x70, 0x74, 0x69, 0x6f, 0x6e, 0x61, 0x6c, 0x20,
    0x73, 0x75, 0x66, 0x66, 0x69, 0x78, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x0a, 0x20, 0x20,
    0x20, 0x20, 0x2d, 0x70, 0x20, 0x22, 0x70, 0x72, 0x65, 0x66, 0x69, 0x78, 0x22, 0x20,
    0x2d, 0x20, 0x73, 0x65, 0x74, 0x20, 0x67, 0x6c, 0x6f, 0x62, 0x61, 0x6c, 0x20, 0x70,
    0x72, 0x65, 0x66, 0x69, 0x78, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x2d, 0x73, 0x20, 0x22,
    0x73, 0x75, 0x66, 0x66, 0x69, 0x78, 0x22, 0x20, 0x2d, 0x20, 0x73, 0x65, 0x74, 0x20,
    0x67, 0x6c, 0x6f, 0x62, 0x61, 0x6c, 0x20, 0x73, 0x75, 0x66, 0x66, 0x69, 0x78, 0x0a,
    0x20, 0x20, 0x20, 0x20, 0x2d, 0x66, 0x20, 0x68, 0x65, 0x78, 0x7c, 0x6f, 0x63, 0x74,
    0x61, 0x6c, 0x7c, 0x63, 0x68, 0x61, 0x72, 0x20, 0x2d, 0x20, 0x73, 0x65, 0x74, 0x20,
    0x6f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x20, 0x66, 0x6f, 0x72, 0x6d, 0x61, 0x74, 0x0a,
    0x0a, 0x20, 0x20, 0x20, 0x20, 0x57, 0x68, 0x65, 0x72, 0x65, 0x20, 0x4c, 0x49, 0x53,
    0x54, 0x20, 0x6d, 0x61, 0x79, 0x20, 0x62, 0x65, 0x20, 0x61, 0x6e, 0x79, 0x20, 0x63,
    0x6f, 0x6d, 0x62, 0x69, 0x6e, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x6f, 0x66, 0x20,
    0x45, 0x53, 0x43, 0x41, 0x50, 0x45, 0x2c, 0x20, 0x43, 0x48, 0x41, 0x52, 0x2c, 0x20,
    0x61, 0x6e, 0x64, 0x20, 0x52, 0x41, 0x4e, 0x47, 0x45, 0x0a, 0x0a, 0x20, 0x20, 0x20,
    0x20, 0x46, 0x6f, 0x72, 0x20, 0x65, 0x78, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x3a, 0x0a,
    0x20, 0x20, 0x20, 0x20, 0x22, 0x5c, 0x6e, 0x5b, 0x61, 0x2d, 0x63, 0x5d, 0x31, 0x32,
    0x33, 0x22, 0x0a, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x69, 0x73, 0x20, 0x61, 0x20, 0x4c,
    0x49, 0x53, 0x54, 0x20, 0x6f, 0x66, 0x20, 0x63, 0x68, 0x61, 0x72, 0x61, 0x63, 0x74,
    0x65, 0x72, 0x20, 0x76, 0x61, 0x6c, 0x75, 0x65, 0x73, 0x3a, 0x20, 0x28, 0x4e, 0x45,
    0x57, 0x4c, 0x49, 0x4e, 0x45, 0x2c, 0x20, 0x61, 0x2c, 0x20, 0x62, 0x2c, 0x20, 0x63,
    0x2c, 0x20, 0x31, 0x2c, 0x20, 0x32, 0x2c, 0x20, 0x33, 0x29, 0x0a, 0x0a, 0x0a, 0x41,
    0x66, 0x66, 0x69, 0x78, 0x20, 0x4f, 0x70, 0x65, 0x72, 0x61, 0x74, 0x69, 0x6f, 0x6e,
    0x73, 0x20, 0x43, 0x68, 0x65, 0x61, 0x74, 0x20, 0x53, 0x68, 0x65, 0x65, 0x74, 0x3a,
    0x0a, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x61, 0x2f, 0x4c, 0x49, 0x53, 0x54, 0x2f, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x2d, 0x20, 0x63, 0x6c, 0x65, 0x61, 0x72, 0x20,
    0x61, 0x66, 0x66, 0x69, 0x78, 0x65, 0x73, 0x20, 0x66, 0x6f, 0x72, 0x20, 0x66, 0x6f,
    0x72, 0x20, 0x4c, 0x49, 0x53, 0x54, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x61, 0x2f, 0x4c,
    0x49, 0x53, 0x54, 0x2f, 0x70, 0x5b, 0x2f, 0x5d, 0x20, 0x20, 0x20, 0x2d, 0x20, 0x73,
    0x65, 0x74, 0x20, 0x70, 0x20, 0x61, 0x6e, 0x64, 0x20, 0x73, 0x20, 0x74, 0x6f, 0x20,
    0x70, 0x20, 0x66, 0x6f, 0x72, 0x20, 0x4c, 0x49, 0x53, 0x54, 0x0a, 0x20, 0x20, 0x20,
    0x20, 0x61, 0x2f, 0x4c, 0x49, 0x53, 0x54, 0x2f, 0x70, 0x2f, 0x2f, 0x20, 0x20, 0x20,
    0x20, 0x2d, 0x20, 0x73, 0x65, 0x74, 0x20, 0x70, 0x2c, 0x20, 0x69, 0x67, 0x6e, 0x6f,
    0x72, 0x65, 0x20, 0x73, 0x20, 0x66, 0x6f, 0x72, 0x20, 0x4c, 0x49, 0x53, 0x54, 0x0a,
    0x20, 0x20, 0x20, 0x20, 0x61, 0x2f, 0x4c, 0x49, 0x53, 0x54, 0x2f, 0x2f, 0x73, 0x5b,
    0x2f, 0x5d, 0x20, 0x20, 0x2d, 0x20, 0x69, 0x67, 0x6e, 0x6f, 0x72, 0x65, 0x20, 0x70,
    0x2c, 0x20, 0x73, 0x65, 0x74, 0x20, 0x73, 0x20, 0x66, 0x6f, 0x72, 0x20, 0x4c, 0x49,
    0x53, 0x54, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x61, 0x2f, 0x4c, 0x49, 0x53, 0x54, 0x2f,
    0x70, 0x2f, 0x73, 0x5b, 0x2f, 0x5d, 0x20, 0x2d, 0x20, 0x73, 0x65, 0x74, 0x20, 0x70,
    0x2c, 0x20, 0x73, 0x65, 0x74, 0x20, 0x73, 0x20, 0x66, 0x6f, 0x72, 0x20, 0x4c, 0x49,
    0x53, 0x54, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x61, 0x2f, 0x4c, 0x49, 0x53, 0x54, 0x2f,
    0x2f, 0x2f, 0x20, 0x20, 0x20, 0x20, 0x20, 0x2d, 0x20, 0x4e, 0x4f, 0x50, 0x0a, 0x0a,
    0x0a, 0x43, 0x48, 0x41, 0x52, 0x41, 0x43, 0x54, 0x45, 0x52, 0x20, 0x45, 0x53, 0x43,
    0x41, 0x50, 0x45, 0x53, 0x0a, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x5c, 0x61, 0x20, 0x61,
    0x6c, 0x65, 0x72, 0x74, 0x20, 0x28, 0x62, 0x65, 0x6c, 0x6c, 0x29, 0x0a, 0x20, 0x20,
    0x20, 0x20, 0x5c, 0x62, 0x20, 0x62, 0x61, 0x63, 0x6b, 0x73, 0x70, 0x61, 0x63, 0x65,
    0x0a, 0x20, 0x20, 0x20, 0x20, 0x5c, 0x66, 0x20, 0x66, 0x6f, 0x72, 0x6d, 0x20, 0x66,
    0x65, 0x65, 0x64, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x5c, 0x6e, 0x20, 0x6e, 0x65, 0x77,
    0x20, 0x6c, 0x69, 0x6e, 0x65, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x5c, 0x72, 0x20, 0x63,
    0x61, 0x72, 0x72, 0x69, 0x61, 0x67, 0x65, 0x20, 0x72, 0x65, 0x74, 0x75, 0x72, 0x6e,
    0x0a, 0x20, 0x20, 0x20, 0x20, 0x5c, 0x74, 0x20, 0x68, 0x6f, 0x72, 0x69, 0x7a, 0x6f,
    0x6e, 0x74, 0x61, 0x6c, 0x20, 0x74, 0x61, 0x62, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x5c,
    0x76, 0x20, 0x76, 0x65, 0x72, 0x74, 0x69, 0x63, 0x61, 0x6c, 0x20, 0x74, 0x61, 0x62,
    0x0a, 0x20, 0x20, 0x20, 0x20, 0x5c, 0x5c, 0x20, 0x62, 0x61, 0x63, 0x6b, 0x73, 0x6c,
    0x61, 0x73, 0x68, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x5c, 0x30, 0x2d, 0x30, 0x33, 0x37,
    0x37, 0x20, 0x74, 0x68, 0x65, 0x20, 0x63, 0x68, 0x61, 0x72, 0x61, 0x63, 0x74, 0x65,
    0x72, 0x20, 0x77, 0x68, 0x6f, 0x73, 0x65, 0x20, 0x41, 0x53, 0x43, 0x49, 0x49, 0x20,
    0x63, 0x6f, 0x64, 0x65, 0x20, 0x69, 0x73, 0x20, 0x30, 0x2d, 0x30, 0x33, 0x37, 0x37,
    0x20, 0x28, 0x6f, 0x63, 0x74, 0x61, 0x6c, 0x29, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x5c,
    0x78, 0x48, 0x48, 0x20, 0x74, 0x68, 0x65, 0x20, 0x65, 0x69, 0x67, 0x68, 0x74, 0x2d,
    0x62, 0x69, 0x74, 0x20, 0x63, 0x68, 0x61, 0x72, 0x61, 0x63, 0x74, 0x65, 0x72, 0x20,
    0x77, 0x68, 0x6f, 0x73, 0x65, 0x20, 0x76, 0x61, 0x6c, 0x75, 0x65, 0x20, 0x69, 0x73,
    0x20, 0x48, 0x48, 0x20, 0x28, 0x68, 0x65, 0x78, 0x61, 0x64, 0x65, 0x63, 0x69, 0x6d,
    0x61, 0x6c, 0x29, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x5c, 0x31, 0x2d, 0x32, 0x35, 0x35,
    0x20, 0x64, 0x65, 0x63, 0x69, 0x6d, 0x61, 0x6c, 0x20, 0x69, 0x6e, 0x74, 0x65, 0x67,
    0x65, 0x72, 0x0a, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x41, 0x6c, 0x6c, 0x20, 0x75, 0x6e,
    0x6c, 0x69, 0x73, 0x74, 0x65, 0x64, 0x20, 0x65, 0x73, 0x63, 0x61, 0x70, 0x65, 0x64,
    0x20, 0x63, 0x68, 0x61, 0x72, 0x73, 0x2c, 0x20, 0x72, 0x65, 0x70, 0x72, 0x65, 0x73,
    0x65, 0x6e, 0x74, 0x20, 0x74, 0x68, 0x65, 0x6d, 0x73, 0x65, 0x6c, 0x76, 0x65, 0x73,
    0x2e, 0x0a, 0x0a, 0x0a, 0x4e, 0x4f, 0x54, 0x45, 0x53, 0x0a, 0x0a, 0x20, 0x20, 0x20,
    0x20, 0x52, 0x61, 0x6e, 0x67, 0x65, 0x20, 0x76, 0x61, 0x6c, 0x75, 0x65, 0x73, 0x20,
    0x6d, 0x61, 0x79, 0x20, 0x61, 0x6c, 0x73, 0x6f, 0x20, 0x62, 0x65, 0x20, 0x65, 0x73,
    0x63, 0x61, 0x70, 0x65, 0x20, 0x73, 0x65, 0x71, 0x75, 0x65, 0x6e, 0x63, 0x65, 0x73,
    0x2e, 0x20, 0x4d, 0x61, 0x78, 0x69, 0x6d, 0x75, 0x6d, 0x20, 0x6f, 0x66, 0x20, 0x32,
    0x35, 0x36, 0x20, 0x73, 0x65, 0x71, 0x75, 0x65, 0x6e, 0x63, 0x65, 0x73, 0x20, 0x70,
    0x65, 0x72, 0x20, 0x72, 0x61, 0x6e, 0x67, 0x65, 0x2e, 0x0a, 0x0a, 0x20, 0x20, 0x20,
    0x20, 0x47, 0x6c, 0x6f, 0x62, 0x61, 0x6c, 0x20, 0x70, 0x72, 0x65, 0x66, 0x69, 0x78,
    0x20, 0x61, 0x6e, 0x64, 0x20, 0x73, 0x75, 0x66, 0x66, 0x69, 0x78, 0x2c, 0x20, 0x74,
    0x61, 0x6b, 0x65, 0x20, 0x70, 0x72, 0x65, 0x63, 0x65, 0x64, 0x65, 0x6e, 0x63, 0x65,
    0x20, 0x6f, 0x6e, 0x6c, 0x79, 0x20, 0x77, 0x68, 0x65, 0x6e, 0x20, 0x61, 0x20, 0x76,
    0x61, 0x6c, 0x75, 0x65, 0x20, 0x28, 0x63, 0x68, 0x61, 0x72, 0x29, 0x20, 0x69, 0x73,
    0x20, 0x6e, 0x6f, 0x74, 0x20, 0x65, 0x78, 0x70, 0x6c, 0x69, 0x63, 0x69, 0x74, 0x6c,
    0x79, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x70, 0x72, 0x65, 0x66, 0x69, 0x78, 0x65, 0x64,
    0x20, 0x76, 0x69, 0x61, 0x20, 0x41, 0x46, 0x46, 0x49, 0x58, 0x20, 0x6f, 0x70, 0x74,
    0x69, 0x6f, 0x6e, 0x20, 0x28, 0x22, 0x61, 0x2f, 0x4c, 0x49, 0x53, 0x54, 0x2f, 0x50,
    0x52, 0x45, 0x46, 0x49, 0x58, 0x5b, 0x2f, 0x53, 0x55, 0x46, 0x46, 0x49, 0x58, 0x2f,
    0x5d, 0x22, 0x29, 0x0a, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x4e, 0x6f, 0x20, 0x70, 0x72,
    0x65, 0x66, 0x69, 0x78, 0x20, 0x6f, 0x72, 0x20, 0x73, 0x75, 0x66, 0x66, 0x69, 0x78,
    0x20, 0x73, 0x68, 0x61, 0x6c, 0x6c, 0x20, 0x62, 0x65, 0x20, 0x70, 0x72, 0x6f, 0x76,
    0x69, 0x64, 0x65, 0x64, 0x20, 0x66, 0x6f, 0x72, 0x20, 0x61, 0x6e, 0x79, 0x20, 0x63,
    0x68, 0x61, 0x72, 0x61, 0x63, 0x74, 0x65, 0x72, 0x20, 0x76, 0x61, 0x6c, 0x75, 0x65,
    0x20, 0x74, 0x68, 0x61, 0x74, 0x20, 0x69, 0x73, 0x20, 0x73, 0x65, 0x74, 0x20, 0x74,
    0x6f, 0x20, 0x65, 0x73, 0x63, 0x61, 0x70, 0x65, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x74,
    0x72, 0x61, 0x6e, 0x73, 0x6c, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x2e, 0x20, 0x43, 0x68,
    0x61, 0x72, 0x61, 0x63, 0x74, 0x65, 0x72, 0x20, 0x73, 0x77, 0x61, 0x70, 0x73, 0x20,
    0x74, 0x61, 0x6b, 0x65, 0x20, 0x70, 0x72, 0x65, 0x63, 0x65, 0x64, 0x65, 0x6e, 0x63,
    0x65, 0x20, 0x61, 0x73, 0x20, 0x6c, 0x6f, 0x6e, 0x67, 0x20, 0x61, 0x73, 0x20, 0x74,
    0x68, 0x65, 0x79, 0x20, 0x61, 0x72, 0x65, 0x20, 0x64, 0x65, 0x66, 0x69, 0x6e, 0x65,
    0x64, 0x2e, 0x0a, 0x00, 0x00

};

unsigned long int main_help_length = 1712;

const char * XTR_DEFAULT_FORMAT = "%02hX";

const char   XTR_TOKEN_ESCAPE = '\\';

const char   XTR_SUBSTITUTION_IDENTIFIER = 's';
const char   XTR_AFFIX_IDENTIFIER = 'a';

const char   XTR_TOKEN_NEXT = '/';

const char   XTR_OPTION_DETRACT = '-';
const char   XTR_OPTION_ATTRACT = '+';

const char   XTR_EXCLUSIVE_OPTION = 'e';
const char   XTR_FORMAT_OPTION = 'f';

const char   XTR_GLOBAL_PREFIX_OPTION = 'p';
const char   XTR_GLOBAL_SUFFIX_OPTION = 's';

const char   XTR_INCLUSIVE_OPTION = 'i';

const char   XTR_RANGE_SPECIFIER_TOKEN = '[';
const char   XTR_RANGE_TERMINATOR_TOKEN = ']';
const char   XTR_RANGE_SEPARATOR_TOKEN = '-';

#define XTR_RANGE_MAX 256
#define XTR_TRUE 1
#define XTR_FALSE 0

const int XTR_RANGE_MAXIMUM_SEQUENCES = XTR_RANGE_MAX;

typedef enum XTR_VALUE_TYPE {
    XTR_VALUE_INVALID,
    XTR_VALUE_NULL,
    XTR_VALUE_CHAR,
    XTR_VALUE_HEX,
    XTR_VALUE_OCTAL,
    XTR_VALUE_INTEGER,
    XTR_VALUE_PREDEFINED
} XTR_VALUE_TYPE;

const char * XTR_VALUE_TYPE_DESCRIPTION[] = {
    "insufficient input", "string terminator", "character", "hexidecimal", "octal",
    "integer", "control character class"
};

typedef struct XTR_VALUE {
    unsigned int value;
    unsigned int length;
    unsigned int type;
} XTR_VALUE;

const char * xtr_utils_value_type_tostring(XTR_VALUE * val) {
    if (val->type > XTR_VALUE_PREDEFINED) return    NULL;
    else return XTR_VALUE_TYPE_DESCRIPTION[val->type];
}

typedef struct XTR_RANGE_SEQUENCE {
    int begin;
    int end;
} XTR_RANGE_SEQUENCE;

typedef enum XTR_RANGE_ERROR {
    XTR_RANGE_ERROR_MISSING_INPUT = 0x01,
    XTR_RANGE_ERROR_MISSING_SPECIFIER_TOKEN,
    XTR_RANGE_ERROR_MISSING_TERMINATOR_TOKEN,
    XTR_RANGE_ERROR_MISSING_RANGE_SEPARATOR,
    XTR_RANGE_ERROR_MISSING_PRIMARY_VALUE,
    XTR_RANGE_ERROR_MISSING_SECONDARY_VALUE,
    XTR_RANGE_ERROR_MAXIMUM_SEQUENCE_OVERFLOW
} XTR_RANGE_ERROR;

typedef enum XTR_LIST_ERROR {
    XTR_LIST_NULL = 0x01,
    XTR_LIST_EMPTY = 0x08,
} XTR_LIST_ERROR;

const char * XTR_LIST_ERROR_DESCRIPTION[] = {
    "", "unable to scan null pointer", "expected token `['",
    "unable to locate range terminator `]'", "expected range separator `-'",
    "expected primary value", "expected secondary value",
    "unable to allocate further sequence storage", "list content empty"
};

#define XTR_RANGE_ERROR_DESCRIPTION XTR_LIST_ERROR_DESCRIPTION

typedef struct XTR_RANGE {
    unsigned long int length;
    int count;
    XTR_RANGE_SEQUENCE ** sequence;
    XTR_RANGE_ERROR error;
} XTR_RANGE;

const char * xtr_utils_range_error_tostring(XTR_RANGE * range) {
    if (range->error > XTR_RANGE_ERROR_MAXIMUM_SEQUENCE_OVERFLOW) return    NULL;
    else return XTR_RANGE_ERROR_DESCRIPTION[range->error];
}

void xtr_range_free(XTR_RANGE * range) {
    int i; for(i = 0; i < range->count; i++) free(range->sequence[i]);
    free(range->sequence); memset(range, 0, sizeof(XTR_RANGE));
}

typedef struct XTR_LIST {
    int length; // length of list in bytes
    int count;    // NUMBER OF DEFINED ITEMS IN LIST
    char * value; // list item status
    int error;
    int range; // ERRANT RANGE SEQUENCE IF ANY
} XTR_LIST;

XTR_LIST xtr_list_new() {
    return (XTR_LIST) { 0, 0, calloc(XTR_RANGE_MAX, sizeof(char)), 0, 0 };
}

void xtr_list_free(XTR_LIST * list) {
    free(list->value); memset(list, 0, sizeof(XTR_LIST));
};

const char * xtr_utils_list_error_tostring(XTR_LIST * val) {
    if (val->error > XTR_LIST_EMPTY) return NULL;
    else return XTR_LIST_ERROR_DESCRIPTION[val->error];
}

// PERFORMANCE PROFILE HINTS AT WHAT TRANSLATION FEATURES ARE ACTIVE in XTR_CONTEXT
typedef enum XTR_PERFORMANCE_PROFILE {
    XTR_PERFORMANCE_STANDARD = 0x00,    // fastest
    XTR_PERFORMANCE_ENHANCED = 0X01,    // enhancement takes time
    XTR_PERFORMANCE_EXCLUSIVE = 0x02,    // exclusivity requires filtering
    XTR_PERFORMANCE_DIVERSE = 0x04        // diversity requires max processing
} XTR_PERFORMANCE_PROFILE;

typedef struct XTR_CONTEXT {

    XTR_PERFORMANCE_PROFILE profile;

    char exclude[XTR_RANGE_MAX];
    char * substitute[XTR_RANGE_MAX];
    char * prefix[XTR_RANGE_MAX];
    char * suffix[XTR_RANGE_MAX];
    char * format[XTR_RANGE_MAX];

    char * default_prefix; // prefix used if none specified
    char * default_suffix; // suffix used if none specified
    char * default_format; // format used if none specified

    char ** intern;
    unsigned long int interns;

} XTR_CONTEXT;

XTR_CONTEXT * xtr_new_context(char * format) {
    XTR_CONTEXT * xtrcx = calloc(1, sizeof(XTR_CONTEXT));
    xtrcx->default_format = format;
}

xtr_context_free(XTR_CONTEXT * xtrcx) {

    int index;
    for (index = 0; index < xtrcx->interns; index++) free(xtrcx->intern[index]);
    free(xtrcx->intern);
    free(xtrcx);

}

// THIS IS FOR INTERNAL PROCESSING OF COMMANDS

int xtr_utils_sequence_match(register char *a, register char *b) {
    if ( a == b ) return 1; if ( ! a || ! b ) return 0;
    while ( *a != 0 && *b !=0 ) if (*a++ != *b++) return 0;
    return 1;
}

char * xtr_utils_token_address(register char * haystack, register char needle) {

    /*
        can find null: true
        can skip escapes: true
        can find escapes: true
        can die on null escapes: true
    */

    if ( ! haystack ) return NULL;

    while (1) {
        if (*haystack == needle) return haystack;
        else if (*haystack == XTR_TOKEN_ESCAPE) {
            if ( ! haystack[1] ) break;    // explicitly disallow null escape
            haystack += 2 ; continue;
        }
        else if ( ! *(haystack++) ) break;
    }

    return NULL;

}

long int xtr_utils_delimited_length(register char * inquisition, unsigned long int max, char tokenDelimiter) {

    char * token = xtr_utils_token_address(inquisition, tokenDelimiter);
    if (token == NULL) return -1;
    unsigned long int length = (token - inquisition);
    if ( max && length >= max ) return -1;
    else return length;

}

#define xtr_isctrlspace(target) target == '\t' || target == '\n' || target == '\r' || target == '\v' || target == '\f'
#define xtr_isoctdigit(target) (target >= '0' && target < '8')

XTR_VALUE xtr_utils_scan_value(register char * source) {

    register unsigned long int index = 0;

    XTR_VALUE scan = { 0, 0, 0 };

    if ( ! source ) return scan;

    if ( ! *source ) {
        scan.length = 1;
        scan.type = XTR_VALUE_NULL;
        return scan;
    }

    // special case escape handling that would otherwise cause incorrect parsing
    if (source[index] == XTR_TOKEN_ESCAPE) {

        scan.value = source[index + 1]; scan.length = 2; // pre-emptive strike

        if ( ! scan.value ) scan.type = XTR_VALUE_NULL;    // no overflows
        else if ( xtr_isctrlspace(scan.value) ) scan.type = XTR_VALUE_PREDEFINED; // no
        else if ( scan.value == ' ' ) scan.type = XTR_VALUE_CHAR;    // SPACE passovers
        else if ( scan.value == '-' ) scan.type = XTR_VALUE_CHAR;    // no negatives

        if (scan.type) return scan;
        else { scan.value = 0; scan.length = 0; } // roll back pre-emptive aggression

    }

    // \xHH
    if (sscanf(source, "\\x%2x", &scan.value)) {
        scan.type = XTR_VALUE_HEX;
        index = 2;
        while (isxdigit(source[index]) && (++index < 4));
        scan.length = index;
        if ( scan.length == 2 ) { // whitespace / null false positive
            scan.type = XTR_VALUE_CHAR; scan.value = 'x';
        }
        return scan;
    }
    // \XHH
    if (sscanf(source, "\\X%2x", &scan.value)) {
        scan.type = XTR_VALUE_HEX;
        index = 2;
        while (isxdigit(source[index]) && (++index < 4));
        scan.length = index;
        if ( scan.length == 2 ) { // whitespace / null false positive
            scan.type = XTR_VALUE_CHAR; scan.value = 'X';
        }
        return scan;
    }

    // \0-0377
    if (sscanf(source, "\\0%3o", &scan.value)) {
        scan.type = XTR_VALUE_OCTAL;
        if (scan.value >= XTR_RANGE_MAX) { // over-step, truncate
            // \0-037
            sscanf(source, "\\0%2o", &scan.value);
            scan.length = 4;
            return scan;
        }
        index = 1;
        while (xtr_isoctdigit(source[index]) && (++index < 5));
        scan.length = index;
        return scan;
    }

    // \1-255
    if (sscanf(source, "\\%3u", &scan.value)) {
        scan.type = XTR_VALUE_INTEGER;
        if (scan.value >= XTR_RANGE_MAX) { // over-step, truncate
            sscanf(source, "\\%2u", &scan.value);
            scan.length = 3;
            return scan;
        }
        index = 1;
        while (isdigit(source[index]) && (++index < 4));
        scan.length = index;
        return scan;
    }

    if ( *source == XTR_TOKEN_ESCAPE) {
        index++;
        scan.value = source[index];

        if ( ! source[index] ) { scan.type = XTR_VALUE_INVALID; return scan; }

        else if ( source[index] == 'a' ) scan.value = (int) '\a';
        else if ( source[index] == 'b' ) scan.value = (int) '\b';
        else if ( source[index] == 'f' ) scan.value = (int) '\f';
        else if ( source[index] == 'n' ) scan.value = (int) '\n';
        else if ( source[index] == 'r' ) scan.value = (int) '\r';
        else if ( source[index] == 't' ) scan.value = (int) '\t';
        else if ( source[index] == 'v' ) scan.value = (int) '\v';

        if (scan.value != source[index]) scan.type = XTR_VALUE_PREDEFINED;
        else scan.type = XTR_VALUE_CHAR;

        scan.length = (index + 1);
        return scan;
    }

    scan.type = XTR_VALUE_CHAR;
    scan.value = *source;
    scan.length = 1;

    return scan;

}

XTR_RANGE xtr_utils_scan_range(char * source) {

    register XTR_RANGE range = { 0, 0, NULL, 0 };
    register XTR_VALUE scan;

    int lbracket = xtr_utils_delimited_length(source, 0, XTR_RANGE_SPECIFIER_TOKEN);

    if (lbracket != 0) {
        range.error = XTR_RANGE_ERROR_MISSING_SPECIFIER_TOKEN;
        return range;
    }

    int rbracket = xtr_utils_delimited_length(source, 0, XTR_RANGE_TERMINATOR_TOKEN);
    if (rbracket < 1) {
        range.error = XTR_RANGE_ERROR_MISSING_TERMINATOR_TOKEN;
        return range;
    }

    int index;

    XTR_RANGE_SEQUENCE * sequence[XTR_RANGE_MAXIMUM_SEQUENCES];

    for( index = 1; index < rbracket; range.count += 1) {

        if (range.count == XTR_RANGE_MAXIMUM_SEQUENCES) {
            range.error = XTR_RANGE_ERROR_MAXIMUM_SEQUENCE_OVERFLOW;
            //range.count++; // don't increase this or overflow occurs @ memcpy
            break;
        }

        if ( source[index] == XTR_RANGE_SEPARATOR_TOKEN ) {
            range.error = XTR_RANGE_ERROR_MISSING_PRIMARY_VALUE;
            range.count++;
            break;
        }

        sequence[range.count] = malloc(sizeof(XTR_RANGE_SEQUENCE));

        scan = xtr_utils_scan_value(source + index);
        sequence[range.count]->begin = scan.value;
        index += scan.length;

        if ( source[index] != XTR_RANGE_SEPARATOR_TOKEN ) {
            range.error = XTR_RANGE_ERROR_MISSING_RANGE_SEPARATOR;
            range.count++;
            break;
        }

        index++;

        if ( index == rbracket ) {
            range.error = XTR_RANGE_ERROR_MISSING_SECONDARY_VALUE;
            range.count++;
            break;
        }

        scan = xtr_utils_scan_value(source + index);
        sequence[range.count]->end = scan.value;
        index += scan.length;

    }

    if ( ! range.count ) {
        range.error = XTR_RANGE_ERROR_MISSING_INPUT;
        range.count++; // range has an implied count
    }
    else {
        long sequence_length = (range.count * sizeof(XTR_RANGE_SEQUENCE *));
        range.sequence = malloc(sequence_length);
        memcpy(range.sequence, sequence, sequence_length);
        range.length = index;
    }

    return range;

}

XTR_LIST xtr_utils_scan_list(char * source) {

    XTR_LIST list = xtr_list_new();
    XTR_RANGE range;
    XTR_VALUE scan;

    if ( ! source ) return list;
    else if ( ! *source ) { list.error = XTR_LIST_EMPTY; return list; }

    // we want a localized list.
    long int length = xtr_utils_delimited_length(source, 0, XTR_TOKEN_NEXT), index;

    if ( length == -1) length = strlen(source);

    char local[length + 1];
    local[length] = 0;

    memcpy(local, source, length);

    for (index = 0; index < length;) {
        list.count++; // COUNT BEGINS AT 1 : NULL COUNT IS A GENERAL ERROR
        if (local[index] == XTR_RANGE_SPECIFIER_TOKEN) {
            range = xtr_utils_scan_range(local + index);
            if ( ! range.error ) {
                register int value, final, set;
                for (set = 0; set < range.count; set++) {
                    if (range.sequence[set]->begin > range.sequence[set]->end) {
                        value = range.sequence[set]->end;
                        final = range.sequence[set]->begin;
                    } else {
                        value = range.sequence[set]->begin;
                        final = range.sequence[set]->end;
                    }
                    for (; value <= final; value++) list.value[value] = XTR_TRUE;
                }
                index += range.length;
            } else {
                list.error = range.error;
                list.range = range.count;
                xtr_range_free(&range);
                break; // end list processing
            }
            xtr_range_free(&range);
            continue;
        }
        scan = xtr_utils_scan_value(local + index);
        list.value[scan.value] = XTR_TRUE;
        index += scan.length;
        continue;
    }

    if ( ! list.count ) {
        list.error = XTR_LIST_EMPTY;
    }

    list.length = length;
    return list;

}

char * xtr_context_intern(XTR_CONTEXT * xtrcx, char * source, char delimiter) {

    if ( ! source ) return source;    // allows NULL to be set in procedures who call this

    unsigned long int existing;
    if (xtrcx->interns) {
        for (existing = 0; existing < xtrcx->interns; existing++) {
            if (xtrcx->intern[existing] == source) return source;
            else if (xtr_utils_sequence_match(xtrcx->intern[existing], source)) {
                return xtrcx->intern[existing];
            }
        }
        xtrcx->intern = realloc(xtrcx->intern, (sizeof(char *) * xtrcx->interns));
    } else xtrcx->intern = realloc(xtrcx->intern, sizeof(char *));

    unsigned long int length = xtr_utils_delimited_length(source, 0, delimiter);
    if (length == -1) length = strlen(source);
    register char * intern = memcpy(calloc(1, length + 1), source, length);
    xtrcx->intern[xtrcx->interns++] = intern;
    return intern;

}

void xtr_context_intern_range(XTR_CONTEXT * xtrcx, char ** target, XTR_RANGE * range, char * string, char delimiter) {

    register int value, final, set;

    string = xtr_context_intern(xtrcx, string, delimiter);

    for (set = 0; set < range->count; set++) {
        if (range->sequence[set]->begin > range->sequence[set]->end) {
            value = range->sequence[set]->end;
            final = range->sequence[set]->begin;
        } else {
            value = range->sequence[set]->begin;
            final = range->sequence[set]->end;
        }
        for (; value <= final; value++) target[value] = string;
    }

}

void xtr_context_intern_list(register XTR_CONTEXT * xtrcx, char ** target, XTR_LIST * list, char * string) {

    if ( ! xtrcx || ! list ) return;

    if (list->error) return;

    string = xtr_context_intern(xtrcx, string, XTR_TOKEN_NEXT);

    register int item1 = 0; register int item2 = 1;

    for (; item2 < XTR_RANGE_MAX; item1+=2, item2+=2 ) {
        if (list->value[item1]) target[item1] = string;
        if (list->value[item2]) target[item2] = string;
    }

}

void xtr_context_set_value_exclude(register XTR_CONTEXT * xtrcx, int status, int value) {
    xtrcx->profile |= XTR_PERFORMANCE_EXCLUSIVE;
    xtrcx->exclude[value] = status;
}

void xtr_context_set_range_exclude(register XTR_CONTEXT * xtrcx, XTR_RANGE * range, register int status) {
    xtrcx->profile |= XTR_PERFORMANCE_EXCLUSIVE;
    register int value, final, set;
    for (set = 0; set < range->count; set++) {
        if (range->sequence[set]->begin > range->sequence[set]->end) {
            value = range->sequence[set]->end;
            final = range->sequence[set]->begin;
        } else {
            value = range->sequence[set]->begin;
            final = range->sequence[set]->end;
        }
        for (; value <= final; value++) xtrcx->exclude[value] = status;
    }
}

void xtr_context_set_list_exclude(register XTR_CONTEXT * xtrcx, XTR_LIST * list, int value) {

    if ( ! xtrcx || ! list ) return;

    if ( list->error ) return;

    xtrcx->profile |= XTR_PERFORMANCE_EXCLUSIVE;

    register int item1 = 0; register int item2 = 1;

    for (; item2 < XTR_RANGE_MAX; item1+=2, item2+=2 ) {
        if (list->value[item1]) xtrcx->exclude[item1] = value;
        if (list->value[item2]) xtrcx->exclude[item2] = value;
    }

}

void xtr_context_set_substitution(register XTR_CONTEXT * xtrcx, char * substitute, int value) {
    xtrcx->profile |= XTR_PERFORMANCE_DIVERSE;
    xtrcx->substitute[value] = xtr_context_intern(xtrcx,
        substitute, XTR_TOKEN_NEXT
    );
}

void xtr_context_set_range_substitution(register XTR_CONTEXT * xtrcx, XTR_RANGE * range, char * substitute) {
    xtrcx->profile |= XTR_PERFORMANCE_DIVERSE;
    xtr_context_intern_range(xtrcx,
        xtrcx->substitute, range, substitute, XTR_TOKEN_NEXT
    );
}

void xtr_context_set_list_substitution(register XTR_CONTEXT * xtrcx, XTR_LIST * list , char * substitute) {
    xtrcx->profile |= XTR_PERFORMANCE_DIVERSE;
    xtr_context_intern_list(xtrcx, xtrcx->substitute, list, substitute);
}

void xtr_context_set_prefix(register XTR_CONTEXT * xtrcx, int value, char * prefix) {
    xtrcx->profile |= XTR_PERFORMANCE_ENHANCED;
    xtrcx->prefix[value] = xtr_context_intern(xtrcx,
        prefix, 0
    );
}

void xtr_context_set_range_prefix(register XTR_CONTEXT * xtrcx, XTR_RANGE * range, register char * prefix) {
    xtrcx->profile |= XTR_PERFORMANCE_ENHANCED;
    xtr_context_intern_range(xtrcx,
        xtrcx->prefix, range, prefix, 0
    );
}

void xtr_context_set_list_prefix(register XTR_CONTEXT * xtrcx, XTR_LIST * list , char * prefix) {
    xtrcx->profile |= XTR_PERFORMANCE_DIVERSE;
    xtr_context_intern_list(xtrcx, xtrcx->prefix, list, prefix);
}

void xtr_context_set_suffix(register XTR_CONTEXT * xtrcx, int value, char * suffix) {
    xtrcx->profile |= XTR_PERFORMANCE_ENHANCED;
    xtrcx->suffix[value] = xtr_context_intern(xtrcx,
        suffix, 0
    );
}

void xtr_context_set_range_suffix(register XTR_CONTEXT * xtrcx, XTR_RANGE * range, register char * suffix) {
    xtrcx->profile |= XTR_PERFORMANCE_ENHANCED;
    xtr_context_intern_range(xtrcx,
        xtrcx->suffix, range, suffix, 0
    );
}

void xtr_context_set_list_suffix(register XTR_CONTEXT * xtrcx, XTR_LIST * list , char * suffix) {
    xtrcx->profile |= XTR_PERFORMANCE_DIVERSE;
    xtr_context_intern_list(xtrcx, xtrcx->suffix, list, suffix);
}

void xtr_context_set_format(register XTR_CONTEXT * xtrcx, int value, char * format) {
    xtrcx->profile |= XTR_PERFORMANCE_ENHANCED;
    xtrcx->format[value] = xtr_context_intern(xtrcx,
        format, 0
    );
}

void xtr_context_set_range_format(register XTR_CONTEXT * xtrcx, XTR_RANGE * range, register char * format) {
    xtrcx->profile |= XTR_PERFORMANCE_ENHANCED;
    xtr_context_intern_range(xtrcx,
        xtrcx->format, range, format, 0
    );
}

void xtr_context_set_list_format(register XTR_CONTEXT * xtrcx, XTR_LIST * list , char * format) {
    xtrcx->profile |= XTR_PERFORMANCE_DIVERSE;
    xtr_context_intern_list(xtrcx, xtrcx->format, list, format);
}


int xtr_print_value_prefix(XTR_CONTEXT * xtrcx, FILE * out, int value) {
    if (xtrcx->prefix[value]) return fprintf(out, "%s", xtrcx->prefix[value]);
    else if (xtrcx->default_prefix) return fprintf(out, "%s", xtrcx->default_prefix);
    else return 0;
}

int xtr_print_value_suffix(XTR_CONTEXT * xtrcx, FILE * out, int value) {
    if (xtrcx->suffix[value]) return fprintf(out, "%s", xtrcx->suffix[value]);
    else if (xtrcx->default_suffix) return fprintf(out, "%s", xtrcx->default_suffix);
    else return 0;
}

int xtr_print_value_format(XTR_CONTEXT * xtrcx, FILE * out, int value) {
    if (xtrcx->format[value]) return fprintf(out, xtrcx->format[value], value);
    else if (xtrcx->default_format) return fprintf(out, xtrcx->default_format, value);
    else return 0;
}

// NOTHING FANCY HERE
int xtr_print_value(XTR_CONTEXT * xtrcx, FILE * out, int value) {
    return fprintf(out, xtrcx->default_format, value);
}

// GETTING FANCY HERE, POSSIBLE PREFIX, SUFFIX, AND FORMAT
int xtr_print_enhanced_value(XTR_CONTEXT * xtrcx, FILE * out, int value) {

    register int p = 0, v = 0, s = 0;

    p = xtr_print_value_prefix(xtrcx, out, value);
    v = fprintf(out, xtrcx->default_format, value);
    s = xtr_print_value_suffix(xtrcx, out, value);

    return (p + v + s);

}

int xtr_print_exclusive_value(XTR_CONTEXT * xtrcx, FILE * out, int value) {

    register int p = 0, v = 0, s = 0;

    if (xtrcx->exclude[value]) return fprintf(out, "%c", value);

    p = xtr_print_value_prefix(xtrcx, out, value);
    v = xtr_print_value_format(xtrcx, out, value);
    s = xtr_print_value_suffix(xtrcx, out, value);

    return (p + v + s);

}

int xtr_print_diverse_value(XTR_CONTEXT * xtrcx, FILE * out, int value) {

    register int p = 0, v = 0, s = 0;

    if (xtrcx->substitute[value])
        return fprintf(out, "%s", xtrcx->substitute[value]);

    if (xtrcx->exclude[value]) return fprintf(out, "%c", value);

    p = xtr_print_value_prefix(xtrcx, out, value);
    v = xtr_print_value_format(xtrcx, out, value);
    s = xtr_print_value_suffix(xtrcx, out, value);

    return (p + v + s);

}

#define xtr_affirmative(n) (n > -1)

XTR_LIST xtr_verify_list_fatal(int argument, XTR_LIST list) {

    if (list.error) {
        if (list.error < 8) {
            fprintf(stderr,
                "error in argument %u: list item %u: range sequence %u: %s\n",
                argument, list.count, list.range,
                xtr_utils_list_error_tostring(&list)
            );
        } else {
            fprintf(stderr,
                "error in argument %u: %s\n",
                argument,  xtr_utils_list_error_tostring(&list)
            );
        }
        exit(argument);
    }

    return list;

}

XTR_RANGE xtr_verify_range_fatal(int argument, XTR_RANGE range) {
    if (range.error) {
        fprintf(stderr,
            "error in argument %u: range sequence %u: %s\n",
            argument, range.count, xtr_utils_range_error_tostring(&range)
        );
        exit(argument);
    }
    return range;
}

void xtr_affix(XTR_CONTEXT * cx, int argument, char * option) {

    long int lp = 0, ls = 0;
    char *p = NULL, *s = NULL;

    XTR_LIST list = xtr_verify_list_fatal(argument, xtr_utils_scan_list(option));

    option += list.length;

    if (! *option++ == XTR_TOKEN_NEXT ) {
        fprintf(stderr, "error in argument %u: missing list terminator `/'\n", argument);
        exit(argument);
    }

    p = option;

    if ( ! *p ) {
        xtr_context_set_list_prefix(cx, &list, NULL);
        xtr_context_set_list_suffix(cx, &list, NULL);
        return;
    }

    if (xtr_utils_sequence_match(p, "//")) /* NOP */ return;

    lp = xtr_utils_delimited_length(p, 0, XTR_TOKEN_NEXT);
    if (lp < 0) {
        xtr_context_set_list_prefix(cx, &list, p);
        xtr_context_set_list_suffix(cx, &list, p);
        return;
    }

    s = (option + lp + 1);

    if (*s) {
        ls = xtr_utils_delimited_length(s, 0, XTR_TOKEN_NEXT);
        if (ls < 0) ls = xtr_utils_delimited_length(s, 0, 0);
    } else {
        xtr_context_set_list_prefix(cx, &list, p);
        xtr_context_set_list_suffix(cx, &list, p);
        return;
    }

    if (lp) {
        xtr_context_set_list_prefix(cx, &list, p);
    }

    if (ls) {
        xtr_context_set_list_suffix(cx, &list, s);
    }

    xtr_list_free(&list);

}

/* used alot so its a fill in cheesepurger */
#define xtr_main_switch(cp) if (*option) cp = option; else cp = argv[++argument]

int main(int argc, char * argv[], char * env[]) {

    /* serious pr4mance hit on linux keep disabled unless set by option */
    //setvbuf(stdin, NULL, _IONBF, 0); setvbuf(stdout, NULL, _IONBF, 0);

    int argument;
    char * option, * subopt1, * subopt2;

    XTR_CONTEXT * xtr = xtr_new_context(
        (char*) XTR_DEFAULT_FORMAT
    );

    XTR_LIST list;    // We scan lists to verify them.
    XTR_RANGE range; // we provide range as an option so sometimes we need to scan.

    if ( argc > 1 ) {
        for (argument = 1; argument < argc; argument++) {
            option = argv[argument];
            if (xtr_utils_sequence_match(option, "--help")) {
                puts(main_help);
                exit(0);
            } else if ( * option == XTR_OPTION_DETRACT ) {
                option++;
                if ( * option == XTR_EXCLUSIVE_OPTION) { // inverse exclude list
                    option++;
                    xtr_main_switch(subopt1);
                    list = xtr_verify_list_fatal(
                        argument, xtr_utils_scan_list(subopt1)
                    );
                    xtr_context_set_list_exclude(xtr, &list, 0);
                    xtr_list_free(&list);
                    continue;
                } else if ( * option == XTR_INCLUSIVE_OPTION ) { // inverse inclu list
                    option++;
                    xtr_main_switch(subopt1);
                    list = xtr_verify_list_fatal(
                        argument, xtr_utils_scan_list(subopt1)
                    );
                    xtr_context_set_list_exclude(xtr, &list, 1);
                    xtr_list_free(&list);
                    continue;
                } else if ( * option == XTR_RANGE_SPECIFIER_TOKEN ) { // exclude range
                    range = xtr_verify_range_fatal(
                        argument, xtr_utils_scan_range(option)
                    );
                    xtr_context_set_range_exclude(xtr, &range, 1);
                    xtr_range_free(&range);
                    continue;
                } else if ( * option == XTR_GLOBAL_PREFIX_OPTION ) {
                    option++;
                    // there is no api to set defaults yet so were setting profile here.
                    xtr->profile |= XTR_PERFORMANCE_ENHANCED;
                    xtr_main_switch(subopt1);
                    xtr->default_prefix = subopt1;
                    continue;
                } else if ( * option == XTR_GLOBAL_SUFFIX_OPTION ) {
                    option++;
                    // there is no api to set defaults yet so were setting profile here.
                    xtr->profile |= XTR_PERFORMANCE_ENHANCED;
                    xtr_main_switch(subopt1);
                    xtr->default_suffix = subopt1;
                    continue;
                } else if ( * option == XTR_FORMAT_OPTION ) {
                    option++;
                    xtr_main_switch(subopt1);
                    if (xtr_utils_sequence_match(subopt1, "char")) {
                        xtr->default_format = "%c";
                    } else if (xtr_utils_sequence_match(subopt1, "hex")) {
                        xtr->default_format = "%02hx";
                    } else if (xtr_utils_sequence_match(subopt1, "octal")) {
                        xtr->default_format = "%03o";
                    } else {
                        fprintf(stderr,
                            "error in argument %u: unknown format `%s'\n",
                            argument, subopt1
                        );
                        exit(argument);
                    }
                    continue;
                } else {
                    fprintf(stderr,
                        "error in argument %u: unknown option or subtractive %s\n",
                        argument, option
                    );
                    exit(argument);
                }
            } else if ( * option == XTR_OPTION_ATTRACT ) {
                option++;
                if ( * option == XTR_EXCLUSIVE_OPTION ) { // exclude list
                    option++;
                    xtr_main_switch(subopt1);
                    list = xtr_verify_list_fatal(
                        argument, xtr_utils_scan_list(subopt1)
                    );
                    xtr_context_set_list_exclude(xtr, &list, 1);
                    xtr_list_free(&list);
                } else if ( * option == XTR_INCLUSIVE_OPTION ) { // include list
                    option++;
                    xtr_main_switch(subopt1);
                    list = xtr_verify_list_fatal(
                        argument, xtr_utils_scan_list(subopt1)
                    );
                    xtr_context_set_list_exclude(xtr, &list, 0);
                    xtr_list_free(&list);
                } else if ( * option == XTR_RANGE_SPECIFIER_TOKEN ) { // include range
                    range = xtr_verify_range_fatal(
                        argument, xtr_utils_scan_range(option)
                    );
                    xtr_context_set_range_exclude(xtr, &range, 0);
                    xtr_range_free(&range);
                } else {
                    fprintf(stderr,
                        "error in argument %u: unknown option or additive %s\n",
                        argument, option
                    );
                    exit(argument);
                }
                continue;
            } else if ( * option == XTR_SUBSTITUTION_IDENTIFIER ) {
                option += 2;
                list = xtr_verify_list_fatal(argument, xtr_utils_scan_list(option));
                subopt1 = xtr_utils_token_address(option, XTR_TOKEN_NEXT);
                if (! subopt1++ ) {
                    fprintf(stderr,
                        "error in argument %u: missing list terminator `/'\n",
                        argument
                    );
                    exit(argument);
                }
                xtr_context_set_list_substitution(xtr, &list, subopt1);
                xtr_list_free(&list);
                continue;
            } else if ( * option == XTR_AFFIX_IDENTIFIER ) {
                option += 2;
                xtr_affix(xtr, argument, option);
                continue;
            } else {
                fprintf(stderr,
                    "error in argument %u: unknown parameter `%s'\n",
                    argument, option
                );
                exit(argument);
            }
        }    // END FOR
    }

    int v;

    if (xtr->profile & XTR_PERFORMANCE_DIVERSE ) {
        while ((v = getchar()) != EOF) xtr_print_diverse_value(xtr, stdout, v);
    } else if (xtr->profile & XTR_PERFORMANCE_EXCLUSIVE ) {
        while ((v = getchar()) != EOF) xtr_print_exclusive_value(xtr, stdout, v);
    } else if (xtr->profile & XTR_PERFORMANCE_ENHANCED ) {
        while ((v = getchar()) != EOF) xtr_print_enhanced_value(xtr, stdout, v);
    } else {
        while ((v = getchar()) != EOF) xtr_print_value(xtr, stdout, v);
    }

    xtr_context_free(xtr);

    return 0;

}
