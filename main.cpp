#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
struct number{ // цифры
    char digit;
    number * next;
};
struct pointer{ // указатели на вопросы
    number * question;
    pointer * next;
};
number * head_of_number[4]; //
pointer * head_of_pointer = NULL; //
void develop(){
    int i;
    number * num;
    pointer * point = head_of_pointer;
    for (i = 0; i <= 3; i++){
        num = head_of_number[i];
        while (num != NULL){
            printf("%c",num->digit);
            num = num->next;
        }
        printf(" ");
    }
    printf("\n");
    while (point != NULL){
        printf("%c",point->question->digit);
        point = point->next;
    }
}
int char_to_int(char num){
    switch (num) {
        case '0':{
            return 0;
            break;
        }
        case '1': {
            return 1;
            break;
        }
        case '2': {
            return 2;
            break;
        }
        case '3': {
            return 3;
            break;
        }
        case '4': {
            return 4;
            break;
        }
        case '5': {
            return 5;
            break;
        }
        case '6': {
            return 6;
            break;
        }
        case '7': {
            return 7;
            break;
        }
        case '8': {
            return 8;
            break;
        }
        case '9': {
            return 9;
            break;
        }
    }
}
void check(){
    int i,num[4] = {0,0,0,0}; // четыре данных числа с каким-то означиванием
    number * symbol; // чтобы ходить по цифрам в числах
    for (i = 0; i <= 3; i++){
        symbol = head_of_number[i];
        while (symbol != NULL){
            num[i] = num[i]*10 + char_to_int(symbol->digit);
            symbol = symbol->next;
        }
    }
    if (num[0] + num[1] == num[2] + num[3]){
        pointer * signification = head_of_pointer; // указатель на вопросы
        symbol = signification->question;
        while (signification != NULL){
            printf("%c ",symbol->digit);
            signification = signification->next;
            if (signification != NULL) {
                symbol = signification->question;
            }
        }
        printf("\n");
    }
}
void scan () { // сканирует числа
    number * head0 = head_of_number [0];
    number * head1 = head_of_number [1];
    number * head2 = head_of_number [2];
	number * head3 = head_of_number [3];
    int i;
    FILE * input;
    input = fopen("C:\\Users\\199930\\CLionProjects\\numbers_with_empties\\numbers.txt","r");
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
		if (feof(input) == false){
				head3 = head_of_number[3];
			make->next = new number;
			make = make->next;
			make->next = NULL;
			make->digit = symbol;
			head3 = head_of_number[3];
			if (symbol == '?') {
				if (head_of_pointer == NULL) {
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
			head3 = head_of_number[3];
    }
	head0 = head_of_number[0];
	head1 = head_of_number[1];
	head2 = head_of_number[2];
	head3 = head_of_number[3];
	fclose(input);
}
void choose (pointer * tek){ // принимает указатель на ? , который будет перебирать от 0 до 9
    int i;
    for (i = '0'; i <= '9'; i++){
        tek->question->digit = i;
        if (tek->next == NULL) { // все вопросы означены
            check();
        }
        else {
            choose(tek->next);
        }
    }
}
int main() {
    scan();
    //develop();
    choose (head_of_pointer);
	system("pause");
    return 0;
}