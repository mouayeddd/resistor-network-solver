#include<stdio.h>

typedef struct {
    int id;
    double value;
    int group_id;
    char type;
}Resistor;

Resistor create_resistor(int id , double value , int group_id , char type){
    Resistor resistor;
    resistor.id = id;
    resistor.value = value;
    resistor.group_id = group_id;
    resistor.type = type;
    return resistor;
}

void print_resistor_info(Resistor rs){
    printf("id: %d\nvalue: %.2f\ngroup_id: %d\ntype: %c\n\n",rs.id,rs.value,rs.group_id,rs.type);
}

double compute_series(Resistor *list, int count){
    double sum = 0.0;
    for(int i=0 ; i<count ; i++){
        if(list[i].type == 'S'){
            sum += list[i].value;
        }
    }

    return sum;
}

double compute_parallel(Resistor *list, int count){
    double sum = 0.0;
    for(int i=0 ; i<count ; i++){
        if(list[i].type == 'P'){
            sum += 1 / list[i].value;
        }
    }

    if(sum != 0){
        return 1 / sum;
    }else{
        printf("No resistors in parallel\n");
        return 0;
    }
}

int read_resistor(char *filename, Resistor *resistors_list){
    FILE *file = fopen(filename, "r");
    if(file == NULL){
        printf("Error: could not open file.\n");
        return 0;
    }

    int id , group_id , count = 0;
    char type;
    double value;

    while(fscanf(file, "%d %lf %d %c" ,&id,&value,&group_id,&type) == 4){
        resistors_list[count++] = create_resistor(id,value,group_id,type);
    }

    fclose(file);
    return count;
}

void print_results_in_file(char *filename, Resistor *resistorList, double series_result, double parallel_result){
    FILE *file = fopen(filename, "w");
    if(file == NULL){
        printf("Cannot write data in the file!\n");
        return;
    }

    fprintf(file, "==== Resistor Network Report ====\n");
    fprintf(file, "Series result: %.2f ohms\n",series_result);
    fprintf(file, "Parallel result: %.2f ohms\n",parallel_result);
    fprintf(file, "=================================");

    fclose(file);
}

int main (){
    Resistor rst[10];

    int count = read_resistor("components.txt" , rst);
    for(int i=0 ; i<count ; i++){
        print_resistor_info(rst[i]);
    }

    printf("\n");

    double series_result = compute_series(rst , count);
    double parallel_result = compute_parallel(rst , count);
    printf("Series result: %.2f\nParallel result: %.2f\n",series_result,parallel_result);
    print_results_in_file("result.txt",rst,series_result,parallel_result);

    return 0;
}