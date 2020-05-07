/***************************************************************************
 *      Organisation    : Kernel Masters, KPHB, Hyderabad, India.          *
 *      Website 	: www.kernelmasters.org		                   *
 *      facebook page   : www.facebook.com/kernelmasters                   *
 *                                                                         *
 *  Conducting Workshops on - Embedded Linux & Device Drivers Training.    *
 *  -------------------------------------------------------------------    *
 *  Tel : 91-9949062828, Email : kishore@kernelmasters.org                 *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation. No warranty is attached; we cannot take *
 *   responsibility for errors or fitness for use.                         *
 ***************************************************************************/
#include<errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <mosquitto.h>
#include <unistd.h>
#include <fcntl.h>

#define MAXLEN 80
#define CONFIG_FILE "config"
struct mosquitto *mosq = NULL;
int keepalive = 60;
bool clean_session = true;

char MQTT_HOST[MAXLEN];
int  MQTT_PORT;
char MQTT_TOPIC[MAXLEN];


void param_config(void);
char* trim (char * );

int main() {

	uint8_t reconnect = true;
	char clientid[24];
	int rc = 0;
        int i = -1000;
        char buf[30]; 

	param_config();	//Reading config file

	mosquitto_lib_init();

	mosq = mosquitto_new(clientid, true, 0);

        rc = mosquitto_connect(mosq, MQTT_HOST, MQTT_PORT, keepalive);
        
	while(1)
	{
        	sprintf(buf,"i=%i",i++);
		int snd = mosquitto_publish(mosq, NULL, MQTT_TOPIC, strlen(buf), buf, 0, 0);
        	if(snd != 0) printf("mqtt_send error=%i\n", snd);
        	usleep(100000);
	}

        mosquitto_destroy(mosq);
	mosquitto_lib_cleanup();
 
	return rc;
}


void param_config(void) {
	char *s, buff[256];
	FILE *fp = fopen (CONFIG_FILE, "r");
	if (fp == NULL)
	{
		return;
	}

	/* Read next line */
	while ((s = fgets (buff, sizeof buff, fp)) != NULL)
	{
		/* Skip blank lines and comments */
		if (buff[0] == '\n' || buff[0] == '#')
			continue;

		/* Parse name/value pair from line */
		char name[MAXLEN], value[MAXLEN];
		s = strtok (buff, "=");
		if (s==NULL)
			continue;
		else
			strncpy (name, s, MAXLEN);
		s = strtok (NULL, "=");
		if (s==NULL)
			continue;
		else
			strncpy (value, s, MAXLEN);
		trim (value);

		/* Copy into correct entry in parameters struct */
		if (strcmp(name, "MQTT_HOST")==0){
			strncpy (MQTT_HOST, value, MAXLEN);
			printf("MQTT_HOST:\t%s\n",MQTT_HOST);
		}
		else if (strcmp(name, "MQTT_PORT")==0){
			MQTT_PORT = atoi(value);
			printf("MQTT_PORT:\t%d\n",MQTT_PORT);
		}
		//      strncpy (parms->flavor, value, MAXLEN);
		else if (strcmp(name, "MQTT_TOPIC")==0){
			strncpy (MQTT_TOPIC, value, MAXLEN);
			printf("MQTT_TOPIC:\t%s\n",MQTT_TOPIC);
		}
		else
			printf ("WARNING: %s/%s: Unknown name/value pair!\n",
					name, value);
	}

	/* Close file */
	fclose (fp);
}


char* trim (char * s)
{
	/* Initialize start, end pointers */
	char *s1 = s, *s2 = &s[strlen (s) - 1];

	/* Trim and delimit right side */
	while ( (isspace (*s2)) && (s2 >= s1) )
		s2--;
	*(s2+1) = '\0';

	/* Trim left side */
	while ( (isspace (*s1)) && (s1 < s2) )
		s1++;

	/* Copy finished string */
	strcpy (s, s1);
	return s;
}

