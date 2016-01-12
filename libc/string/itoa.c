#include <string.h>

char* itoa(int i,char* b,int base)
{
	char const digit[] = "0123456789ABCDEF";
    char* p = b;
    if(base == 16){
    	*p++ = '0';
    	*p++ = 'x';
    	if(i<0){
    	    i *=-1;
    	}    	    
    }
    if(i<0){
        *p++ = '-';
        i *= -1;
    }
    int shifter = i;
    do{ //Move to where representation ends
        ++p;
        shifter = shifter/base;
    } while(shifter);
    *p = '\0';
    do{ //Move back, inserting digits as u go
        *--p = digit[i%base];
        i = i/base;
    } while(i);
    return b;
}

char* uitoa(long unsigned int i,char* b,int base)
{
	char const digit[] = "0123456789ABCDEF";
    char* p = b;
    if(base == 16){
    	*p++ = '0';
    	*p++ = 'x'; 	    
    }
    int shifter = i;
    do{ //Move to where representation ends
        ++p;
        shifter = shifter/base;
    } while(shifter);
    *p = '\0';
    do{ //Move back, inserting digits as u go
        *--p = digit[i%base];
        i = i/base;
    } while(i);
    return b;
}
