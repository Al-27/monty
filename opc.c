#include "monty.h"
extern globs* glob;

void push(stack_t** stack,u_int line)
{
    stack_t* temp = null;
    line = line;
    
    if(*stack)
    {
        temp = memAlloc(sizeof(stack_t));
        temp->n = glob->number;
        temp->prev = null;
        temp->next = *stack;
        (*stack)->prev = temp;
        *stack = temp;
    }
    else
    {
        
        *stack = memAlloc(sizeof(stack_t)); 
        (*stack)->n = glob->number;
        (*stack)->prev = null;
        (*stack)->next = null;
        
    }
}


void pall(stack_t** stack,u_int line)
{
    stack_t *temp = null;
    line = line;
    
    if(*stack)
    {
        temp = *stack;
        
        while(temp)
        {
            printf("%d\n",temp->n);
            temp = temp->next;
        }
    }
    
}


void pint(stack_t** stack,u_int line)
{
    stack_t *temp = null;
    line = line;
    
    if(*stack)
    {
        temp = *stack;
        printf("%d\n",temp->n);
    }
    else
    {
        sprintf(glob->errmsg,"L%u: can't pint, stack empty",line);
        pErr(glob->errmsg);
    }
    
}


void pop(stack_t** stack,u_int line)
{
    stack_t *head = null;
    line = line;
    
    if(*stack)
    {
        head = *stack;
        if((*stack)->next){
            (*stack) = (*stack)->next;
            (*stack)->prev = null;
            free(head);
        }
        else
        {
            free(*stack);
            (*stack) = null;
        }
    }
    else
    {
        sprintf(glob->errmsg,"L%u: can't pop an empty stack",line);
        pErr(glob->errmsg);
    }
    
}


void swap(stack_t** stack,u_int line)
{
    stack_t *Head = null, *newHead = null, *next=null;
    int sSize = 0;
    line = line;
    
    if(*stack)
    {
        Head = *stack;
        ++sSize;
        
        if((*stack)->next){
            ++sSize;
            
            newHead = (*stack)->next;
            if( newHead->next )
            {
                next = newHead->next;
                next->prev = Head;
            }
            newHead->prev = null;
            newHead->next = Head;
            
            Head->prev = newHead;
            Head->next = next ? next : null;
            
            (*stack) = newHead;            
             
        }
        
    }
    
    if(sSize < 2){
        sprintf(glob->errmsg,"L%u: can't swap, stack too short",line);
        pErr(glob->errmsg);
    }
}


