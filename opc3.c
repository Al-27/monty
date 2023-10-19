#include "monty.h"
#include <ctype.h>

extern globs* glob;

void pchar(stack_t** stack,u_int line)
{
    if(*stack)
    {
        if(isprint((*stack)->n))
        {
            printf("%c\n",(*stack)->n);
        }
        else
        {
            sprintf(glob->errmsg,"L%u: can't pchar, value out of range",line);
            pErr(glob->errmsg);
        }
    }
    else{
        sprintf(glob->errmsg,"L%u: can't pchar, stack empty",line);
        pErr(glob->errmsg);
    }  
}


void pstr(stack_t** stack,u_int line)
{
    stack_t *curs = null;
    line = line;
    
    if(*stack)
    {
        curs = *stack;
        
        while(curs ){
            if(isprint(curs->n))
            {
                printf("%c",curs->n);
            }
            else
            {
                break;
            }
            curs = curs->next;
        }
        
    }
    
    printf("\n");    
    
}


void rotl(stack_t **stack, u_int line)
{
    stack_t *cursor = null, *newH = null, *tail = null;
    line = line;
    if(*stack)
    {
        cursor = *stack;
        
        if(cursor->next)
        {
            
            newH = cursor->next;
            
            while(cursor->next) cursor = cursor->next;
            
            tail = cursor, cursor = *stack;
            
            tail->next = *stack;
            
            newH->prev = null;
            
            cursor->next = null;
            cursor->prev = tail;
            
            *stack = newH;
            
        }
        
    }
    
}
