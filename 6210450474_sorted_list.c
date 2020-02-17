
#include <stdio.h>
#include <stdlib.h>

typedef struct list{
    int value;
    struct list *next;
    struct list *prev;
}number;

void sortWoo(number **head, number **tail, number **tmp){
    if ((*tail)->value >= (*tmp)->value){ //หากค่าที่ใส่เข้ามาน้อยกว่าหรือเท่ากับตัวที่หางชี้อยู่
        if (!(*tail)->prev){ //sort ไปเป็นตัวสุดท้ายหากมีค่าน้อยสุด
            (*tail)->prev = *tmp;
            (*tmp)->next = *tail;
            *head = *tmp;
        }
        else if (((*tail)->prev)->value <= (*tmp)->value){ //หากว่าตัวต่อไปนั้นมีค่าน้อยกว่าหรือเท่ากับค่าที่ใส่เข้ามา
            (*tmp)->next = *tail;
            (*tmp)->prev = (*tail)->prev;
            ((*tail)->prev)->next = *tmp;
            (*tail)->prev = *tmp;            
        }
        else { //หากค่าต่อไปยังมีค่ามากกว่าค่าที่ใส่เข้ามา
            sortWoo(&(*head),&(*tail)->prev,&(*tmp));
        }
    }  
    else{ //หากค่าที่ใส่เข้ามามากกว่าตัวที่หางชี้อยู่
        if (!(*tail)->next){ //sort ไปเป็นตัวล่าสุดหากมีค่ามากสุด
            (*tail)->next = *tmp;
            (*tmp)->prev = *tail;
        }
        else if (((*tail)->next)->value > (*tmp)->value){ //หากว่าตัวต่อไปนั้นมีค่ากว่าค่าที่ใส่เข้ามา
            (*tmp)->prev = *tail;
            (*tmp)->next = (*tail)->next;
            ((*tail)->next)->prev = *tmp;
            (*tail)->next = *tmp;            
        }
        else { //หากค่าต่อไปยังมีค่าน้อยกว่าค่าที่ใส่เข้ามา
            sortWoo(&(*head),&(*tail)->next,&(*tmp));
        }
    }
}

int main(){
    int x;
    number *tmp = NULL, *head = NULL, *tail = NULL;
    scanf("%x",&x);
    while(x!=-1){
        if (!head){ //หากส่วนหัวยังว่าง
            head = (number *)malloc(sizeof(number));
            head->next = NULL;
            head->prev = NULL;
            head->value = x;
            tail = head;
        }
        else{
            tmp = (number *)malloc(sizeof(number));
            tmp->next = NULL;
            tmp->prev = NULL;
            tmp->value = x;
            sortWoo(&head,&tail,&tmp);
        }
        scanf("%x",&x);
    }
    for (;head;head = head->next){
        printf("%d ",head->value);
    }

}