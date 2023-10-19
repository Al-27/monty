#include "monty.h"
#include <ctype.h>

extern globs* glob;
void interperter()
{
    unsigned int linenumber = 0;
    size_t buffer = 1024 ;
    char* opcode = null,*line=null, *tok, *tok2;
    instruction_t instruct;
    stack_t *stack = null;
    
    openfile();
    
    while(!feof(glob->fmonty))
    {
        linenumber++;
        
        line = memAlloc(buffer+1);
        
        getline(&line,&buffer,glob->fmonty);
        
        
        tok = strtok(line," $\t\n");
        tok2 = strtok(null," $\t\n");
        
        if(tok && tok[0] != '#') { 
            opcode = memAlloc(64); 
            
            if(tok2) sprintf(opcode,"%s %s",tok, tok2);
            else if(tok) sprintf(opcode,"%s",tok);
            checkOpcode(tok,tok2,linenumber);
            
            /*if(opcode) printf("%s\n", opcode);*/
            
            instruct = initInstruct(tok);
            
            if(strcmp(instruct.opcode,"nop") != 0)
            {
                instruct.f(&stack, linenumber);
            }
            
            
            free(opcode);
        }
        
        free(line);
        opcode = null;
    }
    
    freeStack(stack);
}

void checkOpcode(char* op, char* val, u_int linenum)
{
    char *opcodes[] = {"push"},
          *opcodes_noArg[] = {"pall","pint","pop","nop","add","sub","div","mul","mod","swap","pchar","pstr","rotl",null},
           *cNum = val ? val : null;
    int invalid = 0x01, i = 0; /*  0x01: invalid op, 0x02 : val isn't a digit or no args  */
    
    if(op)
    {
        
        while(opcodes_noArg[i])
        {
            if( !strcmp(op,opcodes_noArg[i]) ) 
            {
                invalid = 0x00;
                break;
            }
            if(  !strcmp(op,opcodes[0]) )
            {
                invalid = 0x02;
                break;
            }
            i++;
        }
        
        if(val && invalid & 0x02)
        {
            invalid ^= 0x02;
            if(val[0] == '-' || val[0] == '+')
                val++;
            
            while(*val)
            {
                if(!isdigit(*val))
                {
                    invalid |= 0x02;
                    break;
                }
                val++;
            }
            if( !(invalid & 0x02) )
            {
                glob->number = atoi(cNum);
            }
        }
        
    }
    
    if(invalid & 0x01){
        sprintf(glob->errmsg,"L%u: unknown instruction %s",linenum, op);
        pErr(glob->errmsg);
    }
    if(invalid & 0x02){
            sprintf(glob->errmsg,"L%u: usage: push integer",linenum);
            pErr(glob->errmsg);
    }
        
    
}


instruction_t initInstruct(char *op)
{
    instruction_t ist[] = {
      {"push",&(push)},
      {"swap",&(swap)},
      {"add", &(add)}, 
      {"sub", &(sub)}, 
      {"pall",&(pall)}, 
      {"pint",&(pint)}, 
      {"pop", &(pop)}, 
      {"nop", (null)}, 
      {"div", &(_div)}, 
      {"mul", &(_mul)}, 
      {"mod", &(_mod)},
      {"pchar", &(pchar)},
      {"pstr", &(pstr)},
      {"rotl", &(rotl)},
      {null, null}
    };
    int i = 0;
    
    while(ist[i].opcode)
    {
        if(strcmp(ist[i].opcode, op) == 0)
        {
            break;
        }
        i++;
    }
    
    return ist[i];
}