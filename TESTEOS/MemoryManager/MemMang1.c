#include "MemMang1.h"

void *firstInfoBlock = NULL; 

//para la syscall
void *startMemory = NULL;  
void *currentMemoryLimit = NULL; 

struct infoBlock{
    size_t size;
    int free;
    struct infoBlock *next;

};
typedef struct infoBlock *infoBlockPtr;


//private:
void *sysCall(size_t size);
infoBlockPtr findFreeBlock(infoBlockPtr *last, size_t size);
infoBlockPtr requestSpace(infoBlockPtr last, size_t size);
infoBlockPtr getBlockPtr(void *ptr);


/*----------------------------------------------------------------*/
void *my_malloc(size_t size){
    if (size <= 0)
        return NULL;
    
    infoBlockPtr block; 
    if (firstInfoBlock == NULL){ // primer llamado
        block = requestSpace(NULL,size);
        if(block == NULL)
            return NULL;
        firstInfoBlock = block;
    }else{
        infoBlockPtr last = firstInfoBlock;
        block = findFreeBlock(&last, size);
        if (block == NULL){ 
            block = requestSpace(last, size);//agrego al final un nuevo bloque
            if(block == NULL)
                return NULL;
        }else{ // se encontro un boque
            // se podria dividir el bloque si es muy grande
            block->free = 0;
        }
    }
    return (block + 1); //la direccion justo despues de infoBlock
}

/*----------------------------------------------------------------*/
infoBlockPtr findFreeBlock(infoBlockPtr* last, size_t size){
    infoBlockPtr current = firstInfoBlock;
    while (current != NULL && !(current->free && current->size >= size)){
        *last = current;
        current = current->next;
    }
    return current;
}

/*----------------------------------------------------------------*/
//agregar un nuevo bloque al final de la lista
infoBlockPtr requestSpace(infoBlockPtr last, size_t size){
    infoBlockPtr block;
    block = sysCall(0); //block = sbrk(0); 
    void* check = sysCall(size + INFO_BLOCK_SIZE);
    if(check == NULL) //no hay mas espacio en el heap
        return NULL;

    if (last != NULL){ // si last==NULL es el primer llamado
        last->next = block;
    }
    block->size = size;
    block->next = NULL;
    block->free = 0;

    return block;
}

/*----------------------------------------------------------------*/
infoBlockPtr getBlockPtr(void *ptr) { //direcciond de 
    return (infoBlockPtr)ptr - 1;
}

/*----------------------------------------------------------------*/
void free(void *ptr) {
    if (!ptr)
        return;
    // TODO: consider merging blocks once splitting blocks is implemented.
    infoBlockPtr block_ptr = getBlockPtr(ptr);
    //assert(block_ptr->free == 0); check
    block_ptr->free = 1;
}


/*--------------------------------debugger------------------------------------*/
void checkMemory(void){
    infoBlockPtr current = firstInfoBlock;
    int numeberOfBlocks= 0;
    int totalMemUsed= 0;
    while (current != NULL){
        
    
        current = current->next;
    }


}

void printMemoryBLock(void){
    infoBlockPtr current = firstInfoBlock;
    int numeberOfBlocks= 0;
    int freeBlock = 0;
    while (current != NULL){
        printf("----------------------------------\n");
        printf("Block %d: %p\n",numeberOfBlocks, current);
        printf("  |-> size:%ld\n",current->size);
        printf("  |-> free:%s\n",(current->free == 0 ? "no" : "yes"));
        printf("  |-> next:%p\n",current->next);
        printf("\n");
        if(current->free == 1)
            freeBlock++;
        current = current->next;
        numeberOfBlocks++;
    }
    printf("----------------------------------\n");
    printf("cantidad de bloques: %d\n",numeberOfBlocks);
    printf("cantidad de bloques libres: %d\n",freeBlock);
    printf("----------------------------------\n");
    return;
}
void printAllMemory(void){
    infoBlockPtr current = firstInfoBlock;
    int numeberOfBlocks= 0;
    int freeBlock = 0;

    while (current != NULL){
        printf("-----------------------------\n");
        printf("Block %d: %p\n",numeberOfBlocks, current);
        printf("  |-> size:%ld\n",current->size);
        printf("  |-> free:%s\n",(current->free == 0 ? "yes" : "no"));
        printf("  |-> next:%p\n",current->next);
        printf("  |-> datos guardados:");
        char *aux = current+1; //NO hacer (char*)(current+1)
        for (int i = 0; i < current->size; i++){
            if(i%60 == 0){
                printf("\n \t");
            }
            printf("%d ", *(aux+i));
        }
        printf("|\n");
        if(current->free == 1)
            freeBlock++;
        current = current->next;
        numeberOfBlocks++;
    }
    printf("----------------------------------\n");
    printf("cantidad de bloques: %d\n",numeberOfBlocks);
    printf("cantidad de bloques libres: %d\n",freeBlock);
    printf("----------------------------------\n");
    return;
}

/*------------------------------SYSCALL----------------------------------------*/
void *sysCall(size_t size){ //devulve
    if(startMemory == NULL){
        startMemory = malloc(HEAP_SIZE);
        if(startMemory == NULL){
            printf("fallo syscall \n");
            exit(0);
        }
        currentMemoryLimit = startMemory;
        return currentMemoryLimit;
    }
    if((currentMemoryLimit-startMemory)+size <= HEAP_SIZE)
        return currentMemoryLimit+=size;

    return NULL;
}
void MM_end(){
    free(startMemory);
}



