#include <stdio.h>
#include "stdlib.h"
#include "time.h"
#define USER 100
#define data_count 10

int space_array[data_count];
int G_index=0;
int char_counting(char my_char[50]);


void space_counter();
void printing_all_data();
void loading_from_file();
void recording_all_data_to_file();



struct rabbit{
    unsigned int id[20];
    char rabbit_name[20];
    char rabbit_type[20];
    char rabbit_colour[20];
    int rabbit_age;
    int rabbit_price;

};
struct rabbit db[USER];

const char *colorNames[] = {
        "Red", "Green", "Blue", "Yellow", "Orange",
        "Purple", "Pink", "Brown", "Gray", "Cyan"
};
const char *typeNames[]={
        "UN","Asia","Chinese","Japan","Korean","UK"
};

int main() {

  
      int numAlphabets=5;
     for (int run = 0; run < 100; run++) {
        for (int i = 0; i < numAlphabets; i++) {
            int randomIndex = rand() % 26;
            char randomAlphabet = 'A' + randomIndex;
            printf("%c", randomAlphabet);
        }

        int numTypes = sizeof(typeNames) / sizeof(typeNames[0]);
        int randomIndex1 = rand() % numTypes;
        const char *randomtypeName = typeNames[randomIndex1];
        printf(" %s ", randomtypeName);

        int numColors = sizeof(colorNames) / sizeof(colorNames[0]);
        int randomIndex2 = rand() % numColors;
        const char *randomColorName = colorNames[randomIndex2];
        printf("%s ", randomColorName);

        int randomNum3 = (rand() % 20) + 1;
        printf("%d ", randomNum3);

        int randomNum4 = rand() % (50000 - 10000 + 1) + 10000;
        printf("%d \n", randomNum4);

        

        printing_all_data();
        
        
    }
    loading_from_file();
    


    return 0;
}

void space_counter(){

    FILE *fptr = fopen("rabbit.txt","r");

    if(fptr != NULL){
        char c = fgetc(fptr);
        int index=0;

        while (!feof(fptr)){
            if(c != '\n'){

                if( c == ' '){
                    space_array[index] +=1;

                }
                c = fgetc(fptr);

            } else{

                index++;
                c = fgetc(fptr);
            }

        }

    } else{
        printf("File open error at space_counter fun()\n");
    }

    for(int i=0; i<data_count; i++){

        printf(" %d",space_array[i]);
    }
    printf("\n");

}
void printing_all_data() {

    for (int user = 0; user < G_index; user++) {

        printf("%u-%s-%s-%s-%d-%d",&db[user].id,&db[user].rabbit_name,&db[user].rabbit_type,&db[user].rabbit_colour, &db[user].rabbit_age, &db[user].rabbit_price);

    
    }
}
void loading_from_file(){

    FILE *fptr = fopen("rabbit.txt","r");

    if( fptr != NULL){

        for(register int user=0; user < USER ; user++){

            fscanf(fptr,"%u%s%s%s%d%d",&db[user].id,&db[user].rabbit_name,&db[user].rabbit_type,&db[user].rabbit_colour,&db[user].rabbit_age,&db[user].rabbit_price);


        if(db[user].id == 0){
                break;
            }
            G_index++;
        }


    fclose(fptr);

}
}
void recording_all_data_to_file(){

    FILE *fptr = fopen("rabbit.txt","w");

    if(fptr == NULL){
        printf("[-]File opening error at recording to file function():\n");
    } else{

        for(int user=0; user<G_index; user++){

            fprintf(fptr,"%u%c%s%c%s%c%s%c%d%c%d",db[user].id,' ',db[user].rabbit_name,' ',db[user].rabbit_type,' ',db[user].rabbit_colour,' ',db[user].rabbit_age,' ',db[user].rabbit_price);

            fprintf(fptr,"%c",'\n');
        }

    }

    printf("Recording complete to 'encrypted_data.txt!' \n");

}
int char_counting(char my_char[50]){

    int count=0;
    for(register int a=0; a<50; a++){

        if(my_char[a]  == '\0') {
            break;
        }
        count++;
    }

    return count;

}


