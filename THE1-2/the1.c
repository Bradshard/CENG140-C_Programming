#include <stdio.h>
#include "the1.h"

#define MAX_ITER 1000
#define INF 1000000


void task1_assembly(void) {
    /* IMPLEMENT THIS FUNCTION */
    int num_instr;
    int instruction_count = 0;
    char inst_type[20];
    int args[20][3]; /* 20 instructions top with max 3 arguments each. */
    int assembly_regs[8];
    int max_iter = 0;
    
    int i;

    for(i = 0; i < 8; i++){
        assembly_regs[i] = 0;
    }
    
    scanf("%d", &num_instr);
    
    for (i = 0; i < num_instr; i++) {
        scanf(" %c", &inst_type[i]);

        if (inst_type[i] == 'A' || inst_type[i] == 'C' || inst_type[i] == 'S') {
            scanf("%d %d", &args[i][0], &args[i][1]);
        } else if (inst_type[i] == 'D' || inst_type[i] == 'I') {
            scanf("%d", &args[i][0]);
        } else if (inst_type[i] == 'J') {
            scanf("%d %d %d", &args[i][0], &args[i][1], &args[i][2]);
        }
    }
    
    while(instruction_count < num_instr && max_iter < MAX_ITER){
        max_iter++;
        
        if(inst_type[instruction_count] == 'A' && args[instruction_count][0] >= 1 && args[instruction_count][0] <= 8 && args[instruction_count][1] >= 1 && args[instruction_count][1] <= 8){
            assembly_regs[args[instruction_count][0] - 1] = assembly_regs[args[instruction_count][0] - 1] + assembly_regs[args[instruction_count][1] - 1];
            instruction_count++;
            
            
        } else if(inst_type[instruction_count] == 'C' && args[instruction_count][0] >= 1 && args[instruction_count][0] <= 8 && args[instruction_count][1] >= 1 && args[instruction_count][1] <= 8){
            assembly_regs[args[instruction_count][0] - 1] = assembly_regs[args[instruction_count][1] - 1];
            instruction_count++;
            
            
        } else if(inst_type[instruction_count] == 'D' && args[instruction_count][0] >= 1 && args[instruction_count][0] <= 8){
            assembly_regs[args[instruction_count][0] - 1] = assembly_regs[args[instruction_count][0] - 1] - 1;
            instruction_count++;
            
            
        } else if(inst_type[instruction_count] == 'I' && args[instruction_count][0] >= 1 && args[instruction_count][0] <= 8){
            assembly_regs[args[instruction_count][0] - 1] = assembly_regs[args[instruction_count][0] - 1] + 1;
            instruction_count++;
            
            
        } else if(inst_type[instruction_count] == 'J'){
            if(assembly_regs[args[instruction_count][0] - 1] > assembly_regs[args[instruction_count][1] - 1] && args[instruction_count][2] >=0 && args[instruction_count][2] < num_instr && args[instruction_count][0] >= 1 && args[instruction_count][0] <= 8 && args[instruction_count][1] >= 1 && args[instruction_count][1] <= 8){
                instruction_count = args[instruction_count][2] - 1;
            } else{
                instruction_count++;
            }
            
        } else if(inst_type[instruction_count] == 'S' && args[instruction_count][0] >= 1 && args[instruction_count][0] <= 8){
            assembly_regs[args[instruction_count][0] - 1] = args[instruction_count][1];
            instruction_count++;
            
        }
    }
    
    for (i = 0; i < 8; i++) {
        printf("R%d: %d\n", i + 1, assembly_regs[i]);
    }
}

int calculate_planes(int land_length, int land_width, int plane_capacities[], int num_of_planes) {
    /* IMPLEMENT THIS FUNCTION */

    int i, min_amount_planes = INF;
    int plane_capacity;
    int l,w,d,total;

    if (land_length == 0 || land_width == 0) {
        return 0; /* already closed.*/
    }

    for (i = 0; i < num_of_planes; i++) {
        plane_capacity = plane_capacities[i];

        if (plane_capacity <= land_length && plane_capacity <= land_width) {
            l = calculate_planes(land_length - plane_capacity, plane_capacity, plane_capacities, num_of_planes);/*symmetrical on length*/
            w = calculate_planes(plane_capacity, land_width - plane_capacity, plane_capacities, num_of_planes); /* symmetrical on width*/
            d = calculate_planes(land_length - plane_capacity, land_width - plane_capacity, plane_capacities, num_of_planes);/* non symmetric cases.*/

            total = 1 + l + w + d; /*1 from first use.*/
            min_amount_planes = (min_amount_planes<total)?min_amount_planes:total;
        }
    }

    return min_amount_planes;
}


void task2_planes(void) {
    /* IMPLEMENT THIS FUNCTION AND CALL calculate_planes() */
    int plane_type[5];
    int land_length, land_width;
    int plane_types;
    int i;
    int result;
    scanf("%d %d",&land_length,&land_width);
    scanf("%d", &plane_types);
    for(i = 0; i<plane_types; i++){
        scanf("%d",&plane_type[i]); /* h*w both. */
    }
    
    result = calculate_planes(land_length, land_width, plane_type, plane_types);
    printf("%d planes\n", result);
    
}

int main(void) {
    /* DO NOT CHANGE main() FUNCTION IMPLEMENTATION */
    int task_id;
    
    scanf("%d", &task_id);
    
    switch(task_id) {
        case 1:
            task1_assembly();
            break;
        case 2:
            task2_planes();
            break;
        default:
            /* no op */
            break;
    }

    return 0;
}
