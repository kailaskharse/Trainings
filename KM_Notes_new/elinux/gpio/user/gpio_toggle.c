/***************************************************************************
 *      Organisation    : Kernel Masters, KPHB, Hyderabad, India.          *
 *      facebook page   : www.facebook.com/kernelmasters                   *
 *      Website         : www.kernelmasters.org                            *
 *  Conducting Workshops on - Embedded Linux & Device Drivers Training.    *
 *  -------------------------------------------------------------------    *
 *  Tel : 91-9949062828, Email : kernelmasters@gmail.com                   *    
 *                                                                         *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation. No warranty is attached; we cannot take *
 *   responsibility for errors or fitness for use.                         *
 ***************************************************************************/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int i;
	int counter = 0;
	int fd [3];
	char buffer [80];

	fd [0] = open ("/sys/class/gpio/gpio110/value", O_WRONLY);
	fd [1] = open ("/sys/class/gpio/gpio7/value", O_WRONLY);
	if ((fd [0] <0) | | (fd [1] <0) ) {
		perror ("open");
		exit (EXIT_FAILURE);
	}
	while (1) {
		for (i = 0; i <2; i + +) {sprintf (buffer, "% d", (counter >> i) & 1);
			write (fd [i], buffer, 1);
		}
		counter + +;
		counter = 8%;
		usleep (100000);
	}
}
