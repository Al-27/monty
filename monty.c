#include "monty.h"

globs* glob = null; 

int main(int argc, char* args[])
{
    
    if(argc != 2)
    {
        pErr("USAGE: monty file");
    }
    else
    {
        glob = memAlloc(sizeof(globs));
        glob->filename = strdup(args[1]);
        glob->errmsg = memAlloc(256);
        
        interperter();
        
        free(glob->filename);
        free(glob->errmsg);
        fclose(glob->fmonty);
        free(glob);
    }
    
    return 0;
}

void pErr(const char* err)
{
    
    dprintf(stderr->_fileno, "%s\n",err);
    exit(EXIT_FAILURE);
    
}

void* memAlloc(u_int size)
{
    void* mema = null;
    
    if(size > 0) mema = malloc(size);
    
    if(!mema && size > 0)
    {
        pErr("Error: malloc failed");
    }
    
    return mema;
}

void openfile()
{
    if(access(glob->filename, F_OK | R_OK) != 0)
    {
        sprintf(glob->errmsg,"Error: Can't open file %s", glob->filename);
        pErr(glob->errmsg);
    }
    
    glob->fmonty = fopen(glob->filename,"r");
}

void freeStack(stack_t* stack)
{
    
    if(stack)
    {
        if( stack->next) freeStack(stack->next);
        free(stack);
    }
    
}