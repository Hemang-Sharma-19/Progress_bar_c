#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<windows.h>
#define bar_length 35
#define MAX_task 5
typedef struct{
        int id;
            char name[30];

    int step ;
    int progress;

}Task;
void bar_to_show(Task task);
void clear_screen();
int main(){
  


    srand(time(NULL));
    Task task[MAX_task];
    char Task_name[MAX_task][30] = {
        "downloading",
        "setup",
        "software changes",
        "error finding",
        "uploading",
};
    for(int i=0;i<MAX_task;i++){
        // intialisation 
    task[i].id= i + 1;
    strcpy(task[i].name , Task_name[i] );
    task[i].progress= 0;
   task[i].step = rand() % 5 +1;//random number between 1 to 5
bar_to_show(task[i]);    
}
int task_incomplete = 1;
while(task_incomplete){
    task_incomplete = 0;
     clear_screen();

        for(int i=0;i<MAX_task;i++){
            task[i].progress += task[i].step;
            if(task[i].progress>100){
               task[i].progress= 100;
            }
            else if(task[i].progress<100){
            task_incomplete = 1;
            }
bar_to_show(task[i]);

}
Sleep(1000);
} 

printf("task completed \n");
printf("CODE WITH HEMANG ");

    
return 0;

}
void clear_screen(){
    #ifdef _WIN32
    system("cls");
    #endif

}


void bar_to_show(Task task){
    int bar_to_show = (task.progress*bar_length)/100;

printf("\n %s: [",task.name);
for(int i = 0; i<bar_length; i++){
    if(i<bar_to_show){
        printf("=");
    }
    else
    printf(" ");

}
int ETA = (100 - task.progress) / task.step;
printf("] %d%% |ETA in sec  = %dsec " , task.progress, ETA);
}