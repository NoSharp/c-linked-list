#include <stdio.h>
#include <stdlib.h>

// Stores:
    // - next_pointer, at the end of the list this will be 0.
    // - value

int set_element(void* list_base, int element_idx, void* val){
    
    void* base_idx = list_base;
    void* current_idx = base_idx;
    int increments = 0;
    while(increments <= element_idx){
        current_idx = (*(void**)(base_idx));
        
        if(increments == element_idx){
            *(void**)(current_idx + sizeof(void*)) = val;
            break;
        }

        if(current_idx == 0){
            break;
        }
        base_idx = current_idx;
        increments++;
    }
}

int append_element(void* list_base, void* value){
    
    void* base_idx = list_base;
    void* current_idx = base_idx;

    while(1==1){
        current_idx = (*(void**)(base_idx));
        if(current_idx == 0){
            break;
        }
        base_idx = current_idx;
    }


    void* new_element_addr = malloc(sizeof(void*) + sizeof(void*));

    *(void**)base_idx = new_element_addr; // Set the next node pointer of the last node to this.
    *(int*)new_element_addr = 0; // Set the next element in the list to 0.
    *(void**)(new_element_addr+sizeof(void*)) = value; // our actual value
}

void* read_element(void* list_base, int element_idx){
    void* base_idx = list_base;
    void* current_idx = base_idx;
    int increments = 0;
    while(1==1){
        current_idx = (*(void**)(base_idx));
        
        if(increments == element_idx){
            return *(void**)(current_idx + sizeof(void*));
        }

        if(current_idx == 0){
            break;
        }
        base_idx = current_idx;
        increments++;
    }

    return 0;
}

int debug_traverse_list(void* list_base){
    int i = 0;
    void* base_idx = list_base;
    void* current_idx = base_idx;
    while(1==1){
        current_idx = (*(void**)(base_idx));

        printf("Element: %d Value: %x Next_Element: 0x%x(base:%x, sz_voidptr: %x, total: %x)\n", 
            i,
          
            *(int*)(current_idx+sizeof(void*)),
            *(void**)current_idx, 
          
            current_idx,
            sizeof(void*),
            current_idx + sizeof(void*)
        
        );

        i++;

        if(*(void**)current_idx == 0){
            break;
        }
        base_idx = current_idx;
    }

}

void* create_list(){
    void* base_addr = malloc(sizeof(void*) + sizeof(int));
    *(int*)base_addr = 0;
}

int main(){
    void* base_addr = create_list();
    append_element(base_addr, (void*)15);
    append_element(base_addr, (void*)15);
    debug_traverse_list(base_addr);
    set_element(base_addr, 1, (void*)16);
    printf("Element: %d Value: %d", 1, read_element(base_addr, 1));
}