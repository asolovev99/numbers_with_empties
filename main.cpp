#include <iostream>
struct number{ // цифры
    char digit;
    number * next;
};
struct question {
    int num;
    question * next;
};
struct pointer{ // указатели на вопросы
    number * question;
    pointer * next;
};
number * head_of_number[4]; //
pointer * head_of_pointer = NULL; //
void scan () { // сканирует числа
    int i;
    FILE * input;
    input = fopen("","r");
    char symbol;
    number * make;
    pointer * makep;
    for (i = 0; i <= 2; i++) {
        fscanf(input, "%c", &symbol);
        make = new number;
        head_of_number[i] = make;
        make->digit = symbol;
        make->next = NULL;
        if (symbol == '?'){
            if (head_of_pointer == NULL){
                makep = new pointer;
                head_of_pointer = makep;
                makep->question = make;
                makep->next = NULL;
            }
            else {
                makep->next = new pointer;
                makep = makep->next;
                makep->next = NULL;
                makep->question = make;
            }
        }
        while (symbol != ' ') {
            fscanf(input, "%c", &symbol);
            if (symbol != ' ') {
                make->next = new number;
                make = make->next;
                make->next = NULL;
                make->digit = symbol;
                if (symbol == '?'){
                    if (head_of_pointer == NULL){
                        makep = new pointer;
                        head_of_pointer = makep;
                        makep->question = make;
                        makep->next = NULL;
                    }
                    else {
                        makep->next = new pointer;
                        makep = makep->next;
                        makep->next = NULL;
                        makep->question = make;
                    }
                }
            }
        }
    }
    fscanf(input, "%c", &symbol);
    make = new number;
    head_of_number[3] = make;
    make->digit = symbol;
    make->next = NULL;
    if (symbol == '?'){
        if (head_of_pointer == NULL){
            makep = new pointer;
            head_of_pointer = makep;
            makep->question = make;
            makep->next = NULL;
        }
        else {
            makep->next = new pointer;
            makep = makep->next;
            makep->next = NULL;
            makep->question = make;
        }
    }
    while (feof(input) == false) {
        fscanf(input, "%c", &symbol);
        make->next = new number;
        make = make->next;
        make->next = NULL;
        make->digit = symbol;
        if (symbol == '?'){
            if (head_of_pointer == NULL){
                makep = new pointer;
                head_of_pointer = makep;
                makep->question = make;
                makep->next = NULL;
            }
            else {
                makep->next = new pointer;
                makep = makep->next;
                makep->next = NULL;
                makep->question = make;
            }
        }
    }
}
void choose (pointer * tek){
    int i;
    for (i = 0; i <= 9; i++){
        ->digit;
        // ?j = i; if j == last do sravnenie
    }
}
int amount [4]; // количество знаков вопроса в числе
number num[4]; // числа
int main() {
    scan();
    choose (head_of_pointer);
    return 0;
}