#include "monty.h"

extern globs* glob;

void add(stack_t** stack,u_int line)
{
    stack_t *head = null;
    int sSize = 0;
    line = line;
    
    if(*stack)
    {
        ++sSize;
        
        if((*stack)->next){
            head = (*stack)->next;
            head->prev = null;
            ++sSize;
            head->n += (*stack)->n;
            free(*stack);
            *stack = head;                       
        }
        
    }
    
    if(sSize < 2){
        sprintf(glob->errmsg,"L%u: can't add, stack too short",line);
        pErr(glob->errmsg);
    }    
}

void sub(stack_t** stack,u_int line)
{
    stack_t *head = null;
    int sSize = 0;
    line = line;
    
    if(*stack)
    {
        
        ++sSize;
        
        if((*stack)->next){
            head = (*stack)->next;
            head->prev = null;
            ++sSize;
            head->n =  head->n - (*stack)->n;
            free(*stack);
            *stack = head;                       
        }
        
    }
    
    if(sSize < 2){
        sprintf(glob->errmsg,"L%u: can't sub, stack too short",line);
        pErr(glob->errmsg);
    }    
}

void _div(stack_t** stack,u_int line)
{
    stack_t *head = null;
    int sSize = 0;
    line = line;
    
    if(*stack)
    {
        
        ++sSize;
        
        if((*stack)->next){
            head = (*stack)->next;
            head->prev = null;
            ++sSize;
            
            if((*stack)->n == 0){
                sprintf(glob->errmsg,"L%u: division by zero",line);
                pErr(glob->errmsg);
            }  
            
            head->n = head->n / (*stack)->n;
            free(*stack);
            *stack = head;                       
        }
        
    }
    
    if(sSize < 2){
        sprintf(glob->errmsg,"L%u: can't div, stack too short",line);
        pErr(glob->errmsg);
    }    
}


void _mod(stack_t** stack,u_int line)
{
    stack_t *head = null;
    int sSize = 0;
    line = line;
    
    if(*stack)
    {
        
        ++sSize;
        
        if((*stack)->next){
            head = (*stack)->next;
            head->prev = null;
            ++sSize;
            
            if((*stack)->n  == 0){
                sprintf(glob->errmsg,"L%u: division by zero",line);
                pErr(glob->errmsg);
            }  
            
            head->n = head->n % (*stack)->n ;
            free(*stack);
            *stack = head;                       
        }
        
    }
    
    if(sSize < 2){
        sprintf(glob->errmsg,"L%u: can't mod, stack too short",line);
        pErr(glob->errmsg);
    }    
}


void _mul(stack_t** stack,u_int line)
{
    stack_t *head = null;
    int sSize = 0;
    line = line;
    
    if(*stack)
    {
        ++sSize;
        
        if((*stack)->next){
            head = (*stack)->next;
            head->prev = null;
            ++sSize;
            head->n *= (*stack)->n;
            free(*stack);
            *stack = head;                       
        }
        
    }
    
    if(sSize < 2){
        sprintf(glob->errmsg,"L%u: can't mul, stack too short",line);
        pErr(glob->errmsg);
    }    
}