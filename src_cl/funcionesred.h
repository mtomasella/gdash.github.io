// Funciones de red

#include "datos.h"

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int put_network_data(int sockfd, char *buffer, char *buffer2, char *buffer3, int k, char s, char e, int num, float v) {
    int n;

    memset((void *) buffer, '\0', 256);
    memset((void *) buffer2, '\0', 256);
    memset((void *) buffer3, '\0', 256);

	if (k != VACIO) {
			
		switch(k) {
			case KEY_UP:
				strcpy(buffer,"KEY_UP;");
				break;
			case KEY_DOWN:
				strcpy(buffer,"KEY_DOWN;"); 
				break;
			case KEY_LEFT:
				strcpy(buffer,"KEY_LEFT;");
				break;
			case KEY_RIGHT:
				strcpy(buffer,"KEY_RIGHT;");
				break;
			case KEY_EXIT:
				strcpy(buffer,"KEY_EXIT;");
				break;
			case KEY_SPACE:
				strcpy(buffer,"KEY_SPACE;"); 
				break;    
			case KEY_P:
				strcpy(buffer,"KEY_P;"); 
				break; 
			}
	
		switch(s) {
			case true:
				strcat(buffer,"true;");
				break;
			case false:
				strcat(buffer,"false;");
				break;           
			}
			
		} else {
			
			strcpy(buffer, "VACIO;");
			strcat(buffer, "VACIO;");
			
		}

	if (num != VACIO) {

		if (e == 'd') {
			strcat(buffer,"d;x;");
		
		} else {
				
			switch(e) {
				case 'x':
					strcat(buffer,"x;");
					break;          
							
				case 'y':
					strcat(buffer,"y;");
					break;      
						
			}
			
			sprintf(buffer2, "%i;", num);
			strcat(buffer, buffer2);
		}
		
		sprintf(buffer3, "%f;\0", v);
		strcat(buffer, buffer3);
		
	} else {
		
		strcat(buffer, "VACIO;");
		strcat(buffer, "VACIO;");
		strcat(buffer, "VACIO;\0");
		
	}

    //DBG - printf("Buffer: %s",buffer);
    n = write(sockfd,buffer,strlen(buffer));
    if (n < 0) error("ERROR writing to socket");

    return n;
}


int get_network_data(int sockfd, char *buffer, int *s, int *k) {
    int n;
    char *key, *status;

    // Me fijo si llegó via red
    memset((void *) buffer, '\0', 256);
    n = recv(sockfd,buffer,255,MSG_DONTWAIT);
    //DBG - printf("Buffer: %s / n: %d",buffer,n);

    if(n>0) {
        key = strtok(buffer,";");
        status = strtok(NULL,";");
        //DBG - printf("key: %s / status: %s\n",key,status);

        if(!strcmp(status,"true")) {
            *s=true;
        } else if(!strcmp(status,"false")) {
            *s=false;
        } else {
            printf("Error recepción. Buffer: %s",buffer);
            return 0;
        }

        if(!strcmp(key,"KEY_UP")) {
            *k=KEY_UP;
        } else if(!strcmp(key,"KEY_DOWN")) {
            *k=KEY_DOWN;
        } else if(!strcmp(key,"KEY_LEFT")) {
            *k=KEY_LEFT;
        } else if(!strcmp(key,"KEY_RIGHT")) {
            *k=KEY_RIGHT;
        } else if(!strcmp(key,"KEY_EXIT")) {
            *k=KEY_EXIT;
        } else if(!strcmp(key,"KEY_SPACE")) {
			*k=KEY_SPACE;
        } else if(!strcmp(key,"KEY_P")) {
			*k=KEY_P;
        } else {
            printf("Error recepción. Buffer: %s",buffer);
            return 0;
        }

        // Data saved (s+k), can return
        //DBG - printf("key: %d / status: %d\n",*k,*s);
        return 1;
    } else {
        return 0;
    }
}
